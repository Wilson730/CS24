#include "Atlas.h"

using namespace std;
Atlas *Atlas::create(std::istream &stream)
{
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.

  string tLine, line, identifier, name, numS;
  int num = 0, prevnum = -1;
  Station *prevS = nullptr;
  bool train;

  while (std::getline(stream, tLine))
  {
    if (tLine.length() == 0 || tLine[0] == '#')
      continue;

    std::istringstream sstream(tLine);
    sstream >> identifier;

    if (identifier == "-")
    {
      sstream >> numS;
      num = stoi(numS);
      sstream >> std::ws;
      getline(sstream, name);
    }
    
    if (identifier == "TRAIN:"){
      train = true;
      prevS = nullptr;
    }
    else {
    train = false;
    prevS = nullptr;
    getline(sstream, line);
    continue;
    }
    // ------------------------------------------------------
    auto itr = atlas.find(name);
    if (itr == atlas.end())
    { // if by the end no repeat is found, create and store new station
      Station* curStation = new Station;
      curStation->name = name;
      curStation->line = line;
      atlas[name] = curStation;

      Neighbor *tedge = new Neighbor;
      Neighbor *bedge = new Neighbor;
      if (prevS)  //case1: top edge exists
      {
        if (train)
        {
          tedge->distance = abs(prevnum - num);
          bedge->distance = abs(prevnum - num);
        }
        else
        {
          tedge->distance = 0;
          bedge->distance = 0;
        }
        tedge->line = line; 
        tedge->train = train;
        tedge->nStation = prevS;
      
        curStation->neighbors.push_back(tedge);

        bedge->line = line;
        bedge->train = train;
        bedge->nStation = curStation;
        prevS->neighbors.push_back(bedge);
      }
        //case2: no topedge
        prevnum = num;
        prevS = curStation;
    } else {
           // equinox      // pisces's line is zodiac line 
      if (line == itr->second->line){
      Neighbor *tedge = new Neighbor;
      Neighbor *bedge = new Neighbor;

      tedge->distance = abs(prevnum - num); // pisces points to aries
      tedge->line = line;
      tedge->train = train;
      tedge->nStation = itr->second;
      prevS->neighbors.push_back(tedge);

      bedge->distance = abs(prevnum - num);
      bedge->line = line;
      bedge->train = train;          // aries points to prev
      bedge->nStation = prevS;
      itr->second->neighbors.push_back(bedge);
      } else {   // pointer to pisces rn. 

        if (prevS == nullptr){
          prevS = itr->second; // prevstation is pisces 
          prevnum = num;   // prevnum is 3
        } else {
          Neighbor *tedge = new Neighbor;      // pisces -> virgo
          Neighbor *bedge = new Neighbor;     //  virgo -> pisces
          tedge->distance = abs(prevnum - num); 
          tedge->line = line;  // equinox
          tedge->train = train;
          tedge->nStation = itr->second;  // top edge points to virgo
          prevS->neighbors.push_back(tedge);  // topedge added to prevstation (pisces)

          bedge->distance = abs(prevnum - num);
          bedge->line = line;
          bedge->train = train;
          bedge->nStation = prevS; // bottom edge points to pisces
          itr->second->neighbors.push_back(bedge);
        }
      }
    }
  }
  return new Atlas(stream);
}

Atlas::~Atlas()
{

}

Trip Atlas::route(const std::string &src, const std::string &dst)
{
  // min heap and dijstras to find vector of shortest distances.
  Trip result;
  result.start = src;

  unordered_set<Station*> mindst;
  unordered_set<Station*> visited;

 

  return result;
  // create heap, map of distances, and a set.
}