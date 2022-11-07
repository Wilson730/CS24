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
    std::set<Person*> sibs = siblings(pmod, smod);
    std::set<Person*> bros;
    for (auto itr = sibs.begin(); itr != sibs.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) bros.insert(*itr);
    }
    return bros;
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
    auto parnts = parents(pmod); // mum, pop, or both
    std::set<Person*> prntchilds;
    for (auto itr1 = parnts.begin(); itr1 != parnts.end(); ++itr1){
        prntchilds.merge((*itr1)->children());   // stores children of parent set
    } //  how about duplicates...

    std::set<Person*> sibs;                // ^ access their children
    for (auto itr = prntchilds.begin(); itr != prntchilds.end(); ++itr){
        switch (smod){
            case SMod::FULL:
            if (((*itr)->moth != nullptr) && ((*itr)->fath != nullptr)){
            if (((*itr)->moth->name() == this->moth->name() ) && ((*itr)->fath->name() == this->fath->name())) sibs.insert(*itr);
            }
            break;         // ^ if current sibling's mom has same name as my mom and they have hte same father as me. insert this person* into sibs

            case SMod::HALF:
            if (((*itr)->moth->name() == this->moth->name() ) || ((*itr)->fath->name() == this->fath->name())) sibs.insert(*itr);
            break;
            default:
            
            sibs.insert(*itr);
        }
    }
    return sibs;
  }

  std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> sibs = siblings(pmod, smod);
    std::set<Person*> siss;
    for (auto itr = sibs.begin(); itr != sibs.end(); ++itr){
        if ((*itr)->gender() == Gender::FEMALE) siss.insert(*itr);
    }
    return siss;
  }

  std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
