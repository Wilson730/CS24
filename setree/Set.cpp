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

size_t countre(Node* currNode){
    int currNodeCount = 0;
    if (currNode == NULL){
        return 0;
    } else if (currNode->left != NULL || currNode->right != NULL){
        
        currNodeCount = countre(currNode->left) + countre(currNode->right);

    } else if (currNode->left == NULL && currNode->right == NULL ){
        currNodeCount += currNode->count; // should be 1 if it's a leaf node
    }

    return currNodeCount;
}

size_t Set::count() const {

    Node* currNode = mRoot;
    return countre(currNode);
   
}

void Set::debug(){
    
}

size_t Set::insert(const std::string&value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;       // random node in mem containing value initialized
    newNode->right = NULL;
    Node* currNode = mRoot;
    size_t total = 0;
    if (mRoot == NULL){         // case 1 - empty list
        mRoot = newNode;
        mRoot->count = 1;
        total++;
    } else {
        while (currNode != NULL){     
            if (value < currNode->data){   // case 2 - smaller than current
                if (currNode->left == NULL){
                    currNode->left = newNode;
                    newNode->count+= 1;
                }         
                currNode = currNode->left;
                total += currNode->count;
            } else if (value > currNode->data ){   // case 3 - larger than current
            
                if (currNode->right == NULL){
                    currNode->right = newNode;
                    newNode->count += 1;             
                }
                currNode = currNode->right; 
                total += currNode->count;
            }
        }

    }
    
    return total;         
}


const std::string& Set::lookup(size_t n) const {
  return NULL;
    
}

void printre(const Node* currNode){ // starts from the root. 
     
    if (currNode->left != NULL || currNode->right != NULL){ // nonleaf node contains 1+ v
        cout << "(";
        currNode = currNode->left; 
        printre(currNode);  // check for more parents ^ 
        cout << " " << currNode->data << " ";  // parent in the middle
        currNode = currNode->right;
        printre(currNode); 
        cout << ")";
    } else  if (currNode->left == NULL && currNode->right == NULL){ // single leaf node
        cout << currNode->data;  
    } else if (currNode == NULL){ // non existent node
        cout << "-";
    }
    cout << "\n";
}

void Set::print() const {
    Node* currNode = mRoot;
    printre(currNode);

    return;
}

size_t Set::remove (const std::string& value){
    size_t amountRemoved = 0;
    Node* currNode = mRoot;
  
    while (currNode->data < value){

    }
    return amountRemoved;
}