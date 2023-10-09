#include "GaussianFilter.h"
#include "Pixel.h"
#include <cmath>
#include <vector>

Pixel GaussianFilter::get_pixel_val(Pixel** image, int height, int width, int x, int y)
{
    x = abs(x);
    y = abs(y);
    if (x >= height)
    {
        x = height - 1 - (x % height);
    }
    if (y >= width)
    {
        y = width - 1 - (y % width);
    }

    return image[x][y];
}

GaussianFilter::GaussianFilter(int _size, double _sigma)
    : sigma(_sigma), size(_size), radius(_size / 2)
{
    this->kernel = new double*[size];
    double kernel_sum = 0;
    for (int y = -radius; y <= radius; y++)
    {
        this->kernel[y + radius] = new double[size];
        for (int x = -radius; x <= radius; x++)
        {
            double exponent = -(x * x + y * y) / (2 * sigma * sigma);
            double value = exp(exponent) / (2 * M_PI * sigma * sigma);
            kernel[y + radius][x + radius] = value;
            kernel_sum += value;
        }
    }
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            kernel[y][x] /= kernel_sum;
        }
    }
}

GaussianFilter::~GaussianFilter()
{
    for (int i = 0; i < size; i++)
    {
        delete[] kernel[i];
    }
    delete[] kernel;
}

void GaussianFilter::apply(Pixel** image, int height, int width)
{
    // Создаем временный массив для хранения промежуточных результатов
    Pixel** tempImage = new Pixel*[height];
    for (int i = 0; i < height; i++)
    {
        tempImage[i] = new Pixel[width];
    }

    // Применяем гауссово размытие к каждому пикселю
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double r = 0, g = 0, b = 0;
            // Применяем маску к окружающим пикселям
            for (int j = -radius; j <= radius; j++)
            {
                for (int i = -radius; i <= radius; i++)
                {
                    Pixel tmp = get_pixel_val(image, height, width, y + j, x + i);
                    r += static_cast<double>(tmp.r) * kernel[j + radius][i + radius];
                    g += static_cast<double>(tmp.g) * kernel[j + radius][i + radius];
                    b += static_cast<double>(tmp.b) * kernel[j + radius][i + radius];
                }
            }

            tempImage[y][x].r = static_cast<uint8_t>(r);
            tempImage[y][x].g = static_cast<uint8_t>(g);
            tempImage[y][x].b = static_cast<uint8_t>(b);
        }
    }

    for (int i = 0; i < height; i++) {
        memcpy(image[i], tempImage[i], width * sizeof(Pixel));
    }

    // Освобождаем память, выделенную под временный массив
    for (int i = 0; i < height; i++)
    {
        delete[] tempImage[i];
    }
    delete[] tempImage;
}
