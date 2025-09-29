#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Node {
    public:
    unordered_map<char,Node*> children;
    bool endofWord ;
    int freq;     // frequency

    Node(){
        endofWord = false;
    }

};

class Trie {
    Node* root;

    public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }
    
    void insert(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;  // intialize frequency
            } else {
                temp->children[key[i]]->freq++;  // exit key so ++ frequency
            }
            temp = temp->children[key[i]];
        }
        temp->endofWord = true;
    }

    string getPrefix(string key){
        Node* temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++)
        {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1)
            {
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }

    // ------------------------
    // start with
bool startWith(string prefix){
    Node* temp = root;
    for (int i = 0; i < prefix.size(); i++)
    {
        if (temp->children.count(prefix[i]))
        {
            return true;
        } else {
            return false;
        }
        temp = temp->children[prefix[i]];
    }
    return true;    

}

};

//  // getting prefix
// void prefixProblem(vector<string>dict){
//     // Trie trie;
//     for (int i = 0; i < dict.size(); i++)
//     {
//         trie.insert(dict[i]);
//     }

//     for (int i = 0; i < dict.size(); i++)
//     {
//         cout << trie.getPrefix(dict[i]) << endl;
//     }
    

// }



int main(){
    vector<string>dict = {"zebra", "dog","duck","dove", "apple"};

    Trie trie;
    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }
    

    cout << boolalpha <<  trie.startWith("app") << endl;
    

return 0;
}