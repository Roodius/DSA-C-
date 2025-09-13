#include <iostream>
#include <vector>
using namespace std;

class Node {
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>nodes){
    idx++;
    
    if (nodes[idx] == -1)
    {
        return NULL;
    }
    

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void InOrder(Node* root){
    if (root == NULL)
    {
        return;
    }
    

    InOrder(root->left);  // left tree

    cout << root->data << " ";  //root

    InOrder(root->right); // right

}

int main(){ 
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    

    Node* root = buildTree(nodes);
    // cout << "Root-data: " << root->data << endl;

    InOrder(root);
    cout << endl;

return 0;
}