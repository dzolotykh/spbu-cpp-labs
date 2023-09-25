#include <vector>
#include "Filter.h"

class GaussianFilter : public Filter {
private:
	std::vector<std::vector<double>> filter;

	double gaussian(double x, double y, double sigma);
	double get_pixel_val(std::vector<std::vector<double>>& image, int x, int y);
public:
	GaussianFilter(int size, double sigma);
	void apply(std::vector<std::vector<double>>& image);
};