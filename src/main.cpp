#include <iostream>

#include "Video.hpp"
#include "Utils.hpp"
#include <array>
#include <malloc.h>
void* operator new(size_t size) {
	std::cout << "allocating " << size << std::endl;
	return malloc(size);
}
int main(int argc, char **argv) {
	{
		size_t width = 1920;
		size_t height = 1080;
		std::string path = "Q:/deletMe/vid1.mkv";
		Video v(path, 0, 3, 30, 1920, 1080);
		size_t size = width * height * 3;
		uint8_t *b = new uint8_t[size];
		for (int i = 0; i < 300; ++i) {
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
	std::cout << "press enter to continue" << std::endl;
	std::cin.get();
//
//	int a = 5;
//	//auto aa = new uint8_t[a][a];
//	//int aa[a];
//	std::array<std::array<int, 16>, 16> *ar = new std::array<std::array<int, 16>, 16>;
//	//std::array<int, 16> *arr = new std::array<int, 16>;
//	Utils::fillIntrementaly(ar->data()->data(), 16 * 16);
//	for (int i = 0; i < 16; ++i) {
//		for (int ii = 0; ii < 16; ++ii) {
//			static int c=0;
//			(*ar)[i][ii]=c++;
//		}
//	}
//	Utils::print(ar->data()->data(), 16 * 16);
//
////	std::fill_n(__first, __n, __value)
//	delete ar;
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

