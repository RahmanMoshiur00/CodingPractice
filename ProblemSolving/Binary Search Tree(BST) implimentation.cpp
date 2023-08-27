#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* Insert(Node* root, int data){
    if(root == NULL) root = newNode(data);
    else if(data <= root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

bool Search(Node* root, int data){
    if(root == NULL) return false;
    else if(data == root->data) return true;
    else if(data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int main()
{
    Node* root = NULL;

    root = Insert(root, 15);
    cout<<root<<endl;
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    cout<<root<<endl;

    printf("%s\n", Search(root, 9) == true ? "found":"not found");
    cout<<root<<endl;

    return 0;
}


