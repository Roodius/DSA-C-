#include <iostream>
// #include <unordered_map>
#include <map>
using namespace std;


int main(){
    map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"]  = 50;
    m["Nepal"] = 10; 
    
    cout << m["India"] << endl;

    for(pair<string, int>country: m){
        cout << country.first << "," << country.second << endl;
    }

    m.erase("Nepal");
    // count -> existence of key
    if (m.count("Nepal") == 1)
    {
        cout << "Nepal found\n";
    } else {
        cout << "Nepal doesn't found\n";
    }
    
    

return 0;
}