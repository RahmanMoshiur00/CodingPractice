#include <bits/stdc++.h>
using namespace std;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


struct node{
    int cnt;
    node* next[52];
    node(){
        cnt = 0;
        rep(i, 0, 52) next[i] = NULL;
    }
};

int idx(char ch){
    if(isupper(ch)) return (ch - 'A');
    else return (ch - 'a' + 26);
}

void INSERT(string& s, node* root){
    int l = s.size();
    node* temp = root;
    rep(i, 0, l){
        int v = idx(s[i]);
        if(temp->next[v] == NULL) temp->next[v] = new node;
        temp = temp->next[v];
    }
    temp->cnt += 1;
}

int QUERY(string& s, node* root){
    int l = s.size();
    node* temp = root;
    rep(i, 0, l){
        int v = idx(s[i]);
        if(temp->next[v] == NULL) return 0; //this word 's' isn't present in the dictionary so no valid sentence is possible
        temp = temp->next[v];
    }

    return temp->cnt;
}

void DELETE(node* root){ //deleting all nodes in the trie
    rep(i, 0, 52){
        if(root->next[i] != NULL) DELETE(root->next[i]);
        delete root->next[i];
    }
}

void solve(int t){
    int n; cin>>n;
    string s;
    node* root = new node;
    while(n--){
        cin>>s;
        if(s.size()>2) sort(s.begin()+1, s.end()-1); //since, the first and last characters are fixed
        INSERT(s, root);
    }

    int q; cin>>q; getchar();

    cout<<"Case "<<t<<":"<<endl;
    while(q--){
        int ans = 1;
        getline(cin, s);
        stringstream ss(s);
        while(ss>>s){
            if(s.size()>2) sort(s.begin()+1, s.end()-1);
            ans *= QUERY(s, root);
        }
        cout<<ans<<endl;
    }

    DELETE(root);
    delete root;
}


int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}
