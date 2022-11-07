#include "Person.h"

using namespace std;
// Person Member Functions

Person::Person(string n, Gender g, Person* m, Person* f){
    nam = n;
    gend = g;
    moth = m;
    fath = f;
    if (moth != nullptr) moth->childs.insert({this});
    if (fath != nullptr) fath->childs.insert({this});
}

  const std::string& Person::name() const {
    return nam;
  }
  Gender Person::gender() const {
    return gend;
  }
  Person*  Person::mother() {
    return moth;
  }
  Person*  Person::father() {
    return fath;
  }


  std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> parents;
    if (pmod == PMod::MATERNAL && moth != nullptr)parents.insert({moth});
    if (pmod == PMod::PATERNAL && fath != nullptr) parents.insert({fath});
    if (pmod == PMod::ANY){
        if (moth!= nullptr) parents.insert({moth});
        if (fath!= nullptr) parents.insert({fath});
    }
    
    return parents;
  }

  std::set<Person*> Person::children(){
    return childs;
  } 
  
  std::set<Person*> Person::daughters(){
    std::set<Person*> childs = children();
    std::set<Person*> femalechilds;
    for (auto itr = childs.begin(); itr != childs.end(); ++itr){
        if ((*itr)->gender() == Gender::FEMALE) femalechilds.insert((*itr));
    }
    return femalechilds;
  }  
  
  std::set<Person*> Person::sons(){
    std::set<Person*> childs = children();
    std::set<Person*> malechilds;
    for (auto itr = childs.begin(); itr != childs.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) malechilds.insert((*itr));
    }
    return malechilds;
  }
//-------------------------------------------------------unfinished----------------------------------------------------------------------------------

  std::set<Person*> Person::ancestors(PMod pmod){                        // mostly copy and paste
    std::set<Person*> ancestors;
   
    return std::set<Person*>();
  }
  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  
  std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
 
  std::set<Person*> Person::descendants(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandchildren(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::granddaughters(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandfathers(PMod pmod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandsons(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
 
  std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> parnts = parents(pmod);
    std::set<Person*> sibs;
    for (auto itr = parnts.begin(); itr != parnts.end(); ++itr){
        sibs.merge((*itr)->children());
    }
    return sibs;
  }
  std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    return std::set<Person*>();
  }

  std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
