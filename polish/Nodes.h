#ifndef NODES_H
#define NODES_H
#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.



//----------------------------------------------------------------------------------------------------------------------------------------------
class numbers: public AST{
    double number;

    public:
    numbers(double token);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class add: public AST{
    
    public:
    AST* left;
    AST* right;

    add();
    ~add();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};


///----------------------------------- Focus on these 2 ^ --------------------------------------------------------------------------------------
class subtract: public AST{
    AST* left;
    AST* right;
    subtract(AST* token1, AST* token2);
    ~subtract();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
class multiply: public AST{
    AST* left;
    AST* right;
    multiply(AST* token1, AST* token2);
    ~multiply();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class divide: public AST{
    AST* left;
    AST* right;
    divide(AST* token1, AST* token2);
    ~divide();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class modulus: public AST{
    AST* left;
    AST* right;
    modulus(AST* token1, AST* token2);
    ~modulus();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class neg: public AST{
    
    ~neg();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
#endif
