#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity){

    mCapacity = capacity;
    mCount = 0;
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
    delete [] other.mData;
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
    Entry result; 
    if (index >= mCount) throw std::out_of_range("Out of range");
    for (size_t i = 0; i < mCount; i++){
        if (i == index){
            result = mData[index];
        }
    }
    return result;
};
//----------------------------------UNFINISHED-----------------------------------------------------



Heap::Entry Heap::pop(){
    Entry result;
    if (mCount == 0){
        throw std::underflow_error("No items");
    }
    for (size_t i = 0; i < mCount; i++){
        if (i + 1 == mCount){
            result = mData[i];

            mCount -= 1;
        }
    }
    return result;
};

Heap::Entry Heap::pushpop(const std::string& value, float score){
    Entry result = {};
    return result;
};
void Heap::push(const std::string& value, float score){
    
    if (mCount > mCapacity){
        throw std::overflow_error("overflow!");
    } else {
        Entry newEntry;
        newEntry.value = value;
        newEntry.score = score;
        if (mCount > 0)   mData[mCount + 1] = newEntry; 
        else mData[0] = newEntry;  
        mCount += 1;
    }
    
};
const Heap::Entry& Heap::top() const {
    if (mCount == 0) throw std::underflow_error("Empty heap");
    Entry& result = mData[mCount-1];
    
    if (mCount == 0) throw std::underflow_error("Empty");
    for (size_t i = mCount; i > 0; i--){
        if (mData[i - 1].score < mData[i].score){
            result = mData[i-1];
        }
    }
    
    return result;
};