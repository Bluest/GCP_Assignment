#include <string>

#include "Camera.h"

class ConsoleInterface
{
private:
	std::string input;
	int winW, winH;
	CameraSettings cameraSettings;

public:
	ConsoleInterface();

	void run();
};
