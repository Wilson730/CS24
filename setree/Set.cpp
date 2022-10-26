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
    Node* currNode = mRoot;
    if (currNode == NULL){
        return false;
    }

    while (currNode != NULL){
        if (value < currNode->data){
        currNode = currNode->left;
        if (currNode == NULL){
            return false;
        }
        } else if (value > currNode->data){
        currNode = currNode->right;
        if (currNode == NULL){
            return false;
        }
        } else if (value == currNode->data){
        return true;
        }
    }

    return false;
}

size_t countre(Node* currNode){
    if (currNode == NULL){
        return 0;
    } else {
        return 1 + countre(currNode->left) + countre(currNode->right);
    }

}

size_t Set::count() const {

    Node* currNode = mRoot;
    return countre(currNode);
   
}

void Set::debug(){
    
}


size_t Set::insert(const std::string&value){
    Node* currNode = mRoot;
    if (currNode == NULL){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        currNode = newNode;
        return 1;
    }

    while (currNode != NULL){
    if (value == currNode->data){   // case equal
        return 0;
        
    } else if (value < currNode->data){ 

        if (currNode->left == NULL){     // case smaller
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->left = newNode;
            return 1;
        } else {
            currNode = currNode->left;
            continue;
        }
    } else if (value > currNode->data){  // case bigger
        if (currNode->right == NULL){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->right = newNode;
            return 1;
        } else {
            currNode = currNode->right;
            continue;
        }
    }

   
    }
    return 0;
}


const std::string& Set::lookup(size_t n) const {
  return NULL;
    
}

void printre(const Node* currNode){ // starts from the root. 
    if (currNode == NULL){
        cout << "-";
    } else if ((currNode->left != NULL) || (currNode->right != NULL)){ // nonleaf node contains 1+ v
        cout << "(";
        printre(currNode->left);  
        cout << " " << currNode->data << " ";  // parent in the middle
        printre(currNode->right); 
        cout << ")";
    } else  if ((currNode->left == NULL) && (currNode->right == NULL)){ // single leaf node
        cout << currNode->data;  
    }
    return;
}

void Set::print() const {
    Node* currNode = mRoot;
    printre(currNode);
    cout << "\n";
    return;
}

size_t Set::remove (const std::string& value){
    size_t amountRemoved = 0;
    Node* currNode = mRoot;
  
    while (currNode->data < value){

    }
    return amountRemoved;
}