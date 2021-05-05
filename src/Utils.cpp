/*
 * Utils.cpp
 *
 *  Created on: 11 Mar 2021
 *      Author: xlxs
 */

#include "Utils.hpp"
template<class t>
void Utils::print(t *arr, int size) {
	auto const c = 16;
	int i = 0;
	for (; i < size; ++i) {
		auto ii = i % c;
		if (!ii)
			std::cout << (i > 0 ? "\n" : "") << i / c << ":	";
		std::cout << std::hex << (int) arr[i] << "	";
	}
	std::cout << "\n" << std::flush;
}
template<class t>
void Utils::fillIntrementaly(t *ar, size_t s) {
	for (size_t i = 0; i < s; ++i)
		ar[i] = i;
}
double Utils::map(double value, double istart, double istop, double ostart, double ostop) {
	return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}
template void Utils::print<int>(int*, int);
template void Utils::print<unsigned char>(unsigned char*, int);

template void Utils::fillIntrementaly<int>(int*, size_t);
