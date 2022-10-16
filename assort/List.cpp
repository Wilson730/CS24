#include "List.h"
#include <string>
#include <iostream>

using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
// other is the other list 
}

List::List(List&& other){

}

List::~List(){

}

size_t List::count() const {
int count = 0;
Node* nullpt = NULL;
while (nullpt != NULL){
    count++;
    nullpt = nullpt->next;
}
    return count;
}

void List::insert(const std::string& value){
Node* newNode = new Node;
newNode->data = value;
newNode->next = NULL; 

if(head == NULL){
    head->next = newNode;
} else {
    Node* currNode = head;
    Node* prevNode = NULL;
    while (currNode->next != NULL && currNode->data < value){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode;
    currNode->data = value;

} 

}

const std::string& List::lookup(size_t index) const {
    Node* currNode = head;
    string temp = " ";
    if (index == 0){
        throw std::out_of_range("head does not contain a value");
    } else {
        for (size_t i = 1; i <= index + 1; i++){
            currNode = currNode->next;
        }
        temp = currNode->data;
    }
    return temp;
}

void List::print(bool reverse) const{ 
    Node* currNode = head;
    if (!reverse){
        cout << "[";
        while (currNode!= NULL){
        cout << currNode->data << ", ";
        currNode = currNode->next;
        }
        cout << "]" << "\n";
    } else {
        
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
string temp = prevNode->data;
prevNode = currNode->next;
return temp;
}

size_t List::remove(const std::string& value){
int count = 0;
Node* currNode = head;
Node* prevNode;
while (currNode->next != NULL){
    prevNode = currNode;
    currNode = currNode->next;
    if (currNode->data == value){
        prevNode = currNode->next;
        count++;
    }
    
}
return count;
}