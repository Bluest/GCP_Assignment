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

void ConsoleInterface::run()
{
	// Display menu, get input, repeat until the user quits
	while (!quit)
	{
		printMenu();
		std::cin >> input;
		processInput();
	}
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
		// Start
		// Construct and launch ray tracer with the current settings
		std::cout << "Starting..." << std::endl;
		App app(winW, winH);
		app.run(cameraSettings);

		// When the ray tracer is closed, the program will continue from here
	}
	else if (input == "2")
	{
		// Change window size
		std::cout << "Enter new window width: ";
		std::cin >> winW;

		std::cout << "Enter new window height: ";
		std::cin >> winH;
	}
	else if (input == "3")
	{
		// Change resolution size
		std::cout << "Enter new resolution scale: ";
		std::cin >> cameraSettings.resolutionScale;
	}
	else if (input == "4")
	{
		// Change anti-aliasing level
		std::cout << "Enter new anti-aliasing level: ";
		std::cin >> cameraSettings.antialiasingLevel;
	}
	else if (input == "5")
	{
		// Change number of threads
		std::cout << "Enter new number of threads (Maximum " << std::thread::hardware_concurrency() << "): ";
		std::cin >> cameraSettings.numberOfThreads;

		// Because numberOfThreads and hardware_concurrency() are unsigned integers,
		// A negative input will underflow and also result in this statement being true
		if (cameraSettings.numberOfThreads > std::thread::hardware_concurrency())
		{
			cameraSettings.numberOfThreads = std::thread::hardware_concurrency();
		}
	}
	else if (input == "6")
	{
		// Quit
		quit = true;
	}
}
 