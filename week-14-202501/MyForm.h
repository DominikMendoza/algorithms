#pragma once
#include "Controller.hpp" 
namespace Project56 {

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
		BufferedGraphics^ bf;
		BufferedGraphicsContext^ context;
		Bitmap^ bmpKenny;
		Controller* controller;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bf = context->Allocate(g, canvas->ClientRectangle);
			bmpKenny = gcnew Bitmap("bmps/kenny.png");
			controller = new Controller(bmpKenny, bmpKenny, bmpKenny, bmpKenny);
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
	private: System::Windows::Forms::Timer^ timer;
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
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(991, 522);
			this->canvas->TabIndex = 0;
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
			this->ClientSize = System::Drawing::Size(1015, 546);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::WhiteSmoke);
		controller->moverDiscos(bf->Graphics);
		controller->verificarColisiones(bmpKenny);
		controller->dibujarTodo(bf->Graphics, bmpKenny, bmpKenny, bmpKenny, bmpKenny);
		bf->Render(g);
	}
	};
}
