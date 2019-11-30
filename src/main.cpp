#include "App.h"
#include "Ray.h"

int main(int argc, char* argv[])
{
	App app(640, 480);

	while (app.run())
	{
		app.draw();
	}

	return 0;
}
