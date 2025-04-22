#include <iostream>
using namespace std;
#include <vector>

template<class T>  // we need use a type of T : T is any Data type

class tack{
    public:
    vector<T>stak;

    void push(T val){
        stak.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Is Empty Nothing is Exist" << endl;
        }
        stak.pop_back();
    }

    int top(){
        if(isEmpty()){
            cout << "Stack Is Empty Nothing is Exist" << endl;
        }
        int lastIdx = stak.size() -1;
        return lastIdx;
    }

    bool isEmpty(){
        if(stak.size() -1 == 0){
            cout << "Stack Is Empty Nothing is Exist" << endl;
        }
    }


};


int main(){
    tack<int>s;

    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }1
    cout << endl;
    return 0;
}