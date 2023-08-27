#include <bits/stdc++.h>
using namespace std;
#define rep(i, begin, end)  for(__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


struct node{
    bool isNumber;
    node* next[10];
    node(){
        isNumber = false;
        rep(i, 0, 10) next[i] = NULL;
    }
};

bool INSERT(string& s, node* root){
    int l = s.size(), v;
    node* temp = root;

    bool ret = true;
    rep(i, 0, l-1){
        v = s[i] - '0';
        if(temp->next[v] == NULL) temp->next[v] = new node;
        temp = temp->next[v];
        if(temp->isNumber) ret = false;
    }
    v = s[l-1] - '0';
    if(temp->next[v] == NULL) temp->next[v] = new node;
    else ret = false;
    temp = temp->next[v];
    if(temp->isNumber) ret = false;
    temp->isNumber = true;

    return ret;
}

void DELETE(node* root){
    rep(i, 0, 10){
        if(root->next[i] != NULL) DELETE(root->next[i]);
        delete root->next[i];
    }
}

void solve(int t)
{
    int n; cin>>n;

    string s;
    bool yes = true;

    node* root = new node;
    while(n--){
        cin>>s;
        yes &= INSERT(s, root);
    }

    DELETE(root);
    delete root;

    if(yes) cout<<"Case "<<t<<": YES"<<endl;
    else cout<<"Case "<<t<<": NO"<<endl;
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1){
        solve(t);
    }

    return 0;
}
