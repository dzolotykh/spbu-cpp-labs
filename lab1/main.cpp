#include <bits/stdc++.h>
#include <stdio.h>
#include "GaussianFilter.h"
#include "BMP8bit.h"

using namespace std;



#include <iostream>
#include <string>
#include <map>

map<string, string> ParseNamedArguments(int argc, char* argv[]) {
    map<string, string> named_args;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg.substr(0, 1) == "-") {
            string arg_name = arg.substr(1);
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                named_args[arg_name] = argv[i + 1];
                ++i; 
            } else {
                named_args[arg_name] = "true";
            }
        }
    }

    return named_args;
}


int main(int argc, char* argv[]) {
	map<string, string> named_args = ParseNamedArguments(argc, argv);

	if (named_args.count("filename") == 0) {
		cout << "Необходимо ввести имя файла через аргумент командной строки -filename" << endl;
		return 0;
	}

	string filename = named_args["filename"];

	int size = 31;
	if (named_args.count("size")) {
		size = atoi(named_args["size"].c_str());
	}

	int sigma = 11;
	if (named_args.count("sigma")) {
		sigma = atoi(named_args["sigma"].c_str());
	}

	GaussianFilter filter(size, sigma);
	BMP8bit file(filename);
	file.rotate_right();
	file.save("rotated_right_" + filename);
	file.rotate_left();
	file.rotate_left();
	file.save("rotated_left_" + filename);
	file.apply_filter(&filter);
	file.save("with_filters_" + filename);

	cout << "OK" << endl;
	return 0;
}

