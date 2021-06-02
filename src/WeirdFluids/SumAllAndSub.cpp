/*
 * SumAllAndSub.cpp
 *
 *  Created on: 27 May 2021
 *      Author: xlxs
 */

#include "SumAllAndSub.hpp"
template<size_t width, size_t height>
SumAllAndSub<width, height>::SumAllAndSub(uint_fast16_t kernelsWidth) :
		previous { new Frame<width, height> }, current { new Frame<width, height> } {
	setKernel1(kernelsWidth, 2.5);
	for (size_t y = 0; y < previous->getHeight(); ++y)
		for (size_t x = 0; x < previous->getWidth()/2; ++x)
			for (size_t c = 0; c < 3; ++c) {
				if (c == 1)
					previous->w(y, x, c, rand());
				else
					previous->w(y, x, c, 0);
			}
}

template<size_t width, size_t height>
SumAllAndSub<width, height>::~SumAllAndSub() {
	delete previous;
	delete current;
}

template<size_t width, size_t height>
void SumAllAndSub<width, height>::setKernel1(uint_fast16_t kernelWidth, double sigma) { // Gausian kernel
	this->kernelsWidth = kernelWidth;
	assert(kernelsWidth % 2 != 0);

	int W = kernelWidth;
	double kernel[W][W];
	double mean = W / 2;
	double sum = 0.0; // For accumulating the kernel values
	for (int x = 0; x < W; ++x)
		for (int y = 0; y < W; ++y) {
			kernel[x][y] = exp(-0.5 * (pow((x - mean) / sigma, 2.0) + pow((y - mean) / sigma, 2.0))) / (2 * M_PI * sigma * sigma);

			// Accumulate the kernel values
			sum += kernel[x][y];
		}

// Normalize the kernel
	for (int x = 0; x < W; ++x)
		for (int y = 0; y < W; ++y)
			kernel[x][y] /= sum;

	this->kernel.resize(kernelsWidth);

	for (int i = 0; i < kernelsWidth; ++i) {
		this->kernel[i].resize(kernelsWidth);
		for (int ii = 0; ii < kernelsWidth; ++ii) {
			this->kernel[i][ii] = (/*std::numeric_limits<decltype(current->r(0,0,0))>::max() **/kernel[i][ii]);
			//std::cout << this->kernel[i][ii] << "	";
		}
		//std::cout << std::endl;
	}
}

//template<size_t width, size_t height>
//void SumAllAndSub<width, height>::setKernel2(uint_fast16_t kernelWidth, double sigma) { // edje kernel
//
//}

template<size_t width, size_t height>
Frame<width, height>* SumAllAndSub<width, height>::getFrame() {
	return previous;
}
template<size_t width, size_t height>
void SumAllAndSub<width, height>::prepareNextFrame() {
	size_t yMax = previous->getHeight() - kernelsWidth / 2;
	size_t xMax = previous->getWidth() - kernelsWidth / 2;
	size_t yMin = kernelsWidth / 2;
	size_t xMin = kernelsWidth / 2;
#pragma omp parallel for
	for (size_t y = yMin; y < yMax; ++y)
		for (size_t x = xMin; x < xMax; ++x) {
			int sum = 0;
			for (size_t kernelY = 0; kernelY < kernelsWidth; ++kernelY)
				for (size_t kernelX = 0; kernelX < kernelsWidth; ++kernelX) {
					auto ly = y - kernelsWidth / 2 + kernelY;
					auto lx = x - kernelsWidth / 2 + kernelX;
					uint8_t prev = round(previous->r(ly, lx, 1) * kernel[kernelY][kernelX]);
					sum += prev;
					previous->w(ly, lx, 1, std::max(previous->r(ly, lx, 1) - prev, 0));
				}
			int8_t r = ((uint8_t) rand()) / 32 - ((uint8_t) rand()) / 32;
			previous->w(y, x, 1, std::clamp(previous->r(y, x, 1) + sum + r, 0, 0xff));
		}

}

template class SumAllAndSub<2560, 1440> ;

template class SumAllAndSub<1920, 1080> ;

//template class SumAllAndSub<1024, 1024> ;

template class SumAllAndSub<1024, 512> ;

template class SumAllAndSub<512, 512> ;

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
