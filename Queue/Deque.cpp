#include <iostream>
#include <deque>
using namespace std;


int main(){
    deque<int>deq;

    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);


    deq.pop_front();
    deq.pop_back();

    cout << deq.front() << endl;
    cout << deq.back() << endl;


    // while (!deq.empty())
    // {
    //     cout << deq.front() << " ";
    //     deq.pop_front();
    // }
    // cout << endl;

return 0;
}