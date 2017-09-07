#include "ButtonTest.h"

using namespace buttontest;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew ButtonTest());
	return 0;
}