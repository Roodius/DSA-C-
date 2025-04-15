#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
        
    }
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    //push_front
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
                newNode->next = head;
                head = newNode;
        }
    }

    // push_back 
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    //pop_font function 
    void pop_front(){
        if(head == NULL) {cout << "LL is empty" << endl;}
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }

    //pop_back function
    void pop_back(){
        if(tail == NULL){
            cout << "Nothing" << endl;
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

    void print(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        
    }


};

// splitMiddle function return => Node

Node* spliteAtmid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

    }
    if(prev != NULL){
        prev->next  =NULL;  // split at middle

    }
    return slow; // slow => rightHead
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j  = right;

    while (i != NULL && j != NULL)
    {
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }
        //{comaparing data }  less or greater
    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }
    // returing a new List
    return ans.head;
}


// merge function
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* rigthHead = spliteAtmid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rigthHead);

    return merge(left,right);   // head of sorted ll

}


int main(){

    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    ll.print();

    cout << endl;

    ll.head = mergeSort(ll.head);

    ll.print();


    return 0; 
}