#include <iostream>
#include <deque>
using namespace std;


class Stack{
    deque<int> deq;
    public:
    void push(int val){
        deq.push_front(val);
    }

    void pop(){
        deq.pop_front();
    }

    int top(){
        return deq.front();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);

    s.pop();

    cout << s.top() << endl;

    return 0;
}