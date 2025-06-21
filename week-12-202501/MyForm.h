#pragma once
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Ejemplo.h"
namespace Project51 {

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
		Graphics^ g;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
		Bitmap^ bmpPersonaje;
		Bitmap^ bmpEnemigo;
		Personaje* per;
		bool chocaron;
		float segundos;
	private: System::Windows::Forms::Timer^ timer5s;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Button^ btnFormEjemplo;
		   Enemigo* ene;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, this->ClientRectangle);

			bmpPersonaje = gcnew Bitmap("bmps/bruno.png");
			bmpEnemigo = gcnew Bitmap("bmps/rojo.png");

			per = new Personaje(50, 50, bmpPersonaje->Width / 4, bmpPersonaje->Height / 4);
			ene = new Enemigo(300, 120, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);

			chocaron = false;
			segundos = 0.0f;
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
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Label^ lblResultado;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->timer5s = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->btnFormEjemplo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResultado->ForeColor = System::Drawing::Color::Maroon;
			this->lblResultado->Location = System::Drawing::Point(257, 324);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(69, 39);
			this->lblResultado->TabIndex = 0;
			this->lblResultado->Text = L"----";
			this->lblResultado->Visible = false;
			// 
			// timer5s
			// 
			this->timer5s->Enabled = true;
			this->timer5s->Interval = 5000;
			this->timer5s->Tick += gcnew System::EventHandler(this, &MyForm::timer5s_Tick);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(949, 36);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(74, 18);
			this->lblTiempo->TabIndex = 1;
			this->lblTiempo->Text = L"Tiempo: ";
			// 
			// btnFormEjemplo
			// 
			this->btnFormEjemplo->Location = System::Drawing::Point(572, 255);
			this->btnFormEjemplo->Name = L"btnFormEjemplo";
			this->btnFormEjemplo->Size = System::Drawing::Size(75, 23);
			this->btnFormEjemplo->TabIndex = 2;
			this->btnFormEjemplo->Text = L"Abrir otro form";
			this->btnFormEjemplo->UseVisualStyleBackColor = true;
			this->btnFormEjemplo->Click += gcnew System::EventHandler(this, &MyForm::btnFormEjemplo_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1099, 787);
			this->Controls->Add(this->btnFormEjemplo);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->lblResultado);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);

		ene->mover(buffer->Graphics, 'x');

		if (per->estaColisionandoCon(ene)) {
			chocaron = true;
		}

		ene->dibujar(buffer->Graphics, bmpEnemigo);
		per->dibujar(buffer->Graphics, bmpPersonaje);

		segundos += 0.1;
		lblTiempo->Text = "Tiempo: " + Convert::ToString(Convert::ToInt32(5 - segundos));
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W:
		case Keys::Up:
		{
			per->mover(buffer->Graphics, 'W');
			break;
		}

		case Keys::A:
		case Keys::Left:
		{
			per->mover(buffer->Graphics, 'A');
			break;
		}

		case Keys::S:
		case Keys::Down:
		{
			per->mover(buffer->Graphics, 'S');
			break;
		}

		case Keys::D:
		case Keys::Right:
		{
			per->mover(buffer->Graphics, 'D');
			break;
		}
		}
	}
	private: System::Void timer5s_Tick(System::Object^ sender, System::EventArgs^ e) {
		timerMain->Enabled = false;
		lblTiempo->Text = "Tiempo: 0";
		buffer->Graphics->Clear(Color::WhiteSmoke);

		if (chocaron) {
			lblResultado->Text = "Jugador gano!!!";
		}
		else {
			lblResultado->Text = "Perdiste :c";
		}

		lblResultado->Visible = true;
		buffer->Render(g);
	}

private: System::Void btnFormEjemplo_Click(System::Object^ sender, System::EventArgs^ e) {
	Ejemplo^ formEjemplo = gcnew Ejemplo();
	this->Hide();
	formEjemplo->ShowDialog();
	this->Show();
	delete formEjemplo;
}
};
}
