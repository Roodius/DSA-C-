#include <iostream>
using namespace std;


class Queue{
    private:
    int* arr;
    
    int capacity;
    int CurrSize;

    int f, r;

    public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        CurrSize  = 0;
        f = r = -1;
    }

    void push(int val){
          if (CurrSize == capacity){
        cout << "Queue is Full" << endl;
        return;
    }
    
    if (CurrSize == 0){
        f = 0; // First push
    }
        r = (r +1) % capacity;
        arr[r] = val;
        CurrSize++;
    }
     
    void pop(){
        if (empty())
        {
            cout << "Queue is EMPTY" << endl;
            return;
        }
        f = (f+1) % capacity;
        CurrSize--;
        
    }

    int front(){
        if (empty())
        {
            cout << "Queue is Empty" << endl;
        }
        
        return arr[f];
    }

    bool empty(){   
        return CurrSize == 0; 
    }


    void printRear(){
        cout << arr[r] << endl;
    }


};




int main(){
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    q.push(5);
    cout << q.front() << endl;
    
    q.printRear();
    return 0;
}