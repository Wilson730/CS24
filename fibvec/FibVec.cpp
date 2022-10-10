#include "FibVec.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//------------------------------------------------------------- CONSTRUCTOR --------------------------------------------------------------------
FibVec::FibVec(){
    x = 1, y = 1;
    nrOfEl = 0;
    cap = 1;
    arr = new int[cap];
    counter = 0;
}
//------------------------------------------------------------- DECONSTRUCTOR ------------------------------------------------------------------
FibVec::~FibVec(){ 
    delete[] arr;
}
//--------------------------------------------------------------- CAPACITY ---------------------------------------------------------------------
size_t FibVec::capacity() const {
    return cap;
}
//---------------------------------------------------------------- COUNT -----------------------------------------------------------------------
size_t FibVec::count() const {
    return nrOfEl;
}
//----------------------------------------------------------------- LOOKUP ---------------------------------------------------------------------
int FibVec::lookup(size_t index) const {
    if (index > nrOfEl - 1)
    {    
        throw std::out_of_range("Index out of range.");
    } 
    if (index >= cap)
    {
        throw std::out_of_range("Index out of range.");
    }
    return arr[index];
}
//----------------------------------------------------------------- EXPAND ---------------------------------------------------------------------
void FibVec::expand(){

        if (nrOfEl >= cap){
            cap = x + y;
            if (counter == 0){       
                x = cap;
                counter = 1;
            } else if (counter == 1){    
                y = cap;
                counter = 0;
            }
        } 

int *temparr = new int[cap];                 

for (size_t i = 0; i < nrOfEl; i++)           
{
    temparr[i] = arr[i];
}
delete[] arr;        
arr = temparr;     
}
//---------------------------------------------------------------- SHRINK ----------------------------------------------------------------------
void FibVec::shrink(){
if (x > y && nrOfEl < cap - x)                    
{   
    cap = y; 
} else if (y > x && nrOfEl > cap - y) {
    cap = x;
} 

int *temparr = new int[cap];                 
for (size_t i = 0; i < nrOfEl; i++)            
{
    temparr[i] = arr[i];
}
delete[] arr;     
arr = temparr;
}
//---------------------------------------------------------------- INSERT ----------------------------------------------------------------------
void FibVec::insert(int value, size_t index){
    if (index > nrOfEl || index > cap) // index cannot be negative, skip, or over. 
    {
        throw std::out_of_range("invalid index");
    }
    if((index == cap) && (cap == nrOfEl)) // insert at cap (1 after the total size)
    {
        nrOfEl += 1;
        expand();
        arr[index] = value;
    }

    if(index <= nrOfEl){                // insert in the middle
        if (++nrOfEl > cap){            // resize of insert makes a value go out of range
            expand();
        }
        for(size_t i = index; i < nrOfEl; i++){   
            int temp = arr[index];
            arr[index] = temp;

        }
    }
}
//----------------------------------------------------------------- PUSH -----------------------------------------------------------------------
void FibVec::push(int value){
    
    if(nrOfEl == cap){
        expand();
    } 
    arr[nrOfEl] = value;
    nrOfEl++; 
}
//------------------------------------------------------------------ POP -----------------------------------------------------------------------
int FibVec::pop(){

    if(nrOfEl == 0){
        throw std::underflow_error("underflow error!");
    } 

    if ((x > y && nrOfEl < cap - x) || (y > x && nrOfEl < cap - y)){
        shrink();
    }
    nrOfEl--; 
    return arr[nrOfEl];
}
//------------------------------------------------------------------ REMOVE --------------------------------------------------------------------

int FibVec::remove(size_t index){
    return arr[index];
}