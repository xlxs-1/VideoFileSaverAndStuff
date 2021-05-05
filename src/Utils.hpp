/*
 * Utils.h
 *
 *  Created on: 11 Mar 2021
 *      Author: xlxs
 */

#pragma once
#include "string.h"
#include "iostream"
#include <array>
class Utils final {
public:
	template<class t>
	static void print(t *arr, int size);
	template<class t>
	static void fillIntrementaly(t *arr, size_t size);
	static double map(double value, double currentStart, double currentStop, double newStart, double newStop);
};
