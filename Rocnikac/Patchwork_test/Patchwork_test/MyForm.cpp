#include "MyForm.h"

int main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Patchworktest::MyForm form;
	System::Windows::Forms::Application::Run(% form);
}
