#ifndef HELPERS_H
#define HELPERS_H
#include "Atlas.h"
#include <string>
// If you want to add any helper classes,
// here's some space to do it in.
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


#endif
