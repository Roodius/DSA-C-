#include <iostream>
using namespace std;

// node building
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left  = NULL;
        right  = NULL;
    }

};

// insertion logic or function
Node* insert(Node* root, int val){  // o(logn)
    if (root == NULL) // base cases
    {
      root =  new Node(val);
      return root;
    } 

    if (val < root->data)  // left subtree
    {
        root->left  = insert(root->left,val);
    } else  // right subtree
    {
        root->right = insert(root->right,val);
    }
    
    return root;
}

// build BST
Node* buildBST(int arr[], int n){
    Node* root  = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}
// inorder
void inorder(Node* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}   

// search key in BST
bool searchKey(Node* root, int key){     // 0 (h)
    if (root == NULL){ return false;} // base case
    if (root->data == key){ return true;} // found base case

    if (root->data > key  ){
        return searchKey(root->left,key); // left subtree
    } else {
        return searchKey(root->right,key);} // right subtree
}

// deletion

int main(){
    // int arr[6] = {5,1,3,4,2,7};
    int arr2[9] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr2)/sizeof(int);
    Node* root = buildBST(arr2,n);
    inorder(root);
    cout << boolalpha << endl;
    cout << "key exists ?: "<< searchKey(root,4) << endl;
    return 0;
}