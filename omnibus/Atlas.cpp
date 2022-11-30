#include "Atlas.h"
using namespace std;
Atlas* Atlas::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.

string l, identifier, name, numS; 
int num;
while(std::getline(stream, l)) {
	if(l.length() == 0 || l[0] == '#') 
		continue;

	std::istringstream sstream(l);
	sstream >> identifier;
	
	if(identifier == "-") {
		sstream >> numS; num = stoi(numS);
		sstream >> std::ws;
		getline(sstream, name);	
	}

}

  return new Atlas(stream);
}

Atlas::~Atlas(){
  
}

Trip Atlas::route(const std::string& src, const std::string& dst){
// min heap and dijstras to find vector of shortest distances. 
}