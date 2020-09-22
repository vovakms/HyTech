#ifndef _HYTECH_H_
#define _HYTECH_H_
#include "HSCLI.H"
#include <iostream> 

#define SIZE_HCSQLDSTINFOT      128

class HyTech
{
	char** dataRes;
	static const size_t N50 = 50;
	hcSqlDstInfoT *infCol;  // ��������� "���������� � �������� ����������"

public:

	HyTech();
	~HyTech();

	int ConnectServer(char*   pStrConnect, char * pStrLogin, char * pStrPassword); // ����������� � �������
	int SqlQuery(char  *pStrSql);                                                  // ��������� ������
	int PasStr();                                                                  // ������ ����������
	int CloseSqlQuery();                                                           // ��������� ������
	int CloseConnectServer();                                                      // ����������� �� �������

private:

	int      pdb = 0;   // ����� ������, ���� ����� ������� �������������   ����������.
	int      pOper = 0; // ����� ������, ���� ����� ������� �������������   ���������.
	int      pCol = 0;  // ���-�� �������
	long     pStr = 0;  // ���-�� �����  
	unsigned pRecSize = 0; // ������ �������� ������ � ������, � �-��� "�������� ����������� ��� ������" .
	unsigned cntOp = 0; // ������ ��������� ���������� � ������, � �-��� "�������� ���������� �� ���������".

};
#endif