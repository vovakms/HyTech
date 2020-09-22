#ifndef _HYTECH_H_
#define _HYTECH_H_
#include "HSCLI.H"
#include <iostream> 

#define SIZE_HCSQLDSTINFOT      128

class HyTech
{
	char** dataRes;
	static const size_t N50 = 50;
	hcSqlDstInfoT *infCol;  // Структура "Информация о колонках результата"

public:

	HyTech();
	~HyTech();

	int ConnectServer(char*   pStrConnect, char * pStrLogin, char * pStrPassword); // Подключение к серверу
	int SqlQuery(char  *pStrSql);                                                  // Выполняем запрос
	int PasStr();                                                                  // Чтение результата
	int CloseSqlQuery();                                                           // Закрываем запрос
	int CloseConnectServer();                                                      // Отключаемся от сервера

private:

	int      pdb = 0;   // Адрес памяти, куда будет записан идентификатор   соединения.
	int      pOper = 0; // Адрес памяти, куда будет записан идентификатор   оператора.
	int      pCol = 0;  // кол-во колонок
	long     pStr = 0;  // кол-во строк  
	unsigned pRecSize = 0; // Размер читаемой записи в байтах, в ф-ции "Открытие результатов для чтения" .
	unsigned cntOp = 0; // Размер считанной информации в байтах, в ф-ции "Получить информацию об операторе".

};
#endif