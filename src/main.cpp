#include <iostream>

#include "Video.hpp"
#include "Frame.hpp"
#include "Utils.hpp"
int main(int argc, char **argv) {
	Frame<5, 10> f;
	std::cout << f.getWidth() << "\n";
	std::cout << f.getHeight();
	exit(0);
	{
		size_t width = 1920;
		size_t height = 1080;
		std::string path = "Q:/deletMe/vid1.mkv";
		Video v(path, 0, 3, 30, 1920, 1080);
		size_t size = width * height * 3;
		uint8_t *b = new uint8_t[size];
		for (int i = 0; i < 30; ++i) {
			static long long c = 0;
			for (size_t ii = 0; ii < size; ii += 3) {
				b[ii] = c;
				b[ii] = c;
				b[ii] = c;
				++c;
			}
			++c;
			v.sendFrame(b, size);
		}
		delete[] b;
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

