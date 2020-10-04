#define HYCFG_WIN32

#include "HyTech.h" 
 
	CConnection::CConnection()
	{
		hcSqlParmT Init = { sizeof(Init) }; // Адрес структуры с параметрами инициализации
		                  
		if ( hcSqlInit(&Init) != 0 ) // Инициализация клиентской части
			throw std::runtime_error("hcSqlInit failed");

		if (hcSqlCheckInit() != 0)   // Проверка завершения инициализации
			throw std::runtime_error("hcSqlCheckInit failed");
		 
		if (hcSqlAllocConnect(&idConnect) != 0) //  Создать соединение
			throw std::runtime_error("hcSqlAllocConnect failed");
	}

	CConnection::~CConnection()
	{
		Disconnect();
		hcSqlFreeConnect(idConnect); // Освободить соединение
	    hcSqlDone();                 // Завершение работы
	}

	void CConnection::Connect(const char * server, const char * user, const char * password)
	{
		const auto err = hcSqlConnect(idConnect, server, user, password);
		if (err != 0)
			throw std::runtime_error("hcSqlConnect failed");
	}

	void CConnection::Disconnect() noexcept
	{                               // Разорвать связь с сервером БД 
		hcSqlDisconnect(idConnect); // Рекомендуется полностью освободить все операторы,
	}                               // выделенные для idConnect указанного соединения.    
 
 
	
	