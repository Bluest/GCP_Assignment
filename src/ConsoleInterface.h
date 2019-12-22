#include <string>

#include "Camera.h"

class ConsoleInterface
{
public:
	ConsoleInterface();

	void run();

private:
	std::string input;
	int winW, winH;
	CameraSettings cameraSettings;
	bool quit;

	void printMenu();
	void processInput();
};
