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
newNode->data = value;2
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
    if (index == 0){
        throw std::out_of_range("head does not contain a value");
    } else {
        for (int i = 1; i <= index + 1; i++){
            currNode = currNode->next;
            if (currNode->next == NULL){
                return currNode->data;
            }
        }
    }
}

void List::print(bool reverse = false) const{ 
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
/* to remove value from a linked list, change the "next"
the prev node is pointing to to the node above. 
so t->next (the prev one) = n + 1 something. idk. 
*/
}

size_t List::remove(const std::string& value){


}