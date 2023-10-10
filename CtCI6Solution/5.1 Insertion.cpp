#include <iostream>
#include <string>
using namespace std;

void PrintBinary(int n)
{
    if(n == 0){
        cout << endl;
        return;
    }

    PrintBinary(n/2);
    cout << n%2;
}

int GetMsbSetIndex(int n)
{
    int ans = 0;
    n /= 2;
    while(n){
        ans++;
        n /= 2;
    }
    return ans;
}

int GetBitValue(int n, int idx)
{
    return (n & (1 << idx)) != 0 ? 1 : 0;
}

int ClearBit(int n, int idx)
{
    return (n & (~(1<<idx)));
}

int SetBit(int n, int idx)
{
    return (n | (1<<idx));
}

int UpdateBit(int n, int idx, int val)
{
    return (ClearBit(n, idx) | (val << idx));
}

void solve(int tc)
{
    int N, M, startIndex, endIndex;
    cin >> N >> M;
    cin >> startIndex >> endIndex;

    PrintBinary(N);
    PrintBinary(M);

    int msbSetIndex = GetMsbSetIndex(M);
    cout << "GetMsbSetIndex(" << M << "): " << msbSetIndex << endl;

    for(int i=0; i<=msbSetIndex; i++){
        N = UpdateBit(N, startIndex, GetBitValue(M, i));
        startIndex++;
    }

    PrintBinary(N);
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int i=1; i<=tc; i++)
        solve(i);
}

/*
5

1024 19
2 6

27876 7688
0 20

255 16
2 6

12 1
0 0

134343445 0
0 1
*/

