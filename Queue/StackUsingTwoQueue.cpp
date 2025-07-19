#include <iostream>
#include <algorithm>
using namespace std;

 // node Class
template<class T>
class Node{
    public:
    T data;
    Node<T>* next;

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
     // List class
template<class T>
class List{

    Node<T>* head;
    Node<T>* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    // push_front 
    void push_front(T val){
        Node<T>* newnode = new Node<T>(val);
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
                return ;
            }
            Node<T>* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;            
        }
    //push_back 
    void push_back(T val){
        Node<T>* newnode = new  Node<T>(val);
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
            return;
        }
        Node<T>* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // top
    T top(){
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }

};

 // Queue using LinkedList
template<class T>
class Queue{

    List<T> ll;

    public:

    // push
    void push(T val){ 
        ll.push_back(val);
    }

    //pop 
    void pop(){
        ll.pop_front();
    }

    //front
    T front(){
       return ll.top();
    }

    bool Empty(){
        return ll.isEmpty();
    }

};


template<class T>
class Stack{
            public:
    Queue<T> q1;
    Queue<T> q2;


    //push
    void push(T val){   
        while (!q1.Empty())
        {
            q2.push(q1.front());
        }

        q1.push(val);

        while (!q2.Empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

    }

    // top 
    T top(){
        return q1.front();
    }

    //pop 
    void pop(){
        q1.pop();
    }

    //empty
    bool isEmpty(){
        return q1.Empty();
    }

};


int main(){
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while (!s1.isEmpty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    return 0;
}