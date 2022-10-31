#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* AST::parse(const std::string& expression) {
   
    std::stringstream stream(expression);
    char token;
    AST* left;
    AST* right;
    Stack stack;
    while (stream >> token){
        switch(token){
            case '+':
                // stack.pop() 2 times
                // perform the addiNode class operation
                 left = stack.pop();
                 right = stack.pop();
                if (left == NULL || right == NULL){
                    delete left;
                    delete right;
                    throw std::out_of_range("temp");
                }
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


