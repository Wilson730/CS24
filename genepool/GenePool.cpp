#include "GenePool.h"
#include <string>
// GenePool Member Functions

GenePool::GenePool(std::istream& stream){     // turns each line into person object
/*
    while(getline(stream)){
        if (empty || first character == #) continue;
        else split it into name, gender, etc. based on tabs. 
        create a new person object for every line. 
    }
*/
}

GenePool::~GenePool(){        // deletes all person objects (instances of the person class)

}

Person* GenePool::find(const std::string& name) const {
    return nullptr;
}

// each person will have a {parent: "--" son: "--"} etc.