#include <iostream>
using namespace std;
#include <vector>

// create stack using vector 


class Stack{
    public:
    vector<int> stack;

    // push for stack 
    void push(int val){   // 0(1)
        stack.push_back(val);
    }   

    // pop for stack
    void pop(){
        if(isEmpty()){
            cout << "stack is empty !" << endl;
            return;
        }
        stack.pop_back();
    }

    int top(){
        if(isEmpty()){
            cout << "stack is Empty !" << endl;
            return -1;
        }
         int lastIdx = stack.size() -1;
         return stack[lastIdx];
    }

    bool isEmpty(){
       return stack.size() == 0;
    }

};  

int main(){
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    while (!s.isEmpty())
    {
        cout << s.top() << " " ;
        s.pop();
    }

    return 0;
}