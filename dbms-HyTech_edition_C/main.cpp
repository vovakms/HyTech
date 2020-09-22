#define HYCFG_WIN32

#include "hscli.h"
#include <iostream>
#include <memory>
 
#define	SIZE_HCSQLDSTINFOT		128

void main() {
	 
	int      err      = 0 ; // Код ошибки
	int      pdb      = 0 ; // Адрес памяти, куда будет записан идентификатор   соединения.
	int      pOper    = 0 ; // Адрес памяти, куда будет записан идентификатор   оператора.

	int      pCol     = 0 ; // количество колонок
	long     pStr     = 0 ; // количество строк  hcRECNO
	unsigned cntOp    = 0 ; // Размер считанной информации в байтах, в ф-ции "Получить информацию об операторе".
	unsigned pRecSize = 0 ; // Размер читаемой записи в байтах, в ф-ции "Открытие результатов для чтения" .

	hcSqlParmT Init = { sizeof(Init) }; // Адрес структуры с параметрами инициализации
  
	err = hcSqlInit(&Init)        ; // Инициализация клиентской части  
	err = hcSqlCheckInit()        ; // Проверка завершения инициализации  
	err = hcSqlAllocConnect(&pdb) ;//  Создать соединение
	err = hcSqlConnect(pdb, "tcpip:/localhost:13000", "HTADMIN", "PASSWORD")    ; //Установить связь с СУБД  
	err = hcSqlAllocStmt(pdb, &pOper)  ; // Создать оператор  
	err = hcSqlSetStmtAttr(pOper, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) ; // ф-ция "Изменение параметров оператора" получаем расширенную инф.о полях
	err = hcSqlExecDirect(pOper, "fix all;select * from TAB4;"); // Выполняем SQLзапрос  

	err = hcSqlNumResultCols (pOper, &pCol     )    ; // Получить кол-во колонок результата
	err = hcSqlRowCount      (pOper, &pStr     )    ; // Получить кол-во строк   результата
	err = hcSqlOpenResults   (pOper, &pRecSize )    ; // Открытие результатов для чтения

	hcSqlDstInfoT *infCol = new hcSqlDstInfoT[pCol] ; // Структура "Информация о колонках результата" 

	err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, 0, infCol, pCol * SIZE_HCSQLDSTINFOT, &cntOp) ;// Получить информацию об операторе
	  
	char *bufOut = new char[pRecSize * pStr]; // Адрес буфера для присылаемых записей.

    unsigned cntOut = 0;
	 
	 err = hcSqlReadResults(pOper, 0, bufOut, pRecSize * pStr, &cntOut);// Чтение результатов

    char *p = bufOut;
	 
	for (long i = 0; i < pStr; i++)//идем по строкам
	{
 
		for (int j = 0; j < pCol ; ++j)// идем по колонкам
		{

			switch (infCol[j].type)// в зависимости от типа колонки преобразовываем в соответствующий тип
			{
				case HSCLI_ET_CHAR: // 0 Массив символов длиной не более заданной 
				{
					 std::string s(p, infCol[j].len);
					 std::cout << s.c_str() << "  "; 
				}
				break;

				case HSCLI_ET_ARRA: // 1 Массив байтов заданной длины 
					std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
					break;

				case HSCLI_ET_BYTE: // 2 Элемент - unsigned char (короткое целое)  short
				 std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
				  break;

				case HSCLI_ET_INTR: // 3 Элемент - signed short  
					std::cout << *reinterpret_cast<signed short *>(p) << "  ";
					break;

				case HSCLI_ET_WORD: // 4 Элемент - unsigned short  
				  std::cout << *reinterpret_cast<unsigned short *>(p) << "  ";
					break;

				case HSCLI_ET_DATE: // 5 Дата    - unsigned short  
					 std::cout << *reinterpret_cast<unsigned short *>(p) << "  ";
					break;

				case HSCLI_ET_NMBR: //6  Номер   - 3-х байтовое целое без знака  
									// std::cout << *reinterpret_cast<  *>(p);
					break;

				case HSCLI_ET_LONG: //7 Элемент - long int 
					std::cout << *reinterpret_cast<long int *>(p) << "  ";
					break;

				case  HSCLI_ET_DWRD: // 8 Элемент - unsigned long int  в БД это dword          
					 std::cout << *reinterpret_cast<unsigned long int *>(p) << "  ";
					break;

				case HSCLI_ET_FLOA: //	9  Элемент - float
					std::cout << *reinterpret_cast<float *>(p) << "  ";
					break;

				case HSCLI_ET_CURR: //	10 Деньги (double)  
					std::cout << *reinterpret_cast<double *>(p) << "  ";
					break;

				case HSCLI_ET_DFLT: // 11 Элемент - double  
					std::cout << *reinterpret_cast<double *>(p) << "  ";
					break;

				case HSCLI_ET_QINT: //	12 Элемент - signed __int64 
					std::cout << *reinterpret_cast<signed __int64 *>(p) << "  ";
					break;
				case HSCLI_ET_QWRD: //	13 Элемент - unsigned __int64 
					std::cout << *reinterpret_cast<unsigned __int64 *>(p) << "  ";
					break;
			}

			p += infCol[j].len;

		}

		std::cout << std::endl;
	}

	hcSqlCloseResults(pOper); // Закрытие доступа к результатам
	hcSqlFreeConnect(pdb);    // Освободить соединение
	hcSqlDone();              // Завершение работы
	 
	std::system("pause");
}
  
//	std::cout << "ф-ция  hcSqlGetStmtAttr  с параметром HSCLI_STMT_DST_INFO  = " << err << endl;
//	std::cout << "Размер считанной информации в байтах.     cntOp            = " << cntOp << endl;
//	std::cout << "...............столбик № " << i + 1 << "   ......................................" << endl;
//	std::cout << "Порядковый номер алиаса aliasno = "            << Kol[i].aliasno << endl;
//	std::cout << "Номер поля в таблице fieldno = "               << Kol[i].fieldno << endl;
//	std::cout << "Тип выражения, константа HSCLI_ET_??? type = " << Kol[i].type << endl;
//	std::cout << "Длина поля в байтах len = "                    << Kol[i].len << endl;
//	std::cout << "Смещение поля относительно начала логической записи off = " << Kol[i].off << endl;
//	std::cout << "Имя кодификатора.только для coder(MYCODER, code). coder = " << Kol[i].coder << endl;
//	std::cout << "Имя поля в таблице, fname = "              << Kol[i].fname << endl;
//	std::cout << "Формат выражения CURS_OUTEXPR func = "     << Kol[i].func << endl;
//	std::cout << "Переименование поля, asname = "            << Kol[i].asname << endl;
//	std::cout << "Ключевитость поля,  key = "                << Kol[i].key << endl;
//	std::cout << "Сквозной номер поля в результате resno = " << Kol[i].resno << endl;
//	std::cout << "................................................................." << endl;
//}