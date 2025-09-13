#include <iostream>
#include <string>
using namespace std;


class Node{
    public:
    string key;
    int data;
    Node* next;


    Node(string key, int data){
        this->key = key;
        this->data = data;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable {
    private:
    int Totalsize;
    int currSize;  // for rehashing
    Node** table;
  
    int HashFunction(string key){
        int idx  = 0 ;
        for(int i=0; i<key.size(); i++){
            idx += (key[i] * key[i]) % Totalsize;
        }
        return idx % Totalsize;
    }

    void rehash(){
        Node** oldTable  =  table;
        int oldsize  = Totalsize;

        Totalsize = 2*Totalsize;
        currSize = 0;
        table = new Node*[Totalsize];

        for (int i = 0; i < Totalsize; i++)
        {
            table[i] = NULL;
        }

        //copy
        for(int i=0; i<oldsize; i++){
            Node* temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->data);
                temp = temp->next;  
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
            
        }
        delete[] oldTable;
    }

    public:
    HashTable(int size = 5){
        Totalsize  =size;
         currSize = 0;

         table = new Node*[Totalsize];

         for(int i=0; i<Totalsize; i++){
            table[i] = NULL;
         }
    }
            // hash func


    // void insert
    void insert(string key, int data){
        int idx = HashFunction(key);
        Node* newnode = new Node(key, data);

        // Node* head  = table[idx];

        newnode->next = table[idx];
        table[idx] = newnode;

        currSize++;

        double lamda = currSize / (double)Totalsize;
        if (lamda > 1) rehash();
    }


    
    //exits 
    bool Exits(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            } 
            temp = temp->next;
        }
        return false;
    }


    // void search
    int search(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->data;
            } 
            temp = temp->next;   
        }
        return -1;
    }

    // void delete/remove/erase
    void remove(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];

        Node* prev = temp;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                // deletion perform
                // --> there two cases node will be head node or not head node
                 if (prev == temp)
                 {
                    table[idx] = temp->next;
                 } else {
                    prev->next = temp->next;
                 }
                 break;
            }
                prev = temp;
                temp = temp->next;
        }

    }

    // print 
    void print(){
        for (int i = 0; i < Totalsize; i++)
        {
            cout << "idx" << i;
            cout << endl;
            Node* temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " -- " << temp->data << endl;
                temp = temp->next; 
            }
            
        }
        
    }

 
    
};

int main(){
    HashTable ht;
    
    ht.insert("India", 150);
    ht.insert("China", 34);
    ht.insert("US", 54);
    ht.insert("canada", 15);
    ht.insert("Nepal", 134);

    ht.print();

    ht.remove("China");

    ht.print();

return 0;
}