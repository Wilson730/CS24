#include "Heap.h"


Heap::Heap(size_t capacity){

    mCapacity = capacity;
    mData[mCapacity];
};
Heap::Heap(const Heap& other){

};
Heap::Heap(Heap&& other){

};
Heap::~Heap(){

};

size_t Heap::capacity() const{
    return mCapacity;
};
size_t Heap::count() const{
    return mCount;
};
const Heap::Entry& Heap::lookup(size_t index) const{
    return mData[index];
};
Heap::Entry Heap::pop(){
    return mData[0];
};
Heap::Entry Heap::pushpop(const std::string& value, float score){
    return mData[0];
};
void Heap::push(const std::string& value, float score){
    mData[0] = {value, score};
};
const Heap::Entry& Heap::top() const {
    return mData[0];
};