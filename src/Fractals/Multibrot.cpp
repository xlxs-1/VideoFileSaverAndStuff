/*
 * Mandelbrot.cpp
 *
 *  Created on: 4 May 2021
 *      Author: Spiros Stavropoulos
 */

#include "Multibrot.hpp"
template<size_t width, size_t height, uint_fast16_t iterations>
Multibrot<width, height, iterations>::Multibrot() :
		frame { new Frame<width, height> }, frameCounter { 0 } {
}
template<size_t width, size_t height, uint_fast16_t iterations>
Multibrot<width, height, iterations>::~Multibrot() {
	delete frame;
}

template<size_t width, size_t height, uint_fast16_t iterations>
void Multibrot<width, height, iterations>::prepareNextFrame() {
#pragma omp parallel for
	for (size_t sY = 0; sY < frame->getHeight(); ++sY) {
		for (size_t sX = 0; sX < frame->getWidth(); ++sX) {
			double scale = 0.85;
			double ratio = frame->getWidth() / (double) frame->getHeight();
			double x = sX / ((double) frame->getWidth() - 1);
			double y = sY / ((double) frame->getHeight() - 1);
			x = x * 2 - 1;
			y = y * 2 - 1;
			x /= scale / ratio;
			y /= scale;

			std::complex<double> z;
			z.real(0);
			z.imag(0);
			std::complex<double> startPosition;
			startPosition.real(x);
			startPosition.imag(y);

			decltype(iterations) iters = 0;

			for (; iters < iterations; ++iters) {
//				z = z * z + startPosition;
				z = pow(z, 2. * frameCounter / 48.) + startPosition;
				if (norm(z) >= 4 * 1000.) {
					break;
				}
			}
			for (size_t i = 0; i < 3; ++i) {
				double c = ((double) iters - log2(.01 * log2(norm(z))) + 4.0) / iterations; //https://www.shadertoy.com/view/tllSWj line 17
				frame->w(sY, sX, i, c * 255);
			}
		}
	}
	frameCounter++;
}
template<size_t width, size_t height, uint_fast16_t iterations>
Frame<width, height>* Multibrot<width, height, iterations>::getFrame() {
	return frame;
}
template class Multibrot<2560, 1440, 16> ;
template class Multibrot<2560, 1440, 32> ;
template class Multibrot<2560, 1440, 64> ;
template class Multibrot<2560, 1440, 128> ;
template class Multibrot<2560, 1440, 1024> ;

template class Multibrot<1920, 1080, 16> ;
template class Multibrot<1920, 1080, 32> ;
template class Multibrot<1920, 1080, 64> ;
template class Multibrot<1920, 1080, 128> ;
template class Multibrot<1920, 1080, 1024> ;

template class Multibrot<1024, 512, 16> ;
template class Multibrot<1024, 512, 32> ;
template class Multibrot<1024, 512, 128> ;

template class Multibrot<512, 512, 16> ;
template class Multibrot<512, 512, 32> ;
template class Multibrot<512, 512, 64> ;

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

