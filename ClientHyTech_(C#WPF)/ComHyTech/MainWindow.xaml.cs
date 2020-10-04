using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Reflection;

using System.Runtime.InteropServices;

using System.IO;
using System.ComponentModel;

namespace ComHyTech
{
 
    public partial class MainWindow : Window
    {
 
        public MainWindow()
        {
            InitializeComponent();
        }

        

        struct hcSqlParmT
        {
            public ushort size;
        };

        [StructLayout(LayoutKind.Sequential)]
        unsafe struct hcSqlDstInfoT     // Структура "Информация о колонках результата"
        {
            public int aliasno;
            public int fieldno;
            public int type;
            public uint len;
            public uint off;
            public fixed char coder[32];
            public fixed char fname[32];
            public int func;
            public fixed char asname[32];
            public int key;
            public int resno;
        };
         
        [DllImport("hscli.dll")]
        static extern int hcSqlInit(IntPtr dummy);

        [DllImport("hscli.dll")]
        static extern int hcSqlCheckInit();
         
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlAllocConnect(out int pdb);
        
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlConnect(int pdb, string server, string login , string password);

        [DllImport("hscli.dll")]                        
        static unsafe extern int hcSqlAllocStmt(int pdb, int * pOper);// Создать оператор

        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlSetStmtAttr(int pOper, int option, void* pValue, int size);

        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlExecDirect(int pOper, string strSQL);// Выполняем SQLзапрос
         
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlNumResultCols(int pOper, int*  pCol);

        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlRowCount(int pOper, int* pStr);

        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlOpenResults(int pOper, int *pRecSize);
        
        [DllImport("hscli.dll", CallingConvention = CallingConvention.StdCall)]
        static unsafe extern int hcSqlGetStmtAttr(int pOper, int option, int pos, [In,Out]hcSqlDstInfoT[]  pValue, int size, int* cnt);

        [DllImport("hscli.dll", CallingConvention = CallingConvention.StdCall)] //, CallingConvention=CallingConvention.Cdecl   |   ,  EntryPoint="hcSqlReadResults" ,CharSet=CharSet.Auto , SetLastError=true
        static unsafe extern int hcSqlReadResults(int pOper, int gStart,  byte[] bufOut , int wBufSize, out int   cntOut);
        
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlCloseResults(int pOper); // Закрытие доступа к результатам
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlFreeConnect(int pdb); // Освободить соединение
        [DllImport("hscli.dll")]
        static unsafe extern int hcSqlDone();// Завершение работы

        private unsafe void button_Click(object sender, RoutedEventArgs e)
        {
            int err = -300000;// код ошибки заведомо не существующий
             
            int       pdb = 0 ;
            int     pOper = 0 ; // идетификатор оператора
            int      pCol = 0 ; // кол-во колонок
            int     pStr = 0 ; // кол-во строк
            int pRecSize = 0 ; // размер записи
            int    cntOp = 0 ; //  сколько байтов записали в буфер
            
            if ((err = hcSqlInit(IntPtr.Zero)) != 0)  { return; } // Инициализация клиентской части 
            textBox_Copy3.AppendText("Инициализация клиентской части err = " + err.ToString() + "\r\n");
            err = hcSqlCheckInit();                              // Проверка завершения инициализации
            textBox_Copy3.AppendText("Проверка завершения инициализации err = " + err.ToString() + "\r\n") ;
            err = hcSqlAllocConnect  (out pdb ) ;           //  Создать соединение
            textBox_Copy3.AppendText ("Создать соединение err = " + err.ToString() + "\r\n" );
            textBox_Copy3.AppendText ("соединение         pdb = " + pdb.ToString() + "\r\n" );
            err = hcSqlConnect       (pdb, textBox.Text.ToString() , textBox1.Text.ToString(), textBox2.Text.ToString()); //Установить связь с СУБД
            textBox_Copy3.AppendText ("Установить связь с СУБД err = " + err.ToString() + "\r\n");
            err = hcSqlAllocStmt     (pdb,   &pOper                                         ); // Создать оператор
            textBox_Copy3.AppendText ("Создать оператор err = " + err.ToString()   + "\r\n" );
            textBox_Copy3.AppendText ("оператор       pOper = " + pOper.ToString() + "\r\n" );
            err = hcSqlSetStmtAttr(pOper, 1001, (void*)1, 0); // ф-ция "Изменение параметров оператора"
            textBox_Copy3.AppendText("ф-ция  Изменение параметров оператора  err = " + pOper.ToString() + "\r\n");
            err = hcSqlExecDirect(pOper, textBox3.Text.ToString()); // Выполняем SQLзапрос
            textBox_Copy3.AppendText("Выполняем SQLзапрос = " + pOper.ToString() + "\r\n");

            err = hcSqlNumResultCols(pOper, &pCol);     // Получить кол-во колонок результата
            textBox_Copy3.AppendText("кол-во колонок = " + pCol.ToString() + "\r\n");
            err = hcSqlRowCount(pOper, &pStr);          // Получить кол-во строк   результата
            textBox_Copy3.AppendText("кол-во строк = " + pStr.ToString() + "\r\n");
            err = hcSqlOpenResults(pOper, &pRecSize);   // Открытие результатов для чтения
            textBox_Copy3.AppendText("размер записи = " + pRecSize.ToString() + "\r\n");
             
            hcSqlDstInfoT[] infCol = new hcSqlDstInfoT[pCol]; // Структура "Информация о колонках результата" 
            err = hcSqlGetStmtAttr(pOper, 107, 0, infCol,  pCol * 128, &cntOp);// Получить информацию об операторе

            int gStart    = 0;                  // с какой записи начинаем читать 
            int wBufSize = pRecSize * pStr ;     // задаем размер сколько прочитать
            byte[] bufOut = new byte[(int)wBufSize] ;   // буфер для результата 
            int cntOut  ;                               // сколько записали в буфер 
            err = hcSqlReadResults(pOper, gStart, bufOut, wBufSize, out cntOut); // Чтение результатов
            textBox_Copy3.AppendText("Чтение результатов  err  = " + err.ToString() + "\r\n");

            //Encoding e1 = Encoding.GetEncoding(866);// .Default; // Encoding.GetEncoding(866)
            //string testString = e1.GetString(bufOut);
             
             
            BindingList<byte> bL =  new BindingList<byte>(bufOut);
            textBox_Copy3.AppendText(String.Join(" ", bL) + " ");

            for (long i = 0; i < pStr; i++)// идем по строкам
            {
             for (int j = 0; j < pCol; ++j)// идем по колонкам
             {
			 
              switch (infCol[j].type)// в зависимости от типа колонки преобразовываем в соответствующий тип
              {
                case 0: // 0 Массив символов длиной не более заданной 
                        //string s(p, infCol[j].len);
                       textBox_Copy3.AppendText( infCol[j].type  + " ");
                     // textBox_Copy3.AppendText( infCol[j].len + " ");
                    // textBox_Copy3.AppendText(testString.ToString() + " ");
                            break;
                 case 1: // 1 Массив байтов заданной длины 
                            textBox_Copy3.AppendText(infCol[j].type + " ");
                            break;

                        //			//            case 2: // 2 Элемент - unsigned char (короткое целое)  short
                        //   //                               std::cout << *reinterpret_cast < unsigned char*> (p) << "  ";
                        //   //                               break;

                        //			//            case 3: // 3 Элемент - signed short  
                        //   //                                     std::cout << *reinterpret_cast < signed short*> (p) << "  ";
                        //   //                                break;

                        //			//case 4: // 4 Элемент - unsigned short  
                        //   //        std::cout << *reinterpret_cast < unsigned short*> (p) << "  ";
                        //   //        break;

                        //			//case 5: // 5 Дата    - unsigned short  
                        //   //        std::cout << *reinterpret_cast < unsigned short*> (p) << "  ";
                        //   //        break;

                        //			//case 6: //6  Номер   - 3-х байтовое целое без знака  
                        //   //                                // std::cout << *reinterpret_cast<  *>(p);
                        //   //        break;

                        //			//case 7: //7 Элемент - long int 
                        //   //        std::cout << *reinterpret_cast < long int*> (p) << "  ";
                        //   //        break;

                      case  8: // 8 Элемент - unsigned long int  в БД это dword  
                         textBox_Copy3.AppendText(infCol[j].type + " ");
                         textBox_Copy3.AppendText(infCol[j].len + " ");
                        //                               //        std::cout << *reinterpret_cast < unsigned long int*> (p) << "  ";
                       break;

                        //			//case 9: //	9  Элемент - float
                        //   //        std::cout << *reinterpret_cast<float*>(p) << "  ";
                        //   //        break;

                        //			//case 10: //	10 Деньги (double)  
                        //   //        std::cout << *reinterpret_cast<double*>(p) << "  ";
                        //   //        break;

                        //			//case 1: // 11 Элемент - double  
                        //   //        std::cout << *reinterpret_cast<double*>(p) << "  ";
                        //   //        break;

                        //			//case 12: //	12 Элемент - signed __int64 
                        //   //        std::cout << *reinterpret_cast < signed __int64 *> (p) << "  ";
                        //   //        break;
                        //			//case 13: //	13 Элемент - unsigned __int64 
                        //   //        std::cout << *reinterpret_cast < unsigned __int64 *> (p) << "  ";
                        //   //        break;
                    }//////switch

                    //      // p += infCol[j].len;

                }/////// идем по колонкам
                textBox_Copy3.AppendText(  "\r\n");  
            } //// идем по строкам


            hcSqlCloseResults(pOper); // Закрытие доступа к результатам

                           hcSqlFreeConnect(pdb);    // Освободить соединение

                          hcSqlDone();              // Завершение работы


             



        }






    }
}
 