#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void printArr(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl; 
}

void MaxAreaHistogram(vector<int>height){
    int n = height.size();
    stack<int>s;
    vector<int>nsl(n);
    vector<int>nsr(n);

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
        s.push(i);    
    }

    printArr(nsl);

    while (!s.empty())
    {
        s.pop();
    }

    // { next smaller right }
    
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
        s.push(i);
    }// finding a a left and right smaller are done   
     
    int maxArea = 0;
    for(int i=0; i<n; i++){
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;

        int Area  =  ht * width;
        maxArea = max(Area,maxArea);
    }

    cout << "Max Area of Histograme : " << maxArea << endl;

}

int main(){
    vector<int>height = {2,1,5,6,2,3};


    MaxAreaHistogram(height);

    return 0;
}