#include <bits/stdc++.h>
using namespace std;

#define MIN -1e9
#define MAX 1e9

int Minimax_Alpha_Beta(int depth, int idx, bool isMax, int arr[], int alpha, int beta, int h)
{
    if(depth == h){
        return arr[idx];
    }

    int best, val;

    if(isMax){
        best = MIN;
        for(int i=0; i<2; i++){
            val = Minimax_Alpha_Beta(depth+1, idx*2 + i, false, arr, alpha, beta, h);
            best = max(best, val);
            alpha = max(alpha, best);
            if(alpha >= beta){
                break;
            }
        }
        return best;
    }
    else{
        best = MAX;
        for(int i=0; i<2; i++){
            val = Minimax_Alpha_Beta(depth+1, idx*2 + i, true, arr, alpha, beta, h);
            best = min(best, val);
            beta = min(beta, best);
            if(alpha >= beta){
                break;
            }
        }
        return best;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int h = 0;
    while(n>1){
        n /= 2;
        h++;
    }

    cout << "The optimal result: " << Minimax_Alpha_Beta(0, 0, true, arr, MIN, MAX, h) << endl;
}

/*
8
3 5 2 9 12 5 23 23
*/

