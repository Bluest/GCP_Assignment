#include <iostream>
#include <thread>

#include "ConsoleInterface.h"
#include "App.h"

ConsoleInterface::ConsoleInterface()
{
	// Default settings
	winW = 640, winH = 480;
	cameraSettings = { glm::vec3(0.0f, 0.0f, 0.0f), 1, 10, std::thread::hardware_concurrency() };
	quit = false;
}

void ConsoleInterface::printMenu()
{
	std::cout << std::endl;
	std::cout << "[1] Start" << std::endl;
	std::cout << "[2] Change window size (currently: " << winW << " by " << winH << ")" << std::endl;
	std::cout << "[3] Change resolution scale (currently: " << cameraSettings.resolutionScale << ")" << std::endl;
	std::cout << "[4] Change anti-aliasing level (currently: " << cameraSettings.antialiasingLevel << ")" << std::endl;
	std::cout << "[5] Change number of threads (currently: " << cameraSettings.numberOfThreads << ")" << std::endl;
	std::cout << "[6] Quit" << std::endl;
	std::cout << std::endl;
}

void ConsoleInterface::processInput()
{
	// String not allowed in a switch statement, using if else instead
	if (input == "1")
	{
		std::cout << "Starting..." << std::endl;
		App app(winW, winH);
		app.run(cameraSettings);
	}
	else if (input == "2")
	{
		std::cout << "Enter new window width: ";
		std::cin >> winW;

		std::cout << "Enter new window height: ";
		std::cin >> winH;
	}
	else if (input == "3")
	{
		std::cout << "Enter new resolution scale: ";
		std::cin >> cameraSettings.resolutionScale;
	}
	else if (input == "4")
	{
		std::cout << "Enter new anti-aliasing level: ";
		std::cin >> cameraSettings.antialiasingLevel;
	}
	else if (input == "5")
	{
		std::cout << "Enter new number of threads (Maximum " << std::thread::hardware_concurrency() << "): ";
		std::cin >> cameraSettings.numberOfThreads;
	}
	else if (input == "6")
	{
		quit = true;
	}
}

void ConsoleInterface::run()
{
	while (!quit)
	{
		printMenu();
		std::cin >> input;
		processInput();
	}
}
