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

using namespace std;


struct Neighbor{
  size_t distance;
  string line; // (line used to get to *this* neighbor)
  Station* nStation;
  bool train;
};

struct Station {
  string name;
  Station* pStation;
  string line; // (to get to *this* station)
  vector<Neighbor> neighbors;
};

class Atlas {
public:
  // Required Class Function
  static Atlas* create(std::istream& stream);

private:
  // Member Variables
  static unordered_map<string, Station> atlas;
public:
  // Constructor & Destructor
  Atlas(std::istream& stream);
  ~Atlas();

  // Required Member Function
  Trip route(const std::string& src, const std::string& dst);
};

#endif
