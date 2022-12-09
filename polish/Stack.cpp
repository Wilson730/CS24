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
    head = nullptr;
}

Stack::~Stack(){
    Node* currNode = nullptr;
    while (head != nullptr){
        currNode = head->next;
        delete head->data;
        delete head;
        head = currNode;
    }
    siz = 0;
}


AST* Stack::pop(){
    if (size() == 0) return nullptr;
    
    AST* result = head->data;
    Node* temphead = head->next;
    if (head == nullptr){                  // empty stack?
        throw std::out_of_range("empty");
    }
    delete head->data;
    delete head;
    head = temphead;
    siz--;
    return result;
}

/* AST* ast = stack.top()->data;
stack.pop();
return ast;
*/


void Stack::push(AST* token){
    Node* newNode = new Node;
    newNode->data = token;
    if (head == nullptr) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = head;
        head = newNode;
    }
    siz++;
}

size_t Stack::size(){
    return siz;
}