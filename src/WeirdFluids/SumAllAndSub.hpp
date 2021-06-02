/*
 * SumAllAndSub.h
 *
 *  Created on: 27 May 2021
 *      Author: xlxs
 */

#pragma once

#include "../Utils.hpp"
#include "../Frame.hpp"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <type_traits>
#include <assert.h>
#include <algorithm>

template<size_t width, size_t height>
class SumAllAndSub {
	uint_fast16_t kernelsWidth;
	std::vector<std::vector<float>> kernel;
	Frame<width, height> *previous;
	Frame<width, height> *current;

public:
	SumAllAndSub(uint_fast16_t);
	~SumAllAndSub();
	void prepareNextFrame();
	void setKernel1(uint_fast16_t,double);
//	void setKernel2(uint_fast16_t,double);
	Frame<width, height>* getFrame();
};

