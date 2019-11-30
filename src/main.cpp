#include "App.h"
#include "Ray.h"

int main(int argc, char* argv[])
{
	const int winW = 640;
	const int winH = 480;

	App app(winW, winH);

	glm::vec3 origin(0.0f, 0.0f, 0.0f);

	for (int y = 0; y < winH; y++)
	{
		for (int x = 0; x < winW; x++)
		{
			// i ranges from -1 (at x = 0) to 1 (at x = winW)
			float i = 2 * float(x) / winW - 1.0f;
			// j ranges from -1 (at y = 0) to 1 (at y = winH)
			float j = 2 * float(y) / winH - 1.0f;

			Ray ray(origin, { i, j, 1.0f });
			glm::vec3 colour = ray.returnColour();
			app.setPixelColour(x, y, colour);
		}
	}

	while (!app.quit())
	{
		app.draw();
	}

	return 0;
}
