#include "FibVec.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

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
    if (index > nrOfEl - 1 || index >= cap || nrOfEl == 0)
    {    
        throw std::out_of_range("Index out of range.");
    } 
    return arr[index];
}
//----------------------------------------------------------------- EXPAND ---------------------------------------------------------------------
void FibVec::expand(){

     cap = x + y;
        if (counter == 0){       
            x = cap;
            counter = 1;
        } else if (counter == 1){    
            y = cap;
            counter = 0;
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
    x = x - cap;
} else if (y > x && nrOfEl > cap - y) {
    cap = x;
    y = y - cap;
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
    if (index > nrOfEl || index > cap){ 
        throw std::out_of_range("invalid index");
    } else if ((index == cap) && (cap == nrOfEl)) {
        ++nrOfEl;
        expand(); 
        arr[index] = value;
    } else if(index < nrOfEl){                
        if (++nrOfEl > cap){                 
            expand();
        }
        for(size_t i = nrOfEl; i >= index; --i){  
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
    } else { 
        arr[index] = value;
        ++nrOfEl;
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
    --nrOfEl;
    if ((x > y && nrOfEl < cap - x) || (y > x && nrOfEl < cap - y)){
        shrink();
    }
    return arr[nrOfEl];
}
//------------------------------------------------------------------ REMOVE --------------------------------------------------------------------

int FibVec::remove(size_t index){
    if (index > nrOfEl || index > cap){
        throw std::out_of_range("Index out of range.");
    }

    return arr[index];
}