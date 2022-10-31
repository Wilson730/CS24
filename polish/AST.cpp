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
    std::string number;
    Stack stack;
    while (stream >> token){
        switch(token){
            case '+':
                // stack.pop() 2 times
                // perform the addiNode class operation
                AST* left = stack.pop();
                AST* right = stack.pop();
                if (left == NULL || right == NULL){
                    delete left;
                    delete right;
                    throw std::out_of_range("temp");
                }
                add* addiNode = new add(left, right);
                stack.push(addiNode);
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
            Numbers* newNum = new Numbers(token);
            stack.push(newNum);
            return nullptr;
        }
    
    }
    
    return nullptr;
}


