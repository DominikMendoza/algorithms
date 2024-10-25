#pragma once
#include "Hulk.hpp"
namespace Project83 {

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
		Hulk* hulk;
	private: System::Windows::Forms::Timer^ timenMain;
		   Bitmap^ bmpHulk;
	private: System::Windows::Forms::Label^ lblZona;
		   Bitmap^ bmpFondo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, canvas->ClientRectangle);
			bmpHulk = gcnew Bitmap("bmps/hulk.png");
			bmpHulk->MakeTransparent(bmpHulk->GetPixel(0, 0));
			bmpFondo = gcnew Bitmap("bmps/selva.png");
			hulk = new Hulk(bmpHulk->Width / 4, bmpHulk->Height / 4);
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
			this->timenMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblZona = (gcnew System::Windows::Forms::Label());
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::BurlyWood;
			this->canvas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->canvas->Controls->Add(this->lblZona);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(1075, 660);
			this->canvas->TabIndex = 0;
			// 
			// timenMain
			// 
			this->timenMain->Enabled = true;
			this->timenMain->Tick += gcnew System::EventHandler(this, &MyForm::timenMain_Tick);
			// 
			// lblZona
			// 
			this->lblZona->AutoSize = true;
			this->lblZona->BackColor = System::Drawing::Color::Red;
			this->lblZona->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblZona->Location = System::Drawing::Point(228, 27);
			this->lblZona->Name = L"lblZona";
			this->lblZona->Size = System::Drawing::Size(701, 108);
			this->lblZona->TabIndex = 0;
			this->lblZona->Text = L"Zona Peligrosa";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1099, 684);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timenMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//g->Clear(Color::Brown);
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, canvas->Width, canvas->Height);
		Pen^ pencil = gcnew Pen(Color::Yellow, 3);
		buffer->Graphics->DrawLine(pencil,
			canvas->ClientRectangle.Width / 2, 0,
			canvas->ClientRectangle.Width / 2, canvas->ClientRectangle.Height);
		hulk->draw(buffer->Graphics, bmpHulk);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			hulk->move(buffer->Graphics, 'W'); break;
		case Keys::S:
			hulk->move(buffer->Graphics, 'S'); break;
		case Keys::A:
			hulk->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			hulk->move(buffer->Graphics, 'D'); break;

		default:
			break;
		}
		if (hulk->getXMasAncho() > canvas->ClientRectangle.Width / 2) {
			lblZona->Text = "Zona Segura";
			lblZona->BackColor = Color::Green;
		}
		else {
			lblZona->Text = "Zona Peligrosa";
			lblZona->BackColor = Color::Red;
		}

	}
	};
}
