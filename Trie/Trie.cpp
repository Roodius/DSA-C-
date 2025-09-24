#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Node for  Trie
class Node {
    public:
    unordered_map<char ,Node*> children;
    bool endOfword;

    Node(){
        endOfword = false;
    }
};

class Trie {
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    // ----- insert ---------
    void insert(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.count(key[i]) == 0) { // count is finding function in unorderd map
                temp->children[key[i]] = new Node();  // inserted
            }
            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }

    // --------search ------------
    bool search(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];    
            } else {
                return false ;
            }
        }
        
        return temp->endOfword;
        
    }

};

int main(){
    vector<string> word = {"the" ,"a", "there", "their","any","thee"};
    Trie trie;

    for (int i = 0; i < word.size(); i++)
    {
        trie.insert(word[i]);
    }

    cout << boolalpha << trie.search("their") << endl; // 1

return 0;
}