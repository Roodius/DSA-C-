#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void MaxAreaHistogram(vector<int>height){
    stack<int>s;
    vector<int>nsl;
    vector<int>nsr;
    // {next smaller left }
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<height.size(); i++){
        int curr = height[i];
        while (!s.empty() && curr <= height[s.top()])
        {
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(curr);    
    }

    while (!s.empty())
    {
        s.pop();
    }

    // { next smaller right }
    int n = height.size();
    s.push(n-1);
    nsr[n-1] = n;

    for(int i = n-2; i>= 0; i--){
        int Curr = height[i];
        while (!s.empty() &&  Curr <= height[s.top()])
        {
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }   
    }

    // findin a a left and right smaller are done   


}

int main(){
    vector<int>height = {2,1,5,6,2,3};
    vector<int>ans = {0,0,0,0,0,0};

    MaxArea(arr,ans);

    return 0;
}