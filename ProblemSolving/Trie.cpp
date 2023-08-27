#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endmark;
    node* next[26];
    node(){
        endmark = false;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

void Insert(string str, node* root){
    node* temp = root;
    for(int i=0; i<str.length(); i++){
        int ch = str[i] - 'a';
        if(temp->next[ch] == NULL){
            temp->next[ch] = new node();
        }
        temp = temp->next[ch];
    }
    temp->endmark = true;
}

bool Search(string str, node* root){
    node* temp = root;
    for(int i=0; i<str.length(); i++){
        int ch = str[i] - 'a';
        if(temp->next[ch] == NULL) return false;
        temp = temp->next[ch];
    }
    return temp->endmark;
}

void Delete(node* root){
    for(int i=0; i<26; i++){
        if(root->next[i] != NULL) Delete(root->next[i]);
    }
    delete root;
}

int main()
{
    cout<<"Enter how many words you wants to enter: ";
    int n; cin>>n;

    string str;
    node* root = new node();
    for(int i=0; i<n; i++){
        cin>>str;
        Insert(str, root);
    }

    cout<<"Enter how many search queries you want to have: ";
    int q; cin>>q;

    for(int i=0; i<q; i++){
        cin>>str;
        if(Search(str, root)) cout<<str<<" is FOUND."<<endl;
        else cout<<str<<" is NOT FOUND!\n";
    }

    Delete(root);

    return 0;
}
