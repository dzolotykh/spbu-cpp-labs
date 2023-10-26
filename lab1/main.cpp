#include <cstdio>
#include <iostream>
#include <map>
#include <string>

#include "BMP24bit.h"
#include "GaussianFilter.h"

using namespace std;

map<string, string> parse_named_arguments(int argc, char* argv[]) {
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

string add_to_name(const string& name, const string& need_add) {
  string new_name = name;
  new_name.resize(name.size() - 4);
  new_name += need_add;
  new_name += ".bmp";
  return new_name;
}

int main(int argc, char* argv[]) {
  map<string, string> named_args = parse_named_arguments(argc, argv);

  if (named_args.count("filename") == 0) {
    cout << "Необходимо ввести имя файла через аргумент командной строки "
            "-filename"
         << endl;
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
  BMP24bit file(filename);
  file.rotate_right();
  file.save(add_to_name(filename, "_rotated_right"));
  file.rotate_left();
  file.rotate_left();
  file.save(add_to_name(filename, "_rotated_left"));
  file.apply_filter(&filter);
  file.save(add_to_name(filename, "_with_filters"));

  cout << "OK" << endl;
  return 0;
}
