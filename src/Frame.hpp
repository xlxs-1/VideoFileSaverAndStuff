/*
 * Frame.hpp
 *
 *  Created on: 4 May 2021
 *      Author: Spiros Stavropoulos
 */

#pragma once
#include <stdint.h>
#include <array>
template<size_t width, size_t height>
class Frame {
	std::array<std::array<std::array<uint8_t, 3>, width>, height> _frame;
public:
	Frame();
	~Frame();
	uint8_t* internalBuffer();
	/**
	 * read
	 */
	uint8_t r(size_t y, size_t x, size_t colorComponent);
	/**
	 * write
	 */
	void w(size_t y, size_t x, size_t colorComponent, uint8_t value);
	size_t getWidth();
	size_t getHeight();
	size_t totalSizeInBytes();
};

