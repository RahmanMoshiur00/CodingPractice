#include <bits/stdc++.h>
using namespace std;



void solve(int tc)
{
    int r, c, k;
    cin >> r >> c >> k;

    vector<string> s(r);
    for(int i=0; i<r; i++) cin >> s[i];

    vector<bool> in_trick[r];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            in_trick[i].push_back(false);
        }
    }

    for(int i=1; i<r; i++){
        for(int j=1; j+1<c; j++){
            if(s[i][j]=='*' && in_trick[i][j]==false && s[i-1][j-1]=='*' && s[i-1][j+1]){
                int left = 0, right = 0;
                for(int x=1; i-x>=0 && j-x>=0 && s[i-x][j-x]=='*'; x++) left++;
                for(int x=1; i-x>=0 && j+x<c && s[i-x][j+x]=='*'; x++) right++;
                if(min(left, right)>=k){
                    int cnt = min(left, right);
                    in_trick[i][j] = true;
                    for(int x=1; cnt-- ; x++){
                        in_trick[i-x][j-x] = true;
                        in_trick[i-x][j+x] = true;
                    }
                }
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(s[i][j]=='*' && in_trick[i][j]==false){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main()
{
    int tc;
    cin >> tc;
    for(int i=1; i<=tc; i++) solve(i);

    return 0;
}
