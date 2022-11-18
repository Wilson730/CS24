#include "StarMap.h"
using namespace std;

StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.


  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
    int id = 1;
    float x, y, z;
    while(stream){
      stream >> x >> y >> z; 
      Star* newStar = new Star({id, x, y, z});  
      stars.insert({newStar});
      id++;
    }

}

StarMap::~StarMap(){

}

std::vector<Star> StarMap::find(size_t n, float x, float y, float z){


}
