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
        if(head == NULL){
            cout << "Empty" << endl;
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

    // inserting a Node in giving position
    void insertInMiddle(int val, int pos ){
        Node* newnode = new Node(int val);
        Node* temp = head;

        for(int i=0; i<pos-1; i++){
            if(head == NULL) { cout << "list are Empty" << endl; }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

    }    

    // iterative search 
    void iterativeSearch(int val){
        Node* temp = head;
        int idx = 0;
        while (head != NULL)
        {
            if(temp->data == val){
                return idx
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // recursive search

    int helper(Node* temp,int key){
        if(temp == NULL){
            return -1;
        }

        if(temp->data == key){
            return 0;
        }

        int idx = helper(temp->next, key);
        if(idx == -1){
            return -1;
        }
        return idx+1;
    }

    void RecursiveSearch(){
        return helper(head,int key);
    }   

    // reverse a linked list 
    // 3 pointer -> prev, curr ,next 
    
    

}       




int main(){
    list ll;

}
