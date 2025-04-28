#include <iostream>
using namespace std;
#include <vector>
#include <string>

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

    T top(){
        // if(isEmpty()){
        //     cout << "Stack Is Empty Nothing is Exist" << endl;
        // }
        int lastIdx = stak.size() -1;
        return lastIdx;
    }

    bool isEmpty(){
       return stak.size() - 1 == 0;
    }     

};


int main(){
    tack<char>s;
    
    s.push('c');
    s.push('b');
    s.push('a');
    while(!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}