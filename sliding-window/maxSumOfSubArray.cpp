#include <iostream>
using namespace std;


int maxSum(int arr[], int k){
    int n = 7;
    int sum = 0;
    for (int i = 0; i <= k; i++)
    {
        sum += arr[i];
    }   
    
    int maxSum =  sum;
    for (int i = 1; i < n-k; i++)
    {
        int prevEle = arr[i - 1];
        int nextEle  = arr[i + k -1];
        sum = sum - prevEle + nextEle;
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        
    }
    return maxSum;

}

int main(){
    int arr[7] = {100,200,50,0,300,20,100};
    int k = 3;
    int ans =  maxSum(arr, k);

    cout << "max Sum = " << ans << endl;
return 0;
}
