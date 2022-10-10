#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{

 private:
    size_t cap;
    size_t nrOfEl;
    int *arr;
    size_t x, y;
    int counter;
    int temp;
public: 
    FibVec();
    ~FibVec();
    

    
    
    size_t capacity() const;
    size_t count() const;
    void insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    void push(int value);
    int remove(size_t index);
    void expand();
    void shrink();
   
};
