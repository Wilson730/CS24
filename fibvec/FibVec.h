#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{
private:
    int cap;
    int nrOfEl;
    int *arr;

public: 

    FibVec(){
    int x = 1, y = 1;
    nrOfEl = 0;
    cap = 10;
    arr = new int[cap];
    }

    ~FibVec(){
        delete[] arr;
    }
    
    size_t capacity() const;
    size_t count() const;
    int insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    int push(int value);
    int remove(size_t index);
};

