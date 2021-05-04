#include <iostream>

#include "Video.hpp"
#include "Frame.hpp"
#include "Utils.hpp"
#include "Mandelbrot.hpp"
int main(int argc, char **argv) {
	{
		size_t width = 1920;
		size_t height = 1080;
		std::string path = "Q:/deletMe/vid1.mkv";
		Video v(path, 0, 3, 1, 1920, 1080);
//		size_t size = width * height * 3;
//		uint8_t *b = new uint8_t[size];
//		for (int i = 0; i < 30; ++i) {
//			static long long c = 0;
//			for (size_t ii = 0; ii < size; ii += 3) {
//				b[ii] = c;
//				b[ii] = c;
//				b[ii] = c;
//				++c;
//			}
//			++c;
//			v.sendFrame(b, size);
//		}
//		delete[] b;
		Mandelbrot<1920, 1080, 32> m;
		for (int i = 0; i < 2; ++i) {
			m.prepareNextFrame();
			v.sendFrame(m.getFrame()->internalBuffer(), m.getFrame()->totalSizeInBytes());
		}

	}
	//std::cout << "press enter to continue" << std::endl;
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

