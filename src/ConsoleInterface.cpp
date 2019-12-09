#include <iostream>
#include <thread>

#include "ConsoleInterface.h"
#include "App.h"

ConsoleInterface::ConsoleInterface()
{
	// Default settings
	winW = 640, winH = 480;
	cameraSettings = { glm::vec3(0.0f, 0.0f, 0.0f), 1, 1, std::thread::hardware_concurrency() };
}

void ConsoleInterface::run()
{
	std::cout << "[1] Start" << std::endl;
	std::cout << "[2] Change window size(currently: " << winW << " by " << winH << ")" << std::endl;
	std::cout << "[3] Change resolution scale(currently: " << cameraSettings.resolutionScale << ")" << std::endl;
	std::cout << "[4] Change anti-aliasing level(currently: " << cameraSettings.antialiasingLevel << ")" << std::endl;
	std::cout << "[5] Change number of threads(currently: " << cameraSettings.numberOfThreads << ")" << std::endl;
	std::cout << std::endl;

	App app(winW, winH);
	app.run(cameraSettings);
}
