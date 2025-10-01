#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
    public:
    unordered_map<char,Node*>children;
    bool endeofword;
    int freq = 0;

    Node(){
        endeofword = false;
    }

};

class Trie {
    Node* root;

    public :
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
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endeofword  = true;
    }

    void LongestStringwithEof(Node* root,string &ans,string temp){
        for (pair<char,Node*> child : root->children)
        {   
            if (child.second->endeofword)
            {
                temp += child.first; 
            /*
                sizeof(temp) == sizeof(ans) && temp (smaller then) ans => ans become temp;
                or
                sizeof(temp) >  sizeof(ans) => temp become ans;
            */
            if (temp.size() == ans.size() && temp < ans || (temp.size() > ans.size()))
            {
                ans = temp; /* according lexicographically small */
                temp = ans;
            }
            LongestStringwithEof(child.second,ans,temp);
            temp = temp.substr(0,temp.size() -1);   // removing ele when subtracked
            }
            
            
        }
    }

    string LongestStringwithEofHelper(){
        string ans = "";
        string temp = "";
        LongestStringwithEof(root,ans,temp);
        return ans;
    }

};

string longestString(vector<string>dict){
    Trie trie;
    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    return trie.LongestStringwithEofHelper();
}

int main(){
    vector<string>dict = {"a", "banana", "app","appl","ap","apply","apple"};

    string ans = longestString(dict);

    cout << "longest string : " << ans << endl;

return 0;
}