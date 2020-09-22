#define HYCFG_WIN32
#include "hscli.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS"); //  рус локаль
	hcERR     err ; // Код ошибки
	hcHDB     pdb ; // Адрес памяти, куда будет записан идентификатор   соединения.
	hcHSTMT pOper ; // Адрес памяти, куда будет записан идентификатор   оператора.
	hcSqlParmT Init = { sizeof(Init) }; // Адрес структуры   с параметрами инициализации
	int      pCol     = 0 ; // количество колонок
	hcRECNO  pStr     = 0 ; // количество строк  
	unsigned cntOp    = 0 ; // Размер считанной информации в байтах, в ф-ции "Получить информацию об операторе". 
	unsigned pRecSize = 0 ; // Размер читаемой записи в байтах, в ф-ции "Открытие результатов для чтения" .
	unsigned cntOut   = 0 ; // для ф-ции "Чтение результатов" Адрес, куда функция запишет количество байтов данных, помещённых в буфер пользователя. Если это количество разделить на длину записи, то получим количество считанных записей. Неполные записи не присылаются. 

	if (err = hcSqlInit(&Init) != 0) {/* Инициализация клиентской части */ printf("Ошибка с параметрами инициализации \n"); return 0; }
	 
	if (hcSqlCheckInit()  < 0) {  /* Проверка завершения инициализации */ printf("Ошибка завершения инициализации \n"); return 0; }
	  
	err = hcSqlAllocConnect(&pdb);     // Создать соединение
	
    err = hcSqlConnect(pdb, "tcpip:/localhost:13000", "HTADMIN", "PASSWORD");//Установить связь с СУБД
	  
	err = hcSqlAllocStmt(pdb, &pOper); // Создать оператор
	 
	err = hcSqlExecDirect(pOper, "fix all; select * from CITY;");// Выполняем SQLзапрос GROUP TAB TABLES USERSPEC UGROUPS

	err = hcSqlNumResultCols(pOper, &pCol) ; // Получить количество колонок результата
	err = hcSqlRowCount(pOper, &pStr)      ; // Получить количество строк результата
	 
	hcSqlDstInfoT *Kol = new hcSqlDstInfoT[pCol];//  Структура   "Информация о колонках результата"
	 
	err = hcSqlOpenResults(pOper, &pRecSize); // Открытие результатов для чтения
	  
	 //for (int i = 0; i < pCol; i++)  //получаем столько сколько столбиков
	 //{
		// err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, i, Kol, pCol * 4 * sizeof(hcSqlAliasInfoT), &cntOp);// Получить информацию об операторе
	 //}
	     std::cout << "........ информация о столбиках ..............." << endl;
	 for (int i = 0; i < pCol; i++)  //получаем столько сколько столбиков
	 {
		 std::cout << ".......... С Т О Л Б И К  №  " << i + 1 << " .............." << endl;
		 err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, i, Kol, pCol * 4 * sizeof(hcSqlAliasInfoT), &cntOp);// Получить информацию об операторе
		 std::cout << "ф-ция                                   err= " << err << endl;
		 std::cout << "прочитали байтов                      cntOp= " << cntOp << endl;
		 std::cout << "Порядковый номер алиаса aliasno =            " << Kol[i].aliasno << endl;
		 std::cout << "Номер поля в таблице fieldno =               " << Kol[i].fieldno << endl;
		 std::cout << "Тип выражения, константа HSCLI_ET_??? type = " << Kol[i].type    << endl;
		 std::cout << "Длина поля в байтах len =                    " << Kol[i].len     << endl;
		 std::cout << "Смещение поля отн-о начала лог.зап. off =    " << Kol[i].off     << endl;
		 //std::cout << "Имя кодификатора.только для coder(MYCODER, code). coder = " << Kol[i].coder << endl;
		 //for (int z = 0; z < 32;z++)
		 std::cout << "Имя поля в таблице, fname =                  " <<  Kol[i].fname  << endl;
		 std::cout << "Формат выражения CURS_OUTEXPR func =         " << Kol[i].func    << endl;
		// std::cout << "Переименование поля, asname = " << Kol[i].asname << endl;
		 std::cout << "Ключевитость поля,  key =                    " << Kol[i].key     << endl;
		 std::cout << "Сквозной номер поля в результате resno =     " << Kol[i].resno   << endl;
		 std::cout << "................................................................." << endl;
	 }
  char bufOut[1024]; 
  // void *bufOut;
	for (long i = 0; i < pStr; i++)//идем по строкам
	{
	 const auto err = hcSqlReadResults(pOper, i, bufOut, sizeof(bufOut), &cntOut);// Чтение результатов
			
	 char *p =  bufOut;
	 for (size_t j = 0; j < cntOut / sizeof(hcSqlAliasInfoT)  ; ++j) 
	 {
	   switch (Kol[j].type)
			  {
				   case HSCLI_ET_CHAR: // 0 Массив символов длиной не более заданной 
				   {  
					   std::string s(p, Kol[j].len) ;
			      	   std::cout   << s.c_str() << "  " ;
				   }
					   break;
				   
				 case HSCLI_ET_ARRA: // 1 Массив байтов заданной длины 
					 std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
					 break;

         		 case HSCLI_ET_BYTE: // 2 Элемент - unsigned char (короткое целое)  short
				 {
					 std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
				 }
				 	 break;

				 case HSCLI_ET_INTR: // 3 Элемент - signed short  
				 	 std::cout << *reinterpret_cast<signed short *>(p) << "  " ;
				  	break;
				
				 case HSCLI_ET_WORD: // 4 Элемент - unsigned short  
				   std::cout   << *reinterpret_cast<unsigned short *>(p) << "  " ;
				 break;

				 case HSCLI_ET_DATE: // 5 Дата    - unsigned short  
					 std::cout << *reinterpret_cast<unsigned short *>(p) << "  " ;
					 break;

				 case HSCLI_ET_NMBR: //6  Номер   - 3-х байтовое целое без знака  
					// std::cout << *reinterpret_cast<  *>(p);
						 break;

				 case HSCLI_ET_LONG: //7 Элемент - long int 
					 std::cout << *reinterpret_cast<long int *>(p) << "  " ;
							 break;

				 case  HSCLI_ET_DWRD: // 8 Элемент - unsigned long int  в БД это dword          
					 std::cout <<  *reinterpret_cast<unsigned long int *>(p) << "  ";
					 break;

				 case HSCLI_ET_FLOA: //	9  Элемент - float
					 std::cout << *reinterpret_cast<float *>(p) << "  ";
						 break;

				 case HSCLI_ET_CURR: //	10 Деньги (double)  
					 std::cout << *reinterpret_cast<double *>(p) << "  ";
					 break;

				 case HSCLI_ET_DFLT: // 11 Элемент - double  
				    std::cout   << *reinterpret_cast<double *>(p) << "  ";
				 break;

				 case HSCLI_ET_QINT: //	12 Элемент - signed __int64 
					 std::cout << *reinterpret_cast<signed __int64 *>(p) << "  ";
					 break;
				 case HSCLI_ET_QWRD: //	13 Элемент - unsigned __int64 
					 std::cout << *reinterpret_cast<unsigned __int64 *>(p) << "  ";
					 break;
            	 }
				p += Kol[j].len;

			}
			std::cout << std::endl ;
		}
	 
	 
	hcSqlCloseResults(pOper); // Закрытие доступа к результатам
	hcSqlFreeConnect(pdb);    // Освободить соединение
	hcSqlDone();              // Завершение работы
	std::system("pause");
}

//***********************************************************************************************

//	double   bufAttr = 0;      // буфер Атрибутов
//	unsigned cntAttr = 0;      // и сколько байтов записали в этот буфер  
//err = hcSqlGetConnectAttr(pdb, HSCLI_CONN_SRV_VERS, 0, &bufAttr, sizeof(bufAttr), &cntAttr);// Получить информацию о соединении
//err = hcSqlSetConnectAttr(pdb, HSCLI_ATTR_CBK_SRVMSG, (void*)SrvMsg, 0); // Изменение параметров соединения  

void HSCLI_CBK SrvMsg(hcHDB conn, int is_err)//Функция обработки текстовых сообщений, выводящая их в стандартный вывод. 
{
	printf("\n%s\n", is_err ? "Error:" : "Message:");

	char buf[256];
	for (; ; )
	{
		unsigned cnt;
		if (hcSqlConnReadMsg(conn, buf, sizeof(buf) - 1, &cnt))
			break;
		if (cnt == 0)
			break;
		if (cnt >= sizeof(buf))
			cnt = sizeof(buf) - 1;
		buf[cnt] = 0;
		fputs(buf, stdout);
	}
	fputc('\n', stdout);
}
//**************************************************************************************** 
//unique_ptr<char[]> buf(new char[pRecSize]);// задаем размер буфера

//unsigned cnt = 0;  //   количество байтов данных, помещённых в буфер пользователя. Если это количество разделить на длину записи, то получим количество считанных записей. Неполные записи не присылаются.


