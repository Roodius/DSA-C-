    #include <iostream>
    #include <string>
    #include <stack>
    using namespace std;

    bool Duplicateparenthesis(string str){
        stack<char>s;
        for(int i=0; i<str.size(); i++){
            char ch = str[i];

            if(ch != ')'){
                s.push(ch); // non-closing
            } else {  // closing
                if(s.top() == '(') {return true; } // Duplicate 
                while (s.top() != '(')
                {
                    s.pop();
                }
                s.pop();
                
            }
            
        }
        return false;
    }


    int main(){
        string str1 = "((a+b) + (c+d))";
        string str2 = "((a+b))";

        cout << boolalpha << endl;
        cout << Duplicateparenthesis(str1) << endl;
        cout << Duplicateparenthesis(str2) << endl;
        

        return 0;
    }