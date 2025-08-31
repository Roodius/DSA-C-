#include <iostream>
using namespace std;

int answer(int arr[], int w) { 
    int current  = 0;
    for (int i = 0; i < w ; i++)
    {
        current += arr[i];
    }

    int maxx = current;
    int n = 7;
    for (int i = 0; i <= n - w; i++)
    {
        current = current  - arr[i - 1] + arr[i + w - 1];
        if (current > maxx)
        {
            maxx  = current;
        }
        
    }
    return maxx;
    
}

int main(){
    int arr[7] = {3,8,2,5,7,6,12};
    int w = 4;
    int ans = answer(arr, w);

    cout << "max number: " << ans << endl;


return 0;
}
