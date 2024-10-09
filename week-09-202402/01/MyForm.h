#pragma once
#include "Figuras.h"
#include "ArrFiguras.h"

namespace Project13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public Form
	{
		//CCirculo* C;
		//CVCFiguras* FCV;
		CVCFiguras* VECFIG;
	private: System::Windows::Forms::TextBox^ txbxRad;

	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Label^ lblCuadrado_Rectangulo;

	private: System::Windows::Forms::TextBox^ txbxLado1;



	private: System::Windows::Forms::Label^ lblLado1;
	private: System::Windows::Forms::Label^ lblAreaDerecha;
	private: System::Windows::Forms::Label^ lblMstrAreaDerecha;

	private: System::Windows::Forms::Label^ lblLado2;
	private: System::Windows::Forms::TextBox^ txbxLado2;

	private: System::Windows::Forms::Label^ lblMstrArea;

	  

	public:
		MyForm(void)
		{
			InitializeComponent();
			//C = new CCirculo(0, 0, 0);
			
			VECFIG = new CVCFiguras();
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//delete C;

			delete VECFIG;
		}
	private: System::Windows::Forms::Button^ btnDibujar;
	private: System::Windows::Forms::ComboBox^ cmbxElegirFigura;
	private: System::Windows::Forms::Label^ lblElegirFigura;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lblPosX;
	private: System::Windows::Forms::Label^ lblPosY;


	private: System::Windows::Forms::TextBox^ txbxPosX;
	private: System::Windows::Forms::TextBox^ txbxPosY;
	private: System::Windows::Forms::Label^ lblCirculo_Elipse;


	private: System::Windows::Forms::Label^ lblRadio;
	private: System::Windows::Forms::Label^ lblMstrarAreaizq;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnDibujar = (gcnew System::Windows::Forms::Button());
			this->cmbxElegirFigura = (gcnew System::Windows::Forms::ComboBox());
			this->lblElegirFigura = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblPosX = (gcnew System::Windows::Forms::Label());
			this->lblPosY = (gcnew System::Windows::Forms::Label());
			this->txbxPosX = (gcnew System::Windows::Forms::TextBox());
			this->txbxPosY = (gcnew System::Windows::Forms::TextBox());
			this->lblCirculo_Elipse = (gcnew System::Windows::Forms::Label());
			this->lblRadio = (gcnew System::Windows::Forms::Label());
			this->lblMstrarAreaizq = (gcnew System::Windows::Forms::Label());
			this->txbxRad = (gcnew System::Windows::Forms::TextBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->lblMstrArea = (gcnew System::Windows::Forms::Label());
			this->lblCuadrado_Rectangulo = (gcnew System::Windows::Forms::Label());
			this->txbxLado1 = (gcnew System::Windows::Forms::TextBox());
			this->lblLado1 = (gcnew System::Windows::Forms::Label());
			this->lblAreaDerecha = (gcnew System::Windows::Forms::Label());
			this->lblMstrAreaDerecha = (gcnew System::Windows::Forms::Label());
			this->lblLado2 = (gcnew System::Windows::Forms::Label());
			this->txbxLado2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnDibujar
			// 
			this->btnDibujar->Location = System::Drawing::Point(240, 4);
			this->btnDibujar->Name = L"btnDibujar";
			this->btnDibujar->Size = System::Drawing::Size(184, 21);
			this->btnDibujar->TabIndex = 0;
			this->btnDibujar->Text = L"Dibujar";
			this->btnDibujar->UseVisualStyleBackColor = true;
			this->btnDibujar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// cmbxElegirFigura
			// 
			this->cmbxElegirFigura->FormattingEnabled = true;
			this->cmbxElegirFigura->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Circulo", L"Cuadrado", L"Elipse", L"Rectangulo" });
			this->cmbxElegirFigura->Location = System::Drawing::Point(92, 12);
			this->cmbxElegirFigura->Name = L"cmbxElegirFigura";
			this->cmbxElegirFigura->Size = System::Drawing::Size(121, 21);
			this->cmbxElegirFigura->TabIndex = 1;
			this->cmbxElegirFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// lblElegirFigura
			// 
			this->lblElegirFigura->AutoSize = true;
			this->lblElegirFigura->Location = System::Drawing::Point(12, 12);
			this->lblElegirFigura->Name = L"lblElegirFigura";
			this->lblElegirFigura->Size = System::Drawing::Size(65, 13);
			this->lblElegirFigura->TabIndex = 2;
			this->lblElegirFigura->Text = L"Elegir Figura";
			this->lblElegirFigura->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 153);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(412, 197);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// lblPosX
			// 
			this->lblPosX->AutoSize = true;
			this->lblPosX->Location = System::Drawing::Point(15, 73);
			this->lblPosX->Name = L"lblPosX";
			this->lblPosX->Size = System::Drawing::Size(35, 13);
			this->lblPosX->TabIndex = 4;
			this->lblPosX->Text = L"Pos X";
			// 
			// lblPosY
			// 
			this->lblPosY->AutoSize = true;
			this->lblPosY->Location = System::Drawing::Point(18, 104);
			this->lblPosY->Name = L"lblPosY";
			this->lblPosY->Size = System::Drawing::Size(35, 13);
			this->lblPosY->TabIndex = 5;
			this->lblPosY->Text = L"Pos Y";
			// 
			// txbxPosX
			// 
			this->txbxPosX->Location = System::Drawing::Point(59, 70);
			this->txbxPosX->Name = L"txbxPosX";
			this->txbxPosX->Size = System::Drawing::Size(100, 20);
			this->txbxPosX->TabIndex = 6;
			this->txbxPosX->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// txbxPosY
			// 
			this->txbxPosY->Location = System::Drawing::Point(59, 101);
			this->txbxPosY->Name = L"txbxPosY";
			this->txbxPosY->Size = System::Drawing::Size(100, 20);
			this->txbxPosY->TabIndex = 7;
			// 
			// lblCirculo_Elipse
			// 
			this->lblCirculo_Elipse->AutoSize = true;
			this->lblCirculo_Elipse->Location = System::Drawing::Point(177, 45);
			this->lblCirculo_Elipse->Name = L"lblCirculo_Elipse";
			this->lblCirculo_Elipse->Size = System::Drawing::Size(39, 13);
			this->lblCirculo_Elipse->TabIndex = 8;
			this->lblCirculo_Elipse->Text = L"Circulo";
			// 
			// lblRadio
			// 
			this->lblRadio->AutoSize = true;
			this->lblRadio->Location = System::Drawing::Point(168, 70);
			this->lblRadio->Name = L"lblRadio";
			this->lblRadio->Size = System::Drawing::Size(35, 13);
			this->lblRadio->TabIndex = 9;
			this->lblRadio->Text = L"Radio";
			// 
			// lblMstrarAreaizq
			// 
			this->lblMstrarAreaizq->AutoSize = true;
			this->lblMstrarAreaizq->Location = System::Drawing::Point(168, 104);
			this->lblMstrarAreaizq->Name = L"lblMstrarAreaizq";
			this->lblMstrarAreaizq->Size = System::Drawing::Size(29, 13);
			this->lblMstrarAreaizq->TabIndex = 10;
			this->lblMstrarAreaizq->Text = L"Area";
			// 
			// txbxRad
			// 
			this->txbxRad->Location = System::Drawing::Point(209, 70);
			this->txbxRad->Name = L"txbxRad";
			this->txbxRad->Size = System::Drawing::Size(55, 20);
			this->txbxRad->TabIndex = 11;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->Location = System::Drawing::Point(240, 22);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(184, 23);
			this->btnLimpiar->TabIndex = 12;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = true;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// lblMstrArea
			// 
			this->lblMstrArea->AutoSize = true;
			this->lblMstrArea->Location = System::Drawing::Point(206, 108);
			this->lblMstrArea->Name = L"lblMstrArea";
			this->lblMstrArea->Size = System::Drawing::Size(36, 13);
			this->lblMstrArea->TabIndex = 13;
			this->lblMstrArea->Text = L"AREA";
			// 
			// lblCuadrado_Rectangulo
			// 
			this->lblCuadrado_Rectangulo->AutoSize = true;
			this->lblCuadrado_Rectangulo->Location = System::Drawing::Point(277, 48);
			this->lblCuadrado_Rectangulo->Name = L"lblCuadrado_Rectangulo";
			this->lblCuadrado_Rectangulo->Size = System::Drawing::Size(53, 13);
			this->lblCuadrado_Rectangulo->TabIndex = 14;
			this->lblCuadrado_Rectangulo->Text = L"Cuadrado";
			this->lblCuadrado_Rectangulo->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// txbxLado1
			// 
			this->txbxLado1->Location = System::Drawing::Point(322, 67);
			this->txbxLado1->Name = L"txbxLado1";
			this->txbxLado1->Size = System::Drawing::Size(85, 20);
			this->txbxLado1->TabIndex = 15;
			// 
			// lblLado1
			// 
			this->lblLado1->AutoSize = true;
			this->lblLado1->Location = System::Drawing::Point(270, 70);
			this->lblLado1->Name = L"lblLado1";
			this->lblLado1->Size = System::Drawing::Size(40, 13);
			this->lblLado1->TabIndex = 16;
			this->lblLado1->Text = L"Lado 1";
			// 
			// lblAreaDerecha
			// 
			this->lblAreaDerecha->AutoSize = true;
			this->lblAreaDerecha->Location = System::Drawing::Point(281, 124);
			this->lblAreaDerecha->Name = L"lblAreaDerecha";
			this->lblAreaDerecha->Size = System::Drawing::Size(29, 13);
			this->lblAreaDerecha->TabIndex = 17;
			this->lblAreaDerecha->Text = L"Area";
			// 
			// lblMstrAreaDerecha
			// 
			this->lblMstrAreaDerecha->AutoSize = true;
			this->lblMstrAreaDerecha->Location = System::Drawing::Point(337, 124);
			this->lblMstrAreaDerecha->Name = L"lblMstrAreaDerecha";
			this->lblMstrAreaDerecha->Size = System::Drawing::Size(36, 13);
			this->lblMstrAreaDerecha->TabIndex = 18;
			this->lblMstrAreaDerecha->Text = L"AREA";
			// 
			// lblLado2
			// 
			this->lblLado2->AutoSize = true;
			this->lblLado2->Location = System::Drawing::Point(270, 97);
			this->lblLado2->Name = L"lblLado2";
			this->lblLado2->Size = System::Drawing::Size(40, 13);
			this->lblLado2->TabIndex = 20;
			this->lblLado2->Text = L"Lado 2";
			this->lblLado2->Click += gcnew System::EventHandler(this, &MyForm::lblLado2_Click);
			// 
			// txbxLado2
			// 
			this->txbxLado2->Location = System::Drawing::Point(322, 97);
			this->txbxLado2->Name = L"txbxLado2";
			this->txbxLado2->Size = System::Drawing::Size(85, 20);
			this->txbxLado2->TabIndex = 21;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 362);
			this->Controls->Add(this->txbxLado2);
			this->Controls->Add(this->lblLado2);
			this->Controls->Add(this->lblMstrAreaDerecha);
			this->Controls->Add(this->lblAreaDerecha);
			this->Controls->Add(this->lblLado1);
			this->Controls->Add(this->txbxLado1);
			this->Controls->Add(this->lblCuadrado_Rectangulo);
			this->Controls->Add(this->lblMstrArea);
			this->Controls->Add(this->btnLimpiar);
			this->Controls->Add(this->txbxRad);
			this->Controls->Add(this->lblMstrarAreaizq);
			this->Controls->Add(this->lblRadio);
			this->Controls->Add(this->lblCirculo_Elipse);
			this->Controls->Add(this->txbxPosY);
			this->Controls->Add(this->txbxPosX);
			this->Controls->Add(this->lblPosY);
			this->Controls->Add(this->lblPosX);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblElegirFigura);
			this->Controls->Add(this->cmbxElegirFigura);
			this->Controls->Add(this->btnDibujar);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
	Void button1_Click(Object^ sender, EventArgs^ e) 
	{
		String^ selectedFigura = cmbxElegirFigura->SelectedItem->ToString();
		Graphics^ g = pictureBox1->CreateGraphics();
		int x = Int32::Parse(txbxPosX->Text);
		int y = Int32::Parse(txbxPosY->Text);
		if (selectedFigura == "Circulo")
		{
			double rd = Double::Parse(txbxRad->Text);
			CCirculo* C = new CCirculo(x, y, rd);
			VECFIG->AgregarFigura(C);
			VECFIG->Dibujar(g);
			lblMstrArea->Text = Convert::ToString((3.1416 * rd));
			//lblMstrarAreaizq
		}
		else if (selectedFigura == "Cuadrado")
		{
			double lado1 = Double::Parse(txbxLado1->Text);
			CCuadrado* Cuad = new CCuadrado(lado1, x, y);
			VECFIG->AgregarFigura(Cuad);
			VECFIG->Dibujar(g);
			lblMstrAreaDerecha->Text = Convert::ToString(lado1 * lado1);
			//lblAreaDerecha
		}
		else if (selectedFigura == "Rectangulo")
		{
			double Altura = Double::Parse(txbxLado1->Text);
			double Base = Double::Parse(txbxLado2->Text);
			CRectangulo* Rect = new CRectangulo(x,y,Base,Altura);
			VECFIG->AgregarFigura(Rect);
			VECFIG->Dibujar(g);
			lblMstrAreaDerecha->Text = Convert::ToString(Base*Altura);
		}
		else if (selectedFigura == "Elipse")
		{
			double SemiEjeA = Double::Parse(txbxLado1->Text);
			double SemiEjeB = Double::Parse(txbxLado2->Text);
			CElipse* Elips = new CElipse(x, y, SemiEjeA, SemiEjeB);
			VECFIG->AgregarFigura(Elips);
			VECFIG->Dibujar(g);
			lblMstrAreaDerecha->Text = Convert::ToString(3.1415* SemiEjeA * SemiEjeB);
		}
		
	}
	Void label1_Click(Object^ sender, EventArgs^ e) 
	{

	}
	Void textBox1_TextChanged(Object^ sender, EventArgs^ e) 
	{
		
	}

	Void comboBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) 
	{
		String^ selectedFigura = cmbxElegirFigura->SelectedItem->ToString();

		lblLado2->Enabled = true;
		txbxLado2->Enabled = true;


		if(selectedFigura == "Circulo")
		{
			//selectedFigura += "";
			//lblCuadrado_Rectangulo->Text = "";
			lblRadio->Enabled = true;
			txbxRad->Enabled = true;

			//lblLado1->Text = "Radio";
			lblLado1->Enabled = false;  // Desactivar Lado1 para Círculo
			lblLado2->Enabled = false;
			txbxLado1->Enabled = false;
			txbxLado2->Enabled = false;
		}
		else if (selectedFigura == "Cuadrado")
		{
			//selectedFigura += "";
			lblCuadrado_Rectangulo->Text = "Cuadrado";
			lblLado1->Text = "Lado";
			lblLado2->Text = "";
			lblLado1->Enabled = true;
			txbxLado1->Enabled = true;

			lblLado2->Enabled = false;
			txbxLado2->Enabled = false;
		}
		else if (selectedFigura == "Rectangulo")
		{
			lblCuadrado_Rectangulo->Text = "Rectangulo";
			//selectedFigura += "";
			lblLado1->Text = "Ancho";
			lblLado2->Text = "Alto";

			lblLado1->Enabled = true;
			lblLado2->Enabled = true;
			txbxLado1->Enabled = true;
			txbxLado2->Enabled = true;
		}
		else if (selectedFigura == "Elipse")
		{
			//selectedFigura += "";
			lblCuadrado_Rectangulo->Text = "Elipse";
			lblLado1->Text = "SemiEje A";
			lblLado2->Text = "SemiEje B";

			lblLado1->Enabled = true;
			lblLado2->Enabled = true;
			txbxLado1->Enabled = true;
			txbxLado2->Enabled = true;
		}

	}

	Void button2_Click(Object^ sender, EventArgs^ e) 
	{
		// Crear una nueva imagen del tamaño del PictureBox y asignar un fondo blanco
		VECFIG->Eliminar();
		Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		Graphics^ g = Graphics::FromImage(bmp);

		g->Clear(Color::White); // Limpiar con color blanco

		pictureBox1->Image = bmp; // Asignar la nueva imagen al PictureBox
		delete g; // Liberar los recursos gráficos


	}
	Void label8_Click(Object^ sender, EventArgs^ e) 
	{

	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void lblLado2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};

}
