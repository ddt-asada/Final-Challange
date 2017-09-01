#include "MyForm.h"

using namespace TableTest;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm());
	return 0;
}