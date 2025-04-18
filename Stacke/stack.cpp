#include <iostream>
using namespace std;
#include <vector>

// create stack using vector 


class Stack{
    vector<int> stack;

    void push(int val){
        stack.push_back(val);
    }

    void pop(){
        stack.pop_back();
    }

    

};  

int main(){

    return 0;
}