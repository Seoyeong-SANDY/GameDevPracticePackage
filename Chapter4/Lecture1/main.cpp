#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "ImageObject.h"
#include <vector>
#include <memory>

namespace jm
{
	using namespace std;


	class Example : public Game2D
	{
	public:

		ImageObject house;
		ImageObject background;

		Example()
			: Game2D("This is my digital canvas!", 1280, 960, false) // MUST initialize Game2D
		{
			house.init("car.png", 255, 255, 255); // white to transparent
			background.init("Background_image.bmp");
		}

		void update() override
		{
			background.draw();
			
			beginTransformation();
			translate(-0.5f, 0.0f);
			drawFilledStar(Colors::gold, 0.2f, 0.1f);
			endTransformation();

			// moving car
			{
				static float x = -1.0f;

				beginTransformation();
				translate(x, 0.0f);
				scale(0.3f, 0.3f);
				house.draw();
				endTransformation();

				x += 0.01f;

				if (x > 1.0f) x = -1.0f;
			}

			beginTransformation();
			translate(0.5f, 0.0f);
			drawFilledStar(Colors::red, 0.2f, 0.1f);
			endTransformation();

			//background.draw(); //this hides everything
		}
	};
}

int main(void)
{
	jm::Example().run();

	return 0;
}
