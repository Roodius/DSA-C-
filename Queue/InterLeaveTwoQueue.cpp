#include <iostream>
#include <queue>
using namespace std;


void InterLeavingTwoQueue(queue<int>& OG){
    int n = OG.size();
    queue<int> newQ;

    for (int i = 0; i <n /2; i++)
    {
        newQ.push(OG.front());
        OG.pop();
    }

    while (!newQ.empty())
    {
        OG.push(newQ.front());
        newQ.pop();

        OG.push(OG.front());
        OG.pop();
    }
}   

int main(){
    queue<int> OG;

    for (int i = 1; i <= 10; i++)
    {
        OG.push(i);
    }

    InterLeavingTwoQueue(OG);

    for (int i = 1; i <= 10; i++)
    {
        cout << OG.front() << " ";
        OG.pop();
    }
    cout << endl;
    

    return 0;
}
