#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <string>
using namespace std;

AST* AST::parse(const std::string& expression) {
   
    istringstream stream(expression);
    string token;
    Stack stack;
    
    while (stream >> token){
        
        if (token == "+"){
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new add(lhs, rhs));
        } else if (token == "-"){
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new subtract(lhs, rhs));
        } else if (token == "*"){
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new multiply(lhs, rhs));
        } else if (token == "/"){
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new divide(lhs, rhs));
        } else if (token == "%"){
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new modulu(lhs, rhs));
        } else if (token == "~"){
           AST* child = stack.pop();
           if (child == nullptr) throw std::runtime_error("Not enough operands");
           stack.push(new neg(child));
        } else {
            size_t index = 0;
            double value = stod(token, &index);
            if(index != token.length()) throw std::runtime_error("invalid");
                
            numbers* newNumber = new numbers(value);
            stack.push(newNumber);
        }

    }
    
    return nullptr;
}


