#ifndef H_GaussianFilter
#define H_GaussianFilter

#include <vector>

#include "BMP24bit.h"
#include "Filter.h"

class GaussianFilter : public Filter {
 private:
  double** kernel;
  double sigma;
  int size;
  int radius;

  static Pixel get_pixel_val(Pixel** image, int height, int width, int x,
                             int y);

 public:
  GaussianFilter(int size, double sigma);
  ~GaussianFilter();
  void apply(Pixel** image, int height, int width);
};

#endif