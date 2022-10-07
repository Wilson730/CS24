#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{
private: 
    


public:
    size_t capacity();
    size_t count();
    int insert(int value, size_t index);
    int lookup(size_t index);
    int pop();
    int push(int value);
    int remove(size_t index);
    FibVec slice(size_t index, size_t count);
};
