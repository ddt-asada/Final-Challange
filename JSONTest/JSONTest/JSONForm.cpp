#include "JSONForm.h"
#include "InputOption.h"

using namespace JSONTest;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew JSONForm());
	return 0;
}