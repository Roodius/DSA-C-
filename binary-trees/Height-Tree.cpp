#include <iostream>
#include <vector>
#include <queue>
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

int height(Node* root){

    if (root == NULL)
    {
        return 0;
    } 
    

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int CurrHeight = max(leftHeight,rightHeight) + 1;

    return CurrHeight;

}

int main(){ 
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    

    Node* root = buildTree(nodes);
    cout << "Root-data: " << root->data << endl;

    int Totalheight = height(root);
    cout << "Height of fa tree: " << Totalheight << endl;

return 0;
}