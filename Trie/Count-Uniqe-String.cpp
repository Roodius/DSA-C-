#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
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

    int countOfNodes(Node* root){
        if (root == NULL) return 0;

        int count = 0;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            count++;  // count this node

         for (auto& child : current->children) {
                q.push(child.second);
            }
        }

        return count;

    }

    int RealCount(){
        return countOfNodes(root);
    }

};

int  countDistinctSubstrings(string s){
    Trie trie;
    
    for (int i = 0; i < s.size(); i++)
    {
        string suffix = s.substr(i);   // suffix
        trie.insert(suffix);           // prefix
    }

    return trie.RealCount() -1;

}

void suffixProblem(vector<string>words){
    for (string word : words)
    {
        cout << "Word: " << word << endl;
        cout << "Distinct substrings: " << countDistinctSubstrings(word) << endl;
    }
    
}



int main(){
    vector<string>words = {" ababa"};

    suffixProblem(words);
    

return 0;
}