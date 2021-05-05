/*
 * Mandelbrot.cpp
 *
 *  Created on: 4 May 2021
 *      Author: xlxs
 */

#include "Mandelbrot.hpp"
template<size_t width, size_t height, uint_fast16_t iterations>
Mandelbrot<width, height, iterations>::Mandelbrot() :
		frame { new Frame<width, height> }, frameCounter { 0 } {
}
template<size_t width, size_t height, uint_fast16_t iterations>
Mandelbrot<width, height, iterations>::~Mandelbrot() {
	delete frame;
}

//template<size_t width, size_t height, uint_fast16_t iterations>
//void zz(double real,double imag,double){
//
//}
template<size_t width, size_t height, uint_fast16_t iterations>
void Mandelbrot<width, height, iterations>::prepareNextFrame() {
#pragma omp parallel for
	for (size_t sY = 0; sY < frame->getHeight(); ++sY) {
		for (size_t sX = 0; sX < frame->getWidth(); ++sX) {
			double ratio = frame->getWidth() / (double) frame->getHeight();
			double x = sX / ((double) frame->getWidth() - 1);
			double y = sY / ((double) frame->getHeight() - 1);
			x = x * 2 - 1;
			x = x * ratio;
			y = y * 2 - 1;

			std::complex<double> z;
			z.real(0);
			z.imag(0);
			//bool outOfBounds = false;
			std::complex<double> temp;
			temp.real(x);
			temp.imag(y);
			for (decltype(iterations) i = 0; i < /*16 * (sin(frameCounter * .1) + 1)*//*frameCounter*/iterations; ++i) {
				z = z * z + temp;
				if (std::norm(z) >= 2) {
					break;
				}
			}
			for (size_t i = 0; i < 3; ++i)
//				frame->w(sY, sX, i, (std::max(log2(std::norm(z)) - 2., 0.) + 1) * 0xff);
//				frame->w(sY, sX, i, std::max(.0, log2(std::norm(z))));
//				frame->w(sY, sX, i, std::max(.0, (std::norm(z) * frameCounter + (255. / 3) * i))); // 9/10
				frame->w(sY, sX, i, std::max(.0, (std::norm(z) * std::pow(frameCounter, 1.5)/5.0 + (255. / 3) * i))); // 9/10
		}
	}
	frameCounter++;
}
template<size_t width, size_t height, uint_fast16_t iterations>
Frame<width, height>* Mandelbrot<width, height, iterations>::getFrame() {
	return frame;
}
template class Mandelbrot<1920, 1080, 32> ;
template class Mandelbrot<512, 512, 32> ;

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

