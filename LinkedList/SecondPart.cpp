#include <iostream>
using namespace std;

// Node 
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
    // push_front 
    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // push_back 
    void push_back(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        } else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    // pop_front
    void pop_front(){
        if(head == NULL) {cout << " list empty" << endl;}
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
    }

    // pop_back
    void pop_back(){
        if(tail == NULL){cout << "list is" << endl;}
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    //insert in Middle
    void insert(int val, int pos){
        Node* newnodew = new Node(val);
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp= temp->next;
            newnodew->next = temp->next;
            temp->next = newnodew;
        }
    }

    //search key
    int Search(int key){
        Node* temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            if(temp->data == key){
                return idx;
            }
        }
        return -1;
        
    }
    
    // helper funtion 
    int help(Node* temp,int key){
        if(temp == NULL) {return -1;}

        if(temp->data == key){
            return 0;
        }

       int idx = help(temp->next,key);
        if(idx == -1){return -1;}

        return idx+1;
    }

    //RecursiveSearch
    void RecursiveSearch(int key){
        help(head,key);
    }

    //reverse a node list
    void Reverse(){
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        
    }

    //print
    void print(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        
    }   
    //size of list 
    int size(){
        Node* temp =head;
        int count =0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    // find And Remove Nth Node from End
    void RemoveNthNode(int n){
        Node* prev = head;
        int sz = size();
        for(int i=0; i<(sz -n); i++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }

    // Delete a loop in LL
     bool isCycle(){
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cout << "cycle exists\n";
                return true;  
            }
        }
        cout << "cycles Does't exist\n";
        return false;
     }  

     

     // Remove cycle
     void RemoveCycle(Node* head){   
        // {detect cycle} => [cycle is exist or not]
        Node* slow = head;
        Node* fast = head;
        bool iscycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cout << "Cycle Exist"<< endl;
                iscycle = true;
                break;
            }
        }
        if(!iscycle){
            cout << "Cycle doesn't Exist";
            return;
        }
        
        // {update slow pointer}
        slow = head;
        if(slow == fast){  // special case : tail -> head 
            while (fast->next != slow)
            {
                fast = fast->next;
            }   
            fast->next = NULL;  // remove cycle
            
        } else {
            Node* prev = fast;
            while (slow != fast)
            {
                slow = slow->next;
                prev = fast;        
                fast = fast->next;
            }
            prev->next = NULL;  // remove cycle
            
        }
     }
     

};  

int main(){
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head;

    ll.RemoveCycle(ll.head);
    ll.print();

    return 0;
}