#define HYCFG_WIN32
#include "HyTech.h"

HyTech::HyTech()
{  
	infCol = NULL;

	
}

HyTech::~HyTech()
{
	if (infCol) delete[] infCol; 
	 
	for (int i = 0; i < pCol; i++) // ����������� ������
		delete[] dataRes[i];

	delete[] dataRes; // ����������� ������
}

int HyTech::ConnectServer(char* pStrConnect, char *  pStrLogin, char*  pStrPassword)/*����������� � �������*/
{
	int err;
	int hdb; // ����� ������, ���� ����� ������� �������������   ����������.

	hcSqlParmT Init = { sizeof(Init) }; // ����� ��������� � ����������� �������������

	if (err = hcSqlInit(&Init) != 0) return err; // ������������� ���������� �����  
	if (err = hcSqlCheckInit()  < 0) return err; // �������� ���������� �������������  
	if (err = hcSqlAllocConnect(&hdb) != 0) return err; // ������� ����������
	pdb = hdb;
	if (err = hcSqlConnect(pdb, pStrConnect, pStrLogin, pStrPassword) != 0) return err; //���������� ����� � ����  

	return err;
}

int HyTech::SqlQuery(char  *pStrSql) /* ��������� SQL-������ */
{
	int err;
	int          hOper;
	unsigned int hcntOp;

	if (err = hcSqlAllocStmt(pdb, &hOper) != 0) return   err; // ������� ��������  
	pOper = hOper;

	if (err = hcSqlSetStmtAttr(pOper, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) != 0) return err;  // �-��� "��������� ���������� ���������" �������� ����������� ���.� �����

	if (err = hcSqlExecDirect    ( pOper, pStrSql   ) != 0 ) return err; // ��������� SQL������  

	if (err = hcSqlNumResultCols ( pOper, &pCol     ) != 0 ) return err; // �������� ���������� ������� ����������

	if (err = hcSqlRowCount      ( pOper, &pStr     ) != 0 ) return err; // �������� ���������� ����� ����������

	if (err = hcSqlOpenResults   ( pOper, &pRecSize ) != 0 ) return err; // �������� ����������� ��� ������

	infCol = new hcSqlDstInfoT[pCol]; // ������� ��������� "���������� � �������� ����������"

	if (err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, 0, infCol, pCol * SIZE_HCSQLDSTINFOT, &hcntOp) != 0)
		return   err;// �������� ���������� �� ���������
    
	dataRes = new char*[N50];                 // ������ ������������ �����  
	for (int i = 0; i < pCol; ++i)            //
		dataRes[i] = new char[infCol[i].len]; // �������� ������ �� ������� ��������

	cntOp = hcntOp;

	return err;
}

int HyTech::PasStr()/* ������ ���������� */
{
	int err;
	
	long position = 0;
	 
	char *bufOut = new char[pRecSize * N50]; // ����� ������ ��� ����������� �������.

	unsigned cntOut = 0;                     // ����� ������ ���������� � �����

	err = hcSqlReadResults(pOper, position, bufOut, pRecSize * N50, &cntOut);// ������ �����������

	char *p = bufOut;                          // ������ ��������� �� �����

	int nomRecBuf = cntOut / pRecSize;         // ����� ������� ���������� � �����

	for (long ib = 1; ib <= nomRecBuf; ib++)   // ���������� ������ ���������� � �����
	{
		
		for (int j = 0; j < pCol; j++)  // ���� �� ��������
		{

			switch (infCol[j].type)// � ����������� �� ����
			{
			case HSCLI_ET_CHAR: {  // 0 ������ �������� ������ �� ����� ��������
					   // dataRes[ib][j] = gcnew String(p, 0, infCol[j].len, System::Text::Encoding::GetEncoding(866)     )  ;// �������
				//dataRes[ib][j] = *reinterpret_cast<char *>(p)  ;
			}
				 break;

			 case HSCLI_ET_ARRA: // 1 ������ ������ �������� �����
				 dataRes[ib][j] = *reinterpret_cast<unsigned char *>(p);
				 break;

			 case HSCLI_ET_BYTE:   // 2 ������� - unsigned char (�������� �����)  short
			     dataRes[ib][j] = *reinterpret_cast<unsigned char *>(p);
			 	 break;

			 case HSCLI_ET_INTR: // 3 ������� - signed short  
			  	 dataRes[ib][j] = *reinterpret_cast<signed short *>(p);
			 	 break;

			 case HSCLI_ET_WORD:   // 4 ������� - unsigned short  
				 dataRes[ib][j] = *reinterpret_cast<unsigned short *>(p);
			 	 break;

			 case HSCLI_ET_DATE: // 5 ����    - unsigned short  
			 	 dataRes[ib][j] = *reinterpret_cast<unsigned short *>(p);
			     break;

			 case HSCLI_ET_NMBR: //6  �����   - 3-� �������� ����� ��� �����  
			 
				 break;

			 case HSCLI_ET_LONG:   //7 ������� - long int
			 	 dataRes[ib][j] = *reinterpret_cast<long int *>(p);
			     break;

			 case  HSCLI_ET_DWRD:   // 8 ������� - unsigned long int  � �� ��� dword          
			 	 dataRes[ib][j] = *reinterpret_cast<unsigned long int *>(p);
			     break;

			 case HSCLI_ET_FLOA:  //    9  ������� - float
			 	 dataRes[ib][j] = *reinterpret_cast<float *>(p);
			 	 break;

			 case HSCLI_ET_CURR:   //    10 ������ (double)  
			     dataRes[ib][j] = *reinterpret_cast<double *>(p);
			   	 break;

			 case HSCLI_ET_DFLT:  // 11 ������� - double  
			 	 dataRes[ib][j] = *reinterpret_cast<double *>(p);
			     break;

			 case HSCLI_ET_QINT: //    12 ������� - signed __int64
				 dataRes[ib][j] = *reinterpret_cast<signed __int64 *>(p);
			     break;

			 case HSCLI_ET_QWRD:  //    13 ������� - unsigned __int64
				 dataRes[ib][j] = *reinterpret_cast<unsigned __int64 *>(p);
			  	 break;
			}

			p += infCol[j].len;// �������� ��������� �� ����� ����, ����� �������� �� ������ ���������� ����

		}

	}
	 
   delete[] bufOut;  // ����������� ������

	return 0;
}

int HyTech::CloseSqlQuery()/* ��������� SQL-������ */
{
	return  hcSqlCloseResults(pOper); // �������� ������� � �����������
}

int HyTech::CloseConnectServer()/* ��������� ���������� ����������� �� ������� */
{
	int err;
	err = hcSqlFreeConnect(pdb);    // ���������� ����������
	err = hcSqlDone();              // ���������� ������

	return err;
}