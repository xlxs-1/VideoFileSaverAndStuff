#include <iostream>

#include "Video.hpp"
#include "Frame.hpp"
#include "Utils.hpp"
#include "Mandelbrot.hpp"
int main(int argc, char **argv) {
	{
		constexpr size_t width = 1920;
		constexpr size_t height = 1080;
		std::string path = "Q:/deletMe/vid1.mkv";
		Video v(path, 0, 0, 24, width, height);
		Mandelbrot<width, height, 32> m;
		for (int i = 0; i < 1200; ++i) {
			m.prepareNextFrame();
			v.sendFrame(m.getFrame()->internalBuffer(), m.getFrame()->totalSizeInBytes());
		}
	}
	std::cin.get();
	return 0;
}
//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

//

