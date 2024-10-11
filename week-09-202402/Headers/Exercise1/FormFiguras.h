#pragma once
#include "ArrayCirculo.h"
#include "ArrayCuadrado.h"
#include "ArrayElipse.h"
#include "ArrayRectangulo.h"
#include "ArrayLinea.h"

namespace Ejercicio1Semana9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			arraycirculo = new ArrayCirculo();
			arraycuadrado = new ArrayCuadrado();
			arrayelipse = new ArrayElipse();
			arrayrectangulo = new ArrayRectangulo();
			arraylinea = new ArrayLinea();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;






	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::Label^ label4;




	private: System::Windows::Forms::Label^ label9;




	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::Label^ label13;




	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label15;


	private: System::Windows::Forms::Label^ label16;




	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Button^ buttonLimpiar;
	private: System::Windows::Forms::Button^ buttonDibujar;
	private: System::Windows::Forms::TextBox^ textBoxPosX;
	private: System::Windows::Forms::TextBox^ textBoxPosY;
	private: System::Windows::Forms::TextBox^ textBoxRCirculo;
	private: System::Windows::Forms::Label^ labelAreaRectan;
	private: System::Windows::Forms::TextBox^ textBoxL1Rectan;
	private: System::Windows::Forms::TextBox^ textBoxL2Rectan;
	private: System::Windows::Forms::ComboBox^ comboBoxElegFigura;
	private: System::Windows::Forms::TextBox^ textBoxEjeMayor;
	private: System::Windows::Forms::TextBox^ textBoxEjeMenor;
	private: System::Windows::Forms::Label^ labelAreaElipse;
	private: System::Windows::Forms::TextBox^ textBoxLCuadrado;
	private: System::Windows::Forms::Label^ labelAreaCuadrado;
	private: System::Windows::Forms::TextBox^ textBoxLongLinea;
	private: System::Windows::Forms::Panel^ panelDibujarFigura;
	private: System::Windows::Forms::Label^ labelAreaCirculo;

	protected:

	private:
		ArrayCirculo* arraycirculo;
		ArrayCuadrado* arraycuadrado;
		ArrayElipse* arrayelipse;
		ArrayRectangulo* arrayrectangulo;
		ArrayLinea* arraylinea;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxElegFigura = (gcnew System::Windows::Forms::ComboBox());
			this->buttonDibujar = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxPosY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPosX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->labelAreaCirculo = (gcnew System::Windows::Forms::Label());
			this->textBoxRCirculo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxL2Rectan = (gcnew System::Windows::Forms::TextBox());
			this->textBoxL1Rectan = (gcnew System::Windows::Forms::TextBox());
			this->labelAreaRectan = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->labelAreaElipse = (gcnew System::Windows::Forms::Label());
			this->textBoxEjeMenor = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEjeMayor = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->labelAreaCuadrado = (gcnew System::Windows::Forms::Label());
			this->textBoxLCuadrado = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxLongLinea = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panelDibujarFigura = (gcnew System::Windows::Forms::Panel());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBoxElegFigura);
			this->groupBox1->Controls->Add(this->buttonDibujar);
			this->groupBox1->Controls->Add(this->buttonLimpiar);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1021, 58);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// comboBoxElegFigura
			// 
			this->comboBoxElegFigura->FormattingEnabled = true;
			this->comboBoxElegFigura->Location = System::Drawing::Point(130, 19);
			this->comboBoxElegFigura->Name = L"comboBoxElegFigura";
			this->comboBoxElegFigura->Size = System::Drawing::Size(146, 21);
			this->comboBoxElegFigura->TabIndex = 5;
			this->comboBoxElegFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxElegFigura_SelectedIndexChanged);
			// 
			// buttonDibujar
			// 
			this->buttonDibujar->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->buttonDibujar->Location = System::Drawing::Point(311, 19);
			this->buttonDibujar->Name = L"buttonDibujar";
			this->buttonDibujar->Size = System::Drawing::Size(349, 23);
			this->buttonDibujar->TabIndex = 4;
			this->buttonDibujar->Text = L"Dibujar";
			this->buttonDibujar->UseVisualStyleBackColor = false;
			this->buttonDibujar->Click += gcnew System::EventHandler(this, &MyForm::buttonDibujar_Click);
			// 
			// buttonLimpiar
			// 
			this->buttonLimpiar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonLimpiar->Location = System::Drawing::Point(666, 19);
			this->buttonLimpiar->Name = L"buttonLimpiar";
			this->buttonLimpiar->Size = System::Drawing::Size(349, 23);
			this->buttonLimpiar->TabIndex = 3;
			this->buttonLimpiar->Text = L"Limpiar";
			this->buttonLimpiar->UseVisualStyleBackColor = false;
			this->buttonLimpiar->Click += gcnew System::EventHandler(this, &MyForm::buttonLimpiar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(31, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Elegir Figura";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxPosY);
			this->groupBox2->Controls->Add(this->textBoxPosX);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(12, 81);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(156, 130);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Posicion Inicial";
			// 
			// textBoxPosY
			// 
			this->textBoxPosY->Location = System::Drawing::Point(77, 69);
			this->textBoxPosY->Name = L"textBoxPosY";
			this->textBoxPosY->Size = System::Drawing::Size(73, 20);
			this->textBoxPosY->TabIndex = 8;
			this->textBoxPosY->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxPosY_TextChanged);
			// 
			// textBoxPosX
			// 
			this->textBoxPosX->Location = System::Drawing::Point(77, 33);
			this->textBoxPosX->Name = L"textBoxPosX";
			this->textBoxPosX->Size = System::Drawing::Size(73, 20);
			this->textBoxPosX->TabIndex = 7;
			this->textBoxPosX->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxPosX_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Posicion Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Posicion X";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->labelAreaCirculo);
			this->groupBox3->Controls->Add(this->textBoxRCirculo);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Location = System::Drawing::Point(183, 81);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(156, 130);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Circulo";
			// 
			// labelAreaCirculo
			// 
			this->labelAreaCirculo->AutoSize = true;
			this->labelAreaCirculo->Location = System::Drawing::Point(59, 73);
			this->labelAreaCirculo->Name = L"labelAreaCirculo";
			this->labelAreaCirculo->Size = System::Drawing::Size(89, 13);
			this->labelAreaCirculo->TabIndex = 11;
			this->labelAreaCirculo->Text = L"Mostrar area aqui";
			// 
			// textBoxRCirculo
			// 
			this->textBoxRCirculo->Location = System::Drawing::Point(69, 35);
			this->textBoxRCirculo->Name = L"textBoxRCirculo";
			this->textBoxRCirculo->Size = System::Drawing::Size(73, 20);
			this->textBoxRCirculo->TabIndex = 10;
			this->textBoxRCirculo->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxRCirculo_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(17, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 15);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Area:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(16, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 15);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Radio";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxL2Rectan);
			this->groupBox4->Controls->Add(this->textBoxL1Rectan);
			this->groupBox4->Controls->Add(this->labelAreaRectan);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Location = System::Drawing::Point(355, 81);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(156, 130);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Rectangulo";
			// 
			// textBoxL2Rectan
			// 
			this->textBoxL2Rectan->Location = System::Drawing::Point(72, 66);
			this->textBoxL2Rectan->Name = L"textBoxL2Rectan";
			this->textBoxL2Rectan->Size = System::Drawing::Size(73, 20);
			this->textBoxL2Rectan->TabIndex = 15;
			this->textBoxL2Rectan->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxL2Rectan_TextChanged);
			// 
			// textBoxL1Rectan
			// 
			this->textBoxL1Rectan->Location = System::Drawing::Point(72, 32);
			this->textBoxL1Rectan->Name = L"textBoxL1Rectan";
			this->textBoxL1Rectan->Size = System::Drawing::Size(73, 20);
			this->textBoxL1Rectan->TabIndex = 14;
			this->textBoxL1Rectan->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxL1Rectan_TextChanged);
			// 
			// labelAreaRectan
			// 
			this->labelAreaRectan->AutoSize = true;
			this->labelAreaRectan->Location = System::Drawing::Point(61, 102);
			this->labelAreaRectan->Name = L"labelAreaRectan";
			this->labelAreaRectan->Size = System::Drawing::Size(89, 13);
			this->labelAreaRectan->TabIndex = 13;
			this->labelAreaRectan->Text = L"Mostrar area aqui";
			this->labelAreaRectan->Click += gcnew System::EventHandler(this, &MyForm::labelAreaRectan_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(21, 100);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 15);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Area:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(16, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 15);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Lado 2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(16, 34);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 15);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Lado 1";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->labelAreaElipse);
			this->groupBox5->Controls->Add(this->textBoxEjeMenor);
			this->groupBox5->Controls->Add(this->textBoxEjeMayor);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->label12);
			this->groupBox5->Controls->Add(this->label11);
			this->groupBox5->Location = System::Drawing::Point(530, 81);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(156, 130);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Elipse";
			// 
			// labelAreaElipse
			// 
			this->labelAreaElipse->AutoSize = true;
			this->labelAreaElipse->Location = System::Drawing::Point(61, 102);
			this->labelAreaElipse->Name = L"labelAreaElipse";
			this->labelAreaElipse->Size = System::Drawing::Size(89, 13);
			this->labelAreaElipse->TabIndex = 18;
			this->labelAreaElipse->Text = L"Mostrar area aqui";
			this->labelAreaElipse->Click += gcnew System::EventHandler(this, &MyForm::labelAreaElipse_Click);
			// 
			// textBoxEjeMenor
			// 
			this->textBoxEjeMenor->Location = System::Drawing::Point(78, 69);
			this->textBoxEjeMenor->Name = L"textBoxEjeMenor";
			this->textBoxEjeMenor->Size = System::Drawing::Size(73, 20);
			this->textBoxEjeMenor->TabIndex = 17;
			this->textBoxEjeMenor->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxEjeMenor_TextChanged);
			// 
			// textBoxEjeMayor
			// 
			this->textBoxEjeMayor->Location = System::Drawing::Point(78, 33);
			this->textBoxEjeMayor->Name = L"textBoxEjeMayor";
			this->textBoxEjeMayor->Size = System::Drawing::Size(73, 20);
			this->textBoxEjeMayor->TabIndex = 16;
			this->textBoxEjeMayor->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxEjeMayor_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(18, 100);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(35, 15);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Area:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(9, 71);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(64, 15);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Eje Menor";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(9, 35);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(62, 15);
			this->label11->TabIndex = 13;
			this->label11->Text = L"Eje Mayor";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->labelAreaCuadrado);
			this->groupBox6->Controls->Add(this->textBoxLCuadrado);
			this->groupBox6->Controls->Add(this->label16);
			this->groupBox6->Controls->Add(this->label15);
			this->groupBox6->Location = System::Drawing::Point(704, 81);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(156, 130);
			this->groupBox6->TabIndex = 6;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Cuadrado";
			// 
			// labelAreaCuadrado
			// 
			this->labelAreaCuadrado->AutoSize = true;
			this->labelAreaCuadrado->Location = System::Drawing::Point(61, 76);
			this->labelAreaCuadrado->Name = L"labelAreaCuadrado";
			this->labelAreaCuadrado->Size = System::Drawing::Size(89, 13);
			this->labelAreaCuadrado->TabIndex = 18;
			this->labelAreaCuadrado->Text = L"Mostrar area aqui";
			this->labelAreaCuadrado->Click += gcnew System::EventHandler(this, &MyForm::labelAreaCuadrado_Click);
			// 
			// textBoxLCuadrado
			// 
			this->textBoxLCuadrado->Location = System::Drawing::Point(67, 33);
			this->textBoxLCuadrado->Name = L"textBoxLCuadrado";
			this->textBoxLCuadrado->Size = System::Drawing::Size(73, 20);
			this->textBoxLCuadrado->TabIndex = 17;
			this->textBoxLCuadrado->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxLCuadrado_TextChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(19, 74);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 16);
			this->label16->TabIndex = 16;
			this->label16->Text = L"Area:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(19, 35);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(38, 16);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Lado";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->textBoxLongLinea);
			this->groupBox7->Controls->Add(this->label18);
			this->groupBox7->Location = System::Drawing::Point(877, 81);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(156, 130);
			this->groupBox7->TabIndex = 7;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Linea";
			// 
			// textBoxLongLinea
			// 
			this->textBoxLongLinea->Location = System::Drawing::Point(75, 54);
			this->textBoxLongLinea->Name = L"textBoxLongLinea";
			this->textBoxLongLinea->Size = System::Drawing::Size(73, 20);
			this->textBoxLongLinea->TabIndex = 18;
			this->textBoxLongLinea->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxLongLinea_TextChanged);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(11, 56);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(58, 16);
			this->label18->TabIndex = 17;
			this->label18->Text = L"Longitud";
			// 
			// panelDibujarFigura
			// 
			this->panelDibujarFigura->Location = System::Drawing::Point(12, 232);
			this->panelDibujarFigura->Name = L"panelDibujarFigura";
			this->panelDibujarFigura->Size = System::Drawing::Size(1021, 289);
			this->panelDibujarFigura->TabIndex = 19;
			this->panelDibujarFigura->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelDibujarFigura_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1056, 533);
			this->Controls->Add(this->panelDibujarFigura);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBoxElegFigura->Items->Add("Circulo");
		comboBoxElegFigura->Items->Add("Rectangulo");
		comboBoxElegFigura->Items->Add("Cuadrado");
		comboBoxElegFigura->Items->Add("Elipse");
		comboBoxElegFigura->Items->Add("Linea");

	}
private: System::Void buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
	arraycirculo = new ArrayCirculo();  
	arraycuadrado = new ArrayCuadrado();
	arrayelipse = new ArrayElipse();
	arrayrectangulo = new ArrayRectangulo();
	arraylinea = new ArrayLinea();
	panelDibujarFigura->Invalidate(); 
}
private: System::Void buttonDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Verifica si hay un elemento seleccionado en el ComboBox
	if (comboBoxElegFigura->SelectedItem == nullptr) {
		MessageBox::Show("Por favor, seleccione una figura primero.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Terminar el m�todo si no hay selecci�n
	}

	String^ selectedItem = comboBoxElegFigura->SelectedItem->ToString();

	// Variables para las coordenadas
	int x, y;

	// Verificar que los campos de posici�n X y Y no est�n vac�os
	if (!Int32::TryParse(textBoxPosX->Text, x) || !Int32::TryParse(textBoxPosY->Text, y)) {
		MessageBox::Show("Por favor, introduzca valores v�lidos para la posici�n X e Y.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Terminar el m�todo si hay error
	}

	// Validaci�n seg�n el tipo de figura seleccionada
	if (selectedItem == "Circulo") {
		double radio;
		if (!Double::TryParse(textBoxRCirculo->Text, radio) || radio <= 0) {
			MessageBox::Show("Por favor, introduzca un valor v�lido para el radio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Circulo* circulo = new Circulo(radio, x, y);
		arraycirculo->agregarCirculo(circulo);
		labelAreaCirculo->Text = circulo->CalcularArea().ToString();
	}
	else if (selectedItem == "Rectangulo") {
		double largo, ancho;
		if (!Double::TryParse(textBoxL1Rectan->Text, largo) || !Double::TryParse(textBoxL2Rectan->Text, ancho) || largo <= 0 || ancho <= 0) {
			MessageBox::Show("Por favor, introduzca valores v�lidos para el Lado 1 y Lado 2.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Rectangulo* rectangulo = new Rectangulo(largo, ancho, x, y);
		arrayrectangulo->agregarRectangulo(rectangulo);
		labelAreaRectan->Text = rectangulo->CalcularArea().ToString();
	}
	else if (selectedItem == "Cuadrado") {
		double lado;
		if (!Double::TryParse(textBoxLCuadrado->Text, lado) || lado <= 0) {
			MessageBox::Show("Por favor, introduzca un valor v�lido para el lado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Cuadrado* cuadrado = new Cuadrado(lado, x, y);
		arraycuadrado->agregarCuadrado(cuadrado);
		labelAreaCuadrado->Text = cuadrado->CalcularArea().ToString();
	}
	else if (selectedItem == "Elipse") {
		double ejemayor, ejemenor;
		if (!Double::TryParse(textBoxEjeMayor->Text, ejemayor) || !Double::TryParse(textBoxEjeMenor->Text, ejemenor) || ejemayor <= 0 || ejemenor <= 0) {
			MessageBox::Show("Por favor, introduzca valores v�lidos para el eje mayor y menor.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Elipse* elipse = new Elipse(ejemayor, ejemenor, x, y);
		arrayelipse->agregarElipse(elipse);
		labelAreaElipse->Text = elipse->CalcularArea().ToString();
	}
	else if (selectedItem == "Linea") {
		double longitud;
		if (!Double::TryParse(textBoxLongLinea->Text, longitud) || longitud <= 0) {
			MessageBox::Show("Por favor, introduzca un valor v�lido para la longitud.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Linea* linea = new Linea(longitud, x, y);
		arraylinea->agregarLinea(linea);
	}

	// Redraw the panel
	panelDibujarFigura->Invalidate();
}
private: System::Void textBoxPosX_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxPosY_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxRCirculo_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void labelAreaCirculo_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void labelAreaRectan_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxL1Rectan_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxL2Rectan_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void comboBoxElegFigura_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ selectedItem = comboBoxElegFigura->SelectedItem->ToString();

	textBoxRCirculo->Text = "";
	textBoxL1Rectan->Text = "";
	textBoxL2Rectan->Text = "";
	textBoxLCuadrado->Text = "";
	textBoxEjeMayor->Text = "";
	textBoxEjeMenor->Text = "";
	textBoxLongLinea->Text = "";
	labelAreaCirculo->Text = "";
	labelAreaRectan->Text = "";
	labelAreaCuadrado->Text = "";
	labelAreaElipse->Text = "";
	if (selectedItem == "Circulo") {
		textBoxRCirculo->Enabled = true;
		textBoxL1Rectan->Enabled = false;
		textBoxL2Rectan->Enabled = false;
		textBoxLCuadrado->Enabled = false;
		textBoxEjeMayor->Enabled = false;
		textBoxEjeMenor->Enabled = false;
		textBoxLongLinea->Enabled = false;
	}
	else if (selectedItem == "Rectangulo") {
		textBoxRCirculo->Enabled = false;
		textBoxL1Rectan->Enabled = true;
		textBoxL2Rectan->Enabled = true;
		textBoxLCuadrado->Enabled = false;
		textBoxEjeMayor->Enabled = false;
		textBoxEjeMenor->Enabled = false;
		textBoxLongLinea->Enabled = false;
	}
	else if (selectedItem == "Cuadrado") {
		textBoxRCirculo->Enabled = false;
		textBoxL1Rectan->Enabled = false;
		textBoxL2Rectan->Enabled = false;
		textBoxLCuadrado->Enabled = true;
		textBoxEjeMayor->Enabled = false;
		textBoxEjeMenor->Enabled = false;
		textBoxLongLinea->Enabled = false;
	}
	else if (selectedItem == "Elipse") {
		textBoxRCirculo->Enabled = false;
		textBoxL1Rectan->Enabled = false;
		textBoxL2Rectan->Enabled = false;
		textBoxLCuadrado->Enabled = false;
		textBoxEjeMayor->Enabled = true;
		textBoxEjeMenor->Enabled = true;
		textBoxLongLinea->Enabled = false;
	}
	else if (selectedItem == "Linea") {
		textBoxRCirculo->Enabled = false;
		textBoxL1Rectan->Enabled = false;
		textBoxL2Rectan->Enabled = false;
		textBoxLCuadrado->Enabled = false;
		textBoxEjeMayor->Enabled = false;
		textBoxEjeMenor->Enabled = false;
		textBoxLongLinea->Enabled = true;
	}
	textBoxPosX->Enabled = true; 
	textBoxPosY->Enabled = true; 
}
private: System::Void textBoxEjeMayor_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxEjeMenor_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void labelAreaElipse_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxLCuadrado_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void labelAreaCuadrado_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBoxLongLinea_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void panelDibujarFigura_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	arraycirculo->dibujarTodos(e);
	arrayrectangulo->dibujarTodos(e);
	arraycuadrado->dibujarTodos(e);
	arrayelipse->dibujarTodos(e);
	arraylinea->dibujarTodos(e);
}
};
}