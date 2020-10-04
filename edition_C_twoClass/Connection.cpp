#define HYCFG_WIN32

#include "HyTech.h" 
 
	CConnection::CConnection()
	{
		hcSqlParmT Init = { sizeof(Init) }; // ����� ��������� � ����������� �������������
		                  
		if ( hcSqlInit(&Init) != 0 ) // ������������� ���������� �����
			throw std::runtime_error("hcSqlInit failed");

		if (hcSqlCheckInit() != 0)   // �������� ���������� �������������
			throw std::runtime_error("hcSqlCheckInit failed");
		 
		if (hcSqlAllocConnect(&idConnect) != 0) //  ������� ����������
			throw std::runtime_error("hcSqlAllocConnect failed");
	}

	CConnection::~CConnection()
	{
		Disconnect();
		hcSqlFreeConnect(idConnect); // ���������� ����������
	    hcSqlDone();                 // ���������� ������
	}

	void CConnection::Connect(const char * server, const char * user, const char * password)
	{
		const auto err = hcSqlConnect(idConnect, server, user, password);
		if (err != 0)
			throw std::runtime_error("hcSqlConnect failed");
	}

	void CConnection::Disconnect() noexcept
	{                               // ��������� ����� � �������� �� 
		hcSqlDisconnect(idConnect); // ������������� ��������� ���������� ��� ���������,
	}                               // ���������� ��� idConnect ���������� ����������.    
 
 
	
	