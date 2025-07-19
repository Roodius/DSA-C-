#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Ctack{
    public:
    vector<T> ctack;

    //push 
    void push(T val){
        ctack.push_back(val);
    }
    //pop
    void pop(){
        if (isEmpty()) {
            cout << "ctack  are Empty"; 
            return;
        }
        ctack.pop_back();
    }
    //top 
    T top(){
        if (isEmpty()) {
             cout << "ctack  are Empty"; 
             return -1;
        }
        
        return ctack.back();
    }
    //isEmpty
    bool isEmpty(){
        return ctack.size() == 0;
    }
};


class Queue{
    Ctack<int> s1, s2;

    public:

    //push 
    void push(int val){
        // step first is transfer s1 ele to s2
        while (!s1.isEmpty())
        {
            s2.push(s1.top()); 
            s1.pop();
        }
        // then push new value to s1
        s1.push(val);

        // now push back s2 values to s1  
        while (!s2.isEmpty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    //pop //
    void pop(){
        s1.pop();
    }

    // front 
    int front(){
        return s1.top();
    }

    // isEmpty
    bool isEmpty(){
        return s1.isEmpty();
    }   

};


int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    

    q.pop();
    q.front();

    
    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    
    return 0;
}