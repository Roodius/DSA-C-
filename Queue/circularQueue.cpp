#include <iostream>
using namespace std;


class Queue{
    private:
    int* arr;
    
    int capacity;
    int CurrSize;

    int f, r;

    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        CurrSize  = 0;

        f = r = -1;
    }

    void push(int val){
        r = (r +1) % capacity;
    }
     
    void pop(){

    }

    void front(){

    }

}




int main(){
    Queue q(5);

    return 0;
}