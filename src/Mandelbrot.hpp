/*
 * Mandelbrot.hpp
 *
 *  Created on: 4 May 2021
 *      Author: xlxs
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
class Mandelbrot {
	Frame<width, height> *frame;
	uint32_t frameCounter;
public:
	Mandelbrot();
	~Mandelbrot();
	void prepareNextFrame();
	Frame<width, height>* getFrame();
	uint8_t mapColor(double mcol);
};
