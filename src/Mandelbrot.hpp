/*
 * Mandelbrot.hpp
 *
 *  Created on: 4 May 2021
 *      Author: xlxs
 */

#pragma once
#include <stdint.h>
#include "Frame.hpp"

class Mandelbrot {
public:
	Mandelbrot(size_t width, size_t height);
	~Mandelbrot();
	void prepareNextFrame();
};
