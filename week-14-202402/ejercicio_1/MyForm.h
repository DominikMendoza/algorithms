#pragma once
#include "Controller.hpp"
namespace Project4 {

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
		Graphics^ g;
		BufferedGraphicsContext^ context;
		Controller* ctrl;
		Bitmap^ bmpDisco;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Timer^ crono;
	public:
		BufferedGraphics^ buffer;
		MyForm(void)
		{
			InitializeComponent();
			srand(time(nullptr));
			g = panel1->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bmpDisco = gcnew Bitmap("discos.png");
			bmpDisco->MakeTransparent(bmpDisco->GetPixel(0, 0));
			buffer = context->Allocate(g, panel1->ClientRectangle);
			ctrl = new Controller(bmpDisco);
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->crono = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblTiempo);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(860, 568);
			this->panel1->TabIndex = 0;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(657, 15);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// crono
			// 
			this->crono->Enabled = true;
			this->crono->Interval = 1000;
			this->crono->Tick += gcnew System::EventHandler(this, &MyForm::crono_Tick);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(809, 83);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(35, 13);
			this->lblTiempo->TabIndex = 1;
			this->lblTiempo->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 592);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		lblVidas->Text = ctrl->getPersonaje()->getVidas().ToString();
		ctrl->moverTodo(buffer->Graphics);
		ctrl->validarColisiones();
		ctrl->dibujar(buffer->Graphics, bmpDisco);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			ctrl->getPersonaje()->movimientoControlado(buffer->Graphics, 'W'); break;
		case Keys::S:
			ctrl->getPersonaje()->movimientoControlado(buffer->Graphics, 'S'); break;
		case Keys::A:
			ctrl->getPersonaje()->movimientoControlado(buffer->Graphics, 'A'); break;
		case Keys::D:
			ctrl->getPersonaje()->movimientoControlado(buffer->Graphics, 'D'); break;

		default:
			break;
		}
	}
	private: System::Void crono_Tick(System::Object^ sender, System::EventArgs^ e) {
		ctrl->disminuirTime();
		lblTiempo->Text = ctrl->getTime().ToString();
	}
};
}
