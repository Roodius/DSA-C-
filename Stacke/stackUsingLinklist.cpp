#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <stack>

template<class T>

class Node{
    public:

    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }

};


template<class T>
 class Stack{
    Node<T>* head;
    public:
    Stack(){
        head = NULL; 
    }

    void push(T val){
        // push-front
        Node<T>* newnode  = new Node<T>(val);
        if(head == NULL){
            head = newnode;
        }else {
            newnode ->next = head;
            head = newnode;
        }
    }
    void pop(){
        // pop-front
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T top(){
        return head->data; // => head
    }
    
    bool isEmpty(){
        return head == NULL;
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