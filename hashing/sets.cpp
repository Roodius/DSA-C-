#include <iostream>
// #include <unordered_set>
#include <set>
using namespace std;

// int main(){
//     unordered_set<int> s;

//     s.insert(1);
//     s.insert(3);
//     s.insert(2);
//     s.insert(4);
//     s.insert(5);
//     s.insert(6);

//     if (s.find(3) != s.end())
//     {
//         cout << "3 are exist" << endl;
//     } else { 
//         cout << "3 not exits" << endl;
//     }

//     for (auto el : s)
//     {
//         cout << el << " ";
//     }
//     cout << endl;
    

    
// return 0;
// }

int main(){
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(6);

     if (s.find(3) != s.end())
    {
        cout << "3 are exist" << endl;
    } else { 
        cout << "3 not exits" << endl;
    }

    for (auto el : s)
    {
        cout << el << " ";
    }
    cout << endl;
    

return 0;
}