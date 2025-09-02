#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> firstNegNumbers(int arr[],queue<int>& q, int N,int K){
    //calculate for first window 
    int result[((N-K) +1)];
    for (int i = 0; i <= K; i++)
    {
        if (arr[i] < 0)
        {
            q.push_back(arr[i]);
        }
           
        result[0] = (q.empty()) ? 0 : q.front();
    }

    for (int i = 1; i < N-K ; i++)
    {
        if (arr[i-1] > 0)
        {
            q.pop();
        }
        if (arr[i+K-1] < 0)
        {
            q.push(arr[i+K -1]);
        }
        result[i] = result[0] = (q.empty()) ? 0 : q.front();
        
    }
    return result;

}   

int main(){
    queue<int>temp;

    int arr[9]  = {12,-1,-7,8,-15,30,16,28};
    int N = 9;
    int K = 3;
    

    vector<int> ans = firstNegNumbers(arr,temp,N,K);

    for (int i = 0; i <= ans.size(); i++)
    {
        cout << ans.data() << " ";
    }
    cout << endl;
    
    
    



return 0;
}