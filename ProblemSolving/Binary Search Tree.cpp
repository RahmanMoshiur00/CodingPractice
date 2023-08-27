#include<bits/stdc++.h>
using namespace std;

struct BST{
    BST* left;
    BST* right;
    int data;
};

BST* createNode(int value){
    BST* temp = new BST;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

BST* insertion(BST* root, int value){
    if(root==NULL) return createNode(value);
    else if(value <= root->data) root->left = insertion(root->left, value);
    else root->right = insertion(root->right, value);
}

BST* searching(BST* root, int value){
    if(root==NULL) return NULL;
    else if(value == root->data) return root;
    else if(value < root->data) return searching(root->left, value);
    else return searching(root->right, value);
}

BST* maximum(BST* root){
    if(root->right == NULL) return root;
    else return maximum(root->right);
}

BST* minimum(BST* root){
    if(root->left == NULL) return root;
    else return minimum(root->left);
}

int height(BST* root){
    if(root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

BST* deletion(BST* root, int value){
    if(root==NULL) return NULL;
    else if(value > root->data) root->right = deletion(root->right, value);
    else if(value < root->data) root->left = deletion(root->left, value);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->right == NULL){
            BST* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL){
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else{
            BST* temp = maximum(root->left);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
}

void BFS(BST* root, queue<BST*>& node){
    if(root == NULL) return;
    cout<<root->data<<" ";
    if(root->left != NULL) node.push(root->left);
    if(root->right != NULL) node.push(root->right);
    BST* temp = node.front();
    node.pop();
    BFS(temp, node);
}

void DFS_inorder(BST* root){
    if(root == NULL) return;
    DFS_inorder(root->left);
    cout<<root->data<<" ";
    DFS_inorder(root->right);
}

void DFS_preorder(BST* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    DFS_preorder(root->left);
    DFS_preorder(root->right);
}

void DFS_postorder(BST* root){
    if(root == NULL) return;
    DFS_postorder(root->left);
    DFS_postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    BST* root = NULL;

    cout<<"Enter how many entries you want to enter: ";
    int n, num; cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        root = insertion(root, num);
    }
/*
    cout<<"Enter how many queries you want to do: ";
    int que; cin>>que;
    for(int i=0; i<que; i++){
        cin>>num;
        if(searching(root, num) != NULL) cout<<"Found!\n";
        else cout<<"NOT Found\n";
    }

    BST* temp;
    temp = maximum(root);
    cout<<"Maximum element: "<<temp->data<<endl;
    temp = minimum(root);
    cout<<"Minimum element: "<<temp->data<<endl;

    cout<<"HEIGHT = "<<height(root)<<endl;

    cout<<"Enter how many data you want to delete: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        root = deletion(root, num);
    }

    cout<<"Enter how many queries you want to do: ";
    cin>>que;
    for(int i=0; i<que; i++){
        cin>>num;
        if(searching(root, num) != NULL) cout<<"Found!\n";
        else cout<<"NOT Found\n";
    }
*/
    cout<<"Tree traversal using BFS: ";
    queue<BST*> node;
    BFS(root, node);

    cout<<endl<<"Tree traversal using DFS[inorder traversal]: ";
    DFS_inorder(root);

    cout<<endl<<"Tree traversal using DFS[preorder traversal]: ";
    DFS_preorder(root);

    cout<<endl<<"Tree traversal using DFS[postorder traversal]: ";
    DFS_postorder(root);

    return 0;
}
