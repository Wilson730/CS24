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
    if (index > nrOfEl - 1 || index > cap || index < 0)
    {    // nrOfelements = current # of spaces occupied in the array. so if there's 9 occupied, max index should be 8, hence nrOfEl -1. 
            throw std::out_of_range("index is out of range!");
    } else {
        return arr[index];
    }
}
//----------------------------------------------------------------- RESIZE ---------------------------------------------------------------------
int FibVec::resize(size_t index){
//-------------------------IF INDEX BIGGER THAN CAPACITY (FULL) BY 1, INCREASE TO NEXT FIBONACCI NUMBER. 
        if (index > nrOfEl){
            cap = x + y;
            if (y == (cap-x)){
                x = cap;
            } else if (x == (cap - y)){
                y = cap;
            }
        } 

        if (index < nrOfEl - 2)                       // make sure to get the cap right.  or index < capacity - 2. 
        {                                    // don't worry about insert ruining the sequence. insert will check that for you. 
            cap = nrOfEl - 1; 
        }
//-------------------------- COPY VALUES TO NEWER AND BIGGER ARRAY
        int *temparr = new int[cap];                 // changes capacity of array. operates using x and y. capacity = f(n)

        for (size_t i = 0; i < nrOfEl; i++)            // cap or f(n) will increase so new cap = previous x + y, and 
        {
            temparr[i] = arr[i];
        }

        delete[] arr;
         
        arr = temparr;
}
//---------------------------------------------------------------- INSERT ----------------------------------------------------------------------
void FibVec::insert(int value, size_t index){
    if(index = nrOfEl)
    {
        resize(index);
    }
    arr[nrOfEl++] = value;
}
//----------------------------------------------------------------- PUSH -----------------------------------------------------------------------



