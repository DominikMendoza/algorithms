#pragma once
#include "JuegoHulk.h"

namespace Ejercicio1Semana11 {

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
			imgHulk = gcnew Bitmap("spriteHulk.png");
		}
		void UpdateZona()
		{
			// Texto y color de fondo
			int x = juego->getHulk()->getX();
			if (x > 450)
			{
				this->lblTextZona->Text = "Zona Segura";
				this->BackColor = System::Drawing::Color::Green;
			}
			else if (x < 450)
			{
				this->lblTextZona->Text = "Zona Peligrosa";
				this->BackColor = System::Drawing::Color::Red;
			}
			else
			{
				this->lblTextZona->Text = "Zona Intermedia";
				this->BackColor = System::Drawing::Color::LightBlue;
			}
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
			delete imgHulk;
		}

	private:
		Juego* juego;
		Bitmap^ imgHulk;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblTextZona;



	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblTextZona = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 10;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // lblTextZona
			   // 
			   this->lblTextZona->AutoSize = true;
			   this->lblTextZona->BackColor = System::Drawing::Color::Transparent;
			   this->lblTextZona->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblTextZona->Location = System::Drawing::Point(419, 17);
			   this->lblTextZona->Name = L"lblTextZona";
			   this->lblTextZona->Size = System::Drawing::Size(167, 25);
			   this->lblTextZona->TabIndex = 2;
			   this->lblTextZona->Text = L"Zona Intermedia";
			   this->lblTextZona->Click += gcnew System::EventHandler(this, &MyForm::lblTextZona_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(984, 525);
			   this->Controls->Add(this->lblTextZona);
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
		juego->Iniciar(buffer->Graphics, imgHulk);
		UpdateZona();
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:juego->getHulk()->setTecla(Izquierda); break;
		case Keys::Right:juego->getHulk()->setTecla(Derecha); break;
		case Keys::Up:juego->getHulk()->setTecla(Arriba); break;
		case Keys::Down:juego->getHulk()->setTecla(Abajo); break;
		default: break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->getHulk()->setTecla(Ninguno);
	}
	private: System::Void lblTextZona_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
