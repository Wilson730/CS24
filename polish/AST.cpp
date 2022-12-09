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
            if (stack.size() < 2) {
                stack.clean();
                throw runtime_error("Need 1 or 2 operands");
            }
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new add(lhs, rhs));
        } else if (token == "-"){
            if (stack.size() < 2) {
                stack.clean();
                throw runtime_error("Need 1 or 2 operands");
            }
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new subtract(lhs, rhs));
        } else if (token == "*"){
            if (stack.size() < 2) {
            stack.clean();
            throw runtime_error("Need 1 or 2 operands");
            }
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new multiply(lhs, rhs));
        } else if (token == "/"){
            if (stack.size() < 2) {
                stack.clean();
                throw runtime_error("Need 1 or 2 operands");
            }
            AST* rhs = stack.pop();
            AST* lhs = stack.pop();
            if(lhs == nullptr || rhs == nullptr) {
             delete lhs;
             delete rhs;
            throw std::runtime_error("Invalid.");
            } 
            stack.push(new divide(lhs, rhs));
        } else if (token == "%"){
            if (stack.size() < 2) {
                stack.clean();
                throw runtime_error("Need 1 or 2 operands");
            }
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
           if (child == nullptr) {
           stack.clean();
           throw std::runtime_error("Need 1 operand");
           }
           stack.push(new neg(child));
        } else {
            size_t index = 0;
            double value = stod(token, &index);
            if(index != token.length()){
                stack.clean();
                throw std::runtime_error("invalid");
            }
            stack.push(new numbers(value));
        }

    }
    
    return nullptr;
}


