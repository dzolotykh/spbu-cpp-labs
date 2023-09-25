#include <bits/stdc++.h>
#include <stdio.h>
#include "GaussianFilter.h"
#include "BMP8bit.h"

using namespace std;

int main() {
	GaussianFilter filter(31, 15);
	BMP8bit file("8bit_2.bmp");
	file.rotate_right();
	file.save("rotated_right.bmp");
	file.rotate_left();
	file.rotate_left();
	file.save("rotated_left.bmp");
	file.apply_filter(&filter);
	file.save("with_filters.bmp");
}

