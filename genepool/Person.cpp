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
  
  std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    
    set<Person*> result;   
    std::set<Person*> pmodChildren;
    for (Person* parent : parents(pmod)){
        pmodChildren.merge(parent->children());  
    } 

                 // ^ access their children
    for (Person* child : pmodChildren){
        if (child->name() != this->name()){
        switch (smod){

            case SMod::HALF:   
            if (child->moth != nullptr){
            if ((child->moth->name() == this->moth->name()) && (child->fath == nullptr || child->fath->name() != this->fath->name())) result.insert(child);
            // same mother AND father doesnt exist or different father.
            }
            if (child->fath != nullptr){ 
            if ((child->fath->name() == this->fath->name()) && (child->moth == nullptr || child->moth->name() != this->moth->name())) result.insert(child);
            // same father AND mother doesn't exist  but different mother
            }
            break;        
            
            case SMod::FULL:   // makes sure both child and this have two parents
            if (((child->moth != nullptr) && (child->fath != nullptr)) && ((this->moth != nullptr) && (this->fath != nullptr))){
                if (((child)->moth->name() == this->moth->name()) && ((child)->fath->name() == this->fath->name())) result.insert(child);
                                 
            }
            break;          
                        // maybe hte problem si that this->moth or this->fath is pointing to a nullptr.
            default:          // ^ ^ ^ ^ ^ ^ ^ ^ ^
            
            result.insert(child);
            break;
        }
        }
    }
    return result;
  }
  
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> result = siblings(pmod, smod);
    std::set<Person*> bros;
    for (auto itr = result.begin(); itr != result.end(); ++itr){
        if ((*itr)->gender() == Gender::MALE) bros.insert(*itr);
    }
    return bros;
  }
  std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> result = siblings(pmod, smod);
    std::set<Person*> siss;
    for (auto itr = result.begin(); itr != result.end(); ++itr){
        if ((*itr)->gender() == Gender::FEMALE) siss.insert(*itr);
    }
    return siss;
  } 
  
  std::set<Person*> Person::ancestors(PMod pmod){                        // mostly copy and paste
    std::set<Person*> result; // creates an empty set that stores Person* s
    for (Person* parent: parents(pmod)){    // for every parent in the parent set created
        result.merge(parent->ancestors());    // get their parents
        result.insert(parent);            // insert 
    }
    return result;
  }  
  
  std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> result;
    for (Person* parent: parents(pmod)){
        result.merge(parent->brothers(PMod::ANY, smod));
    } 
    return result;
  } 
  
  std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> result;
    for (Person* parent: parents(pmod)){
        result.merge(parent->sisters(PMod::ANY, smod));
    } 
    return result;
  }

   std::set<Person*> Person::descendants(){
    std::set<Person*> result;
    for (Person* child : children()){
        result.merge(child->descendants());
        result.insert(child);
    }
    return result;
  }
 
  std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> result;
    for (Person* sibling : siblings(pmod, smod)){
        result.merge(sibling->sons());
    }
    return result;
  }
  
  std::set<Person*> Person::nieces(PMod pmod, SMod smod){
     std::set<Person*> result;
    for (Person* sibling2 : siblings(pmod, smod)){
        result.merge(sibling2->daughters());
    }
    return result;
  }
 

   std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> result;
    std::set<Person*> parentsibs;
    for (Person* parent: parents(pmod)){
        parentsibs.merge(parent->siblings(PMod::ANY, smod));
    }

    for (auto itr = parentsibs.begin(); itr != parentsibs.end(); ++itr){
        result.merge((*itr)->children());
    }

    return result;
  }
 
//-------------------------------------------------------unfinished----------------------------------------------------------------------------------

 
 
  

 


