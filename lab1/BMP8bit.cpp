#include "BMP8bit.h"
#include <string>
#include <vector>
#include <stdexcept>

BMP8bit::BMP8bit(const std::string &filename) {
	unsigned char buff[1];
	FILE* f = fopen(filename.c_str(), "rb");
	header = new BMPHeader();
	fread(header, sizeof(BMPHeader), 1, f);
	if (header->biBitCount != 8) {
		throw std::runtime_error("Глубина изображения должна равняться 8.");
    }
	int height = header->height;
    int width = header->width;
    pixels.resize(height, std::vector<double>(width, 0));
    other_info = new unsigned char[header->bfOffBits - sizeof(BMPHeader)];
    fread(other_info, sizeof(unsigned char), header->bfOffBits - sizeof(BMPHeader), f);
    for (int i = 0; i < width * height; i++) {
    	pixels[i / width][i % width] = readn(1, buff, f);
    }
    fclose(f);
}


void BMP8bit::save(const std::string &filename) {
	unsigned char buff[1];
	FILE* f = fopen(filename.c_str(), "wb");
    fwrite(header, sizeof(BMPHeader), 1, f);
    fwrite(other_info, sizeof(unsigned char), header->bfOffBits - sizeof(BMPHeader), f);
    for (int i = 0; i < pixels.size(); i++) {
    	for (int j = 0; j < pixels[i].size(); j++) {
    		buff[0] = static_cast<unsigned char>(pixels[i][j]);
    		writen(1, buff, f);
    	}
    }
    fclose(f);
}

void BMP8bit::rotate_left() {
	std::vector<std::vector<double>> rotated(header->width, std::vector<double>(header->height, 0));
	for (int i = 0; i < header->height; i++) {
		for (int j = 0; j < header->width; j++) {
			rotated[j][header->height - 1 - i] = pixels[i][j];
		}
	}
	pixels = rotated;
	std::swap(header->width, header->height);
}

void BMP8bit::rotate_right() {
	std::vector<std::vector<double>> rotated(header->width, std::vector<double>(header->height, 0));
	for (int i = 0; i < header->height; i++) {
		for (int j = 0; j < header->width; j++) {
			rotated[header->width - j - 1][i] = pixels[i][j];
		}
	}
	pixels = rotated;
	std::swap(header->width, header->height);
}

void BMP8bit::apply_filter(Filter* filter) {
	filter->apply(pixels);
}

int BMP8bit::readn(int n, unsigned char *buff, FILE *f) {
	fread(buff, sizeof(unsigned char), n, f);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += static_cast<int>(buff[i] << (8 * i));
	}
	return ans;
}

void BMP8bit::writen(int n, unsigned char *buff, FILE *f) {
	fwrite(buff, sizeof(unsigned char), n, f);
}