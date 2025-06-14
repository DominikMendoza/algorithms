#pragma once
#include "Hulk.hpp"
#include "Bomba.hpp"
namespace Project46 {

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
		Bitmap^ bmpHulk;
		Bitmap^ bmpBomba;
	private: System::Windows::Forms::Timer^ timer;
		   Hulk* hulk;
	private: System::Windows::Forms::Timer^ timerbomba;
		   Bomba* bomba;
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(time(nullptr));
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, canvas->ClientRectangle);
			bmpHulk = gcnew Bitmap("imgs/Hulk.png");
			bmpBomba = gcnew Bitmap("imgs/bomba.png");
			bmpHulk->MakeTransparent(bmpHulk->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			hulk = new Hulk(bmpHulk->Width / 4, bmpHulk->Height / 4, 0.7);
			bomba = new Bomba(0, 0, bmpBomba->Width / 3, bmpBomba->Height, 0.3);
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
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerbomba = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(710, 418);
			this->canvas->TabIndex = 0;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// timerbomba
			// 
			this->timerbomba->Enabled = true;
			this->timerbomba->Interval = 400;
			this->timerbomba->Tick += gcnew System::EventHandler(this, &MyForm::timerbomba_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 442);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
		case Keys::Up:
			hulk->mover(buffer->Graphics, 'W'); break;
		case Keys::A:
		case Keys::Left:
			hulk->mover(buffer->Graphics, 'A'); break;
		case Keys::S:
		case Keys::Down:
			hulk->mover(buffer->Graphics, 'S'); break;
		case Keys::D:
		case Keys::Right:
			hulk->mover(buffer->Graphics, 'D'); break;
		}
		/*
		if (hulk->estaColisionando(bomba->getHitbox())) {
			bomba->actualizarCoordenadas(buffer->Graphics);
		}
		*/
		if (hulk->estaColisionandoTolerancia(bomba->getHitbox(), 15, 5)) {
			bomba->actualizarCoordenadas(buffer->Graphics);
		}
	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		bomba->draw(buffer->Graphics, bmpBomba);
		hulk->draw(buffer->Graphics, bmpHulk);
		buffer->Render(g);
	}
	private: System::Void timerbomba_Tick(System::Object^ sender, System::EventArgs^ e) {
		bomba->mover();
	}
};
}
