#include <iostream>
#include <queue>
#include <string>   
using namespace std;

int main(){
    priority_queue<string, vector<string>,greater<string>> pq;

    pq.push(5);
    pq.push(10);   // by default high PQ
    pq.push(3);

    cout << "top: " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    pq.push("a");
    pq.push("b");
    pq.push("c");
    pq.push("d");
    pq.push("e");
    
    while (!pq.empty())
    {
        cout << pq.top() << " < ";
        pq.pop();
    }
    cout << endl;

return 0;
}