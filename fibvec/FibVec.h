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


    
    void resize(){
        cap = x + y;
        int *temparr = new int[cap];

        for (size_t i = 0; i < nrOfEl; i++)
        {
            temparr[i] = arr[i];
        }

        delete[] arr;
         
        arr = temparr;


    }

     
    size_t capacity() const;
    size_t count() const;
    int insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    int push(int value);
    int remove(size_t index);
};
