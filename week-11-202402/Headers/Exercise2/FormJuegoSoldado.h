#pragma once
#include "JuegoSoldado.h"

namespace Ejercicio2Semana11 {

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
			juego = new Juego();
			imgSoldado = gcnew Bitmap("spriteSoldado.png");
			imgBomba = gcnew Bitmap("bomba.png");
			imgFrutas = gcnew Bitmap("spriteFrutas.png");
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
			delete juego;
			delete imgSoldado;
			delete imgBomba;
			delete imgFrutas;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Juego* juego;
		Bitmap^ imgSoldado;
		Bitmap^ imgBomba;
		Bitmap^ imgFrutas;
	private: System::Windows::Forms::Label^ lblvidas;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblvidas = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 50;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // lblvidas
			   // 
			   this->lblvidas->AutoSize = true;
			   this->lblvidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblvidas->Location = System::Drawing::Point(874, 9);
			   this->lblvidas->Name = L"lblvidas";
			   this->lblvidas->Size = System::Drawing::Size(98, 25);
			   this->lblvidas->TabIndex = 1;
			   this->lblvidas->Text = L"Vidas: 3";
			   this->lblvidas->Click += gcnew System::EventHandler(this, &MyForm::lblvidas_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(984, 528);
			   this->Controls->Add(this->lblvidas);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		juego->Iniciar(buffer->Graphics, imgSoldado, imgBomba, imgFrutas);
		lblvidas->Text = "Vidas: " + juego->getSoldado()->getVidas();
		if (juego->Perdiste())
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste el juego!!");
			Application::Exit();
		}
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left: juego->getSoldado()->setTecla(Izquierda); break;
		case Keys::Right: juego->getSoldado()->setTecla(Derecha); break;
		case Keys::Up: juego->getSoldado()->setTecla(Arriba); break;
		case Keys::Down: juego->getSoldado()->setTecla(Abajo); break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->getSoldado()->setTecla(Ninguno);
	}
	private: System::Void lblvidas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
