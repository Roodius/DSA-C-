#include <iostream>
using namespace std;


// node 
class Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        cout << "Deleting Node.." << endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }


};

// list
class list{
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

    // push-front 
    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // push-back
    void push_back(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
             tail->next = newnode;
            tail = newnode;
        }
    }

    //pop-front
    void pop_front(){
        if(head == NULL){
            cout << "List are Empty" << endl;
        }
        Node* temp = head;
        head = head->next;
        head->next = NULL;
        delete temp;
    }

    //pop-back
    void pop_back(){
        if(head == NULL){
            cout << "List are Empty" << endl;
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
    //print
    void print(){
        if(head == NULL){ cout << "List are Empty" << endl; }

        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " " ;
        }
        cout << endl;
    }

    // insert in middle of ll 
    void InsertInMiddle(int val, int pos){
        Node* newnode = new Node(val);
        Node* temp = head;
        for(int i=0; i < pos-1; i++){
            if(temp == NULL) { cout << "Position is Invalid" << endl;}
            return;
            temp = temp->next; 
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    // deleting a list
    ~list(){
        cout << "Deleting a List.." << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
    // Recursive Search
    
};

int main(){ 

    return 0;
}