#pragma once 

#define HYCFG_WIN32

#include "HyTech.h" 

class CStatement
{
public:

	CStatement(CConnection  & idConnect, const char *strSqlQuery)  ; // �����������  

	~CStatement();
	 
	int      GetColumns() ; // ���������� ���-�� �������
	long     GetRows()    ; // ���������� ���-�� �����
	unsigned GetRowSize() ; // ���������� ������ ������ � ������ (����� ���� �������� �����)
	 
	std::vector<char> ReadResults(long start, size_t n) ; // ������ ����������

	const hcSqlDstInfoT  *GetColumnsInfo(int idx) const ; // ��������� ��������� ���������� � �������

protected:

	hcHSTMT  idOperator; // ����� ������, ���� ����� ������� ������������� ���������� ���������.

	int      sumColumns; // ���-�� �������  ����������
	long     sumRows;    // ���-�� �����    ����������
	unsigned pRecSize;   // ������ �������� ������ � ������, � �-���  "�������� ����������� ��� ������" .
	unsigned cntOp;      // ������ ��������� ���������� � ������, � �-��� "�������� ���������� �� ���������".  ���� ��� ���-�� ��������� �� ������ ��������, �� ����� �������� ���-�� ��������� ��������(��� ����������, ������� ����� ������ ��������).

    std::unique_ptr<hcSqlDstInfoT[]> infoColumns; // ��������� "���������� � �������� ����������"
	 
};

