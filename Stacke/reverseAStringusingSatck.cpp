#include <iostream>
#include <stack>
using namespace std;
#include <string>


string ToreverseString(string str){
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    while (!s.empty())
    {
        char top = s.top();
        ans += top;
        s.pop();
    }
    
    return ans;
}

int main(){
    string ans = ToreverseString("osman");
    for(int i=0; i < ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl;

    return 0;
}