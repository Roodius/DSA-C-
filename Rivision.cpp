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


}

// list
class List{
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

    ~list(){
        cout << "Deleting a List.." << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    // push-front 
    void push_front(int val){
        Node newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // push-back
    void push_back(int val){
        Node newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
             
        }
    }

}

int main(){ 



    return 0;
}