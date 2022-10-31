#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
// Implement your AST subclasses' member functions here.


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();



addiNode::addiNode(){

}

addiNode::~addiNode(){
    delete left;
    delete right;
}
 // continue w/ substraciton, multiplication...negate



 