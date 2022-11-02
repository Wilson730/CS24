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
class Numbers: public AST{
    double number;

    public:
    Numbers(char token);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class add: public AST{
    AST* left;
    AST* right;
    public:
    add(AST* token1, AST* token2);
    ~add();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

///----------------------------------- Focus on these 2 ^ --------------------------------------------------------------------------------------
class multiNode: public AST{
    multiNode();
    ~multiNode();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class diviNode: public AST{
    diviNode();
    ~diviNode();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class moduNode: public AST{
    moduNode();
    ~moduNode();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class negNode: public AST{
    negNode();
    ~negNode();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
#endif
