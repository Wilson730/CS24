#include "FibVec.h"
#include <iostream>
#include <stdexcept>

using namespace std;


int main()
{
   FibVec* v;
    v = new FibVec();
}

FibVec::FibVec(){
    x = 1, y = 1;
    nrOfEl = 0;
    cap = 1;
    arr = new int[cap];
}

FibVec::~FibVec(){
    delete[] arr;
}
