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
        
        if (token == "+"){
            if (stack.size() < 2) throw std::runtime_error("2 operands needed");
            add* newNode = new add;
            newNode->left = stack.pop(); 
            newNode->right = stack.pop();
            stack.push(newNode);
        } else if (token == "-"){
            return;
        } else if (token == "*"){
            return;
        } else if (token == "/"){
            return;
        } else if (token == "%"){
            return;
        } else if (token == "-"){
            return;
        } else {
            size_t reference;
             if(reference != token.length()) throw std::runtime_error("invalid");
                
            double numConvertor = stod(token, &reference);
            numbers* newNumber = new numbers(numConvertor);
            stack.push(newNumber);
        }

    }
    
    return nullptr;
}


