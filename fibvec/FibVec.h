#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{
private: 
    


public:
    size_t capacity() const;
    size_t count() const;
    int insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    int push(int value);
    int remove(size_t index);
};
