#include <iostream>
#include <vector>
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

// ----------insertion logic or function ---------
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

//---------- build BST -------------
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

//---------- search key in BST ---------
bool searchKey(Node* root, int key){     // 0 (h)
    if (root == NULL){ return false;} // base case
    if (root->data == key){ return true;} // found base case

    if (root->data > key  ){
        return searchKey(root->left,key); // left subtree
    } else {
        return searchKey(root->right,key);} // right subtree
}

// Inorder Sucessor
Node* getInorderSuccessor(Node* root){
    while (root->left == NULL)
    {
        root =  root->left;
    }
    return root;
    
}

// ---------- deletion -------------
Node* deleteNode(Node* root, int val){
    if (root == NULL)
    {
        return root;
    } else if (val < root->data){
        root->left = deleteNode(root->left,val);
    } else if (val > root->data){
        root->right = deleteNode(root->right,val);
    } else {  // 3 cases childer
        // root == val
        //case1 :0 children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        //case2 : one child
        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }

        // case3 : two child (successor, predessor)
        Node* successor = getInorderSuccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right,successor->data);
        
        return root;        
    }
    return NULL ;
}

// Print in Range Start = 5 , end = 12 ;
void PrintInRange(Node* root, int start, int end){
    if (root == NULL){
        return ;
    }

    if (root->data >= start && root->data <= end)
    {
        cout << root->data << " ";
        PrintInRange(root->left,start,end);
        PrintInRange(root->right,start,end);

    } else if (root->data < start){   // search only in right sub tree
        PrintInRange(root->right, start,end);

    } else if (root->data > end)  // search only in left sub tree
    { 
        PrintInRange(root->left, start,end);
    }
}

// ---------------------------------------------------
// helper function for print vector
void printpath(vector<int>path){
    cout << " path: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    
}

// helper function to Root to leaf
void pathHelper(Node* root,vector<int> &path){
    if (root == NULL)
    {
        return;
    }
    

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL)  // leaf condition
    {
        printpath(path); // print
        path.pop_back(); //pop 
        return;   // back track
    }

    pathHelper(root->left,path); // left subtree
    pathHelper(root->right,path); // right subtree

    path.pop_back();
}

// Root to leaf Path 
void RootToLeaf(Node* root){
    vector<int> path;
    pathHelper(root,path);
    
}
// --------------------------------------------------------

int main(){
    // int arr[6] = {5,1,3,4,2,7};
    int arr2[9] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr2)/sizeof(int);
    Node* root = buildBST(arr2,n);
    

    RootToLeaf(root);
    cout << endl;
    return 0;
}