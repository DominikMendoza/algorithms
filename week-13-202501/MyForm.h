#pragma once
#include "Carro.hpp"
#include "FileManager.hpp"
namespace Project54 {

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
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ context;
		Bitmap^ bmpCarro;
		Carro* car;
		FileManager* fm;
		int cntArbolesRojos, cntArbolesVerdes;
		int cntFrames;
	private: System::Windows::Forms::Button^ btnFinish;
	private: System::Windows::Forms::Label^ lblArboles;
		   char movimiento;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Focus();
			this->KeyPreview = true;
			g = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, this->ClientRectangle);
			bmpCarro = gcnew Bitmap("sprites/rojo.png");
			bmpCarro->MakeTransparent(bmpCarro->GetPixel(0, 0));
			int width = bmpCarro->Width / 4;
			int height = bmpCarro->Height / 4;
			car = new Carro((this->Width - width) / 2, (this->Height - height) / 2,
				width, height);
			movimiento = 'P';
			fm = new FileManager();
			cntArbolesRojos = cntArbolesVerdes = cntFrames = 0;
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
		}
	private: System::Windows::Forms::Timer^ timer;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnFinish = (gcnew System::Windows::Forms::Button());
			this->lblArboles = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// btnFinish
			// 
			this->btnFinish->Location = System::Drawing::Point(802, 12);
			this->btnFinish->Name = L"btnFinish";
			this->btnFinish->Size = System::Drawing::Size(162, 50);
			this->btnFinish->TabIndex = 0;
			this->btnFinish->Text = L"Save";
			this->btnFinish->UseVisualStyleBackColor = true;
			this->btnFinish->Click += gcnew System::EventHandler(this, &MyForm::btnFinish_Click);
			// 
			// lblArboles
			// 
			this->lblArboles->AutoSize = true;
			this->lblArboles->Location = System::Drawing::Point(262, 12);
			this->lblArboles->Name = L"lblArboles";
			this->lblArboles->Size = System::Drawing::Size(42, 13);
			this->lblArboles->TabIndex = 1;
			this->lblArboles->Text = L"Arboles";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(976, 497);
			this->Controls->Add(this->lblArboles);
			this->Controls->Add(this->btnFinish);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		cntFrames++;
		buffer->Graphics->Clear(Color::WhiteSmoke);
		car->mover(buffer->Graphics, movimiento);
		car->dibujar(buffer->Graphics, bmpCarro);
		if (cntFrames == 4) {
			if (movimiento == 'R')
				cntArbolesRojos++;
			if (movimiento == 'V')
				cntArbolesVerdes++;
			cntFrames = 0;
		}
		lblArboles->Text = "Arboles rojos: " + Convert::ToString(cntArbolesRojos) + " " +
			"Arboles verdes: " + Convert::ToString(cntArbolesVerdes);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::V: movimiento = 'V'; break;
		case Keys::R: movimiento = 'R'; break;
		case Keys::P: movimiento = 'P'; break;
		case Keys::Space: this->Close(); break;
		default:
			break;
		}
	}
	private: System::Void btnFinish_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Enabled = false;
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Render(g);
		string text = "Arboles rojos: " + to_string(cntArbolesRojos) + "\n" +
			"Arboles verdes: " + to_string(cntArbolesVerdes);
		fm->guardarEnTxt("resultado.txt", text);
		MessageBox::Show("Datos guardados correctamente");

	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	pair<int, int> arboles = fm->getArboles("resultado.txt");
	this->cntArbolesRojos = arboles.first;
	this->cntArbolesVerdes = arboles.second;
	//this->cntArbolesRojos = fm->getArbolesRojos("resultado.txt");
	//this->cntArbolesVerdes = fm->getArbolesVerdes("resultado.txt");
}
};
}
