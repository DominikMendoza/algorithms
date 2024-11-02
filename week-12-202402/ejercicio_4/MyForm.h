#pragma once
#include "Controller.hpp"
namespace Project88 {

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
		Bitmap^ bmpPrincesa;
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Label^ lblResumen;

		   Controller* controller;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, canvas->ClientRectangle);
			bmpPrincesa = gcnew Bitmap("princesas.png");
			controller = new Controller(100, 100, bmpPrincesa->Width / 5, bmpPrincesa->Height / 4);
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
	private: System::Windows::Forms::Panel^ canvas;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->lblResumen = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::Transparent;
			this->canvas->Controls->Add(this->lblResumen);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(814, 529);
			this->canvas->TabIndex = 0;
			// 
			// lblResumen
			// 
			this->lblResumen->AutoSize = true;
			this->lblResumen->BackColor = System::Drawing::Color::Transparent;
			this->lblResumen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResumen->Location = System::Drawing::Point(473, 11);
			this->lblResumen->Name = L"lblResumen";
			this->lblResumen->Size = System::Drawing::Size(324, 33);
			this->lblResumen->TabIndex = 0;
			this->lblResumen->Text = L"Se asustaron: 3 veces";
			this->lblResumen->Visible = false;
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(838, 553);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//buffer->Graphics->Clear(Color::WhiteSmoke);
		controller->move();
		controller->draw(buffer->Graphics, bmpPrincesa);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			controller->setAnimation(true);
			lblResumen->Visible = false;
			break;
		case Keys::F:
			controller->setAnimation(false);
			lblResumen->Visible = true;
			lblResumen->Text = "Se asustaron: " + controller->getCnt().ToString() + " veces";
			//this->lblResumen->BackColor = System::Drawing::Color::Transparent;
			controller->restore(); break;
		default:
			break;
		}
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		this->canvas->Location = System::Drawing::Point(0, 0);
		this->canvas->Size = System::Drawing::Size(this->Size.Width, this->Size.Height);
		buffer = context->Allocate(g, canvas->ClientRectangle);
	}
};
}
