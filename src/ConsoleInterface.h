#include <string>

#include "Camera.h"

class ConsoleInterface
{
private:
	std::string input;
	int winW, winH;
	CameraSettings cameraSettings;
	bool quit;

	void printMenu();
	void processInput();

public:
	ConsoleInterface();

	void run();
};
