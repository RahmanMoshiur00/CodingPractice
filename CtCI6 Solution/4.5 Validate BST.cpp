#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root, int val)
{
    if(root == NULL){
        Node* newNode = new Node;
        root = newNode;
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(val <= root->data){
        root->left = Insert(root->left, val);
        return root;
    }
    else{
        root->right = Insert(root->right, val);
        return root;
    }
}

Node* BuildBST(vector<int>& vec)
{
    Node* root = NULL;

    for(int i=0; i<vec.size(); i++){
        if(i==0)
            root = Insert(root, vec[i]);
        else
            Insert(root, vec[i]);
    }

    return root;
}



void Traverse(Node* root){
    if(root == NULL)
        return;


    Traverse(root->left);
    cout << root->data << ' ';
    Traverse(root->right);
}

int solve(int tc)
{
    vector<int> vec;
    int sz, x;
    cin >> sz;

    for(int i=0; i<sz; i++){
        cin >> x;
        vec.push_back(x);
    }

    Node* root = BuildBST(vec);
    cout << "BST is built." << endl;
    Traverse(root);
}

int main() {

	solve(1);

	return 0;
}

/*
Input:
8
20 10 30 5 15 3 7 17
Expected Output:
3 5 7 10 15 17 20 30
*/

