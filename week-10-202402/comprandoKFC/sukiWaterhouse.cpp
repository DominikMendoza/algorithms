#include "sukiWaterhouse.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew comprandoKFC::sukiWaterhouse());
}
/*
#include "sukiWaterhouse.h"
using namespace comprandoKFC;
void main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew sukiWaterhouse());
}
*/