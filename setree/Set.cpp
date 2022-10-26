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

int insertre(const std::string&value, Node* currNode){
    if (value < currNode->data){
        if (currNode->left == NULL){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->left = newNode;
            return 1;
        } else {
            currNode = currNode->left;
            if (currNode != NULL){
            insertre(value, currNode);  //  returns 1 for sure
            } else {
                return 1;   // returns 0 meaning doesn't exist
            }
        }
    } else if (value > currNode->data){
        if (currNode->right == NULL){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->right = newNode;
            return 1;
        } else {
            currNode = currNode->right;
            if (currNode != NULL){
            insertre(value, currNode);  // returns 1 for sure
            } else {
                return 1;
            }
        }
    }

    if (value == currNode->data){
        return 0;
    }
    
    
    return 0;
}

size_t Set::insert(const std::string&value){
    if (mRoot == NULL){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        mRoot = newNode;
        return 1;
    }
    int result = insertre(value, mRoot);  // what's the problem? new nodes?
    return result;
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