#include "BMP24bit.h"
#include "Pixel.h"
#include <stdexcept>
#include <string>
#include <vector>

BMP24bit::BMP24bit(const std::string& filename)
{
    FILE* f = fopen(filename.c_str(), "rb");
    header = new BMPHeader();
    fread(header, sizeof(BMPHeader), 1, f);
    if (header->bits_per_pixel != 24)
    {
        throw std::runtime_error("Глубина изображения должна равняться 24.");
    }
    int height = header->height;
    int width = header->width;
    this->pixels = new Pixel*[height];
    bytes_between_header_and_pixels = new unsigned char[header->bits_offset - sizeof(BMPHeader)];
    fread(bytes_between_header_and_pixels,
          sizeof(unsigned char),
          header->bits_offset - sizeof(BMPHeader),
          f);
    for (int i = 0; i < height; i++)
    {
        this->pixels[i] = new Pixel[width];
        fread(this->pixels[i], sizeof(Pixel), header->width, f);
    }
    fclose(f);
}

void BMP24bit::save(const std::string& filename)
{
    FILE* f = fopen(filename.c_str(), "wb");
    fwrite(header, sizeof(BMPHeader), 1, f);
    fwrite(bytes_between_header_and_pixels,
           sizeof(unsigned char),
           header->bits_offset - sizeof(BMPHeader),
           f);
    for (int i = 0; i < header->height; i++)
    {
        fwrite(this->pixels[i], sizeof(Pixel), header->width, f);
    }
    fclose(f);
}

void BMP24bit::rotate_left()
{
    Pixel** rotated = new Pixel*[header->width];
    for (int i = 0; i < header->width; i++)
    {
        rotated[i] = new Pixel[header->height];
    }
    for (int j = 0; j < header->width; j++)
    {
        for (int i = 0; i < header->height; i++)
        {
            rotated[j][header->height - 1 - i] = this->pixels[i][j];
        }
    }
    for (int i = 0; i < header->height; i++)
    {
        delete[] this->pixels[i];
    }
    delete[] this->pixels;
    this->pixels = rotated;
    std::swap(header->width, header->height);
}

void BMP24bit::rotate_right()
{
    auto** rotated = new Pixel*[header->width];
    for (int i = 0; i < header->width; i++)
    {
        rotated[i] = new Pixel[header->height];
    }
    for (int i = 0; i < header->height; i++)
    {
        for (int j = 0; j < header->width; j++)
        {
            rotated[header->width - 1 - j][i] = this->pixels[i][j];
        }
    }
    for (int i = 0; i < header->height; i++)
    {
        delete[] this->pixels[i];
    }
    delete[] this->pixels;
    this->pixels = rotated;
    std::swap(header->width, header->height);
}

void BMP24bit::apply_filter(Filter* filter)
{
    filter->apply(this->pixels, header->height, header->width);
}

BMP24bit::~BMP24bit()
{
    for (int i = 0; i < header->height; i++)
    {
        delete[] this->pixels[i];
    }
    delete[] this->pixels;

    delete header;
    delete[] bytes_between_header_and_pixels;
}