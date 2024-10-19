#pragma once
#include "Controladora.h"

namespace My01movimientofigura {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FrmFiguras : public System::Windows::Forms::Form
    {
    public:
        FrmFiguras(void)
        {
            InitializeComponent();

            graph = panelFiguras->CreateGraphics();
            sistema = new Controladora(graph);
        }

    protected:
        ~FrmFiguras()
        {
            if (components)
            {
                delete components;
            }
            delete sistema;
        }

    private:
        System::Windows::Forms::Panel^ panelFiguras;
        System::Windows::Forms::Timer^ timer;
        System::ComponentModel::IContainer^ components;
        Graphics^ graph;
        Controladora* sistema;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->panelFiguras = (gcnew System::Windows::Forms::Panel());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // panelFiguras
            // 
            this->panelFiguras->Location = System::Drawing::Point(12, 12);
            this->panelFiguras->Name = L"panelFiguras";
            this->panelFiguras->Size = System::Drawing::Size(518, 493);
            this->panelFiguras->TabIndex = 0;
            this->panelFiguras->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguras::panelFiguras_Paint);
            // 
            // timer
            // 
            this->timer->Enabled = true;
            this->timer->Tick += gcnew System::EventHandler(this, &FrmFiguras::timer_Tick);
            // 
            // FrmFiguras
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(542, 517);
            this->Controls->Add(this->panelFiguras);
            this->Name = L"FrmFiguras";
            this->Text = L"FrmFiguras";
            this->ResumeLayout(false);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmFiguras::FrmFiguras_KeyDown);
        }
#pragma endregion

    private:
        System::Void panelFiguras_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
            
        }

        System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
            graph->Clear(Color::Gray);
            sistema->moverTodos(graph);
            sistema->dibujarTodos(graph);
        }

        System::Void FrmFiguras_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            switch (e->KeyCode)
            {
            case Keys::T:
                sistema->agregarTriangulo();
                break;
            case Keys::C:
                sistema->agregarCirculo();
                break;
            case Keys::E:
                sistema->agregarElipse();
                break;
            case Keys::D:
                sistema->agregarCuadrado();
                break;
            case Keys::R:
                sistema->agregarRectangulo();
                break;
            case Keys::Escape:
                System::Windows::Forms::Application::Exit();
                break;
            default:
                break;
            }
        }
    };
}
