#pragma once
#include "Carro.hpp"
#include "FileManager.hpp"
namespace Project95 {

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
		Carro* carro;
		FileManager* fileManager;
		Graphics^ g;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
		Bitmap^ bmpCarro;
		int cntArbolesVerdes, cntArbolesRojos;
	private: System::Windows::Forms::Label^ lblResumen;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, canvas->ClientRectangle);
			bmpCarro = gcnew Bitmap("carro.png");
			carro = new Carro(bmpCarro->Width / 5, bmpCarro->Height / 3);
			fileManager = new FileManager();
			cntArbolesRojos = cntArbolesVerdes = 0;

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
	protected:
	private: System::Windows::Forms::Timer^ timerMain;
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
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->lblResumen = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Controls->Add(this->lblResumen);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(1067, 621);
			this->canvas->TabIndex = 0;
			// 
			// lblResumen
			// 
			this->lblResumen->AutoSize = true;
			this->lblResumen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResumen->Location = System::Drawing::Point(14, 10);
			this->lblResumen->Name = L"lblResumen";
			this->lblResumen->Size = System::Drawing::Size(0, 39);
			this->lblResumen->TabIndex = 0;
			this->lblResumen->Click += gcnew System::EventHandler(this, &MyForm::lblResumen_Click);
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Interval = 150;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1091, 645);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		carro->move(buffer->Graphics);
		carro->draw(buffer->Graphics, bmpCarro);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::P: carro->changeAnimation(0); break;
		case Keys::R: carro->changeAnimation(1); cntArbolesRojos++; break;
		case Keys::V: carro->changeAnimation(2); cntArbolesVerdes++; break;
		case Keys::F: {
			lblResumen->Text = "Cantidad de arboles verdes: " + cntArbolesVerdes.ToString() + "\n" +
				"Cantidad de arboles rojos: " + cntArbolesRojos.ToString();
			fileManager->guardarCantidadDeArboles("arboles.txt", cntArbolesRojos, cntArbolesVerdes);
			break;
		}
		case Keys::A: lblResumen->Text = gcnew String(fileManager->readFile("sample.txt").c_str());
		}
	}
	private: System::Void lblResumen_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
