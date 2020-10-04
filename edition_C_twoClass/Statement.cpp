#define HYCFG_WIN32

#include "HyTech.h" 
 

CStatement::CStatement(CConnection  & idConnect, const char *strSqlQuery) : idOperator(0)
                                                                           , sumColumns(0)
                                                                           , sumRows(0)
                                                                           , pRecSize(0)
                                                                             // Конструктор 
{
	if (hcSqlAllocStmt(idConnect, &idOperator) != 0) // ф-ция hscli.dll "Создать оператор"
		throw std::runtime_error("hcSqlAllocStmt     failed");

	if (hcSqlSetStmtAttr(idOperator, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) != 0) // ф-ция hscli.dll "Изменение параметров оператора" получаем расширенную инф.о полях
		throw std::runtime_error("hcSqlSetStmtAttr     failed");
 
	if (hcSqlExecDirect(idOperator, strSqlQuery) != 0)           //ф-ция hscli.dll Выполняем SQLзапрос
		throw std::runtime_error("hcSqlExecDirect     failed");

	if (hcSqlNumResultCols(idOperator, &sumColumns) != 0)       //ф-ция hscli.dll Получить кол-во колонок результата
		throw std::runtime_error("hcSqlNumResultCols   failed");

	if (hcSqlRowCount(idOperator, &sumRows) != 0)               //ф-ция hscli.dll Получить кол-во строк   результата
		throw std::runtime_error("hcSqlRowCount        failed");

	if (hcSqlOpenResults(idOperator, &pRecSize) != 0)         //ф-ция hscli.dll Открытие результатов для чтения
		throw std::runtime_error("hcSqlOpenResults     failed");
 
	infoColumns.reset(new hcSqlDstInfoT[sumColumns]); // Структура "Информация о колонках результата"
	 
	if (hcSqlGetStmtAttr(idOperator, HSCLI_STMT_DST_INFO, 0,  infoColumns.get() , sumColumns * SIZE_HCSQLDSTINFOT, &cntOp) != 0)
		throw std::runtime_error("hcSqlGetStmtAttr      failed");                 // Получить информацию об операторе

	//std::cout << infoColumns[0].fname << std::endl;

}

CStatement::~CStatement()
{
	hcSqlCloseResults(idOperator) ; // ф-ция hscli.dll "Закрытие доступа к результатам"
	hcSqlFreeStmt(idOperator)     ; // ф-ция hscli.dll "Закрыть оператор"
}

int      CStatement::GetColumns() // Возвращает кол-во колонок 
{
	return sumColumns;
}

long     CStatement::GetRows() // Возвращает кол-во строк
{
	return  sumRows;
}

unsigned CStatement::GetRowSize() // Возвращает размер строки в байтах (сумма всех размеров полей)
{
	return pRecSize;
}
 
std::vector<char> CStatement::ReadResults(long start, size_t n) // Чтение результата
{
	unsigned 	cnt;

	if (!sumRows || !pRecSize || start > sumRows || !n) // если кол-во строк или размер записи или стртовая позиция чтения больше читаемых байт  равно нулю
		return std::vector<char>();

	std::vector<char>   masResult(n *pRecSize); // делаем буфер под прислнный результат 
	 
	hcSqlReadResults(idOperator, start,  masResult.data(), masResult.size(), &n);// ф-ция hscli.dll "Чтение результатов"
	
	if (  n != masResult.size()  ) // если кол-во считанных байтов не равно размеру выделенного буфера
		          masResult.resize(n);// то меняем размер буфера на кол-во считанных байтов

	  return masResult; //  
}
 
const hcSqlDstInfoT *CStatement::GetColumnsInfo(int idx) const // Заполняем структуру информация о колнках
{
	return idx < sumColumns ? infoColumns.get() + idx : nullptr;
}
  