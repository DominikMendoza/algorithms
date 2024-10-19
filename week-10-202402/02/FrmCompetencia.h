#pragma once
#include "Controladora.h"

namespace My02competencia {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FrmCompetencia : public System::Windows::Forms::Form
    {
    public:
        FrmCompetencia(void)
        {
            InitializeComponent();
            srand(time(nullptr));
            graph = panel->CreateGraphics();
            sistema = new Controladora();
        }

    protected:
        ~FrmCompetencia()
        {
            if (components)
            {
                delete components;
            }
            delete sistema;
        }

    private:
        System::Windows::Forms::Timer^ timer;
        System::Windows::Forms::Panel^ panel;
        System::ComponentModel::IContainer^ components;
        Graphics^ graph;
        Controladora* sistema;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();
            // 
            // timer
            // 
            this->timer->Enabled = true;
            this->timer->Tick += gcnew System::EventHandler(this, &FrmCompetencia::timer_Tick);
            // 
            // panel
            // 
            this->panel->Location = System::Drawing::Point(12, 12);
            this->panel->Name = L"panel";
            this->panel->Size = System::Drawing::Size(603, 476);
            this->panel->TabIndex = 0;
            this->panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmCompetencia::panel_Paint);
            // 
            // FrmCompetencia
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(627, 500);
            this->Controls->Add(this->panel);
            this->KeyPreview = true;
            this->Name = L"FrmCompetencia";
            this->Text = L"FrmCompetencia";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmCompetencia::FrmCompetencia_KeyDown);
            this->ResumeLayout(false);

        }
#pragma endregion
    private:
        System::Void panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

        System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
            if (sistema->getCarreras() < 5) {
                graph->Clear(Color::Gray);
                sistema->moverTodos(graph);
                sistema->dibujarTodos(graph);

                if (sistema->comprobarGanador()) {
                    sistema->reiniciarFiguras();
                }
            } else {
                timer->Enabled = false;
                sistema->mostrarRanking();
            }
        }

        System::Void FrmCompetencia_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            switch (e->KeyCode) {
            case Keys::Escape:
                System::Windows::Forms::Application::Exit();
                break;
            default:
                break;
            }
        }
    };
}
