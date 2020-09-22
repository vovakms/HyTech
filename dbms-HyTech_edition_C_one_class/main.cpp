#define HYCFG_WIN32
#include "HyTech.h"

int main(int argc, char* argv[])
{
	int  err;

	HyTech  hT1;

	err = hT1.ConnectServer("tcpip:/localhost:13000", "HTADMIN", "PASSWORD");
	std::cout << "ConnectServer     err= " << err << std::endl;

	err = hT1.SqlQuery("fix all; select * from TAB4;");
	std::cout << "SqlQuery          err= " << err << std::endl;

	err = hT1.PasStr();
	std::cout << "PasStr            err= " << err << std::endl;
	 
	err = hT1.CloseSqlQuery();
	std::cout << "CloseSqlQuery     err= " << err << std::endl;

	err = hT1.CloseConnectServer();
	std::cout << "CloseConnectServer err= " << err << std::endl;

	std::system("pause");

	return 0;

}