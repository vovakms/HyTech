#pragma once 

#define HYCFG_WIN32

#include "HyTech.h" 


	class CConnection
	{
	   public:
		CConnection();
		~CConnection();

		void Connect(const char *server, const char *user, const char *password);
		
		void Disconnect() noexcept;
		
		operator hcHDB() const
		{
			return idConnect;
		}

	  protected:
		  hcHDB	 idConnect = 0; // Адрес памяти, куда будет записан идентификатор соединения.  hcHDB pdb;

	};
 
 
