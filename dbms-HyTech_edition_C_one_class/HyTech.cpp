#define HYCFG_WIN32
#include "HyTech.h"

HyTech::HyTech()
{  
	infCol = NULL;

	
}

HyTech::~HyTech()
{
	if (infCol) delete[] infCol; 
	 
	for (int i = 0; i < pCol; i++) // освобождаем память
		delete[] dataRes[i];

	delete[] dataRes; // освобождаем память
}

int HyTech::ConnectServer(char* pStrConnect, char *  pStrLogin, char*  pStrPassword)/*Подключение к серверу*/
{
	int err;
	int hdb; // Адрес памяти, куда будет записан идентификатор   соединения.

	hcSqlParmT Init = { sizeof(Init) }; // Адрес структуры с параметрами инициализации

	if (err = hcSqlInit(&Init) != 0) return err; // Инициализация клиентской части  
	if (err = hcSqlCheckInit()  < 0) return err; // Проверка завершения инициализации  
	if (err = hcSqlAllocConnect(&hdb) != 0) return err; // Создать соединение
	pdb = hdb;
	if (err = hcSqlConnect(pdb, pStrConnect, pStrLogin, pStrPassword) != 0) return err; //Установить связь с СУБД  

	return err;
}

int HyTech::SqlQuery(char  *pStrSql) /* Выполняем SQL-запрос */
{
	int err;
	int          hOper;
	unsigned int hcntOp;

	if (err = hcSqlAllocStmt(pdb, &hOper) != 0) return   err; // Создать оператор  
	pOper = hOper;

	if (err = hcSqlSetStmtAttr(pOper, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) != 0) return err;  // ф-ция "Изменение параметров оператора" получаем расширенную инф.о полях

	if (err = hcSqlExecDirect    ( pOper, pStrSql   ) != 0 ) return err; // Выполняем SQLзапрос  

	if (err = hcSqlNumResultCols ( pOper, &pCol     ) != 0 ) return err; // Получить количество колонок результата

	if (err = hcSqlRowCount      ( pOper, &pStr     ) != 0 ) return err; // Получить количество строк результата

	if (err = hcSqlOpenResults   ( pOper, &pRecSize ) != 0 ) return err; // Открытие результатов для чтения

	infCol = new hcSqlDstInfoT[pCol]; // создаем структуру "Информация о колонках результата"

	if (err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, 0, infCol, pCol * SIZE_HCSQLDSTINFOT, &hcntOp) != 0)
		return   err;// Получить информацию об операторе
    
	dataRes = new char*[N50];                 // Делаем динамический буфер  
	for (int i = 0; i < pCol; ++i)            //
		dataRes[i] = new char[infCol[i].len]; // выделяем памяти по размеру столбика

	cntOp = hcntOp;

	return err;
}

int HyTech::PasStr()/* Чтение результата */
{
	int err;
	
	long position = 0;
	 
	char *bufOut = new char[pRecSize * N50]; // Адрес буфера для присылаемых записей.

	unsigned cntOut = 0;                     // число байтов помещенных в буфер

	err = hcSqlReadResults(pOper, position, bufOut, pRecSize * N50, &cntOut);// Чтение результатов

	char *p = bufOut;                          // делаем указатель на буфер

	int nomRecBuf = cntOut / pRecSize;         // число записей записанных в буфер

	for (long ib = 1; ib <= nomRecBuf; ib++)   // перебираем строки записанные в буфер
	{
		
		for (int j = 0; j < pCol; j++)  // идем по колонкам
		{

			switch (infCol[j].type)// в зависимости от типа
			{
			case HSCLI_ET_CHAR: {  // 0 Массив символов длиной не более заданной
					   // dataRes[ib][j] = gcnew String(p, 0, infCol[j].len, System::Text::Encoding::GetEncoding(866)     )  ;// отладка
				//dataRes[ib][j] = *reinterpret_cast<char *>(p)  ;
			}
				 break;

			 case HSCLI_ET_ARRA: // 1 Массив байтов заданной длины
				 dataRes[ib][j] = *reinterpret_cast<unsigned char *>(p);
				 break;

			 case HSCLI_ET_BYTE:   // 2 Элемент - unsigned char (короткое целое)  short
			     dataRes[ib][j] = *reinterpret_cast<unsigned char *>(p);
			 	 break;

			 case HSCLI_ET_INTR: // 3 Элемент - signed short  
			  	 dataRes[ib][j] = *reinterpret_cast<signed short *>(p);
			 	 break;

			 case HSCLI_ET_WORD:   // 4 Элемент - unsigned short  
				 dataRes[ib][j] = *reinterpret_cast<unsigned short *>(p);
			 	 break;

			 case HSCLI_ET_DATE: // 5 Дата    - unsigned short  
			 	 dataRes[ib][j] = *reinterpret_cast<unsigned short *>(p);
			     break;

			 case HSCLI_ET_NMBR: //6  Номер   - 3-х байтовое целое без знака  
			 
				 break;

			 case HSCLI_ET_LONG:   //7 Элемент - long int
			 	 dataRes[ib][j] = *reinterpret_cast<long int *>(p);
			     break;

			 case  HSCLI_ET_DWRD:   // 8 Элемент - unsigned long int  в БД это dword          
			 	 dataRes[ib][j] = *reinterpret_cast<unsigned long int *>(p);
			     break;

			 case HSCLI_ET_FLOA:  //    9  Элемент - float
			 	 dataRes[ib][j] = *reinterpret_cast<float *>(p);
			 	 break;

			 case HSCLI_ET_CURR:   //    10 Деньги (double)  
			     dataRes[ib][j] = *reinterpret_cast<double *>(p);
			   	 break;

			 case HSCLI_ET_DFLT:  // 11 Элемент - double  
			 	 dataRes[ib][j] = *reinterpret_cast<double *>(p);
			     break;

			 case HSCLI_ET_QINT: //    12 Элемент - signed __int64
				 dataRes[ib][j] = *reinterpret_cast<signed __int64 *>(p);
			     break;

			 case HSCLI_ET_QWRD:  //    13 Элемент - unsigned __int64
				 dataRes[ib][j] = *reinterpret_cast<unsigned __int64 *>(p);
			  	 break;
			}

			p += infCol[j].len;// сдвигаем указатель на длину поля, чтобы указывал на начало следующего поля

		}

	}
	 
   delete[] bufOut;  // освобождаем память

	return 0;
}

int HyTech::CloseSqlQuery()/* Закрываем SQL-запрос */
{
	return  hcSqlCloseResults(pOper); // Закрытие доступа к результатам
}

int HyTech::CloseConnectServer()/* Закрываем соединение отключаемся от сервера */
{
	int err;
	err = hcSqlFreeConnect(pdb);    // Освободить соединение
	err = hcSqlDone();              // Завершение работы

	return err;
}