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
template<size_t width, size_t height, uint_fast16_t iterations>
uint8_t mapColor(double mcol, uint8_t component) {
//	return vec4(0.5 + 0.5 * cos(2.7 + mcol * 30.0 + vec3(0.0, .6, 1.0)), 1.0);
}

template<size_t width, size_t height, uint_fast16_t iterations>
void Mandelbrot<width, height, iterations>::prepareNextFrame() {
#pragma omp parallel for
	for (size_t sY = 0; sY < frame->getHeight(); ++sY) {
		double min = 100, max = 0;
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

			for (; iters < iterations /*- frameCounter % iterations*/; ++iters) {
				z = z * z + startPosition;
//				z = pow(z, 2. * frameCounter / 48.) + startPosition; //del and uncomment upper for normal
				if (norm(z) >= 4 + frameCounter) {
					break;
				}
			}
			for (size_t i = 0; i < 3; ++i) {
//				frame->w(sY, sX, i, (std::max(log2(std::norm(z)) - 2., 0.) + 1) * 0xff);
//				frame->w(sY, sX, i, std::max(.0, log2(std::norm(z))));
//				frame->w(sY, sX, i, std::max(.0, (std::norm(z) * std::pow(frameCounter, 1.5) / 5.0 + (255. / 3) * i))); // 9/10
//				frame->w(sY, sX, i, std::max(.0, ((std::norm(z) / 18.) * 24. + frameCounter * 24 + (255. / 3) * i))); // 9/10
//				frame->w(sY, sX, i, 255. * iters / iterations); // typical imaging 8/10
//				frame->w(sY, sX, i, (std::norm(z) / 18.) * 0xff);
				double c = ((double) iters - log2(log2(norm(z))) + 4.0) / (iterations /** sqrt(2.)*/); //https://www.shadertoy.com/view/tllSWj 9.5/10
				c = log2(log2(norm(z))); //9.5/10
				if (c > max && c > 1.)
					max = c;
				if (c < min)
					min = c;

				frame->w(sY, sX, i, Utils::map(c, 2.5, 3.6, 0., 255.));/////////////2536
//				double m = pow(10., 2.);
//				frame->w(sY, sX, i, (std::min(log2(norm(z - startPosition * (double) iters)), m) / m) * 255.);
			}
		}
		std::cout << min << "	" << max << "\n";
	}
	frameCounter++;
}
template<size_t width, size_t height, uint_fast16_t iterations>
Frame<width, height>* Mandelbrot<width, height, iterations>::getFrame() {
	return frame;
}
template class Mandelbrot<2560, 1440, 16> ;

template class Mandelbrot<1920, 1080, 16> ;
template class Mandelbrot<1920, 1080, 32> ;
template class Mandelbrot<1920, 1080, 128> ;
template class Mandelbrot<1920, 1080, 1024> ;

template class Mandelbrot<1024, 512, 16> ;
template class Mandelbrot<1024, 512, 32> ;
template class Mandelbrot<1024, 512, 128> ;

template class Mandelbrot<512, 512, 16> ;
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

