#include "List.h"
#include <string>
#include <iostream>

using namespace std;

List::List(){
    head = NULL;
    Node* curr = NULL;
}

List::List(const List& other){
// other is the other list 
}

List::List(List&& other){

}

List::~List(){

}

size_t List::count() const {

}

List insert(const std::string& value){
Node* n = new Node;
n->data = value;

}

const std::string& List::lookup(size_t index) const {

}

void List::print(bool reverse = false) const{

}

std::string List::remove(size_t index){
/* to remove value from a linked list, change the "next"
the prev node is pointing to to the node above. 
so t->next (the prev one) = n + 1 something. idk. 
*/
}

size_t List::remove(const std::string& value){

}