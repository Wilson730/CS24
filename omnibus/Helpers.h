#ifndef HELPERS_H
#define HELPERS_H
#include "Atlas.h"
#include <string>
// If you want to add any helper classes,
// here's some space to do it in.
using namespace std;

struct Neighbor{
  size_t distance;
  string line; // (line used to get to *this* neighbor)
  Station* nStation;
  bool train;
};

struct Station {
  string name;
  string line; // (to get to *this* station)
  vector<Neighbor*> neighbors;
};

#endif
