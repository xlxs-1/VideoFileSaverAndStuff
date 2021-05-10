#include <iostream>

#include "Video.hpp"
#include "Frame.hpp"
#include "Utils.hpp"
#include "Mandelbrot.hpp"
int main(int argc, char **argv) {
	{
		constexpr size_t width = 1024;
		constexpr size_t height = 512;
		std::string path = "Q:/deletMe/vid2.mkv";
		Video v(path, 0, 5, 24, width, height);
		Mandelbrot<width, height, 128> m;
		for (int i = 0; i < 60; ++i) {
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
