#include <iostream>
#include <stack>
using namespace std;


 //  1 2 3 4 => {4 , 3 , 2, 1}

 void pushAtBottom(stack<int> s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(val);
 }

void reverse(stack<int>s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s,temp);

}


int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);

    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}