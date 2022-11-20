#ifndef HELPERS_H
#define HELPERS_H
#include "Star.h"
#include <string>
// If you want to add any helper classes,
// here's some space to do it in.

// implement heap and kd tree
#endif

struct Entry {
  float score;
  Star star;

  bool operator < (const Entry& other) const {
    return this->score < other.score;
  }
};
   
