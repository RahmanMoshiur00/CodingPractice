#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string GetBinaryString(int n)
{
    string bits = "";
    bool isNegative = false;
    if(n < 0){
        n = (int)pow(2, 31) + n;
        isNegative = true;
    }

    while(n != 0){
        if(n%2 == 1)
            bits += '1';
        else
            bits += '0';
        n /= 2;
    }
    if(isNegative){
        bits += '1';
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

void MySolution(int a, int b)
{
    cout << "[MySolution] Number of bits needs to flip in the conversion of " << a << " to " << b << ": ";
    int ans = 0;
    while(a != 0 || b != 0){
        cout << "debug: " << GetBinaryString(a) << ' ' << GetBinaryString(b) << endl;
        if((a&1) == 1 && (b&1) == 0) ans++;
        else if((a&1) == 0 && (b&1) == 1) ans++;
        a >>= 1;
        b >>= 1;
    }
    cout << ans << endl;
}

void CtCISolution(int a, int b)
{
    cout << "[CtCISolution] Number of bits needs to flip in the conversion of " << a << " to " << b << ": ";
    int ans = 0;
    int c = a^b;
    while(c != 0){
        if((c & 1) == 1){
            ans++;
        }
        c >>= 1;
    }
    cout << ans << endl;
}

void solve(int tc)
{
    int a, b;
    cin >> a >> b;

    //these solutions works for (a,b) >= 0
    MySolution(a, b);
    CtCISolution(a, b);
}

int main()
{
    int tc = 1;
    cin >> tc;

    for(int i=1; i<=tc; i++){
        solve(i);
    }
}