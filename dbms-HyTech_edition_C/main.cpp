#define HYCFG_WIN32

#include "hscli.h"
#include <iostream>
#include <memory>
 
#define	SIZE_HCSQLDSTINFOT		128

void main() {
	 
	int      err      = 0 ; // ��� ������
	int      pdb      = 0 ; // ����� ������, ���� ����� ������� �������������   ����������.
	int      pOper    = 0 ; // ����� ������, ���� ����� ������� �������������   ���������.

	int      pCol     = 0 ; // ���������� �������
	long     pStr     = 0 ; // ���������� �����  hcRECNO
	unsigned cntOp    = 0 ; // ������ ��������� ���������� � ������, � �-��� "�������� ���������� �� ���������".
	unsigned pRecSize = 0 ; // ������ �������� ������ � ������, � �-��� "�������� ����������� ��� ������" .

	hcSqlParmT Init = { sizeof(Init) }; // ����� ��������� � ����������� �������������
  
	err = hcSqlInit(&Init)        ; // ������������� ���������� �����  
	err = hcSqlCheckInit()        ; // �������� ���������� �������������  
	err = hcSqlAllocConnect(&pdb) ;//  ������� ����������
	err = hcSqlConnect(pdb, "tcpip:/localhost:13000", "HTADMIN", "PASSWORD")    ; //���������� ����� � ����  
	err = hcSqlAllocStmt(pdb, &pOper)  ; // ������� ��������  
	err = hcSqlSetStmtAttr(pOper, HSCLI_ATTR_FLD_VERBOSE, (void*)1, 0) ; // �-��� "��������� ���������� ���������" �������� ����������� ���.� �����
	err = hcSqlExecDirect(pOper, "fix all;select * from TAB4;"); // ��������� SQL������  

	err = hcSqlNumResultCols (pOper, &pCol     )    ; // �������� ���-�� ������� ����������
	err = hcSqlRowCount      (pOper, &pStr     )    ; // �������� ���-�� �����   ����������
	err = hcSqlOpenResults   (pOper, &pRecSize )    ; // �������� ����������� ��� ������

	hcSqlDstInfoT *infCol = new hcSqlDstInfoT[pCol] ; // ��������� "���������� � �������� ����������" 

	err = hcSqlGetStmtAttr(pOper, HSCLI_STMT_DST_INFO, 0, infCol, pCol * SIZE_HCSQLDSTINFOT, &cntOp) ;// �������� ���������� �� ���������
	  
	char *bufOut = new char[pRecSize * pStr]; // ����� ������ ��� ����������� �������.

    unsigned cntOut = 0;
	 
	 err = hcSqlReadResults(pOper, 0, bufOut, pRecSize * pStr, &cntOut);// ������ �����������

    char *p = bufOut;
	 
	for (long i = 0; i < pStr; i++)//���� �� �������
	{
 
		for (int j = 0; j < pCol ; ++j)// ���� �� ��������
		{

			switch (infCol[j].type)// � ����������� �� ���� ������� ��������������� � ��������������� ���
			{
				case HSCLI_ET_CHAR: // 0 ������ �������� ������ �� ����� �������� 
				{
					 std::string s(p, infCol[j].len);
					 std::cout << s.c_str() << "  "; 
				}
				break;

				case HSCLI_ET_ARRA: // 1 ������ ������ �������� ����� 
					std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
					break;

				case HSCLI_ET_BYTE: // 2 ������� - unsigned char (�������� �����)  short
				 std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
				  break;

				case HSCLI_ET_INTR: // 3 ������� - signed short  
					std::cout << *reinterpret_cast<signed short *>(p) << "  ";
					break;

				case HSCLI_ET_WORD: // 4 ������� - unsigned short  
				  std::cout << *reinterpret_cast<unsigned short *>(p) << "  ";
					break;

				case HSCLI_ET_DATE: // 5 ����    - unsigned short  
					 std::cout << *reinterpret_cast<unsigned short *>(p) << "  ";
					break;

				case HSCLI_ET_NMBR: //6  �����   - 3-� �������� ����� ��� �����  
									// std::cout << *reinterpret_cast<  *>(p);
					break;

				case HSCLI_ET_LONG: //7 ������� - long int 
					std::cout << *reinterpret_cast<long int *>(p) << "  ";
					break;

				case  HSCLI_ET_DWRD: // 8 ������� - unsigned long int  � �� ��� dword          
					 std::cout << *reinterpret_cast<unsigned long int *>(p) << "  ";
					break;

				case HSCLI_ET_FLOA: //	9  ������� - float
					std::cout << *reinterpret_cast<float *>(p) << "  ";
					break;

				case HSCLI_ET_CURR: //	10 ������ (double)  
					std::cout << *reinterpret_cast<double *>(p) << "  ";
					break;

				case HSCLI_ET_DFLT: // 11 ������� - double  
					std::cout << *reinterpret_cast<double *>(p) << "  ";
					break;

				case HSCLI_ET_QINT: //	12 ������� - signed __int64 
					std::cout << *reinterpret_cast<signed __int64 *>(p) << "  ";
					break;
				case HSCLI_ET_QWRD: //	13 ������� - unsigned __int64 
					std::cout << *reinterpret_cast<unsigned __int64 *>(p) << "  ";
					break;
			}

			p += infCol[j].len;

		}

		std::cout << std::endl;
	}

	hcSqlCloseResults(pOper); // �������� ������� � �����������
	hcSqlFreeConnect(pdb);    // ���������� ����������
	hcSqlDone();              // ���������� ������
	 
	std::system("pause");
}
  
//	std::cout << "�-���  hcSqlGetStmtAttr  � ���������� HSCLI_STMT_DST_INFO  = " << err << endl;
//	std::cout << "������ ��������� ���������� � ������.     cntOp            = " << cntOp << endl;
//	std::cout << "...............������� � " << i + 1 << "   ......................................" << endl;
//	std::cout << "���������� ����� ������ aliasno = "            << Kol[i].aliasno << endl;
//	std::cout << "����� ���� � ������� fieldno = "               << Kol[i].fieldno << endl;
//	std::cout << "��� ���������, ��������� HSCLI_ET_??? type = " << Kol[i].type << endl;
//	std::cout << "����� ���� � ������ len = "                    << Kol[i].len << endl;
//	std::cout << "�������� ���� ������������ ������ ���������� ������ off = " << Kol[i].off << endl;
//	std::cout << "��� ������������.������ ��� coder(MYCODER, code). coder = " << Kol[i].coder << endl;
//	std::cout << "��� ���� � �������, fname = "              << Kol[i].fname << endl;
//	std::cout << "������ ��������� CURS_OUTEXPR func = "     << Kol[i].func << endl;
//	std::cout << "�������������� ����, asname = "            << Kol[i].asname << endl;
//	std::cout << "������������ ����,  key = "                << Kol[i].key << endl;
//	std::cout << "�������� ����� ���� � ���������� resno = " << Kol[i].resno << endl;
//	std::cout << "................................................................." << endl;
//}