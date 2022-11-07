#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* AST::parse(const std::string& expression) {
   
    stringstream stream(expression);
    char token;
    std::string number;
    Stack stack;
    
    while (stream >> token){
        AST* left;
        AST* right;
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
                stack.push(new add(left,right));
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
            if (isdigit(token)){
                number = token;
            }
            stack.push(new Numbers(token));
            return nullptr;
        }
    
    }
    
    return nullptr;
}


