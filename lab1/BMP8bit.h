#ifndef H_BMP8bit
#define H_BMP8bit

#include <vector>
#include "Filter.h"

class BMP8bit {
private:
	#pragma pack(push, 1)
	struct BMPHeader {
		unsigned short int bfType;
		int bfSize;
		unsigned short int reserved1;
		unsigned short int reserved2;
		int bfOffBits;
		int bcSize;
		int width;
		int height;
		unsigned short int bcPlanes;
		unsigned short int biBitCount;
		int biCompression;
	};
	#pragma pack(pop) 

	BMPHeader* header;

	std::vector<std::vector<double>> pixels;
	unsigned char *other_info;
	int readn(int n, unsigned char *buff, FILE *f);
	void writen(int n, unsigned char *buff, FILE *f);

public:
	BMP8bit(const std::string &filename);
	void rotate_left();
	void rotate_right();
	void apply_filter(Filter* filter);
	void save(const std::string &filename);
};

#endif