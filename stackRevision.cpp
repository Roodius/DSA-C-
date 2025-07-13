#include <iostream>
using namespace std;
#include <vector>


class Stak{
    public:
    vector<int>stack;
    
    // push
    void push(int val){
        stack.push_back(val);
    }

    // pop
    void pop(){
        if(isEmpty()){
            cout << "stack is Empty" << endl;
            return;
        }
        stack.pop_back();
    }

    //top
    int top(){
        if(isEmpty()){
            cout << "stack is Empty" << endl;
        }
        int lastidx = stack.size() - 1;
        return stack[lastidx];
    }

    // isEmpty()
    bool isEmpty(){
        return stack.size() == 0;
    }

};

int main(){
    Stak s;
    s.push(3);
    s.push(2);
    s.push(1);

   cout <<  s.top() << endl;

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}