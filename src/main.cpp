#include <iostream>

#include "Video.hpp"
#include "Fractals/Multibrot.hpp"

/**
 * FFmpeg is required in path. Compile with:
 * compilation flags used: -O3 -Ofast -fopenmp -march=native -frename-registers -funroll-loops
 */
int main(int argc, char **argv) {
	{
		constexpr size_t width = 1920;
		constexpr size_t height = 1080;
		std::string path = "Q:/deletMe/vid2.mkv"; //input path TODO set this to an actual path.
		Video v(path, 0, 5, 1, width, height);
		constexpr uint_fast16_t iterations = 64;
		Multibrot<width, height, iterations> m;
		int framesToGenerate = 5;
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
