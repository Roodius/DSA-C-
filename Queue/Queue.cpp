#include <iostream>


class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }

    ~Node(){
        std::cout << "constructer called" << std::endl;
    }
};

class list{
    public:
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

    // push-front
    void push_front(int val){
        Node* newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        
    }

    // pop- front
    void pop_front(){
        if (head == NULL)
        {
            std::cout << "List are Empty" << std::endl;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL)
        {
            tail = NULL;
        }
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
            if (head == NULL) {
        std::cout << "List is empty. Nothing to pop." << std::endl;
        return;
    }

    // If only one node exists
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
        Node* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        
    }

    void print(){
        Node* temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            std::cout << temp->data << " ";
        }
        std::cout << std::endl;
    }
};


class Queue{
    // constructer
    public:
    list ll;
    Queue(){
        ll;
    }

    void push(int val){
        ll.push_back(val);
    }

    void pop(){
        ll.pop_front();
    }

    int front(){
        if (ll.head != NULL){ return ll.head->data;}
        else{std::cout << "Queue are empty" << std::endl; return -1;}
    }

    void print(){
        ll.print();
    }
};



int main(){
    Queue Que;

    Que.push(4);
    Que.print();

    return 0;
}