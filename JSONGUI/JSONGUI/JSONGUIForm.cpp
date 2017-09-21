#include "JSONGUIForm.h"
#include "OptionForm.h"		

using namespace JSONGUI;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew JSONGUIForm());
	
	return 0;
}