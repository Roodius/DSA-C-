#include <iostream>
using namespace std;
#include <stack>

// template<typename T>
// typename enable_if<is_function<T>::value == false, void> :: type
void pushAtBottom(stack<int>& s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);   // restore the stack state
}


int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);

    pushAtBottom(s,4);

    // printing
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }  // => 4, 3, 2, 1
    

    return 0;
}