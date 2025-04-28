#include <iostream>
using namespace std;
#include <list>
#include <vector>

template<class T>

class Node{
    T data;
    Node* next;

    public:
    Node(T val){
        data = val;
        next = NULL;
    }

}


template<class T>
class Stack{
    Node* head;
    public:
    Stack(){
        head = NULL; 
    }

    void push(T val){
        // push-front
        Node* newnode  = new Node(val);
        if(head == NULL){
            head = newnode;
        }
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front(); // => head
    }
    
    bool isEmpty(){
        return ll.size() == 0;
    }
    
};


int main(){
    Stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " "; 
        s.pop();
    }
    cout << endl;
    
    return 0;
}