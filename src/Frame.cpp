/*
 * Frame.cpp
 *
 *  Created on: 4 May 2021
 *      Author: Spiros Stavropoulos
 */

#include "Frame.hpp"
template<size_t width, size_t height>
Frame<width, height>::Frame() {

}
template<size_t width, size_t height>
Frame<width, height>::~Frame() {
}
template<size_t width, size_t height>
uint8_t* Frame<width, height>::internalBuffer() {
	return (_frame.data()->data()->data());
}
template<size_t width, size_t height>
uint8_t Frame<width, height>::r(size_t y, size_t x, size_t colorComponent) {
	return _frame[y][x][colorComponent];
}
template<size_t width, size_t height>
void Frame<width, height>::w(size_t y, size_t x, size_t colorComponent, uint8_t value) {
	_frame[y][x][colorComponent] = value;
}
template<size_t width, size_t height>
size_t Frame<width, height>::getWidth() {
	return _frame[0].size();
}
template<size_t width, size_t height>
size_t Frame<width, height>::getHeight() {
	return _frame.size();
}
template<size_t width, size_t height>
size_t Frame<width, height>::totalSizeInBytes() {
	return getWidth() * getHeight() * 3 * sizeof(uint8_t);
}

template class Frame<2560, 1440> ;
template class Frame<1920, 1080> ;
template class Frame<1024, 512> ;
template class Frame<512, 512> ;
