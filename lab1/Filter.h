#ifndef H_Filter
#define H_Filter

class Filter {
public:
	virtual ~Filter() {}
	virtual void apply(std::vector<std::vector<double>>& image) = 0;
};

#endif