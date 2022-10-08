#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class FibVec{
private:
    size_t cap;
    size_t count;
    int *arr;
    int x, y;
public: 

    FibVec(){
    x = 1, y = 1;
    count = 0;
    cap = 10;
    arr = new int[cap];
    }

    ~FibVec(){
        delete[] arr;
    }
    
    void resize(){
        cap = x + y;
        int *temparr = new int[cap];

        for (size_t i = 0; i < count; i++)
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
