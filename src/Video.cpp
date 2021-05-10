/*
 * Video.cpp
 *
 *  Created on: 1 May 2021
 *      Author: Spiros Stavropoulos
 */

#include "Video.hpp"
std::string Video::getPreset(uint8_t encodeSpeed) {
	switch (encodeSpeed) {
	case 0:
		return std::string("placebo");
	case 1:
		return std::string("veryslow");
	case 2:
		return std::string("slower");
	case 3:
		return std::string("slow");
	case 4:
		return std::string("medium");
	case 5:
		return std::string("fast");
	case 6:
		return std::string("faster");
	case 7:
		return std::string("veryfast");
	case 8:
		return std::string("superfast");
	case 9:
		return std::string("ultrafast");
	default:
		return std::string("ultrafast");
	}
}
Video::Video(std::string path, uint8_t crf/*[0..51]*/, uint8_t encodeSpeed/*[0..9]*/, uint16_t fps, size_t width, size_t height) {
	std::stringstream sstm;
	sstm << "ffmpeg -loglevel info -y -f rawvideo -vcodec rawvideo -s " << std::to_string(width) << "x" << std::to_string(height) //
			<< " -pix_fmt rgb24 -framerate " << std::to_string(fps) << " -i - -c:v libx264 -preset " << getPreset(encodeSpeed) << //
			" -crf " << std::to_string(crf) << " -shortest " << path;

	if (!(pPipe = popen(sstm.str().c_str(), "w"))) {
		std::cout << "popen error" << std::endl;
		exit(1);
	}
	_setmode(_fileno(pPipe), _O_BINARY);
}

Video::~Video() {
	fclose(pPipe);
}

void Video::sendFrame(uint8_t *buffer, size_t numberOfBytes2write) {
	fwrite(buffer, 1, numberOfBytes2write, pPipe);
	fflush(pPipe);
}
