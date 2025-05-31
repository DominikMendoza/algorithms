#pragma once
#include "Rectangulo.hpp"
#include "Elipse.hpp"

namespace Project34 {

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
	private:
		Graphics^ graph;
	public:
		MyForm(void)
		{
			InitializeComponent();
			graph = canvas->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cBElegirFigura;
	protected:

	private: System::Windows::Forms::Label^ lblElegirFigura;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ bttnDibujar;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ tBPosY;
	private: System::Windows::Forms::TextBox^ tBPosX;
	private: System::Windows::Forms::Label^ lblPosY;
	private: System::Windows::Forms::Label^ lblPosX;

	private: System::Windows::Forms::Label^ lblAreaRectangulo;


	private: System::Windows::Forms::GroupBox^ gBRectangulo;
	private: System::Windows::Forms::Label^ lblArea;
	private: System::Windows::Forms::TextBox^ tBLado2;


	private: System::Windows::Forms::TextBox^ tBLado1;
	private: System::Windows::Forms::Label^ lblLado2;
	private: System::Windows::Forms::Label^ lblLado1;
	private: System::Windows::Forms::Panel^ canvas;
	private: System::Windows::Forms::GroupBox^ gBElipse;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblAreaElipse;

	private: System::Windows::Forms::TextBox^ tBRadio;
	private: System::Windows::Forms::Label^ lblRadio;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cBElegirFigura = (gcnew System::Windows::Forms::ComboBox());
			this->lblElegirFigura = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bttnDibujar = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tBPosY = (gcnew System::Windows::Forms::TextBox());
			this->tBPosX = (gcnew System::Windows::Forms::TextBox());
			this->lblPosY = (gcnew System::Windows::Forms::Label());
			this->lblPosX = (gcnew System::Windows::Forms::Label());
			this->lblAreaRectangulo = (gcnew System::Windows::Forms::Label());
			this->gBRectangulo = (gcnew System::Windows::Forms::GroupBox());
			this->lblArea = (gcnew System::Windows::Forms::Label());
			this->tBLado2 = (gcnew System::Windows::Forms::TextBox());
			this->tBLado1 = (gcnew System::Windows::Forms::TextBox());
			this->lblLado2 = (gcnew System::Windows::Forms::Label());
			this->lblLado1 = (gcnew System::Windows::Forms::Label());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->gBElipse = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblAreaElipse = (gcnew System::Windows::Forms::Label());
			this->tBRadio = (gcnew System::Windows::Forms::TextBox());
			this->lblRadio = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->gBRectangulo->SuspendLayout();
			this->gBElipse->SuspendLayout();
			this->SuspendLayout();
			// 
			// cBElegirFigura
			// 
			this->cBElegirFigura->FormattingEnabled = true;
			this->cBElegirFigura->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Elipse", L"Rectangulo" });
			this->cBElegirFigura->Location = System::Drawing::Point(184, 39);
			this->cBElegirFigura->Name = L"cBElegirFigura";
			this->cBElegirFigura->Size = System::Drawing::Size(182, 21);
			this->cBElegirFigura->TabIndex = 0;
			this->cBElegirFigura->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::cBElegirFigura_SelectedValueChanged);
			// 
			// lblElegirFigura
			// 
			this->lblElegirFigura->AutoSize = true;
			this->lblElegirFigura->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblElegirFigura->Location = System::Drawing::Point(19, 31);
			this->lblElegirFigura->Name = L"lblElegirFigura";
			this->lblElegirFigura->Size = System::Drawing::Size(143, 29);
			this->lblElegirFigura->TabIndex = 1;
			this->lblElegirFigura->Text = L"Elegir figura";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->bttnDibujar);
			this->groupBox1->Controls->Add(this->lblElegirFigura);
			this->groupBox1->Controls->Add(this->cBElegirFigura);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1148, 91);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// bttnDibujar
			// 
			this->bttnDibujar->Enabled = false;
			this->bttnDibujar->Location = System::Drawing::Point(424, 35);
			this->bttnDibujar->Name = L"bttnDibujar";
			this->bttnDibujar->Size = System::Drawing::Size(718, 29);
			this->bttnDibujar->TabIndex = 2;
			this->bttnDibujar->Text = L"Dibujar";
			this->bttnDibujar->UseVisualStyleBackColor = true;
			this->bttnDibujar->Click += gcnew System::EventHandler(this, &MyForm::bttnDibujar_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tBPosY);
			this->groupBox2->Controls->Add(this->tBPosX);
			this->groupBox2->Controls->Add(this->lblPosY);
			this->groupBox2->Controls->Add(this->lblPosX);
			this->groupBox2->Location = System::Drawing::Point(12, 119);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(366, 154);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Posicion Inicial";
			// 
			// tBPosY
			// 
			this->tBPosY->Location = System::Drawing::Point(139, 90);
			this->tBPosY->Name = L"tBPosY";
			this->tBPosY->Size = System::Drawing::Size(100, 20);
			this->tBPosY->TabIndex = 3;
			this->tBPosY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tBPosY_KeyPress);
			// 
			// tBPosX
			// 
			this->tBPosX->Location = System::Drawing::Point(139, 37);
			this->tBPosX->Name = L"tBPosX";
			this->tBPosX->Size = System::Drawing::Size(100, 20);
			this->tBPosX->TabIndex = 2;
			this->tBPosX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tBPosX_KeyPress);
			// 
			// lblPosY
			// 
			this->lblPosY->AutoSize = true;
			this->lblPosY->Location = System::Drawing::Point(21, 93);
			this->lblPosY->Name = L"lblPosY";
			this->lblPosY->Size = System::Drawing::Size(72, 13);
			this->lblPosY->TabIndex = 1;
			this->lblPosY->Text = L"Posicion en Y";
			// 
			// lblPosX
			// 
			this->lblPosX->AutoSize = true;
			this->lblPosX->Location = System::Drawing::Point(21, 40);
			this->lblPosX->Name = L"lblPosX";
			this->lblPosX->Size = System::Drawing::Size(72, 13);
			this->lblPosX->TabIndex = 0;
			this->lblPosX->Text = L"Posicion en X";
			// 
			// lblAreaRectangulo
			// 
			this->lblAreaRectangulo->AutoSize = true;
			this->lblAreaRectangulo->Location = System::Drawing::Point(145, 122);
			this->lblAreaRectangulo->Name = L"lblAreaRectangulo";
			this->lblAreaRectangulo->Size = System::Drawing::Size(100, 13);
			this->lblAreaRectangulo->TabIndex = 6;
			this->lblAreaRectangulo->Text = L"Mostrar el area aqui";
			// 
			// gBRectangulo
			// 
			this->gBRectangulo->Controls->Add(this->lblArea);
			this->gBRectangulo->Controls->Add(this->tBLado2);
			this->gBRectangulo->Controls->Add(this->lblAreaRectangulo);
			this->gBRectangulo->Controls->Add(this->tBLado1);
			this->gBRectangulo->Controls->Add(this->lblLado2);
			this->gBRectangulo->Controls->Add(this->lblLado1);
			this->gBRectangulo->Enabled = false;
			this->gBRectangulo->Location = System::Drawing::Point(788, 119);
			this->gBRectangulo->Name = L"gBRectangulo";
			this->gBRectangulo->Size = System::Drawing::Size(366, 154);
			this->gBRectangulo->TabIndex = 4;
			this->gBRectangulo->TabStop = false;
			this->gBRectangulo->Text = L"Rectangulo";
			// 
			// lblArea
			// 
			this->lblArea->AutoSize = true;
			this->lblArea->Location = System::Drawing::Point(21, 122);
			this->lblArea->Name = L"lblArea";
			this->lblArea->Size = System::Drawing::Size(29, 13);
			this->lblArea->TabIndex = 7;
			this->lblArea->Text = L"Area";
			// 
			// tBLado2
			// 
			this->tBLado2->Location = System::Drawing::Point(139, 62);
			this->tBLado2->Name = L"tBLado2";
			this->tBLado2->Size = System::Drawing::Size(100, 20);
			this->tBLado2->TabIndex = 3;
			this->tBLado2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tBLado2_KeyPress);
			// 
			// tBLado1
			// 
			this->tBLado1->Location = System::Drawing::Point(139, 19);
			this->tBLado1->Name = L"tBLado1";
			this->tBLado1->Size = System::Drawing::Size(100, 20);
			this->tBLado1->TabIndex = 2;
			this->tBLado1->TextChanged += gcnew System::EventHandler(this, &MyForm::tBLado1_TextChanged);
			this->tBLado1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tBLado1_KeyPress);
			// 
			// lblLado2
			// 
			this->lblLado2->AutoSize = true;
			this->lblLado2->Location = System::Drawing::Point(21, 65);
			this->lblLado2->Name = L"lblLado2";
			this->lblLado2->Size = System::Drawing::Size(40, 13);
			this->lblLado2->TabIndex = 1;
			this->lblLado2->Text = L"Lado 2";
			// 
			// lblLado1
			// 
			this->lblLado1->AutoSize = true;
			this->lblLado1->Location = System::Drawing::Point(21, 19);
			this->lblLado1->Name = L"lblLado1";
			this->lblLado1->Size = System::Drawing::Size(40, 13);
			this->lblLado1->TabIndex = 0;
			this->lblLado1->Text = L"Lado 1";
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 279);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(1142, 436);
			this->canvas->TabIndex = 5;
			// 
			// gBElipse
			// 
			this->gBElipse->Controls->Add(this->label1);
			this->gBElipse->Controls->Add(this->lblAreaElipse);
			this->gBElipse->Controls->Add(this->tBRadio);
			this->gBElipse->Controls->Add(this->lblRadio);
			this->gBElipse->Enabled = false;
			this->gBElipse->Location = System::Drawing::Point(407, 119);
			this->gBElipse->Name = L"gBElipse";
			this->gBElipse->Size = System::Drawing::Size(366, 154);
			this->gBElipse->TabIndex = 8;
			this->gBElipse->TabStop = false;
			this->gBElipse->Text = L"Elipse";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 122);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Area";
			// 
			// lblAreaElipse
			// 
			this->lblAreaElipse->AutoSize = true;
			this->lblAreaElipse->Location = System::Drawing::Point(154, 122);
			this->lblAreaElipse->Name = L"lblAreaElipse";
			this->lblAreaElipse->Size = System::Drawing::Size(100, 13);
			this->lblAreaElipse->TabIndex = 6;
			this->lblAreaElipse->Text = L"Mostrar el area aqui";
			// 
			// tBRadio
			// 
			this->tBRadio->Location = System::Drawing::Point(145, 58);
			this->tBRadio->Name = L"tBRadio";
			this->tBRadio->Size = System::Drawing::Size(100, 20);
			this->tBRadio->TabIndex = 2;
			this->tBRadio->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tBRadio_KeyPress);
			// 
			// lblRadio
			// 
			this->lblRadio->AutoSize = true;
			this->lblRadio->Location = System::Drawing::Point(27, 58);
			this->lblRadio->Name = L"lblRadio";
			this->lblRadio->Size = System::Drawing::Size(35, 13);
			this->lblRadio->TabIndex = 0;
			this->lblRadio->Text = L"Radio";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1172, 727);
			this->Controls->Add(this->gBElipse);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->gBRectangulo);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->gBRectangulo->ResumeLayout(false);
			this->gBRectangulo->PerformLayout();
			this->gBElipse->ResumeLayout(false);
			this->gBElipse->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bttnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
		// graph->Clear(Color::WhiteSmoke);
		if (!ValidateInputs()) return;

		int posX = Convert::ToInt32(tBPosX->Text);
		int posY = Convert::ToInt32(tBPosY->Text);
		
		Figura* fig;
		if (cBElegirFigura->Text == "Elipse") {
			int radio = Convert::ToInt32(tBRadio->Text);
			fig = new Elipse(posX, posY, radio);
			lblAreaElipse->Text = Convert::ToString(fig->getArea());
		}
		if (cBElegirFigura->Text == "Rectangulo") {
			int lado1 = Convert::ToInt32(tBLado1->Text);
			int lado2 = Convert::ToInt32(tBLado2->Text);
			fig = new Rectangulo(posX, posY, lado1, lado2);
			lblAreaRectangulo->Text = Convert::ToString(fig->getArea());
		}
		fig->dibujar(graph);
		delete fig;
	}
	private: bool ValidateInputs() {
		if (String::IsNullOrEmpty(tBPosX->Text) || String::IsNullOrEmpty(tBPosY->Text)) {
			MessageBox::Show("Please enter x and y.", "Input Error");
			return false;
		}

		if (cBElegirFigura->Text == "Elipse") {
			if (String::IsNullOrEmpty(tBRadio->Text)) {
				MessageBox::Show("Please enter radius for ellipse.", "Input Error");
				return false;
			}
		}
		else if (cBElegirFigura->Text == "Rectangulo") {
			if (String::IsNullOrEmpty(tBLado1->Text) || String::IsNullOrEmpty(tBLado2->Text)) {
				MessageBox::Show("Please enter both sides for rectangle.", "Input Error");
				return false;
			}
		}

		return true;
	}
	private: System::Void cBElegirFigura_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
		bttnDibujar->Enabled = true;
		if (cBElegirFigura->Text == "Elipse") {
			gBElipse->Enabled = true;
			gBRectangulo->Enabled = false;
		}
		if (cBElegirFigura->Text == "Rectangulo") {
			gBRectangulo->Enabled = true;
			gBElipse->Enabled = false;
		}
	}
	private: System::Void tBPosX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Si no es un digito o tecla de borrar
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void tBPosY_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void tBRadio_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void tBLado1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tBLado1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void tBLado2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
};
}
