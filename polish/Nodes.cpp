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

 

add::add(AST* token1, AST* token2) {
    left = token1;
    right = token2;

}

add::~add()  {
    delete left;
    delete right;
}

std::string add::prefix() const {
    return "+ " + left->prefix() + ' ' + right->prefix();
}

std::string add::postfix() const {
    return left->prefix() + ' ' + right->prefix() + " +";
}

double add::value() const{
    return left->value() + right->value();
};

//-----------------------------------------------------------

Numbers::Numbers(char token){
    number = token;
}




std::string Numbers::prefix() const {
    return std::to_string(number);
}

std::string Numbers::postfix() const {
    return std::to_string(number);
}

double Numbers::value() const {
    return number;
}


 