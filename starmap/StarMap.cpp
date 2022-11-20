#include "StarMap.h"
using namespace std;

StarMap* StarMap::create(std::istream& stream) {
  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
    head = nullptr;
    char depth = 'x';
    int id = 1;
    float x, y, z;
    while(stream){
      stream >> x >> y >> z; 
      Star* newStar = new Star({id, x, y, z});  
      // traverse kdtree insert function 
      Entry* newNode = new Entry;
      
      id++;
    }

}

StarMap::~StarMap(){
 
}

std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
  vector<Star>minstars;
  priority_queue<Entry> Entries;
  return minstars;
}
