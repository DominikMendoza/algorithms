#pragma once
#include "CControl.hpp"
namespace comprandoKFC {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class sukiWaterhouse : public System::Windows::Forms::Form {
	public:
		sukiWaterhouse(void) {
			InitializeComponent();
			graphic = panelFigures->CreateGraphics();
			control = new CControler(graphic);
		}

	protected:
		~sukiWaterhouse() {
			if (components) delete components;
			delete control;
		}

	private:
		System::Windows::Forms::Panel^ panelFigures;
		System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

		System::Drawing::Graphics^ graphic;
		CControler* control;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->panelFigures = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// panelFigures
			this->panelFigures->Location = System::Drawing::Point(0, 0);
			this->panelFigures->Name = L"panelFigures";
			this->panelFigures->Size = System::Drawing::Size(700, 700);
			this->panelFigures->TabIndex = 0;
			// timer
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &sukiWaterhouse::timer_Tick);
			// sukiWaterhouse
			this->ClientSize = System::Drawing::Size(700, 700);
			this->Controls->Add(this->panelFigures);
			this->Name = L"sukiWaterhouse";
			this->Text = L"OMG";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &sukiWaterhouse::sukiWaterhouse_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			graphic->Clear(Color::Transparent);
			control->moveAllFigures(graphic);
			control->drawAllFigures(graphic);
		}
		System::Void sukiWaterhouse_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::C:
				control->addCircle(); break;
			case Keys::D:
				control->addSquare(); break;
			case Keys::E:
				control->addEllipse(); break;
			case Keys::R:
				control->addRectangle(); break;
			case Keys::T:
				control->addTriangle(); break;
			case Keys::Escape:
				System::Windows::Forms::Application::Exit(); break;
			default:
				break;
			}
		}
	};
}
