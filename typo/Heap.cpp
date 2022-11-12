#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity){

    mCapacity = capacity;
    mData = new Entry[mCapacity];
};
Heap::Heap(const Heap& other){
    Entry* newmData = {};
    for (size_t i = 0; i < mCount; i++){
        newmData[i] = other.mData[i];
    }
    delete [] other.mData;
    mData = newmData;
};
Heap::Heap(Heap&& other){
    this->mData = other.mData;
    other.mData = nullptr;
};
Heap::~Heap(){
    delete [] mData;
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
    if (mCount > mCapacity){
        throw std::overflow_error("overflow!");
    } else {
        Entry newEntry;
        newEntry.value = value;
        newEntry.score = score;
        mData[mCount - 1] = newEntry;    // insert new entry 
        mCount += 1;
    }
};
const Heap::Entry& Heap::top() const {
    return mData[0];
};