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
    if (mRoot == NULL){         // case 1 - empty list
        mRoot = newNode;
    } else {
        while (currNode != NULL){     
            if (value < currNode->data){   // case 2 - smaller than current
                if (currNode->left == NULL){
                    currNode->left = newNode;
                }         
                currNode = currNode->left;

            } else if (value > currNode->data ){   // case 3 - larger than current
            
                if (currNode->right == NULL){
                    currNode->right = newNode;
                }
                currNode = currNode->right; 
            } else if (value == currNode->data){
                return 1;
            }

        }

    }
    
    return 0;         
}

const std::string& Set::lookup(size_t n) const {
  return NULL;
    
}

void Set::print() const {
    Node* currNode = mRoot;
    if (currNode == NULL){
        cout << "-";
    }
    
}

size_t Set::remove (const std::string& value){
    size_t amountRemoved = 0;
    Node* currNode = mRoot;
  
    while (currNode->data < value){

    }
    return amountRemoved;
}