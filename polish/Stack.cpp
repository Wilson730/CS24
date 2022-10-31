#include "Stack.h"
#include "AST.h"
#include "Nodes.h"
#include <iostream>
#include "Stack.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
// Implement your Stack member functions here.

// q: what functions should we have in our stack class?
// a: constructor, destructor, push, pop, ~ top would also be helpful

//Your stack isn’t a subclass of AST. It stores AST*s, but it’s a separate type (like how FibVec stored ints, but wasn’t an int).

// q: Yeah I think I meant something different than what I typed...in our stack, we want to initialize and array that holds data of type AST* right?

// a: Ah. Yep - exactly.

// And you can choose if you want to use a vector stack or a linked list stack (I used a linked list so I wouldn’t have

Stack::Stack(){
    head = NULL;
}

Stack::~Stack(){
    Node* currNode = head;
    Node* prevNode = NULL;
    while (currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }
    delete currNode->data;
    delete currNode;
}


AST* Stack::pop(){
    AST* temp = NULL;
    Node* currNode = head;
    Node* prevNode = NULL;
    if (currNode == NULL){                  // empty stack?
        throw std::out_of_range("empty");
    } else {
    while (currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
    }
    temp = prevNode->data;
    delete prevNode->data;
    delete prevNode;
    delete currNode;
    }
    return temp;
}

void Stack::push(AST* token){
    Node* newNode = new Node;
    newNode->data = token;
    Node* currNode = head;
    Node* prevNode = NULL;
    newNode->data = token;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    } else {
        while (currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
        }
        currNode = newNode;
        prevNode->next = currNode;
    }
}

size_t Stack::size(){
    size_t count = 0;
    Node* currNode = head;
    while (currNode != NULL){
        currNode = currNode->next;
        count++;
    }
    return count;
}