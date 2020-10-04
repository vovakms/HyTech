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
  setlocale(LC_ALL,"RUS"); // подключаем русскую локаль
  HMODULE hDll;            // дескриптор DLL-библиотеки
 
#define _DYNAMIC_  <- закомментировать, если lib
#ifdef _DYNAMIC_  // если грузим hscli.dll сами    
 
  int (__stdcall *htInit)(hcSqlParmT*);//Указатель на hcSqlInit(hcSqlParmT *arg) // функция "Инициализация клиентской части"
 
  hDll = LoadLibrary(_T("hscli.dll"));// Загружаем нашу DLL-ку
  if(!hDll)
      cout << "DDL не загружена \n";
  else
      cout << "ОК DLL-ка загрузилась \n";
 
  htInit = (int (__stdcall *)(hcSqlParmT*))GetProcAddress(hDll, "hcSqlInit");  // Настраиваем адрес функции
 
  if(!htInit)
      cout << _T("Хрен вам а не функция \n");
  else
      cout << "Адрес функции:  " << htInit  << "\n" ;
 
  hcERR err;
 
  hcSqlParmT Init = { sizeof(Init) };
  if((err = htInit(&Init)) != 0)
     cout << "код ошибки = " << GetLastError();
 
  if(!FreeLibrary(hDll)) // Отключаем библиотеку
  {
    cout << "Ошибка выгрузки библиотеки из памяти \n";
    cout << "код ошибки = " << GetLastError();
  }
  else{
    cout <<  "DLL выгрузили из памяти \n"  ;
  }
 
#else   // если к проекту подключена hscli.lib
  hcERR err;
 
  hcSqlParmT Init = { sizeof(Init) };
  if((err = hcSqlInit(&Init)) != 0)
     cout << "код ошибки = " << GetLastError();
  else
     cout << "ok";
#endif
  system("pause");// Пауза
}