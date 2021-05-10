/*
 * Video.hpp
 *
 *  Created on: 1 May 2021
 *      Author: Spiros Stavropoulos
 */

#pragma once
#include <iomanip>
#include <iostream>

#include <fcntl.h>
#include <io.h>

class Video {
	FILE *pPipe;
	static std::string getPreset(uint8_t encodeSpeed);
public:
	Video(std::string path, uint8_t crf/*[0..51]*/, uint8_t encodeSpeed/*[0..9]*/, uint16_t fps, size_t width, size_t height);
	virtual ~Video();
	void sendFrame(uint8_t *buffer, size_t numberOfBytes2write);
};
