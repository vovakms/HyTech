#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#define HYCFG_WIN32
#include "HSCLI.H"
 
using namespace std;
 
void main()
{
  setlocale(LC_ALL,"RUS"); // ���������� ������� ������
  HMODULE hDll;            // ���������� DLL-����������
 
#define _DYNAMIC_  <- ����������������, ���� lib
#ifdef _DYNAMIC_  // ���� ������ hscli.dll ����    
 
  int (__stdcall *htInit)(hcSqlParmT*);//��������� �� hcSqlInit(hcSqlParmT *arg) // ������� "������������� ���������� �����"
 
  hDll = LoadLibrary(_T("hscli.dll"));// ��������� ���� DLL-��
  if(!hDll)
      cout << "DDL �� ��������� \n";
  else
      cout << "�� DLL-�� ����������� \n";
 
  htInit = (int (__stdcall *)(hcSqlParmT*))GetProcAddress(hDll, "hcSqlInit");  // ����������� ����� �������
 
  if(!htInit)
      cout << _T("���� ��� � �� ������� \n");
  else
      cout << "����� �������:  " << htInit  << "\n" ;
 
  hcERR err;
 
  hcSqlParmT Init = { sizeof(Init) };
  if((err = htInit(&Init)) != 0)
     cout << "��� ������ = " << GetLastError();
 
  if(!FreeLibrary(hDll)) // ��������� ����������
  {
    cout << "������ �������� ���������� �� ������ \n";
    cout << "��� ������ = " << GetLastError();
  }
  else{
    cout <<  "DLL ��������� �� ������ \n"  ;
  }
 
#else   // ���� � ������� ���������� hscli.lib
  hcERR err;
 
  hcSqlParmT Init = { sizeof(Init) };
  if((err = hcSqlInit(&Init)) != 0)
     cout << "��� ������ = " << GetLastError();
  else
     cout << "ok";
#endif
  system("pause");// �����
}