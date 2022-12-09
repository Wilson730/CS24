#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
using namespace std;

AST* AST::parse(const std::string& expression) {
   
    istringstream stream(expression);
    string token;
    Stack stack;
    
    while (stream >> token){
        if (stack.size() < 2) throw std::runtime_error("2 operands needed");
        if (token == "+"){
         add* newNode = new add;
         newNode->left = stack.pop(); 
         newNode->right = stack.pop();
        stack.push(newNode);
        }
    }
    
    return nullptr;
}


