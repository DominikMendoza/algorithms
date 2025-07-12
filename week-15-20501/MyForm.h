#pragma once
#include "Controladora.hpp"
namespace Project59 {

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
		Controladora* ctrl;
		Graphics^ g;
		BufferedGraphics^ bf;
		BufferedGraphicsContext^ ctx;
		Bitmap^ bmpZoo;
		Bitmap^ bmpPlanta;
		Bitmap^ bmpBloque;
	private: System::Windows::Forms::Label^ lblVidas;
		   Bitmap^ bmpFondo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = panel->CreateGraphics();
			ctx = BufferedGraphicsManager::Current;
			bf = ctx->Allocate(g, panel->ClientRectangle);
			bmpZoo = gcnew Bitmap("bmps/zoombie.png");
			bmpPlanta = gcnew Bitmap("bmps/plantas.png");
			// bmpPlanta->MakeTransparent(bmpPlanta->GetPixel(0, 0));
			bmpBloque = gcnew Bitmap("bmps/bloque.png");
			// bmpBloque->MakeTransparent(bmpBloque->GetPixel(0, 0));
			bmpFondo = gcnew Bitmap("bmps/fondo.png");
			ctrl = new Controladora(bmpZoo, bmpPlanta, bmpBloque);
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
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Timer^ timer;
	protected:

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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Controls->Add(this->lblVidas);
			this->panel->Location = System::Drawing::Point(12, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(1017, 765);
			this->panel->TabIndex = 0;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::Peru;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblVidas->Location = System::Drawing::Point(667, 15);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(52, 39);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"V:";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 789);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		ctrl->moverObjetos(bf->Graphics);
		ctrl->evaluarColisiones();
		lblVidas->Text = "Vidas: " + Convert::ToString(ctrl->getZoombie()->getVidas());
		ctrl->dibujarObjetos(bf->Graphics, bmpZoo, bmpPlanta, bmpBloque, bmpFondo);
		bf->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W:
		case Keys::Up:
		{
			ctrl->getZoombie()->mover(bf->Graphics, 'W');
			break;
		}

		case Keys::A:
		case Keys::Left:
		{
			ctrl->getZoombie()->mover(bf->Graphics, 'A');
			break;
		}

		case Keys::S:
		case Keys::Down:
		{
			ctrl->getZoombie()->mover(bf->Graphics, 'S');
			break;
		}

		case Keys::D:
		case Keys::Right:
		{
			ctrl->getZoombie()->mover(bf->Graphics, 'D');
			break;
		}
		}
	}
	};
}
