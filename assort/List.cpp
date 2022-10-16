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
    head = newNode;
} else {
    Node* currNode = head;
    Node* prevNode = NULL;
    while (currNode->next != NULL && currNode->data < value){
        currNode = currNode -> next;
    }
} 

}

const std::string& List::lookup(size_t index) const {

}

void List::print(bool reverse = false) const{
    if (!reverse){
        cout << "[";
        while (nullptr!= NULL){
        cout << /* this.data */  ", " ;
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