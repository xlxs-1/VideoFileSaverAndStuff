#include <iostream>

#include "Video.hpp"
#include "Multibrot.hpp"

/**
 * FFmpeg is required in path. Compile with:
 * -O3 -Ofast -fopenmp -march=native -frename-registers -funroll-loops
 */
int main(int argc, char **argv) {
	{
		constexpr size_t width = 1024;
		constexpr size_t height = 512;
		std::string path = "C:/input path here/vid1.mkv"; //input path
		Video v(path, 0, 6, 24, width, height);
		constexpr uint_fast16_t iterations = 32;
		Multibrot<width, height, iterations> m;
		int framesToGenerate = 150;
		for (auto i = 0; i < framesToGenerate; ++i) {
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
