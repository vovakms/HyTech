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
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->button1->Text = L"������������  � ��";
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
			this->label1->Text = L"����� ����������  ����������";
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->����ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(679, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 213);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"����������";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(511, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"�������";
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
			this->Text = L"������� HYTECH";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
 
	  hcSqlParmT  init = {0};
    init.size = sizeof(hcSqlParmT);
  
    unsigned option;// ����� 
    int pos;        // ������� 
	  void *pValue;   // ����� ��� �������� 
     //    unsigned	size;   // � ��� ������ 
     //    unsigned	cnt;    // ������� ������ �������� � ����� 
  
				 //hcHSTMT 	*p ;    // ����� ��� �������������� ��������� 
     //    hcHSTMT	hstmt;  // ������������� ���������
     //    p=&hstmt ;
 
     //            //const char	*pSql ; // ����� SQL-���������, �������� � ���� C-������. ������ SQL-��������� ������ C-������ ����������� ��������� '\n' (������� ������). 
     //            //const char SqlString  = "fix all;select * from TABLES;" ;// fix all;select * from TABLES;
     //            //pSql=&SqlString;
     //            
				 //int pCol ;// ����� ��� ���������� �������  
     //            hcRECNO  pCnt;// ����� ������, ���� ��������� ���������� ����� � ����������. 
				 //int kCol ;
				 //// pCol=&kCol;

     //            unsigned *pRecSize;// ����� �����, � ������� ��������� ������ �������� ������ � ������. ���� ������ ������ �� �����, �� ����� ������ . 
     //            hcRECNO	gStart=0 ; // � ����� ������ �������� ������  
     //            void *pBuf ; // ����� ������ ��� ����������� �������. 
     //            unsigned  wBufSize;//  ������ ������ ��� �����������. � ����� ���������� ����� ���������� �������. ���� ������ �� ����� ����� � ����� �������, ��� �� �����������.  
     //            unsigned	*cntBuf ;   // ������� ���������  

	  hcHDB  *pdb; // ����� ������, ���� ����� ������� ������������� ���������� ����������. 
	  hcHDB  hdb ; // �������������  ����������. 
	  pdb = &hdb ; // ����� ����� ��������������  ����������
	  
	  textBox1->AppendText("������������� ���������� �����    = " + hcSqlInit(nullptr)     + "\r\n");     
	  textBox1->AppendText("�������� ���������� ������������� = " + hcSqlCheckInit()       + "\r\n");       
    textBox1->AppendText("������� ����������                = " + hcSqlAllocConnect(pdb) + "\r\n"); 
			 
	  textBox1->AppendText("����� �������������� ���������� *pdb = " +(reinterpret_cast<hcHDB>(pdb)).ToString()+"\r\n" );
    textBox1->AppendText("�������������  ����������        hdb = " +  hdb.ToString()    +"\r\n" );

		//textBox2->Text += "������� hcSqlConnect  = " + hcSqlConnect(hdb, "tcpip:/localhost:13000","HTADMIN","PASSWORD") + "\r\n" ;//   ���������� ����� � ����
		 		// 
				 //textBox2->Text +="������� hcSqlGetConnectAttr="+hcSqlGetConnectAttr(hdb,
     //            option,		/* ����� */
     //            pos,		/* ������� */
     //            pValue,	/* ����� ��� �������� */
     //            size,		/* � ��� ������ */
     //            &cnt)+"\r\n" ;		/* ������� ������ �������� � ����� */
				 //
				 //textBox2->Text += "�����   = " + option + "\r\n" ;//
     //            textBox2->Text += "������� = " + pos + "\r\n" ;//
				 //textBox2->Text += "����� ��� ��������   = " + Convert::ToString( pValue )  + "\r\n" ;//
				 //textBox2->Text += "� ��� ������   = " + size + "\r\n" ;//
				 //textBox2->Text += "������� ������ �������� � �����   = " +  cnt  + "\r\n" ;//

     //            textBox2->Text += "������� hcSqlAllocStmt  = " +hcSqlAllocStmt(hdb, p)+ "\r\n" ;//������� ��������
     //            
     //            hcSqlExecDirect(hstmt,"fix all;select * from TABLES;");// ���������� SQL-��������� � ��������� ���������
     //            hcSqlNumResultCols( hstmt, &pCol ); // ���������� ���������
			  //   hcSqlRowCount( hstmt,  &pCnt);		// ���������� �����
     //            textBox2->Text += "���������� ������� = " +  pCol + "\r\n";		 
				 //textBox2->Text += "���������� �����   = " +  pCnt + "\r\n";		 

     //            hcSqlOpenResults(hstmt,  pRecSize);// �������� ����������� ��� ������
     //            hcSqlReadResults(hstmt, gStart,   pBuf, wBufSize,   cntBuf);// ������ �����������    	 
     //            //textBox2->Text += "������ �����������   = " +   pBuf   + "\r\n";
 
     //            textBox2->Text += "������������� ��������� = " +   hstmt + "\r\n";
     //            textBox2->Text += "����� ��� �������������� ���������  = " +   *p + "\r\n";
     //            
				 
			//	 textBox2->Text += "������� hcSqlFreeStmt   = "+hcSqlFreeStmt(hstmt)+ "\r\n";// ���������� ��������
	   textBox1->Text += "���������� ���������� = "+hcSqlFreeConnect(hdb) + "\r\n" ;//
	   textBox1->Text += "���������� ������     = "+hcSqlDone() + "\r\n" ; //   

 







    
			 }

  



	};
}

