#include "Person.h"

// Person Member Functions
Person::Person(std::string name, std::string gender, Person* mother, Person* father, std::set<Person*> children){
    name = name;
    gender = gender;
    mother = mother;
    father = father;
    children = children;

}

Person::~Person(){


}

  const std::string& Person::name()  const {
    
  }
  Gender Person::gender() const {
    Gender temp;
    return temp;
  }
  Person*   Person::mother() {
    Person* temp;
    return temp;
  }
  Person*   Person::father() {
    return nullptr;
  }


  std::set<Person*> Person::ancestors(PMod pmod){                        // mostly copy and paste
    return std::set<Person*>();
  }
  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::children(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::cousins(PMod pmod, SMod smod){
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
  std::set<Person*> Person::parents(PMod pmod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
  std::set<Person*> Person::sons(){
    return std::set<Person*>();
  }
  std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
