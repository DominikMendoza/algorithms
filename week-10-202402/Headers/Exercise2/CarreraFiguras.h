#pragma once
#include "Competencia.h"

namespace Ejercicio2Semana10 {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			competencia = gcnew Competencia();
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

	protected:

	private:
		Competencia^ competencia;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labelMeta;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelMeta = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// labelMeta
			// 
			this->labelMeta->AutoSize = true;
			this->labelMeta->BackColor = System::Drawing::Color::Transparent;
			this->labelMeta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMeta->ForeColor = System::Drawing::Color::Yellow;
			this->labelMeta->Location = System::Drawing::Point(869, 9);
			this->labelMeta->Name = L"labelMeta";
			this->labelMeta->Size = System::Drawing::Size(57, 20);
			this->labelMeta->TabIndex = 0;
			this->labelMeta->Text = L"META";
			this->labelMeta->Click += gcnew System::EventHandler(this, &MyForm::labelMeta_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 528);
			this->Controls->Add(this->labelMeta);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		competencia->Iniciar(g);
		delete g;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawLine(Pens::Yellow, competencia->getMeta(), 11, competencia->getMeta(), 567);
		competencia->MoverFiguras();
		competencia->DibujarFiguras(buffer->Graphics);
		if (!competencia->TodosEnCarrera()) //Verificar si alguna figura ha llegado a la meta
		{
			timer1->Stop(); //Detener el timer cuando alguien llega a la meta
			competencia->VerificarVictorias();
			competencia->reducirCantidadCarreras();
			if (competencia->getCantidadCarreras() > 0)
			{
				_sleep(2000); //2s
				competencia->Iniciar(g);
				timer1->Start(); //Reactivar el timer para la siguiente carrera
			}
			else
			{
				labelMeta->Text = ""; //Limpiar o borrar label 
				buffer->Graphics->Clear(Color::White); //Limpiar pantalla
				competencia->MostrarRanking(buffer->Graphics); //Todas las carreras terminaron, mostrar el ranking y ganador
			}
		}
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void labelMeta_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
