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
    Node* head;           // creates a linked list. ok so form what im understanding node is not the individual leafs/nonleafs ina tree, but the actual nodes on linked list. 
                          // and each node on linked list stores a pointer to a subtree, operator, etc. 

    public:
    Stack();              // initializes linked list.        
    ~Stack();             // deletes linked list. 
    Node* pop();          // pops the last pointer stored in the linked list on stack and returns it. 
    void push(AST* token);// pushes a pointer argument to the linked list on stack. 
};

#endif
