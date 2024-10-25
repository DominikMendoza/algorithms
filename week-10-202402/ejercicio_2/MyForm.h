#pragma once
#include "CController.hpp"
namespace Project77 {

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
		CController* contr;
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Label^ lblMeta;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblPrimerLugar;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblSegundoLugar;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ lblTercerLugar;
	private: System::Windows::Forms::GroupBox^ gBPodio;
	private: System::Windows::Forms::Label^ lblResumen;

		   Graphics^ g;
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			g = canvas->CreateGraphics();
			contr = new CController(g);
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
			this->gBPodio = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lblPrimerLugar = (gcnew System::Windows::Forms::Label());
			this->lblTercerLugar = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblSegundoLugar = (gcnew System::Windows::Forms::Label());
			this->lblMeta = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblResumen = (gcnew System::Windows::Forms::Label());
			this->canvas->SuspendLayout();
			this->gBPodio->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Controls->Add(this->lblResumen);
			this->canvas->Controls->Add(this->gBPodio);
			this->canvas->Controls->Add(this->lblMeta);
			this->canvas->Location = System::Drawing::Point(0, 1);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(1263, 585);
			this->canvas->TabIndex = 0;
			// 
			// gBPodio
			// 
			this->gBPodio->Controls->Add(this->panel2);
			this->gBPodio->Controls->Add(this->panel3);
			this->gBPodio->Controls->Add(this->lblPrimerLugar);
			this->gBPodio->Controls->Add(this->lblTercerLugar);
			this->gBPodio->Controls->Add(this->panel1);
			this->gBPodio->Controls->Add(this->lblSegundoLugar);
			this->gBPodio->Location = System::Drawing::Point(71, 63);
			this->gBPodio->Name = L"gBPodio";
			this->gBPodio->Size = System::Drawing::Size(650, 453);
			this->gBPodio->TabIndex = 7;
			this->gBPodio->TabStop = false;
			this->gBPodio->Text = L"Podio";
			this->gBPodio->Visible = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel2->Location = System::Drawing::Point(123, 148);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(88, 268);
			this->panel2->TabIndex = 4;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel3->Location = System::Drawing::Point(430, 237);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(88, 179);
			this->panel3->TabIndex = 6;
			// 
			// lblPrimerLugar
			// 
			this->lblPrimerLugar->AutoSize = true;
			this->lblPrimerLugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrimerLugar->Location = System::Drawing::Point(285, 13);
			this->lblPrimerLugar->Name = L"lblPrimerLugar";
			this->lblPrimerLugar->Size = System::Drawing::Size(66, 24);
			this->lblPrimerLugar->TabIndex = 1;
			this->lblPrimerLugar->Text = L"label1";
			// 
			// lblTercerLugar
			// 
			this->lblTercerLugar->AutoSize = true;
			this->lblTercerLugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTercerLugar->Location = System::Drawing::Point(442, 199);
			this->lblTercerLugar->Name = L"lblTercerLugar";
			this->lblTercerLugar->Size = System::Drawing::Size(66, 24);
			this->lblTercerLugar->TabIndex = 5;
			this->lblTercerLugar->Text = L"label1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(278, 40);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(88, 376);
			this->panel1->TabIndex = 2;
			// 
			// lblSegundoLugar
			// 
			this->lblSegundoLugar->AutoSize = true;
			this->lblSegundoLugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSegundoLugar->Location = System::Drawing::Point(135, 109);
			this->lblSegundoLugar->Name = L"lblSegundoLugar";
			this->lblSegundoLugar->Size = System::Drawing::Size(66, 24);
			this->lblSegundoLugar->TabIndex = 3;
			this->lblSegundoLugar->Text = L"label1";
			// 
			// lblMeta
			// 
			this->lblMeta->AutoSize = true;
			this->lblMeta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMeta->ForeColor = System::Drawing::Color::Goldenrod;
			this->lblMeta->Location = System::Drawing::Point(1087, 21);
			this->lblMeta->Name = L"lblMeta";
			this->lblMeta->Size = System::Drawing::Size(110, 37);
			this->lblMeta->TabIndex = 0;
			this->lblMeta->Text = L"META";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// lblResumen
			// 
			this->lblResumen->AutoSize = true;
			this->lblResumen->Location = System::Drawing::Point(797, 116);
			this->lblResumen->Name = L"lblResumen";
			this->lblResumen->Size = System::Drawing::Size(35, 13);
			this->lblResumen->TabIndex = 8;
			this->lblResumen->Text = L"label1";
			this->lblResumen->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1263, 586);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->gBPodio->ResumeLayout(false);
			this->gBPodio->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (!contr->acaboJuego()) {
			g->Clear(Color::WhiteSmoke);
			contr->moverTodos(g);
			contr->dibujarTodos(g);
			contr->dibujarMeta(g);
		}
		else {
			g->Clear(Color::WhiteSmoke);
			gBPodio->Visible = true;
			lblResumen->Visible = true;
			lblMeta->Visible = false;
			lblPrimerLugar->Text = gcnew String(contr->getNombrePrimerLugar().c_str());
			lblSegundoLugar->Text = gcnew String(contr->getNombreSegundoLugar().c_str());
			lblTercerLugar->Text = gcnew String(contr->getNombreTercerLugar().c_str());
			lblResumen->Text = gcnew String(contr->getResumenDeCarrera().c_str());
		}
	}
	};
}
