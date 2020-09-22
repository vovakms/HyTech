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
using System.Collections.Generic;
using System.Data;
using System.Runtime.InteropServices;
using System.IO;

namespace test01HyTech
{
   public unsafe partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
         
        struct hcSqlParmT // Структура для инициализации клиентской части
        {
            public uint size;  // Размер структуры (в Си unsigned)
        };
        
        [StructLayout(LayoutKind.Sequential)]
        struct hcSqlDstInfoT // Структура содержит внутреннюю информацию о колонке результата, 
        {
            // полученного при выполнении SQL-запроса. http://hytechdb.ru/index.php?s=docs&ru=V25/hscli/str_hcSqlDstInfoT.htm 
            public int aliasno ; // Порядковый номер алиаса, 
            public int fieldno ; // Номер колонки в таблице 
            public int type ; // Тип колонки 
            public uint len ; // Длина поля в байтах ( в Си unsigned ) 
            public uint off ; // Смещение поля относительно начала логической записи ( в Си unsigned ) 
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)] public byte[] coder ;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)] public byte[] fname; // public fixed byte fname[32] ; // Имя поля в таблице
            public int func;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)] public byte[] asname ; // Переименование поля 
            public int key ; public int resno ; // Сквозной номер поля в результате 
        };

   




                
        [DllImport("hscli.dll")]
        static extern int hcSqlInit(IntPtr pInit); // Инициализация клиентской части

        [DllImport("hscli.dll")]
        static extern int hcSqlCheckInit();        // Проверка завершения инициализации
        
        [DllImport("hscli.dll")]
        static  extern int hcSqlAllocConnect(out int pdb); // Создать соединение

        [DllImport("hscli.dll")]
        static  extern int hcSqlConnect(int pdb, string server, string login, string password); // Установить связь с СУБД

        [DllImport("hscli.dll")]
        static  extern int hcSqlAllocStmt(int pdb, int* pOper);// Создать оператор

        [DllImport("hscli.dll")]               // ф-ция
        static  extern int hcSqlSetStmtAttr(   // "Изменение параметров оператора"
                                            int pOper,  // Идентификатор оператора  
                                         uint option, // Режим  
                                              void* pValue,	// Значение или буфер значения  
                                         uint size);  // Размер буфера или 0  
          
        [DllImport("hscli.dll")]
        static  extern int hcSqlExecDirect(int pOper, string strSQL);// Выполняем SQLзапрос

        [DllImport("hscli.dll")]
        static  extern int hcSqlNumResultCols(int pOper, int* pCol); // ф-ция "Получить количество колонок результата"

        [DllImport("hscli.dll")]
        static  extern int hcSqlRowCount(int pOper, int* pStr); // ф-ция "Получить количество строк результата"

        [DllImport("hscli.dll")]
        static  extern int hcSqlOpenResults(int pOper, uint* pRecSize); // ф-ция "Открытие результатов для чтения"

        [DllImport("hscli.dll", CallingConvention = CallingConvention.StdCall)] // ф-ция   
        static  extern int hcSqlGetStmtAttr(                                    // "Получить информацию об операторе"
                                            int pOper,  // Идентификатор оператора  
                                            uint option, // unsigned  Режим  
                                            int pos,    // int   Позиция  
                      [In, Out]hcSqlDstInfoT[] pValue,  // void*  Буфер для значения  
                                            uint size,   // unsigned   и его размер  
                                            uint* cntOp) ; // unsigned*   сколько байтов записали в буфер  

        [DllImport("hscli.dll", CallingConvention = CallingConvention.StdCall)] // ф-ция  
        static unsafe extern int hcSqlReadResults(                                   // "Чтение результатов"
                                                  int pOper,  // Идентификатор оператора
                                                  int gStart, // С какой записи начинаем читать
                                                  byte[] bufOut, // Адрес буфера для присылаемых записей.
                                                  int wBufSize,  // Размер буфера для результатов
                                                  out int cntOut ); // Сколько прочитали


        [DllImport("hscli.dll")]
        static  extern int hcSqlCloseResults(int pOper); // Закрытие доступа к результатам
        [DllImport("hscli.dll")]
        static  extern int hcSqlFreeConnect(int pdb); // Освободить соединение
        [DllImport("hscli.dll")]
        static  extern int hcSqlDone(); // Завершение работы

        private void button_Click(object sender, RoutedEventArgs e)
        {
            uint HSCLI_STMT_DST_INFO = 107; // Информация об колонке результата dst (dstinfo * i)  
            uint HSCLI_STMT_RC_TYPE = 109; // Тип retcode (int)  
            uint HSCLI_STMT_RC_SIZE = 110; // Длина retcode (int)  
            uint HSCLI_STMT_RC_BODY = 111; // Значение retcode (char[], long, double)  
            uint HSCLI_STMT_CURSNO = 140; // Номер курсора в HTSQL-сервере (int)  

            int SIZE_HCSQLDSTINFOT = 128;

            int err = 30000;// код ошибки заведомо не существующий

            int pdb   = 0 ; // Идентификатор соединения
            int pOper = 0 ; // Идетификатор оператора
            int pCol  = 0 ; // кол-во колонок
            int pStr  = 0 ; // кол-во строк
            uint pRecSize = 0 ; // размер строки 
            uint cntOp    = 0 ; //  сколько байтов записали в операторский буфер 

            int pos = 0 ;

            if ((err = hcSqlInit(IntPtr.Zero)) != 0) { return; } // Инициализация клиентской части 
            textBox4.AppendText("Ф-ция <Инициализация клиентской> части    err = " + err.ToString() + "\r\n");

            err = hcSqlCheckInit();                              // Проверка завершения инициализации
            textBox4.AppendText("Ф-ция <Проверка завершения инициализации> err = " + err.ToString() + "\r\n");

            err = hcSqlAllocConnect(out pdb);           //  Создать соединение
            textBox4.AppendText("Ф-ция <Создать соединение> err = " + err.ToString() + "\r\n");
            textBox4.AppendText("Идентификатор соединения   pdb = " + pdb.ToString() + "\r\n");

            err = hcSqlConnect(pdb, textBox5.Text.ToString(), textBox6.Text.ToString(), textBox7.Text.ToString()); //Установить связь с СУБД
            textBox4.AppendText("Ф-ция <Установить связь с СУБД>           err = " + err.ToString() + "\r\n");

            err = hcSqlAllocStmt(pdb, &pOper); // Создать оператор
            textBox4.AppendText("Ф-ция <Создать оператор>    err = " + err.ToString() + "\r\n");
            textBox4.AppendText("Идентификатор оператора   pOper = " + pOper.ToString() + "\r\n");

            err = hcSqlSetStmtAttr(pOper, 1001, (void*)1, 0); // ф-ция "Изменение параметров оператора"
            textBox4.AppendText("ф-ция <Изменение параметров оператора>    err = " + err.ToString() + "\r\n");

            err = hcSqlExecDirect(pOper, textBox3.Text.ToString()); // Выполняем SQLзапрос
            textBox4.AppendText("Ф-ция <Выполняем SQLзапрос>               err = " + err.ToString() + "\r\n");

            err = hcSqlNumResultCols(pOper, &pCol);     // Получить кол-во колонок результата
            textBox4.AppendText("кол-во колонок = " + pCol.ToString() + "\r\n");

            err = hcSqlRowCount(pOper, &pStr);          // Получить кол-во строк   результата
            textBox4.AppendText("кол-во строк = " + pStr.ToString() + "\r\n");

            err = hcSqlOpenResults(pOper, &pRecSize);   // Открытие результатов для чтения
            textBox4.AppendText("размер записи  pRecSize = " + pRecSize.ToString() + "\r\n");

            hcSqlDstInfoT[] infCol = new hcSqlDstInfoT[pCol]; // Структура "Информация о колонках результата" 
            uint size =  Convert.ToUInt32( pCol * SIZE_HCSQLDSTINFOT  );
            err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, pos, infCol, size, &cntOp);// Получить информацию об операторе
            textBox4.AppendText("ф-ция <Получить информацию об операторе>  err = " + err.ToString() + "\r\n");
             
            int gStart = 0;                  // с какой записи начинаем читать результат
            int wBufSize = (int)pRecSize * pStr;     // задаем размер сколько прочитать результата
            byte[] bufOut = new byte[(int)wBufSize];   // буфер для результата 
            int cntOut;                               // сколько записали в буфер  результата

            err = hcSqlReadResults(pOper, gStart, bufOut, wBufSize, out cntOut); // Чтение результатов
            textBox4.AppendText("Ф-ция <Чтение результатов>  err  = " + err.ToString() + "\r\n");

            DataTable dT = new DataTable();
            for (int n = 0; n < pCol; n++)
            {
                dT.Columns.Add(Encoding.GetEncoding(866).GetString(infCol[n].fname).TrimEnd('\0'));
            }
            DataRow dR;
             
            MemoryStream memStream = new MemoryStream(bufOut);
            BinaryReader reader = new BinaryReader(memStream);

            byte[] tempBuf;
             
           for (int i = 0; i < pStr; i++)// перебираем как бы строки
            {
             dR = dT.NewRow();
             for (int j = 0; j < pCol; j++)//перебираем как бы поля на каждой строке
             {
                   switch (infCol[j].type)// в зависимости от типа колонки преобразовываем в соответствующий тип
                            {
                                case 0: // 0 Массив символов длиной не более заданной 

                            // dR[j] =  reader.Read(bufOut, (i * (int)pRecSize) + (int)infCol[j].off, (int)infCol[j].len);// tempBuf.ToString() ;
                            tempBuf = new byte[(int)infCol[j].len];
                            reader.Read(tempBuf, 0, (int)infCol[j].len);
                            dR[j] = Encoding.GetEncoding(866).GetString(tempBuf);
                            break;
                             
                                case 1: // 1 Массив байтов заданной длины 
                                    tempBuf = new byte[(int)infCol[j].len];
                                    reader.Read(tempBuf, 0, (int)infCol[j].len);
                                    dR[j] = BitConverter.ToString(tempBuf);// tempBuf.ToString() ;
                                    break;
                                  
                                 case 2: // 2 Элемент - unsigned char (короткое целое)  short
                                    dR[j] = reader.ReadByte() ;
                                    break;
                                
                                 case 3: // 3 Элемент - signed short  
                                    dR[j] = reader.ReadInt16();
                                    break;

                                 case 4: // 4 Элемент - unsigned short  
                                    dR[j] = reader.ReadUInt16();
                                    break;

                                 case 5: // 5 Дата    - unsigned short  
                                     dR[j] = reader.ReadUInt16();
                                     break;

                                 case 6: //6  Номер   - 3-х байтовое целое без знака  
                                     //textBox4.AppendText(infCol[j].type + " ");
                                   break;

                                 case 7: //7 Элемент - long int 
                                      dR[j] = reader.ReadInt32();
                                   break;

                                 case 8: // 8 Элемент - unsigned long int  в БД это dword 
                                     dR[j] = reader.ReadInt32();
                                    break;

                                case 9: //	9  Элемент - float
                                    dR[j] = reader.ReadSingle();
                                 break;

                                case 10: //	10 Деньги (double)  
                                   dR[j] = reader.ReadDouble();
                                  break;

                                case 11: // 11 Элемент - double  
                                     dR[j] = reader.ReadDouble();
                                  break;

                                case 12: //	12 Элемент - signed __int64 
                                     dR[j] = reader.ReadInt64();
                                   break;
                                case 13: //	13 Элемент - unsigned __int64 
                                    dR[j] = reader.ReadUInt64();
                                   break;

                    }// switch
                }/////////////////
                dT.Rows.Add(dR);
            }//////////////////// перебираем как бы строки


            // string name = reader.ReadString();
            //textBox4.AppendText(name + "\r\n");

            //int age = reader.ReadInt32();
            //textBox4.AppendText(age + "\r\n");

            //double salary = reader.ReadDouble();

            //for (int j = 0; j < pCol; j++) 
            //{
            //    for (int m = 0; m < 32; m++)
            //    {
            //        textBox4.AppendText(infCol[j].fname[m] + " ");
            //    }
            //    textBox4.AppendText(infCol[j].fname[m] + " ");
            //    //infCol[j].fname[0]
            //    //textBox4.AppendText(Encoding.GetEncoding(866).GetString( , (i * (int)pRecSize) + (int)infCol[j].off, (int)infCol[j].len) + " "); 
            //}


            //for (int i = 0; i < pStr; i++)// идем по строкам
            //{
            //    dR = dT.NewRow(); 
            //    for (int j = 0; j < pCol; j++)// идем по колонкам
            //    {
            //        switch (infCol[j].type)// в зависимости от типа колонки преобразовываем в соответствующий тип
            //        {
            //            case 0: // 0 Массив символов длиной не более заданной 
            //                textBox4.AppendText(Encoding.GetEncoding(866).GetString(bufOut, (i * (int)pRecSize) + (int)infCol[j].off, (int)infCol[j].len) + " ");
            //                dR[j] = Encoding.GetEncoding(866).GetString(bufOut, (i * (int)pRecSize) + (int)infCol[j].off, (int)infCol[j].len) ;
            //                break;

            //            case 1: // 1 Массив байтов заданной длины 
            //                byte[] mB = new byte[(int)infCol[j].len];
            //                Buffer.BlockCopy(bufOut, (i * (int)pRecSize) + (int)infCol[j].off, mB, 0, (int)infCol[j].len);
            //                string strHex = BitConverter.ToString(mB) ;
            //                textBox4.AppendText(strHex + " ");
            //                dR[j] = strHex;
            //                break;

            //            case 2: // 2 Элемент - unsigned char (короткое целое)  short
            //                textBox4.AppendText(( bufOut[(i * (int)pRecSize) + (int)infCol[j].off] ).ToString() + " ");
            //                dR[j] = bufOut[(i * (int)pRecSize) + (int)infCol[j].off] ;
            //                break;

            //            case 3: // 3 Элемент - signed short  
            //                textBox4.AppendText(BitConverter.ToUInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off)    + " ");
            //                dR[j] = BitConverter.ToInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off)  ;
            //                break;

            //            case 4: // 4 Элемент - unsigned short  
            //                textBox4.AppendText(BitConverter.ToUInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToUInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 5: // 5 Дата    - unsigned short  
            //                textBox4.AppendText(BitConverter.ToUInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToUInt16(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 6: //6  Номер   - 3-х байтовое целое без знака  
            //                textBox4.AppendText(infCol[j].type + " ");
            //                break;

            //            case 7: //7 Элемент - long int 
            //                textBox4.AppendText(BitConverter.ToInt32(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToInt32(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 8: // 8 Элемент - unsigned long int  в БД это dword 
            //                textBox4.AppendText(BitConverter.ToInt32(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToInt32(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 9: //	9  Элемент - float
            //                textBox4.AppendText(BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 10: //	10 Деньги (double)  
            //                textBox4.AppendText(BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 11: // 11 Элемент - double  
            //                textBox4.AppendText(BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToDouble(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;

            //            case 12: //	12 Элемент - signed __int64 
            //                textBox4.AppendText(BitConverter.ToInt64(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToInt64(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;
            //            case 13: //	13 Элемент - unsigned __int64 
            //                textBox4.AppendText(BitConverter.ToUInt64(bufOut, (i * (int)pRecSize) + (int)infCol[j].off) + " ");
            //                dR[j] = BitConverter.ToUInt64(bufOut, (i * (int)pRecSize) + (int)infCol[j].off);
            //                break;
            //        }//////switch
            //    }/////// идем по колонкам
            //    dT.Rows.Add(dR);
            //    textBox4.AppendText("\r\n");
            //} //// идем по строкам

            dataGrid.ItemsSource = dT.DefaultView    ;

            err = hcSqlCloseResults(pOper); // Закрытие доступа к результатам
            textBox4.AppendText("ф-ция <Закрытие доступа к результатам>    err = " + err.ToString() + "\r\n");
            err = hcSqlFreeConnect(pdb);    // Освободить соединение
            textBox4.AppendText("ф-ция <Освободить соединение>    err = " + err.ToString() + "\r\n");
            err = hcSqlDone();              // Завершение работы
            textBox4.AppendText("ф-ция <Завершение работы>    err = " + err.ToString() + "\r\n");

            label1.Content = pStr.ToString();

        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

       

        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            this.DragMove();
        }

        private void button1_Copy_Click(object sender, RoutedEventArgs e)
        {
            if (this.WindowState != WindowState.Normal)
                this.WindowState = WindowState.Normal;
            else
                this.WindowState = WindowState.Maximized;
        }

        private void button1_Copy1_Click(object sender, RoutedEventArgs e)
        {
           
            this.WindowState = WindowState.Minimized;

        }
    }
}
 
// byte[] regionCol = new byte[infCol[j].len + 1];
// Buffer.BlockCopy( regionStr,   (int)infCol[j].off, regionStr, 0, (int)infCol[j].len);
 
//DataTable dT = new DataTable();
//
//dataGrid.ItemsSource = dT.DefaultView ; 

//            for (int n = 0; n<pCol; n++)
//                 dT.Columns.Add( );
 
 
// textBox4.AppendText(Encoding.ASCII.GetString(regionStr) + " ");

//Encoding e1 = Encoding.GetEncoding(866);
