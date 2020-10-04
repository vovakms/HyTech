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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ToolStripMenuItem^  ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  �������ToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  �������ToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  ���������ToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  ������ToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripButton^  ��������ToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  ����������ToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  �������ToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  �������ToolStripButton;
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
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->�������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->�������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->���������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->����������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->�������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�������ToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
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
				this->���ToolStripMenuItem, this->������ToolStripMenuItem, this->�������ToolStripMenuItem});
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
			this->aToolStripMenuItem->Text = L"����";
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->���ToolStripMenuItem->Text = L"���";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripSeparator2, 
				this->��������ToolStripMenuItem, this->���������ToolStripMenuItem});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->������ToolStripMenuItem->Text = L"������";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(128, 6);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->�������ToolStripButton, 
				this->�������ToolStripButton, this->���������ToolStripButton, this->������ToolStripButton, this->toolStripSeparator, this->��������ToolStripButton, 
				this->����������ToolStripButton, this->�������ToolStripButton, this->toolStripSeparator1, this->�������ToolStripButton, this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(974, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// �������ToolStripButton
			// 
			this->�������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->�������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripButton.Image")));
			this->�������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripButton->Name = L"�������ToolStripButton";
			this->�������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->�������ToolStripButton->Text = L"&�������";
			// 
			// �������ToolStripButton
			// 
			this->�������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->�������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripButton.Image")));
			this->�������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripButton->Name = L"�������ToolStripButton";
			this->�������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->�������ToolStripButton->Text = L"&�������";
			// 
			// ���������ToolStripButton
			// 
			this->���������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->���������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"���������ToolStripButton.Image")));
			this->���������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->���������ToolStripButton->Name = L"���������ToolStripButton";
			this->���������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->���������ToolStripButton->Text = L"&���������";
			// 
			// ������ToolStripButton
			// 
			this->������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"������ToolStripButton.Image")));
			this->������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->������ToolStripButton->Name = L"������ToolStripButton";
			this->������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->������ToolStripButton->Text = L"&������";
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(6, 25);
			// 
			// ��������ToolStripButton
			// 
			this->��������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->��������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"��������ToolStripButton.Image")));
			this->��������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->��������ToolStripButton->Name = L"��������ToolStripButton";
			this->��������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->��������ToolStripButton->Text = L"�&�������";
			// 
			// ����������ToolStripButton
			// 
			this->����������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->����������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"����������ToolStripButton.Image")));
			this->����������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->����������ToolStripButton->Name = L"����������ToolStripButton";
			this->����������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->����������ToolStripButton->Text = L"&����������";
			// 
			// �������ToolStripButton
			// 
			this->�������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->�������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripButton.Image")));
			this->�������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripButton->Name = L"�������ToolStripButton";
			this->�������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->�������ToolStripButton->Text = L"���&����";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// �������ToolStripButton
			// 
			this->�������ToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->�������ToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripButton.Image")));
			this->�������ToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripButton->Name = L"�������ToolStripButton";
			this->�������ToolStripButton->Size = System::Drawing::Size(23, 22);
			this->�������ToolStripButton->Text = L"���&����";
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
			this->button1->Text = L"������������ � ��";
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
			this->label1->Text = L"�����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"�������";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 304);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"����������";
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
			this->Text = L"������� HYTECH";
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
  
   unsigned option;// ����� 
   int pos;        // ������� 
	 void *pValue;   // ����� ������ ������, � ������� ����� �������� �������� (��������) ��������� ����������. 
   unsigned	size;  // � ��� ������ 
   unsigned	cnt;   // ������� ������ �������� � ����� 
  
	 hcHSTMT 	*p ;    // ����� ������, ���� ����� ������� ������������� ���������� ���������.   
   hcHSTMT	hstmt;  // ������������� ���������
   p=&hstmt ;
 
     //            //const char	*pSql ; // ����� SQL-���������, �������� � ���� C-������. ������ SQL-��������� ������ C-������ ����������� ��������� '\n' (������� ������). 
     //            //const char SqlString  = "fix all;select * from TABLES;" ;// fix all;select * from TABLES;
     //            //pSql=&SqlString;
                 
   int *pCol ;     // ����� ������ �����, ���� ����� �������� ���������� ������� � ����������.   
   int kolCol ;    // ���������� ������� � ����������
	 pCol=&kolCol;
	 
	 hcRECNO  *pCnt; // ����� ������, ���� ��������� ���������� ����� � ����������. 
   hcRECNO kolCnt ;// ���������� ����� � ����������
   pCnt=&kolCnt ;
   
   unsigned *pRecSize; // ����� �����, � ������� ��������� ������ �������� ������ � ������. ���� ������ ������ �� �����, �� ����� ������ . 
   unsigned rSize;     // ������ �������� ������ � ������
	 pRecSize=&rSize;

	 hcRECNO	gStart=0 ; // � ����� ������ �������� ������  
   void     *pBuf    ; // ����� ������ ��� ����������� �������.
   unsigned Buf ;
	 pBuf=&Buf ;
   unsigned wBufSize ; // ������ ������ ��� �����������. � ����� ���������� ����� ���������� �������. ���� ������ �� ����� ����� � ����� �������, ��� �� �����������.  
   unsigned	*cntBuf  ; // �����, ���� ������� ������� ���������� ������ ������, ���������� � ����� ������������. ���� ��� ���������� ��������� �� ����� ������, �� ������� ���������� ��������� �������. �������� ������ �� �����������.  
	 unsigned kolBd    ; // ���������� ������ ������ ���������� � �����
	 cntBuf=&kolBd;

	 hcHDB *pdb ; // ����� ������, ���� ����� ������� ������������� ����������. 
	 hcHDB  hdb ; // �������������  ����������. 
	 pdb = &hdb ; // ����� ����� ��������������  ����������
	  
		textBox3->AppendText("�������������  ����������(�� �������������) hdb = " +  hdb.ToString()    +"\r\n" );

	  textBox2->AppendText("������������� ���������� �����    = " + hcSqlInit(nullptr)     + "\r\n");     
	  textBox2->AppendText("�������� ���������� ������������� = " + hcSqlCheckInit()       + "\r\n");       
    textBox2->AppendText("������� ����������                = " + hcSqlAllocConnect(pdb) + "\r\n"); 
			 
	  textBox3->AppendText("����� �������������� ���������� *pdb = " +(reinterpret_cast<hcHDB>(pdb)).ToString()+"\r\n" );
    textBox3->AppendText("�������������  ����������        hdb = " +  hdb.ToString()    +"\r\n" );

    textBox2->AppendText("���������� ����� � ����  = " + hcSqlConnect(hdb, "tcpip:/10.27.11.131:1000","HTADMIN","PASSWORD") + "\r\n") ;   
                                                                                      // ����� , �������, ����� ��� ��������, � ��� ������, ������� ������ �������� � �����
    textBox2->AppendText("�������� ���������� �� ����������="+hcSqlGetConnectAttr(hdb,   option, pos,   	pValue,             size,             &cnt)+"\r\n" );		 
    textBox3->AppendText("�����   = " + option + "\r\n" ) ;//
    textBox3->AppendText("������� = " + pos    + "\r\n") ;//
    textBox3->AppendText("����� ��� ""�����������������"" = " + (reinterpret_cast<int>(pValue)).ToString()   + "\r\n") ;//
	  textBox3->AppendText("������ ""�����������������""    = " + size + "\r\n" );//
	  textBox3->AppendText("������� ������ �������� � ""����������������""= " +  cnt  + "\r\n" ) ;//

    textBox2->AppendText("������� ��������  = " +hcSqlAllocStmt(hdb, p) + "\r\n" ) ;//
    textBox3->AppendText("����� �������������� ��������� = " +(reinterpret_cast<hcHSTMT>(p)).ToString()+ "\r\n" ) ; 
    textBox3->AppendText("������������� ���������        = " +  hstmt   + "\r\n" ) ;

    hcSqlExecDirect(hstmt,"fix all;select * from TABLES;");// ���������� SQL-��������� � ��������� ���������
    hcSqlNumResultCols( hstmt, pCol ); // ���������� ���������
    hcSqlRowCount( hstmt,  pCnt);		   // ���������� �����
    textBox1->AppendText("���������� ������� = " +  kolCol + "\r\n");		 
	  textBox1->AppendText("���������� �����   = " +  kolCnt + "\r\n");		 
 
    textBox2->AppendText("�������� ����������� ��� ������   = " + hcSqlOpenResults(hstmt,  pRecSize) + "\r\n" ) ; 
    textBox3->AppendText("����� �����, � ������� ��������� ������ �������� ������ � ������. = "+(reinterpret_cast<unsigned>(pRecSize)).ToString()+"\r\n"); 
		    	 
    textBox2->AppendText("������ �����������                     = " + hcSqlReadResults(hstmt, gStart, pBuf, wBufSize, cntBuf) + "\r\n" ) ;  
   // textBox3->AppendText("����� ������ ��� ����������� �������.  = " +   pBuf    + "\r\n");
    textBox3->AppendText("������ ������ ��� �����������          = " +   wBufSize  + "\r\n");
    textBox3->AppendText("�����, ���� ������� ������� ���������� ������ ������ , ���������� � ����� ������������.  = " + cnt   + "\r\n");
             
		 textBox1->AppendText("�������� ������� � ����������� = " + hcSqlCloseResults(hstmt) + "\r\n");	 
	   textBox1->AppendText("���������� ��������            = " + hcSqlFreeStmt(hstmt)     + "\r\n");  
	   textBox1->AppendText("���������� ����������          = " + hcSqlFreeConnect(hdb)    + "\r\n"); 
	   textBox1->AppendText("���������� ������              = " + hcSqlDone()              + "\r\n");   

 

  




	}






};
}
