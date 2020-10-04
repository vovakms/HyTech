#pragma once 

#define HYCFG_WIN32

#include "HyTech.h" 

class CStatement
{
public:

	CStatement(CConnection  & idConnect, const char *strSqlQuery)  ; // Конструктор  

	~CStatement();
	 
	int      GetColumns() ; // Возвращает кол-во колонок
	long     GetRows()    ; // Возвращает кол-во строк
	unsigned GetRowSize() ; // Возвращает размер строки в байтах (сумма всех размеров полей)
	 
	std::vector<char> ReadResults(long start, size_t n) ; // Чтение результата

	const hcSqlDstInfoT  *GetColumnsInfo(int idx) const ; // Заполняем структуру информация о колнках

protected:

	hcHSTMT  idOperator; // Адрес памяти, куда будет записан идентификатор созданного оператора.

	int      sumColumns; // кол-во колонок  результата
	long     sumRows;    // кол-во строк    результата
	unsigned pRecSize;   // Размер читаемой записи в байтах, в ф-ции  "Открытие результатов для чтения" .
	unsigned cntOp;      // Размер считанной информации в байтах, в ф-ции "Получить информацию об операторе".  Если это кол-во разделить на размер значения, то можно получить кол-во считанных значений(для параметров, которые имеют массив значений).

    std::unique_ptr<hcSqlDstInfoT[]> infoColumns; // Структура "Информация о колонках результата"
	 
};

