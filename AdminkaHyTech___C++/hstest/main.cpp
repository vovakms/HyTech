#define HYCFG_WIN32
#include "hscli.h"
#include <iostream>

int main() {
    hcSqlParmT  init = {0};
    init.size = sizeof(hcSqlParmT);
    std::cout << "��������� ������ ����� " << hcSqlInit(nullptr) << std::endl;
}