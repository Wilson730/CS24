#include "GenePool.h"

using namespace std;
// GenePool Member Functions
GenePool::GenePool(std::istream& stream){     // turns each line into person object
    string line;
    string name_string, gender_string, mother_string, father_string;
    Gender gender;
    Person* mother_ptr;
    Person* father_ptr;
    while (getline(stream, line)){
        if(line.empty() || line[0] == '#') {continue;
        } else {
            istringstream token(line);        // "So the first token you read will always be a name, the second one will always be a gender, and so on.
            getline(token, name_string, '\t'); // includes names with more than one word
            getline(token, gender_string, '\t');
            getline(token, mother_string, '\t');
            getline(token, father_string, '\t');
        if (gender_string == "male") gender = Gender::MALE;
        else gender = Gender::FEMALE;
        if (mother_string == "???") mother_ptr = nullptr;
        else mother_ptr = find(mother_string);
        
        if (father_string == "???") father_ptr = nullptr;
        else father_ptr = find(father_string);        // returns pointer to that father. this child can point to parent when we call. person mem functions

        }                             //string,  Gender, pointer, pointer (either Person* or nullptr)
        Person* person = new Person(name_string, gender, mother_ptr, father_ptr);
        people.insert({name_string, person});
    }

}

GenePool::~GenePool(){        // deletes all person objects (instances of the person class)
    for (auto itr = people.begin(); itr != people.end(); ++itr){
        delete itr->second;
    }
}

Person* GenePool::find(const std::string& name) const {
    for (auto itr = people.begin(); itr != people.end(); ++itr){
        if (itr->first == name) return itr->second;    // return parent pointers to child 
    }
    return nullptr;
}

// each person will have a {parent: "--" son: "--"} etc.