#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next[35];

    node(){
        data = -1;
        for(int i=0; i<35; i++) next[i] = NULL;
    }
};

node* root = new node;

void INSERT(string s){
    node* temp = root;

    for(int i=0, j=0; i<s.size(); i++){
        if(isalpha(s[i])) j = s[i] - 'a';
        else j = s[i] - '0' + 25;
        if(temp->next[j] == NULL) temp->next[j] = new node;
        temp = temp->next[j];
    }

    cout<<s;
    if(temp->data > -1) cout<<temp->data;
    cout<<endl;
    temp->data = 1 + temp->data;
}

int main()
{
    int n; cin>>n;

    string str;

    while(n--) cin>>str , INSERT(str);

    return 0;
}
