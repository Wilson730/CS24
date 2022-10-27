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
    size_t temp = count();
    if (mRoot == NULL) return 0;
    else delete mRoot;
    mRoot = NULL;
    return temp;
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


//---------------------------------------------------------------------------------
int insertre(const std::string&value, Node* currNode){
    if (currNode == NULL){
        return 0;
    }
    if (value < currNode->data){
        if (currNode->left == NULL){
            Node* newNode = new Node;   //
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->left = newNode;
            return 1;
        } else {
            currNode = currNode->left;
            return insertre(value, currNode); 
           
        }
    } else if (value > currNode->data){
        if (currNode->right == NULL){
            Node* newNode = new Node;  //
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            currNode->right = newNode;
            return 1;
        } else {
            currNode = currNode->right;
            return insertre(value, currNode);  
            
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
    int result = insertre(value, mRoot);     //
    return result;
}

//-------------------------------------------------------------------------------
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

/*
std::__1::string returnBiggest(const std::string& value, Node* currNode){
    while (currNode->data < value){
        if (currNode->left == NULL && currNode->right == NULL){
            return currNode->data;
        } else if (currNode->left == NULL){
            return returnBiggest(value, currNode->right);
        } else if (currNode->right == NULL){
            return returnBiggest(value, currNode->left);
        }
    }
    return currNode->data;
}
void checkLeaf(const std::string& value, Node* currNode, Node* prevNode){
    if (currNode->left == NULL && currNode->right == NULL){     // case 1: leaf node (w/ no children)
        delete currNode;               
    } 
    if (currNode->left != NULL || currNode->right != NULL){     // case 2: non leaf node (w/ 1+ children)
        if (currNode->left == NULL){                            // subcase 1: 1 children 164-166 checks which child is NULL
            prevNode->right = currNode->right;
        } else if (currNode->right == NULL){
            prevNode->left = currNode->left;
        }            
        delete currNode;
    } else {
        std::__1::string possibility1 = returnBiggest(value, currNode->left);
        std::__1::string possibility2 = returnBiggest(value, currNode->right);
        if (possibility1 < possibility2){
            currNode->data = possibility2;
            delete currNode;
        } else {
            currNode->data = possibility1;
            delete currNode;
        }
    }                                            
}
*/
size_t Set::remove (const std::string& value){
    size_t amountRemoved = 0;
 /*  Node* currNode = mRoot;
    Node* prevNode = NULL;
    if(!contains(value)){
        return amountRemoved;
    } else {
        while (currNode!= NULL){
            if (value < currNode->data)
            {
                prevNode = currNode;
                currNode = currNode->left;                  // so I need a prev node. 
            } else if (value > currNode->data){
                prevNode = currNode;
                currNode = currNode->right;
            } else if (value == currNode->data){
                checkLeaf(value, currNode, prevNode);
                return 1;
            }
        }
    }
    */
   
    return amountRemoved;
}