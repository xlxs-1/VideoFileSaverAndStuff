#include <iostream>

#include "Video.hpp"
#include "Fractals/Multibrot.hpp"
#include "WeirdFluids/SumAllAndSub.hpp"
/**
 * FFmpeg is required in path. Compile with:
 * compilation flags used: -O3 -Ofast -fopenmp -march=native -frename-registers -funroll-loops
 */
int main(int argc, char **argv) {

	{
		constexpr size_t width = 512;
		constexpr size_t height = 512;
		SumAllAndSub<width, height> a { 7 };
		std::string path = "Q:/deletMe/vid2.mkv"; //input path TODO set this to an actual path.
		Video v(path, 0, 5, 24, width, height);
		constexpr uint_fast16_t iterations = 64;
//		Multibrot<width, height, iterations> m;
		int framesToGenerate = 150;
		for (auto i = 0; i < framesToGenerate; ++i) {
			if (i==100)a.setKernel1(7,.25);
			a.prepareNextFrame();
			v.sendFrame(a.getFrame()->internalBuffer(), a.getFrame()->totalSizeInBytes());
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
