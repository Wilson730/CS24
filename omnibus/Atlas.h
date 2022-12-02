#ifndef ATLAS_H
#define ATLAS_H

#include <istream>
#include <string>
#include <map>
#include <vector>
#include "Trip.h"
#include <sstream>
#include <unordered_map>
#include <cstddef>
#include "Helpers.h"
using namespace std;



class Atlas {
public:
  // Required Class Function
  static Atlas* create(std::istream& stream);

private:
  // Member Variables
  static unordered_map<string, Station*> atlas;
public:
  // Constructor & Destructor
  Atlas(std::istream& stream);
  ~Atlas();

  // Required Member Function
  Trip route(const std::string& src, const std::string& dst);
};

#endif
