#include <iostream>
#include "Stack.h"
#include "AST.h"
#include "Nodes.cpp"
#include "Nodes.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* parse(const std::string& expression) {
   
    std::stringstream stream(expression);
    char token;

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


