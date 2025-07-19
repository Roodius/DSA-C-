#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node{
    public:
    T Data;
    Node<T>* next;

    Node(T val){
        this->Data = val;
        this->next = NULL; 
    }
};

template<class T>
class List{
    public:
    Node<T>* head;
    Node<T>* tail;

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

    // push_back - FIXED
    void push_back(T val){
        Node<T>* newnode = new Node<T>(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;  // FIXED: Added return to avoid further execution
        }
        
        // FIXED: Use tail pointer for efficiency
        tail->next = newnode;
        tail = newnode;
    }

    //pop_front - FIXED
    void pop_front(){
        if (head == NULL)
        {
            cout << "LL is Empty" << endl;
            return;
        }
        
        Node<T>* temp = head;
        head = head->next;
        
        // FIXED: Update tail if list becomes empty
        if (head == NULL) {
            tail = NULL;
        }
        
        delete temp;   
    }

    //pop_back - FIXED
    void pop_back(){
        if (head == NULL)
        {
            cout << "LL is Empty" << endl;
            return;
        }
        
        // FIXED: Handle single node case
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        
        Node<T>* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;  // FIXED: Update tail pointer
    }

    // top 
    T top(){
        if (head == NULL) {
            throw runtime_error("List is empty");
        }
        return head->Data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

template<class T>
class Queue{
    List<T> ll;
    public:

    // push
    void push(T val){
        ll.push_back(val);
    }

    // pop 
    void pop(){
        ll.pop_front();
    }

    // front
    T front(){
        return ll.top();
    }

    // isEmpty
    bool isEmpty(){
        return ll.isEmpty();
    }
};

// -----------------------------------------

void firstNonRepeatLetter(string str){
    Queue<char> Q;
    int freq[26] = {0};

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        Q.push(ch);
        freq[ch-'a']++;

        // FIXED: Added -'a' to convert char to array index
        while (!Q.isEmpty() && freq[Q.front()-'a'] > 1){
            Q.pop();
        }

        if (Q.isEmpty())
        {
            cout << "-1" << endl;
        } else {
            cout << Q.front() << endl;
        }
    }   
}

int main(){
    string str = "aabccxb"; 
    
    cout << "Processing string: " << str << endl;
    cout << "First non-repeating character at each step:" << endl;
    firstNonRepeatLetter(str);

    return 0;
}