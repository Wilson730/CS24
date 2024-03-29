#include "Heap.h"
#include <stdexcept>
#include <cmath>
Heap::Heap(size_t capacity){

    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[mCapacity];
};
Heap::Heap(const Heap& other){
    
    this->mData = other.mData;
    this->mCount = other.mCount;
    this->mCapacity = other.mCapacity;
    Entry* newmData = new Entry[mCapacity];
    for (size_t i = 0; i < mCount; i++){
        newmData[i] = other.mData[i];
    }
    mData = newmData;
};
Heap::Heap(Heap&& other){
    this->mData = other.mData;
    this->mCount = other.mCount;
    this->mCapacity = other.mCapacity;
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

void Heap::push(const std::string& value, float score){
    Entry newEntry;
    newEntry.value = value;
    newEntry.score = score;
    size_t index = mCount;

    if (mCount >= mCapacity){    // Full
        throw std::overflow_error("overflow!"); 
    } else if (mCount == 0){     // first available slot
        mData[0] = newEntry;
    } else {                    // percolate up 
        mData[index] = newEntry;
        size_t i = index;
        do {
        i = floor((i-1)/2);
            if (newEntry.score < mData[i].score) {
                Entry temp = mData[i];
                mData[i] = newEntry;
                mData[index] = temp;  // index = 0
                index = i; // switch index to new parent
            }
        } while (i > 0);
    }
    mCount += 1;
};

const Heap::Entry& Heap::top() const {
    if (mCount == 0) throw std::underflow_error("Empty heap");
    return mData[0];
};
//----------------------------------UNFINISHED-----------------------------------------------------

const Heap::Entry& Heap::lookup(size_t index) const{
   
    if (mCount == 0 || index >= mCount ) {
         throw std::out_of_range("Out of range");
    } else {
        return mData[index];
    }
};

void percolateDown(Heap::Entry* mData, size_t i, size_t mCount){ 
    size_t leftChild = (i * 2) + 1;
    size_t rightChild = (i * 2) + 2;
    if (i < mCount){
    
    if (leftChild < mCount && mData[i].score > mData[leftChild].score) { 
        Heap::Entry temp = mData[leftChild];  
        mData[leftChild] = mData[i]; 
        mData[i] = temp; 
        i = leftChild;
        percolateDown(mData, leftChild, mCount);
    } else if (rightChild < mCount && mData[i].score > mData[rightChild].score) {
        Heap::Entry temp = mData[rightChild];
        mData[rightChild] = mData[i];
        mData[i] = temp;
        i = rightChild;
        percolateDown(mData, rightChild, mCount);
    }
    }
};

Heap::Entry Heap::pop(){
    if (mCount == 0) throw std::underflow_error("Empty");
    Entry result = mData[0];
    size_t i = 0; 
    mCount--;
    mData[0] = mData[mCount];  
    
    percolateDown(mData, i, mCount);
  
    return result;
};

Heap::Entry Heap::pushpop(const std::string& value, float score){
    Entry lowestScore = top();
    Entry newEntry;
    newEntry.value = value;
    newEntry.score = score;
    mData[0] = newEntry; // replace popped entry with newentry
    percolateDown(mData, 0, mCount); // then percolates down 
    return lowestScore;
};



