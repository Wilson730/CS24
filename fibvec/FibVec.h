#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{

 private:
    size_t cap;
    size_t nrOfEl;
    int *arr;
    int x, y;

public: 
    FibVec();
    ~FibVec();
    

    
    
    size_t capacity() const;
    size_t count() const;
    void insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    int push(int value);
    int remove(size_t index);
    int resize(size_t index);
   
};
