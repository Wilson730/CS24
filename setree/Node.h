#ifndef NODE_H
#define NODE_H

// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
struct Node{
    std::string data;
    struct Node* left; 
    struct Node* right;
};


#endif
