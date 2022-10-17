#include "List.h"
#include <string>
#include <iostream>

using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
 
}

List::List(List&& other){

}

List::~List(){

}

size_t List::count() const {
int count = 0;
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
    if (index == 0){
        throw std::out_of_range("head does not contain a value");
    } else {
        for (size_t i = 1; i <= index + 1; i++){
            currNode = currNode->next;
        }
        return currNode->data;
    }
}

void List::print(bool reverse) const{ 
    int count = 0;
    Node* currNode = head;
    if (!reverse){
         while (currNode != NULL){
            

            count++;
            
            currNode = currNode->next;

        }
        currNode = head;
        cout << "[";
        for (int i = 0; i < count; i++){
            cout << currNode->data;

            cout << ", ";
            
            currNode = currNode->next;
        }
        cout << "]" << "\n";
       
    }   
}

std::string List::remove(size_t index){

Node* currNode = head;
Node* prevNode = NULL;
for (size_t i = 1; i <= index; i++){
    prevNode = currNode;
    currNode = currNode->next;
    if (currNode->next == NULL){
        throw std::out_of_range("out of range!");
    }
}
prevNode = currNode->next;
return prevNode->data;


}


size_t List::remove(const std::string& value){
int count = 0;
/* Node* currNode = head;
Node* prevNode = currNode;
while (currNode->next != NULL){
    prevNode = currNode;
    currNode = currNode->next;
    if (currNode->data == value){
        prevNode = currNode->next;
        count++;
    }
    
} */
return count;
}