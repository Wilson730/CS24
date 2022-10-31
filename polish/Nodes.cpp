#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <sstream>
// Implement your AST subclasses' member functions here.


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();



addiNode::addiNode(AST* token1, AST* token2){
    left = token1;
    right = token2;
}

addiNode::~addiNode(){
    delete left;
    delete right;
}

std::string addiNode::prefix() const {
    
}





 