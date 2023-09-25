#include "GaussianFilter.h"
#include <vector>
#include <cmath>

double GaussianFilter::get_pixel_val(std::vector<std::vector<double>>& image, int x, int y) {
	x = abs(x);
	y = abs(y);
	if (x >= image.size()) {
		x = image.size() - 1 - (x % (int)image.size());
	}
	if (y >= image[x].size()) {
		y = image[x].size() - 1 - (y % (int)image[x].size());
	}

	return image[x][y];
}

double GaussianFilter::gaussian(double x, double y, double sigma) {
    return (1.0 / (2.0 * M_PI * sigma * sigma)) * exp(-(x * x + y * y) / (2.0 * sigma * sigma));
}

GaussianFilter::GaussianFilter(int size, double sigma) {
    filter.resize(size, std::vector<double>(size, 0.0));

    // Вычисляем среднюю позицию фильтра
    int center = size / 2;

    // Заполняем матрицу коэффициентами Гаусса
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int x = i - center;
            int y = j - center;
            filter[i][j] = gaussian(x, y, sigma);
        }
    }

    // Нормализуем фильтр (сумма всех элементов равна 1)
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum += filter[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            filter[i][j] /= sum;
        }
    }
}

void GaussianFilter::apply(std::vector<std::vector<double>>& image) {
    int imageHeight = image.size();
    int imageWidth = image[0].size();
    int filterSize = filter.size();
    int filterRadius = filterSize / 2;

    std::vector<std::vector<double>> result(imageHeight, std::vector<double>(imageWidth, 0.0));

    for (int y = 0; y < imageHeight; ++y) {
        for (int x = 0; x < imageWidth; ++x) {
            double blurredPixel = 0.0;

            for (int i = -filterRadius; i <= filterRadius; ++i) {
                for (int j = -filterRadius; j <= filterRadius; ++j) {
                    int imageX = x + j;
                    int imageY = y + i;
                    blurredPixel += get_pixel_val(image, imageY, imageX) * filter[i + filterRadius][j + filterRadius];
                }
            }

            result[y][x] = blurredPixel;
        }
    }

    image = result;
}