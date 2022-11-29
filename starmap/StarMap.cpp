#include "StarMap.h"
using namespace std;

StarMap* StarMap::create(std::istream& stream) {
  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
    // Initializatino
   
    int id = 1;
    float x, y, z;
   
    while(stream){
      stream >> x >> y >> z; 
      Star nStar = Star({id, x, y, z});  
      Entry nEntry = Entry({0, nStar});
      insert(nEntry, root, 0);
      id++;
    }

}

StarMap::~StarMap(){
 
}

std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
  vector<Star> result;
  priority_queue<Entry> Entries;  /* Traverses the KD Tree. stores entries, 
  max by default. meaning, small to biggest
  split into median. into smaller data sets
  */
  // 1. traverse to the part where your spaceship is
  // 2. push every star you encounter (and calculate their distance) until heap is full
  // 3. if heap is full, compare to top (the current worst distance) using bool operator. if farther, replace it. 
  // 4. go to the other branch (only if you might find good stars there. refer back to vid). 
  return result;
}
