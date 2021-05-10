/*
 * Mandelbrot.hpp
 *
 *  Created on: 4 May 2021
 *      Author: Spiros Stavropoulos
 */

#pragma once
#include <stdint.h>
#include <complex>
#include <algorithm>
#include <cmath>
#include <limits>

#include "Frame.hpp"
#include "Utils.hpp"
template<size_t width, size_t height, uint_fast16_t iterations>
class Multibrot {
	Frame<width, height> *frame;
	uint32_t frameCounter;
public:
	Multibrot();
	~Multibrot();
	void prepareNextFrame();
	Frame<width, height>* getFrame();
};
