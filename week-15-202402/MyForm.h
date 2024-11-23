#pragma once
#include "FileManager.hpp"
#include "Controller.hpp"
namespace Project8 {

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
		Bitmap^ bmpAvion;
		Bitmap^ bmpBala;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpFondo1;
		Bitmap^ bmpFondo2;
		Bitmap^ bmpFondo;
		Graphics^ g;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
		FileManager* fm;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Label^ lblDespedida;
		   Controller* ctrl;
	public:
		MyForm(void)
		{
			InitializeComponent();
			bmpAvion = gcnew Bitmap("bmps/girasol.png");
			bmpBala = gcnew Bitmap("bmps/tumba.png");
			bmpEnemigo = gcnew Bitmap("bmps/mounstro.png");
			bmpFondo1 = gcnew Bitmap("bmps/fondo1.png");
			bmpFondo2 = gcnew Bitmap("bmps/fondo2.png");
			bmpFondo = bmpFondo1;

			bmpAvion->MakeTransparent(bmpAvion->GetPixel(0, 0));
			bmpBala->MakeTransparent(bmpBala->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(5, 5));
			g = panel1->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, panel1->ClientRectangle);
			ctrl = new Controller(buffer->Graphics, bmpAvion->Width, bmpAvion->Height, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);
			fm = new FileManager();
			//
			//TODO: agregar código de constructor aquí
			//
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

	protected:
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
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
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblDespedida = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblDespedida);
			this->panel1->Controls->Add(this->lblPuntos);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1008, 653);
			this->panel1->TabIndex = 1;
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntos->Location = System::Drawing::Point(0, 0);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(268, 73);
			this->lblPuntos->TabIndex = 1;
			this->lblPuntos->Text = L"Puntos: ";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->Location = System::Drawing::Point(644, -3);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(337, 108);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"Vidas: ";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// lblDespedida
			// 
			this->lblDespedida->AutoSize = true;
			this->lblDespedida->Font = (gcnew System::Drawing::Font(L"MV Boli", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDespedida->ForeColor = System::Drawing::Color::Red;
			this->lblDespedida->Location = System::Drawing::Point(204, 400);
			this->lblDespedida->Name = L"lblDespedida";
			this->lblDespedida->Size = System::Drawing::Size(582, 82);
			this->lblDespedida->TabIndex = 2;
			this->lblDespedida->Text = L"Juego terminado, los resultados se\r\nguardaron en \"resultados.txt\"";
			this->lblDespedida->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 677);
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
		//buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpFondo, panel1->ClientRectangle);
		ctrl->moverTodos(buffer->Graphics);
		ctrl->evaluarColisiones();
		ctrl->dibujarTodos(buffer->Graphics, bmpBala, bmpEnemigo, bmpAvion);
		lblVidas->Text = "Vidas: " + ctrl->getVidasAvion().ToString();
		lblPuntos->Text = "Puntos: " + ctrl->getPuntos().ToString();
		if (ctrl->getPuntos() > 100) {
			fm->saveInTxt("resultados.txt", "Los puntos fueron: " + to_string(ctrl->getPuntos()));
			timer1->Enabled = false;
			timer2->Enabled = false;
			buffer->Graphics->Clear(Color::WhiteSmoke);
			lblDespedida->Visible = true;
			lblVidas->Visible = false;
			lblPuntos->Visible = false;
		}
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			ctrl->moverAvion(buffer->Graphics, 'W'); break;
		case Keys::S:
			ctrl->moverAvion(buffer->Graphics, 'S'); break;
		case Keys::A:
			ctrl->moverAvion(buffer->Graphics, 'A'); break;
		case Keys::D:
			ctrl->moverAvion(buffer->Graphics, 'D'); break;
		case Keys::P:
			ctrl->agregarBala(bmpBala->Width, bmpBala->Height); break;
		case Keys::O:
			if (bmpFondo != bmpFondo1) {
				bmpFondo = bmpFondo1;
			}
			else {
				bmpFondo = bmpFondo2;
			}
		default:
			break;
		}
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	ctrl->agregarEnemigo(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);
}
};
	
}
