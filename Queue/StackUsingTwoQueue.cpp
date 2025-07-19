#include <iostream>
using namespace std;
template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        this->data = val;
        this->next = NULL;
    }

    ~Node(){
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
template<class T>
class List{
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    // push_front 
    void push_front(T val){
        Node* newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // pop_front 
        void pop_front(){
            if (head == NULL){
                cout << "Linked List" << endl;
            }
            Node* temp = head;
            head = head->next;
            head->next = NULL;
            delete head;            
        }
    //push_back 
    void push_back(int val){
        Node* newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode; 
        }
    }

    // pop_back
    void pop_back(){
        if (head == NULL)
        {
            cout << "empty LL" << endl;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // top
    void top(){
        return head->data;
    }

};

class Queue{
    List ll;

    // push
    void push(int val){ 
        ll.push_back(val);
    }

    //pop 
    void pop(){
        ll.pop_front();
    }

    //front
    int front(){
        ll.top();
    }
};

class Stack{
    Queue q1, q2;

    //push
    void push(){
            
    }

}


int main(){

    return 0;
}