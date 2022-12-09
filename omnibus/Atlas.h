#ifndef ATLAS_H
#define ATLAS_H


#include <map>
#include <vector>
#include <string>
#include "Trip.h"
#include "Helpers.h"
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cstddef>
#include <iostream>
#include <istream>
#include <iomanip>
#include <stdexcept>
#include <queue>
using namespace std;


struct Station;

struct Neighbor{
  size_t distance;
  string line; 
  Station* nStation; // pointer to neighbor in map. 
  bool train;
};

struct Station {
  string name;
  string line; 

  vector<Neighbor*> neighbors; 
};

//---------------------------------------------------------------------

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
