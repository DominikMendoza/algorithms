#pragma once
#include "CControladora.hpp"
namespace Project66 {

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
		CControladora* toxica;
		Graphics^ graph;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//srand(time(nullptr));
			graph = panel1->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(graph, panel1->ClientRectangle);
			toxica = new CControladora(graph);
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
	private: System::Windows::Forms::Timer^ myTimer;
	protected:

	private: System::Windows::Forms::Panel^ panel1;

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
			this->myTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// myTimer
			// 
			this->myTimer->Enabled = true;
			this->myTimer->Tick += gcnew System::EventHandler(this, &MyForm::myTimer_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(891, 555);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &MyForm::panel1_Click);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 579);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void myTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		// donde usaba graphics ahora uso buffer
		buffer->Graphics->Clear(Color::Gray);
		toxica->moverTodos(buffer->Graphics);
		toxica->verificarColisiones();
		toxica->dibujarTodos(buffer->Graphics);
		buffer->Render(graph);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Space:
			toxica->agregarTriangulo(); break;
		default:
			break;
		}
	}
	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		toxica->agregarTriangulo();
	}
	private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e) {
		toxica->agregarCirculo();
	}
};
}
