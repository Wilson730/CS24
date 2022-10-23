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

}

bool Set::contains(const std::string&value) const {

}

size_t Set::count() const {

}

void Set::debug(){

}

size_t Set::insert(const std::string&value){

}

const std::string& Set::lookup(size_t n) const {

}

void Set::print() const {

}

size_t remove (const std::string& value){

}