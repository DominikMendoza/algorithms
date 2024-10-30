#pragma once
#include "JuegoTortugas.h"

namespace Ejercicio3Semana11 {

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
			imgTortuga = gcnew Bitmap("spriteTortuga.jpg");
			tiempoInicio = clock();
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
			delete imgTortuga;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Juego* juego;
		Bitmap^ imgTortuga;
		clock_t tiempoInicio;
		bool carreraIniciada = false;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1334, 531);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		double segundosTranscurridos = (clock() - tiempoInicio) / (double)CLOCKS_PER_SEC;
		if (!carreraIniciada && segundosTranscurridos < 3.0)
		{
			buffer->Graphics->DrawString("COMENZAMOS!!!", gcnew System::Drawing::Font("Arial", 24), Brushes::Red, PointF(500, 200));
		}
		else
		{
			carreraIniciada = true;
			juego->Iniciar(buffer->Graphics, imgTortuga);
			if (juego->ExisteGanador())
			{
				timer1->Enabled = false;
				MessageBox::Show("Juego Terminado!!");
				Application::Exit();
			}
		}
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	};
}
