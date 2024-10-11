#pragma once
#include "ArrFiguras.h"

namespace Ejercicio2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		CVCFiguras* FCV;
	public:
		MyForm(void)
		{
			InitializeComponent();
			FCV = new CVCFiguras();
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//FCV->~CVCFiguras();
			delete FCV ;
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ Clock;

	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(747, 351);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Clock
			// 
			this->Clock->Enabled = true;
			this->Clock->Interval = 22;
			this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(771, 375);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void Clock_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		
		Graphics^ G = this->pictureBox1->CreateGraphics();
		G->Clear(Color::White);
		
		int mxAnch = G->VisibleClipBounds.Width;
		int mxAlt = G->VisibleClipBounds.Height;
		int x = rand()% (mxAnch-30);
		int y = rand() % (mxAlt-40);
		FCV->AgregarFigura(new CCirculo(1, y, 1, 0, 1, 1, 40));
		FCV->AgregarFigura(new CTriangulo(x, 1, 0, 1, 1, 1, 60));
	
		FCV->Animar(G);

		
		
	}
	};
}
