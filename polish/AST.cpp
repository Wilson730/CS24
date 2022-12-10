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
             stack.clean();
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
             stack.clean();
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
             stack.clean();
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
             stack.clean();
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
             stack.clean();
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
            try{
                if(index != token.length()){
                    stack.clean();
                    throw std::runtime_error("invalid");
                }
                stack.push(new numbers(value));
            }
            
            catch(...){
                stack.clean();
                throw std::runtime_error("invalid");
            }
        }

    }
    AST* root = stack.pop();
    if (root != nullptr){
        return root;
    } else {
        throw std::out_of_range("Stack is empty!");
    }
}


// if seg fault continues. create new node step by step inside
// so add* nwenode = new add; instead of new add(token1, token2);

// check if the newly impelemented return root works. if not, 
// go to default. just return root. 


// stack size cases: 0, more than 2. and what exactly does it mean 
// to push a subclass ast onto the stack? like add for ex. 
// what happens when there's an add ast and two numbers are pushed? 
// 

// also check delete head->data. that could be a problem 
// since it appeared in seg fault before. 
// if ti appears again, make a temp AST* temp and set it to head->data & delete it