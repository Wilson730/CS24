#include "Nodes.h"

// Implement your AST subclasses' member functions here.


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();

std::string AST::prefix() const {

}

std::string AST::postfix() const {

}

double AST::value() const {

}

class addition: public AST{

};  // continue w/ substraciton, multiplication...negate