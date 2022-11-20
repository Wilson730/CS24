#include "StarMap.h"
using namespace std;

StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.


  return new StarMap(stream);
}

StarMap::StarMap(std::istream& stream){
    head = nullptr;
    depth = "x";
    int id = 1;
    float x, y, z;
    while(stream){
      stream >> x >> y >> z; 
      Star* newStar = new Star({id, x, y, z});  
      // traverse kdtree insert function 
      Node* newNode = new Node;
      newNode->data = newStar;
      newNode->left = nullptr;
      newNode->right = nullptr;
      
      if (head == nullptr) head = newNode;
      else insert(newNode, depth);
      id++;
    }

}

StarMap::~StarMap(){
 
}

std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
  vector<Star>stars;
  return stars;
}
