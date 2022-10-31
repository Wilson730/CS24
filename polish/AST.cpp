#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* parse(const std::string& expression) {
   
    std::stringstream stream(expression);
    char token;

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


