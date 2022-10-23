#include "Set.h"
#include <string>
#include <iostream>

using namespace std;

Set::Set(){
    mRoot = NULL;
}

Set::Set(const Set& other){

}

Set::Set(Set&& other){
    mRoot = other.mRoot;
    other.mRoot = NULL;
}

Set::~Set(){

    delete mRoot;
}
//-----------------------------------------------------------------------------------

size_t Set::clear(){
    size_t amRemoved = 0;
    return amRemoved;
}

bool Set::contains(const std::string&value) const {

    return false;
}

size_t Set::count() const {
    size_t totalinSet = 0;

    return totalinSet;
}

void Set::debug(){
    
}

size_t Set::insert(const std::string&value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;       // random node in mem containing value initialized
    newNode->right = NULL;
    Node* currNode = mRoot;

    if (mRoot == NULL){
        mRoot = newNode;
        mRoot->left = NULL;    // empty list? initialize set with a new head.
        mRoot->right = NULL;
        currNode = mRoot;
    } else if (mRoot != NULL && (mRoot->left == NULL || mRoot->right == NULL)) {
        if (value < mRoot->data){
            currNode = currNode->left;
        } 
        if (value > mRoot->data){
            currNode = currNode->right;
        }
    } else {
        while (currNode != NULL){
            if (currNode->left != NULL && value < currNode->left->data){
            currNode = currNode->left;
            } else if (currNode->right != NULL && value < currNode->right->data ){
            currNode = currNode->right; 
            }
        }

        currNode = newNode;

    }
    return 0;         
}

const std::string& Set::lookup(size_t n) const {
  return NULL;
    
}

void Set::print() const {

}

size_t Set::remove (const std::string& value){
    size_t amountRemoved = 0;
    Node* currNode = mRoot;
    Node* prevNode = NULL;
    while (currNode->data < value){

    }
    return amountRemoved;
}