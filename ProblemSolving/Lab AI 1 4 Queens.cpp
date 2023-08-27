#include <bits/stdc++.h>
using namespace std;

int chess[4][4];

void FourQueens(int r, int c, bool isTaken, vector<vector<int>> v)
{
    if(r<0 or r>=4 or c<0 or c>=4) return;



}

int main()
{
    vector<vector<int>> v(4);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            v[i].push_back(0);
        }
    }

    FourQueens(0, 0, true, v);
    FourQueens(0, 0, false, v);
}
