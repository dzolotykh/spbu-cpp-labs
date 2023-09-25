#pragma once

class Filter {
public:
	virtual ~Filter() {}
	virtual void apply(std::vector<std::vector<double>>& image) = 0;
};
