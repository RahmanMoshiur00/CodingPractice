#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int positive_blocks = 0, block_start = -1, zero = 0, sum = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > 0) sum += arr[i];

        if(i==0){
            if(arr[i]>=0){
                block_start = i;
                if(arr[i]==0) zero++;
            }
        }
        else{
            if(arr[i]>0){
                if(block_start == -1){
                    block_start = i;
                }
            }
            else if(arr[i]==0){
                if(block_start == -1){
                    block_start = i;
                    zero++;
                }
                else{
                    zero++;
                }
            }
            else{
                if(block_start!=-1 && i-block_start != zero){
                    positive_blocks++;
                    debug cout << "At: " << i << endl;
                }
                block_start = -1;
                zero = 0;
            }
        }
    }

    if(block_start!=-1 && n-block_start != zero){
        positive_blocks++;
        debug cout << "At: " << n << endl;
    }


    int ans = sum, z = 0;
    if(sum == 0){
        ans = *max_element(arr, arr+n);
    }

    cout << "Case " << test_case << ": " << ans << " " << max(z, positive_blocks-1) << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
12

15
0 -1 0 2 -10 -4 0 0 -1 3 4 0 -10 -2 4

5
0 0 -1 -2 0

5
0 0 0 0 0

1
-1

1
0

1
5

3
-1 -2 -3

2
4 5

7
-1 2 0 4 -2 -3 0

11
0 -1 2 4 6 -2 -3 3 3 -1 0

5
1 0 2 3 4

3
-1 3 -5
*/
