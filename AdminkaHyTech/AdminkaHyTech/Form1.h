#pragma once

#define HYCFG_WIN32
#include "HSCLI.H"
 
namespace AdminkaHyTech {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
   

 int fun1(int *p){
  int x = 10 ;
   p=&x ;
 return 0 ;
}

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(0, 229);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(264, 157);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(541, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Подключиться  к БД";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Вывод отладочной  информации";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 389);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(679, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->файлToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(679, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 213);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Переменные";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(511, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Функции";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(514, 229);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(153, 157);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(290, 229);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(161, 157);
			this->textBox2->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 411);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Админка HYTECH";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
 
	  hcSqlParmT  init = {0};
    init.size = sizeof(hcSqlParmT);
  
    unsigned option;// Режим 
    int pos;        // Позиция 
	  void *pValue;   // Буфер для значения 
     //    unsigned	size;   // и его размер 
     //    unsigned	cnt;    // сколько байтов записали в буфер 
  
				 //hcHSTMT 	*p ;    // Место для идентификатора оператора 
     //    hcHSTMT	hstmt;  // Идентификатор оператора
     //    p=&hstmt ;
 
     //            //const char	*pSql ; // Адрес SQL-программы, заданной в виде C-строки. Строки SQL-программы внутри C-строки разделяются символами '\n' (перевод строки). 
     //            //const char SqlString  = "fix all;select * from TABLES;" ;// fix all;select * from TABLES;
     //            //pSql=&SqlString;
     //            
				 //int pCol ;// Место для количества колонок  
     //            hcRECNO  pCnt;// Адрес памяти, куда запишется количество строк в результате. 
				 //int kCol ;
				 //// pCol=&kCol;

     //            unsigned *pRecSize;// Адрес слова, в которое запишется размер читаемой записи в байтах. Если размер записи не нужен, то можно задать . 
     //            hcRECNO	gStart=0 ; // С какой записи начинаем читать  
     //            void *pBuf ; // Адрес буфера для присылаемых записей. 
     //            unsigned  wBufSize;//  Размер буфера для результатов. В буфер помещается целое количество записей. Если запись не может войти в буфер целиком, она не присылается.  
     //            unsigned	*cntBuf ;   // Сколько прочитали  

	  hcHDB  *pdb; // Адрес памяти, куда будет записан идентификатор созданного соединения. 
	  hcHDB  hdb ; // Идентификатор  соединения. 
	  pdb = &hdb ; // Берем адрес Идентификатора  соединения
	  
	  textBox1->AppendText("Инициализация клиентской части    = " + hcSqlInit(nullptr)     + "\r\n");     
	  textBox1->AppendText("Проверка завершения инициализации = " + hcSqlCheckInit()       + "\r\n");       
    textBox1->AppendText("Создать соединение                = " + hcSqlAllocConnect(pdb) + "\r\n"); 
			 
	  textBox1->AppendText("Адрес идентификатора соединения *pdb = " +(reinterpret_cast<hcHDB>(pdb)).ToString()+"\r\n" );
    textBox1->AppendText("Идентификатор  соединения        hdb = " +  hdb.ToString()    +"\r\n" );

		//textBox2->Text += "Функция hcSqlConnect  = " + hcSqlConnect(hdb, "tcpip:/localhost:13000","HTADMIN","PASSWORD") + "\r\n" ;//   Установить связь с СУБД
		 		// 
				 //textBox2->Text +="Функция hcSqlGetConnectAttr="+hcSqlGetConnectAttr(hdb,
     //            option,		/* Режим */
     //            pos,		/* Позиция */
     //            pValue,	/* Буфер для значения */
     //            size,		/* и его размер */
     //            &cnt)+"\r\n" ;		/* сколько байтов записали в буфер */
				 //
				 //textBox2->Text += "Режим   = " + option + "\r\n" ;//
     //            textBox2->Text += "Позиция = " + pos + "\r\n" ;//
				 //textBox2->Text += "Буфер для значения   = " + Convert::ToString( pValue )  + "\r\n" ;//
				 //textBox2->Text += "и его размер   = " + size + "\r\n" ;//
				 //textBox2->Text += "сколько байтов записали в буфер   = " +  cnt  + "\r\n" ;//

     //            textBox2->Text += "Функция hcSqlAllocStmt  = " +hcSqlAllocStmt(hdb, p)+ "\r\n" ;//Создать оператор
     //            
     //            hcSqlExecDirect(hstmt,"fix all;select * from TABLES;");// Выполнение SQL-программы в указанном операторе
     //            hcSqlNumResultCols( hstmt, &pCol ); // количества столбиков
			  //   hcSqlRowCount( hstmt,  &pCnt);		// количества строк
     //            textBox2->Text += "Количества колонок = " +  pCol + "\r\n";		 
				 //textBox2->Text += "Количества строк   = " +  pCnt + "\r\n";		 

     //            hcSqlOpenResults(hstmt,  pRecSize);// Открытие результатов для чтения
     //            hcSqlReadResults(hstmt, gStart,   pBuf, wBufSize,   cntBuf);// Чтение результатов    	 
     //            //textBox2->Text += "Чтение результатов   = " +   pBuf   + "\r\n";
 
     //            textBox2->Text += "Идентификатор оператора = " +   hstmt + "\r\n";
     //            textBox2->Text += "Место для идентификатора оператора  = " +   *p + "\r\n";
     //            
				 
			//	 textBox2->Text += "Функция hcSqlFreeStmt   = "+hcSqlFreeStmt(hstmt)+ "\r\n";// Освободить оператор
	   textBox1->Text += "Освободить соединение = "+hcSqlFreeConnect(hdb) + "\r\n" ;//
	   textBox1->Text += "Завершение работы     = "+hcSqlDone() + "\r\n" ; //   

 







    
			 }

  



	};
}

