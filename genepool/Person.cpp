#include "Person.h"

// Person Member Functions
Person::Person(){

}

Person::~Person(){


}

  std::set<Person*> Person::ancestors(PMod pmod = PMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::children(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::daughters(){
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
  std::set<Person*> Person::grandfathers(PMod pmod = PMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandmothers(PMod pmod = PMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandparents(PMod pmod = PMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::grandsons(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::parents(PMod pmod = PMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
  std::set<Person*> Person::sons(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    return std::set<Person*>();
  }
