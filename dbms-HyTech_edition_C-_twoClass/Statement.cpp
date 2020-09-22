#define HYCFG_WIN32

#include "HyTech.h" 
 

CStatement::CStatement(CConnection  & idConnect, const char *strSqlQuery) : idOperator(0)
                                                                           , sumColumns(0)
                                                                           , sumRows(0)
                                                                           , pRecSize(0)
                                                                             // ����������� 
{
	if (hcSqlAllocStmt(idConnect, &idOperator) != 0) // �-��� hscli.dll "������� ��������"
		throw std::runtime_error("hcSqlAllocStmt     failed");

	if (hcSqlSetStmtAttr(idOperator, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) != 0) // �-��� hscli.dll "��������� ���������� ���������" �������� ����������� ���.� �����
		throw std::runtime_error("hcSqlSetStmtAttr     failed");
 
	if (hcSqlExecDirect(idOperator, strSqlQuery) != 0)           //�-��� hscli.dll ��������� SQL������
		throw std::runtime_error("hcSqlExecDirect     failed");

	if (hcSqlNumResultCols(idOperator, &sumColumns) != 0)       //�-��� hscli.dll �������� ���-�� ������� ����������
		throw std::runtime_error("hcSqlNumResultCols   failed");

	if (hcSqlRowCount(idOperator, &sumRows) != 0)               //�-��� hscli.dll �������� ���-�� �����   ����������
		throw std::runtime_error("hcSqlRowCount        failed");

	if (hcSqlOpenResults(idOperator, &pRecSize) != 0)         //�-��� hscli.dll �������� ����������� ��� ������
		throw std::runtime_error("hcSqlOpenResults     failed");
 
	infoColumns.reset(new hcSqlDstInfoT[sumColumns]); // ��������� "���������� � �������� ����������"
	 
	if (hcSqlGetStmtAttr(idOperator, HSCLI_STMT_DST_INFO, 0,  infoColumns.get() , sumColumns * SIZE_HCSQLDSTINFOT, &cntOp) != 0)
		throw std::runtime_error("hcSqlGetStmtAttr      failed");                 // �������� ���������� �� ���������

	//std::cout << infoColumns[0].fname << std::endl;

}

CStatement::~CStatement()
{
	hcSqlCloseResults(idOperator) ; // �-��� hscli.dll "�������� ������� � �����������"
	hcSqlFreeStmt(idOperator)     ; // �-��� hscli.dll "������� ��������"
}

int      CStatement::GetColumns() // ���������� ���-�� ������� 
{
	return sumColumns;
}

long     CStatement::GetRows() // ���������� ���-�� �����
{
	return  sumRows;
}

unsigned CStatement::GetRowSize() // ���������� ������ ������ � ������ (����� ���� �������� �����)
{
	return pRecSize;
}
 
std::vector<char> CStatement::ReadResults(long start, size_t n) // ������ ����������
{
	unsigned 	cnt;

	if (!sumRows || !pRecSize || start > sumRows || !n) // ���� ���-�� ����� ��� ������ ������ ��� �������� ������� ������ ������ �������� ����  ����� ����
		return std::vector<char>();

	std::vector<char>   masResult(n *pRecSize); // ������ ����� ��� ��������� ��������� 
	 
	hcSqlReadResults(idOperator, start,  masResult.data(), masResult.size(), &n);// �-��� hscli.dll "������ �����������"
	
	if (  n != masResult.size()  ) // ���� ���-�� ��������� ������ �� ����� ������� ����������� ������
		          masResult.resize(n);// �� ������ ������ ������ �� ���-�� ��������� ������

	  return masResult; //  
}
 
const hcSqlDstInfoT *CStatement::GetColumnsInfo(int idx) const // ��������� ��������� ���������� � �������
{
	return idx < sumColumns ? infoColumns.get() + idx : nullptr;
}
  