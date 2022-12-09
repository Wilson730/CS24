#ifndef STACK_H
#define STACK_H
#include "AST.h"
#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <sstream>
#include <cmath>
#include <cstddef>
#include <stdexcept>
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

struct Node{
    AST* data;
    Node* next;    
};


class Stack{
    Node* head;           // creates a linked list. ok so form what im understanding node is not the individual leafs/nonleafs ina tree, but the actual nodes on linked list. 
    size_t siz;                     // and each node on linked list stores a pointer to a subtree, operator, etc. 

    public:
    Stack();              // initializes linked list.        
    ~Stack();             // deletes linked list and clean up partial ASTs
    AST* pop();          // pops the last pointer stored in the linked list on stack and returns it. 
    void push(AST* token);// pushes a pointer argument to the linked list on stack. 
    size_t size();        // returns Stack length

};

#endif
