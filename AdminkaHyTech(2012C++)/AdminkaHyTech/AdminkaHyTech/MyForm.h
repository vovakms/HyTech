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

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  видToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сервисToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  создатьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  открытьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  сохранитьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  печатьToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripButton^  вырезатьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  копироватьToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  вставкаToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  справкаToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  свойствоToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  параметрыToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сервисToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->свойствоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->параметрыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->создатьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->открытьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->сохранитьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->печатьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->вырезатьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->копироватьToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->вставкаToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->справкаToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 533);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(974, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->aToolStripMenuItem, 
				this->видToolStripMenuItem, this->сервисToolStripMenuItem, this->справкаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(974, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aToolStripMenuItem
			// 
			this->aToolStripMenuItem->Name = L"aToolStripMenuItem";
			this->aToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->aToolStripMenuItem->Text = L"Файл";
			// 
			// видToolStripMenuItem
			// 
			this->видToolStripMenuItem->Name = L"видToolStripMenuItem";
			this->видToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->видToolStripMenuItem->Text = L"Вид";
			// 
			// сервисToolStripMenuItem
			// 
			this->сервисToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripSeparator2, 
				this->свойствоToolStripMenuItem, this->параметрыToolStripMenuItem});
			this->сервисToolStripMenuItem->Name = L"сервисToolStripMenuItem";
			this->сервисToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->сервисToolStripMenuItem->Text = L"Сервис";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(128, 6);
			// 
			// свойствоToolStripMenuItem
			// 
			this->свойствоToolStripMenuItem->Name = L"свойствоToolStripMenuItem";
			this->свойствоToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->свойствоToolStripMenuItem->Text = L"Свойство";
			// 
			// параметрыToolStripMenuItem
			// 
			this->параметрыToolStripMenuItem->Name = L"параметрыToolStripMenuItem";
			this->параметрыToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->параметрыToolStripMenuItem->Text = L"Параметры";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->создатьToolStripButton, 
				this->открытьToolStripButton, this->сохранитьToolStripButton, this->печатьToolStripButton, this->toolStripSeparator, this->вырезатьToolStripButton, 
				this->копироватьToolStripButton, this->вставкаToolStripButton, this->toolStripSeparator1, this->справкаToolStripButton, this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(974, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// создатьToolStripButton
			// 
			this->создатьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->создатьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"создатьToolStripButton.Image")));
			this->создатьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->создатьToolStripButton->Name = L"создатьToolStripButton";
			this->создатьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->создатьToolStripButton->Text = L"&Создать";
			// 
			// открытьToolStripButton
			// 
			this->открытьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->открытьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"открытьToolStripButton.Image")));
			this->открытьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->открытьToolStripButton->Name = L"открытьToolStripButton";
			this->открытьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->открытьToolStripButton->Text = L"&Открыть";
			// 
			// сохранитьToolStripButton
			// 
			this->сохранитьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->сохранитьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"сохранитьToolStripButton.Image")));
			this->сохранитьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->сохранитьToolStripButton->Name = L"сохранитьToolStripButton";
			this->сохранитьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->сохранитьToolStripButton->Text = L"&Сохранить";
			// 
			// печатьToolStripButton
			// 
			this->печатьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->печатьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"печатьToolStripButton.Image")));
			this->печатьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->печатьToolStripButton->Name = L"печатьToolStripButton";
			this->печатьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->печатьToolStripButton->Text = L"&Печать";
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(6, 25);
			// 
			// вырезатьToolStripButton
			// 
			this->вырезатьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->вырезатьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"вырезатьToolStripButton.Image")));
			this->вырезатьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->вырезатьToolStripButton->Name = L"вырезатьToolStripButton";
			this->вырезатьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->вырезатьToolStripButton->Text = L"В&ырезать";
			// 
			// копироватьToolStripButton
			// 
			this->копироватьToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->копироватьToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"копироватьToolStripButton.Image")));
			this->копироватьToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->копироватьToolStripButton->Name = L"копироватьToolStripButton";
			this->копироватьToolStripButton->Size = System::Drawing::Size(23, 22);
			this->копироватьToolStripButton->Text = L"&Копировать";
			// 
			// вставкаToolStripButton
			// 
			this->вставкаToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->вставкаToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"вставкаToolStripButton.Image")));
			this->вставкаToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->вставкаToolStripButton->Name = L"вставкаToolStripButton";
			this->вставкаToolStripButton->Size = System::Drawing::Size(23, 22);
			this->вставкаToolStripButton->Text = L"Вст&авка";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// справкаToolStripButton
			// 
			this->справкаToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->справкаToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"справкаToolStripButton.Image")));
			this->справкаToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->справкаToolStripButton->Name = L"справкаToolStripButton";
			this->справкаToolStripButton->Size = System::Drawing::Size(23, 22);
			this->справкаToolStripButton->Text = L"Спр&авка";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"toolStripButton3";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(719, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 54);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Подключиться к БД";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(559, 320);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(403, 199);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(556, 304);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Вывод";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Функции";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 304);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Переменные";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 76);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(421, 199);
			this->textBox2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 320);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox3->Size = System::Drawing::Size(421, 199);
			this->textBox3->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(974, 555);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Админка HYTECH";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

   hcSqlParmT  init = {0};
   init.size = sizeof(hcSqlParmT);
  
   unsigned option;// Режим 
   int pos;        // Позиция 
	 void *pValue;   // Адрес буфера памяти, в которую будут записаны значение (значения) параметра соединения. 
   unsigned	size;  // и его размер 
   unsigned	cnt;   // сколько байтов записали в буфер 
  
	 hcHSTMT 	*p ;    // Адрес памяти, куда будет записан идентификатор созданного оператора.   
   hcHSTMT	hstmt;  // Идентификатор оператора
   p=&hstmt ;
 
     //            //const char	*pSql ; // Адрес SQL-программы, заданной в виде C-строки. Строки SQL-программы внутри C-строки разделяются символами '\n' (перевод строки). 
     //            //const char SqlString  = "fix all;select * from TABLES;" ;// fix all;select * from TABLES;
     //            //pSql=&SqlString;
                 
   int *pCol ;     // Адрес целого цисла, куда будет записано количество колонок в результате.   
   int kolCol ;    // Количество колонок в результате
	 pCol=&kolCol;
	 
	 hcRECNO  *pCnt; // Адрес памяти, куда запишется количество строк в результате. 
   hcRECNO kolCnt ;// Количество строк в результате
   pCnt=&kolCnt ;
   
   unsigned *pRecSize; // Адрес слова, в которое запишется размер читаемой записи в байтах. Если размер записи не нужен, то можно задать . 
   unsigned rSize;     // размер читаемой записи в байтах
	 pRecSize=&rSize;

	 hcRECNO	gStart=0 ; // С какой записи начинаем читать  
   void     *pBuf    ; // Адрес буфера для присылаемых записей.
   unsigned Buf ;
	 pBuf=&Buf ;
   unsigned wBufSize ; // Размер буфера для результатов. В буфер помещается целое количество записей. Если запись не может войти в буфер целиком, она не присылается.  
   unsigned	*cntBuf  ; // Адрес, куда функция запишет количество байтов данных, помещённых в буфер пользователя. Если это количество разделить на длину записи, то получим количество считанных записей. Неполные записи не присылаются.  
	 unsigned kolBd    ; // количество байтов данных помещённых в буфер
	 cntBuf=&kolBd;

	 hcHDB *pdb ; // Адрес памяти, куда будет записан идентификатор соединения. 
	 hcHDB  hdb ; // Идентификатор  соединения. 
	 pdb = &hdb ; // Берем адрес Идентификатора  соединения
	  
		textBox3->AppendText("Идентификатор  соединения(до инициализации) hdb = " +  hdb.ToString()    +"\r\n" );

	  textBox2->AppendText("Инициализация клиентской части    = " + hcSqlInit(nullptr)     + "\r\n");     
	  textBox2->AppendText("Проверка завершения инициализации = " + hcSqlCheckInit()       + "\r\n");       
    textBox2->AppendText("Создать соединение                = " + hcSqlAllocConnect(pdb) + "\r\n"); 
			 
	  textBox3->AppendText("Адрес идентификатора соединения *pdb = " +(reinterpret_cast<hcHDB>(pdb)).ToString()+"\r\n" );
    textBox3->AppendText("Идентификатор  соединения        hdb = " +  hdb.ToString()    +"\r\n" );

    textBox2->AppendText("Установить связь с СУБД  = " + hcSqlConnect(hdb, "tcpip:/10.27.11.131:1000","HTADMIN","PASSWORD") + "\r\n") ;   
                                                                                      // Режим , Позиция, Буфер для значения, и его размер, сколько байтов записали в буфер
    textBox2->AppendText("Получить информацию об соединении="+hcSqlGetConnectAttr(hdb,   option, pos,   	pValue,             size,             &cnt)+"\r\n" );		 
    textBox3->AppendText("Режим   = " + option + "\r\n" ) ;//
    textBox3->AppendText("Позиция = " + pos    + "\r\n") ;//
    textBox3->AppendText("Адрес для ""БуфераПодЗначения"" = " + (reinterpret_cast<int>(pValue)).ToString()   + "\r\n") ;//
	  textBox3->AppendText("Размер ""БуфераПодЗначения""    = " + size + "\r\n" );//
	  textBox3->AppendText("Сколько байтов записали в ""БуферПодЗначения""= " +  cnt  + "\r\n" ) ;//

    textBox2->AppendText("Создать оператор  = " +hcSqlAllocStmt(hdb, p) + "\r\n" ) ;//
    textBox3->AppendText("Адрес идентификатора оператора = " +(reinterpret_cast<hcHSTMT>(p)).ToString()+ "\r\n" ) ; 
    textBox3->AppendText("Идентификатор оператора        = " +  hstmt   + "\r\n" ) ;

    hcSqlExecDirect(hstmt,"fix all;select * from TABLES;");// Выполнение SQL-программы в указанном операторе
    hcSqlNumResultCols( hstmt, pCol ); // количество столбиков
    hcSqlRowCount( hstmt,  pCnt);		   // количество строк
    textBox1->AppendText("Количества колонок = " +  kolCol + "\r\n");		 
	  textBox1->AppendText("Количества строк   = " +  kolCnt + "\r\n");		 
 
    textBox2->AppendText("Открытие результатов для чтения   = " + hcSqlOpenResults(hstmt,  pRecSize) + "\r\n" ) ; 
    textBox3->AppendText("Адрес слова, в которое запишется размер читаемой записи в байтах. = "+(reinterpret_cast<unsigned>(pRecSize)).ToString()+"\r\n"); 
		    	 
    textBox2->AppendText("Чтение результатов                     = " + hcSqlReadResults(hstmt, gStart, pBuf, wBufSize, cntBuf) + "\r\n" ) ;  
   // textBox3->AppendText("Адрес буфера для присылаемых записей.  = " +   pBuf    + "\r\n");
    textBox3->AppendText("Размер буфера для результатов          = " +   wBufSize  + "\r\n");
    textBox3->AppendText("Адрес, куда функция запишет количество байтов данных , помещённых в буфер пользователя.  = " + cnt   + "\r\n");
             
		 textBox1->AppendText("Закрытие доступа к результатам = " + hcSqlCloseResults(hstmt) + "\r\n");	 
	   textBox1->AppendText("Освободить оператор            = " + hcSqlFreeStmt(hstmt)     + "\r\n");  
	   textBox1->AppendText("Освободить соединение          = " + hcSqlFreeConnect(hdb)    + "\r\n"); 
	   textBox1->AppendText("Завершение работы              = " + hcSqlDone()              + "\r\n");   

 

  




	}






};
}
