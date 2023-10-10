#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int val;

    TreeNode(int _val, TreeNode* _parent){
        left = right = nullptr;
        val = _val;
        parent = _parent;
    }
};

TreeNode* Insert(TreeNode* root, TreeNode* parent, int x)
{
    if(root == nullptr){
        root = new TreeNode(x, parent);
        return root;
    }
    if(x <= root->val)
        root->left = Insert(root->left, root, x);
    else
        root->right = Insert(root->right, root, x);
    return root;
}

TreeNode* FindLeftMostNode(TreeNode* root)
{
    if(root->left == nullptr)
        return root;
    return FindLeftMostNode(root->left);
}

TreeNode* FindUpperRightAncestor(TreeNode* root)
{
    if(root == nullptr)
        return nullptr;

    if(root->parent != nullptr && root->parent->left == root)
        return root->parent;

    return FindUpperRightAncestor(root->parent);
}

TreeNode* FindInOrderSuccessor(TreeNode* root)
{
    if(root == nullptr)
        return nullptr;
    if(root->right != nullptr)
        return FindLeftMostNode(root->right);
    else
        return FindUpperRightAncestor(root);
}


int main()
{
    TreeNode* root = nullptr;
    root = Insert(root, nullptr, 20);
    root = Insert(root, nullptr, 8);
    root = Insert(root, nullptr, 22);
    root = Insert(root, nullptr, 4);
    root = Insert(root, nullptr, 12);
    root = Insert(root, nullptr, 10);
    root = Insert(root, nullptr, 14);

    /* BST:
                (20)
                /  \
              (8)  (22)
              / \
            (4) (12)
                / \
              (10)(14)


    */

    cout << "Insertion completed" << endl;

    TreeNode* node = root->left;
    TreeNode* successor = FindInOrderSuccessor(node);
    cout << "Successor of " << node->val << " is " << successor->val << endl;

    node = root->left->right->right;
    successor = FindInOrderSuccessor(node);
    cout << "Successor of " << node->val << " is " << successor->val << endl;

    node = root->left->left;
    successor = FindInOrderSuccessor(node);
    cout << "Successor of " << node->val << " is " << successor->val << endl;

    node = root->left->right->left;
    successor = FindInOrderSuccessor(node);
    cout << "Successor of " << node->val << " is " << successor->val << endl;

    node = root;
    successor = FindInOrderSuccessor(node);
    cout << "Successor of " << node->val << " is " << successor->val << endl;

    return 0;
}
