#ifndef NODES_H
#define NODES_H
#include "AST.h"
#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.




class Numbers: public AST{
    double number;
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class addiNode: public AST{
    AST* left;
    AST* right;

    addiNode();
    ~addiNode();
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class multiNode: public AST{
    multiNode();
    ~multiNode();
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class diviNode: public AST{
    diviNode();
    ~diviNode();
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class moduNode: public AST{
    moduNode();
    ~moduNode();
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class negNode: public AST{
    negNode();
    ~negNode();
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};
#endif
