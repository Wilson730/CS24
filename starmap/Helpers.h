#ifndef HELPERS_H
#define HELPERS_H
#include "Star.h"
#include <string>
// If you want to add any helper classes,
// here's some space to do it in.

// implement heap and kd tree
#endif

struct Node{
    Star* data;
    Node* left;
    Node* right;
};

void insert (Node* currNode, Node* newNode, string depth){
    if (depth == "x"){
        depth = "y";
        if (newNode->data->x < currNode->data->x)
        {
            if (currNode->left == nullptr) currNode->left = newNode;
            else insert(currNode, newNode, depth);
        }
        if (newNode->data->x > currNode->data->x)
        {   
            if (currNode->right == nullptr) currNode->right = newNode;
            else insert(currNode, newNode, depth);
        }
        
    }
    if (depth == "y"){
        depth = "z";
    }
    if (depth == "z"){
        depth = "x";
    }
};