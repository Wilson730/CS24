#include "Person.h"

using namespace std;
// Person Member Functions

Person::Person(string n, Gender g, Person* m, Person* f){
    nam = n;
    gend = g;
    moth = m;
    fath = f;
    if (moth != nullptr) moth->childs.insert(this);
    if (fath != nullptr) fath->childs.insert(this);
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
    if (pmod == PMod::MATERNAL && moth != nullptr)parents.insert(moth);
    if (pmod == PMod::PATERNAL && fath != nullptr) parents.insert(fath);
    if (pmod == PMod::ANY){
        if (moth!= nullptr) parents.insert(moth);
        if (fath!= nullptr) parents.insert(fath);
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
  
  std::set<Person*> Person::grandfathers(PMod pmod){
     auto grndfthrs = grandparents(pmod);
    std::set<Person*> grndfthrs1;
    for (auto itr = grndfthrs.begin(); itr != grndfthrs.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) grndfthrs1.insert(*itr);
    }
    return grndfthrs1;
  }
  std::set<Person*> Person::grandmothers(PMod pmod){
    auto grndmthrs = grandparents(pmod);
    std::set<Person*> grndmthrs1;
    for (auto itr = grndmthrs.begin(); itr != grndmthrs.end(); ++itr){
        if ((*itr)->gender() == Gender::FEMALE) grndmthrs1.insert(*itr);
    }
    return grndmthrs1;
  }
  std::set<Person*> Person::grandparents(PMod pmod){
    auto parnts  = parents(pmod);
    std::set<Person*> grndparnts;
    for (auto itr = parnts.begin(); itr != parnts.end(); ++itr){
        if ((*itr)->moth != nullptr) grndparnts.insert((*itr)->moth);
        if ((*itr)->fath != nullptr) grndparnts.insert((*itr)->fath);
    }
    return grndparnts;
  } 
  
  std::set<Person*> Person::grandchildren(){
    std::set<Person*> childrenchildren;
    auto tempchildren = children();
    for (auto itr = tempchildren.begin(); itr != tempchildren.end(); ++itr){
        childrenchildren.merge((*itr)->children());
    }
    return childrenchildren;
  }
  std::set<Person*> Person::granddaughters(){
    auto grndchldrn = grandchildren();
    std::set<Person*> female1;
    for (auto itr = grndchldrn.begin(); itr != grndchldrn.end(); ++itr){
        if ((*itr)->gender() == Gender::FEMALE) female1.insert(*itr);
    }
    return female1;
  }
 
  std::set<Person*> Person::grandsons(){
    auto grndchldrn = grandchildren();
    std::set<Person*> male1;
    for (auto itr = grndchldrn.begin(); itr != grndchldrn.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) male1.insert(*itr);
    }
    return male1;
  }
//-------------------------------------------------------unfinished----------------------------------------------------------------------------------

  std::set<Person*> Person::ancestors(PMod pmod){                        // mostly copy and paste
    std::set<Person*> ancestors;
   
    return std::set<Person*>();
  }
  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
   // std::set<Person*> auntsisters = this->moth->sisters(pmod, smod);

    return std::set<Person*>();
  }
  
  
  std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    return std::set<Person*>();
  }
 
  std::set<Person*> Person::descendants(){
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
        if (((*itr)->name() != this->name()) && ((*itr)->moth != nullptr && (*itr)->fath != nullptr)){
        switch (smod){
            
            case SMod::FULL:
            if (((*itr)->moth->name() == this->moth->name()) && ((*itr)->fath->name() == this->fath->name())) sibs.insert(*itr);
                           // ^ checks whether both of our parents have same names
            break;          
            
            case SMod::HALF:
            if ((((*itr)->moth->name() == this->moth->name()) && ((*itr)->fath->name() != this->fath->name())) || (((*itr)->fath->name() == this->fath->name()) && ((*itr)->moth->name() != this->moth->name()))) sibs.insert(*itr);
            break;         // ^ checks if same mom but diff dad, or same dad but diff mom
            
            case SMod::ANY:
            sibs.insert(*itr);
            break;

            default:
            break;
        }
        }
    }
    return sibs;
  }
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> sibs = siblings(pmod, smod);
    std::set<Person*> bros;
    for (auto itr = sibs.begin(); itr != sibs.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) bros.insert(*itr);
    }
    return bros;
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
