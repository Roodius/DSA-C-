#include <iostream>
using namespace std;
#include <stack>

class Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
            next =NULL;
        }
    }

}

class list{
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

    // push_front, push_back, pop_front, pop_back, insert in middle, delete , 

    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void push_back(int val){
        Node* newnode = new Node(val);
        Node* temp = head;
        if(head == NULL){
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void print(){
        if(head == NULL){
            cout << "List are Empty" << endl;
        } 
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }

    void pop_front(){
        if(head == NULL) {
            cout << "Empty" << endl;
        }
        Node* temp = head;
        head = head->next;
        head->next = NULL;
        delete temp;
    }

    void pop_back(){
        
    }

    





}



int main(){
    list ll;

}
