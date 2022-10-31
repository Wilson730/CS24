#include "AST.h"
#include "Nodes.cpp"
#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* AST::parse(const std::string& expression) {
   
    char token;
    std::stringstream stream(expression);

    Stack stack;
    while (stream >> token){
        switch(token){
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            case '%':
                break;
            case '~':
                break;
            default:
        }
    
    }
    
    return nullptr;
}


std::string AST::prefix() const {

}

std::string AST::postfix() const {

}

double AST::value() const {
    
}

