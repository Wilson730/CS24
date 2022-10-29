#ifndef STACK_H
#define STACK_H
#include "AST.h"
#include "AST.cpp"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

struct Node{
    AST* data;
    Node* next;
};


class Stack{
    Node* head;
    
    public:
    Stack();
    ~Stack();
    int pop();
    void push(int value);
};

#endif
