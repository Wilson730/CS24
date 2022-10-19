#include "List.h"
#include <string>
#include <iostream>

using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
    head = new Node();
    if (other.head == NULL){
        head = NULL;
    } else {

    head->data = other.head->data;   // new head's data copies old head's data
    Node* currNode = head;           // set dummy node on new head
    Node* otherNode = other.head->next;          // set dummy node on old head

    while (otherNode != NULL){             // while old list nodes don't reach the end
        Node* newNode = new Node();              // create new node
        newNode->data = otherNode->data;   // new node copies current old node's data (starting from head)
        newNode->next = otherNode->next;                    // set next to NULL
        currNode->next = newNode;                // current node next points to newnode

        otherNode = otherNode->next;             // iterate old node
        currNode = currNode->next;               // iterate new node
    }

 }
    delete(other.head);                          // delete old list
}



List::List(List&& other){
    this->head = other.head;
    other.head = NULL;
}

List::~List(){
    Node* currNode = head;
    Node* prevNode;
    while (currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        delete(prevNode);
    }
    delete (currNode);
}

size_t List::count() const {
size_t count = 0;
Node* currNode = head;
while (currNode != NULL){
    count++;
    currNode = currNode->next;
}
    return count;
}

void List::insert(const std::string& value){
Node* newNode = new Node;
newNode->next = NULL; 
newNode->data = value;

if(head == NULL){
    head = newNode;
} else if (value < head->data){   // if value is smaller than current head's value
    string temp = head->data;
    head->data = value;    // change current head's value to smaller value
    newNode->next = head->next;     // make newnode's next point to where head is pointing to next
    head->next = newNode;            // make head's next point to the newnode
    newNode->data = temp;        //make newnode's value current head's value. duplicat here
} else {
    Node* currNode = head;
    Node* prevNode;
    while (currNode != NULL && currNode->data <= value){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = newNode;
    newNode->next = currNode;
} 

}

const std::string& List::lookup(size_t index) const {
    Node* currNode = head;
    if (index >= count()){
        throw std::out_of_range("Index out of range.");
    } else {
        for (size_t i = 0; i < index; i++){
            currNode = currNode->next;
        }
        return currNode->data;
    }
}

void List::print(bool reverse) const{ 
    Node* currNode = head;
    Node* prevNode = NULL;
    if (!reverse){
         
        cout << "[";

        while (currNode != NULL){
            
                cout << currNode->data;     
                currNode = currNode->next;
                if (currNode != NULL){
                cout << ", "; 
                }
        }
        cout << "]" << "\n";

     
    } else {
        
        string tempStr = "]";
        while (currNode != NULL){
            
            tempStr = currNode->data + tempStr;
           
            if ((currNode->data) <= (head->data) && currNode->next != NULL){
                tempStr = ", " + tempStr;
            } 
           prevNode = currNode;
           currNode = currNode->next;
           prevNode->data = "why is it saying set but not used";
        }
        tempStr = "[" + tempStr;
        cout << tempStr << "\n";
    }
    
}

//---------------------------------------------------------------------------------------------------

std::string List::remove(size_t index){

Node* currNode = head;
Node* prevNode = NULL;
string temp = " ";             // test if index is greater than or equal to count after
if (head == NULL || index >= count()){  //---------------------------------  if list empty, exit. 
    throw std::out_of_range("Index out of range.");     

} else if (index == 0) {
    temp = currNode->data;
    prevNode = head;
    head = head->next;
    delete(prevNode);
} else {                                           // problem: how to link prevnode to the node after the deleted node?
    for (size_t i = 0; i < index; i++){
    prevNode = currNode;
    currNode = currNode->next;
    }
temp = currNode->data;
prevNode->next = currNode->next;
delete(currNode);
}

return temp;
}
//--------------------------------------------------------------------------------------------------

size_t List::remove(const std::string& value){
int count = 0;
int removed = 0;
Node* currNode = head;
while (currNode->data < value){
    currNode = currNode->next;
    count++;
}
while (currNode && currNode->data == value){
    currNode = currNode->next;
    remove(count);
    removed++;
}   
return removed;
}
