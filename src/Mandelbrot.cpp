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
	for (size_t sY = 0; sY < frame->getHeight(); ++sY) {
		for (size_t sX = 0; sX < frame->getWidth(); ++sX) {
			double ratio = frame->getWidth() / (double) frame->getHeight();
			double x = sX / ((double) frame->getWidth() - 1);
			double y = sY / ((double) frame->getHeight() - 1);
			x = x * 2 - 1;
			x=x * ratio;
			y = y * 2 - 1;
			std::complex<double> complex;
			complex.real(x);
			complex.imag(y);
			//bool outOfBounds = false;
			std::complex<double> temp = complex;
			for (decltype(iterations) i = 0; i < 32; ++i) {
				complex = complex * complex + temp;
			}
			if (/*complex.real() > 2 || complex.imag() > 2*/std::norm(complex) > 2) {
				frame->w(sY, sX, 0, 0x7f);
				frame->w(sY, sX, 1, 0x7f);
				frame->w(sY, sX, 2, 0x7f);
			} else {
				frame->w(sY, sX, 0, 0);
				frame->w(sY, sX, 1, 0);
				frame->w(sY, sX, 2, 0);
			}
		}
	}
	frameCounter++;
}
template<size_t width, size_t height, uint_fast16_t iterations>
Frame<width, height>* Mandelbrot<width, height, iterations>::getFrame() {
	return frame;
}
template class Mandelbrot<1920, 1080, 32> ;

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

