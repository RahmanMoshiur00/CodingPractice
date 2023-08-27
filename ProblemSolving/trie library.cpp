#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* next[26];
    node* par;

    node(){
        value = -1;
        par = NULL;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

node* root = new node;

void INSERT(string s, int val){
    node* temp = root;
    node* prev = NULL;

    int j;
    for(int i=0; i<s.size(); i++){
        j = s[i]-'a';
        if(temp->next[j] == NULL) temp->next[j] = new node;
        prev = temp;
        temp = temp->next[j];
        temp->par = prev;
    }
    temp->value = val;

    int mx = INT_MIN;
    while(temp->par != NULL){
        mx = max(mx, temp->value);
        temp->value = mx;
        temp = temp->par;
    }
}


int SEARCH(string s){
    node* temp = root;
    int res = -1;

    int j;
    for(int i=0; i<s.size(); i++){
        j = s[i]-'a';
        if(temp->next[j] == NULL) return -1;
        temp = temp->next[j];
    }
    res = temp->value;
    return res;
}

int main()
{
    string str;
    int n, q, val;
    cin>>n>>q;

    while(n--){
        cin>>str>>val;
        INSERT(str, val);
    }

    while(q--){
        cin>>str;
        cout<<SEARCH(str)<<endl;
    }

    return 0;
}
