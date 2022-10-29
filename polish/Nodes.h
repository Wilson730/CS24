#ifndef NODES_H
#define NODES_H
#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.


struct Node{
    AST* data;
    Node* next;
};


class Numbers: public AST{
    double number;
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class addition: public AST{
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class multiplication: public AST{
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class division: public AST{
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class modulus: public AST{
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};

class negate: public AST{
    virtual std::string prefix() const = 0;
    virtual std::string postfix() const = 0;
    virtual double value() const = 0;
};
#endif
