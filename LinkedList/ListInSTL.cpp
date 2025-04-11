#include <iostream>
#include <list>
#include <iterator>
using namespace std;


void printList(list<int> ll){
    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << " -> " ;
    }
    cout << "NULL" << endl;
}


int main(){
    list<int> ll;    

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);

    printList(ll);    // printing

    cout << ll.size() << endl;   // size calculating

    cout << "head = " << ll.front() << endl; // value of front
    cout << "tail = " << ll.back() << endl; //  value of back

    ll.pop_front();    // pop-front
    ll.pop_back();     // pop-back

    printList(ll);
    

    return 0;
}