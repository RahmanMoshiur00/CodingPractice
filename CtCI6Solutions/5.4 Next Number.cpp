#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string GetBitString(int n)
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

void SetBit(int &n, int idx)
{
    n |= 1 << idx;
}

void ClearBit(int &n, int idx)
{
   n &= ~(1 << idx);
}

void ClearBitRange(int &n, int startIndex, int endIndex)
{
    int LsbSetSide = (1 << startIndex) - 1;
    int MsbSetSide = ~((1 << (endIndex+1)) - 1);
    int mask = MsbSetSide | LsbSetSide;
    //cout << "ClearBitRange Mask(" << mask << "): " << GetBitString(mask) << endl;
    n &= mask;
}

void SetBitRange(int &n, int startIndex, int endIndex)
{
    int LsbSetSide = (1 << startIndex) - 1;
    int MsbSetSide = ~((1 << (endIndex+1)) - 1);
    int mask = MsbSetSide | LsbSetSide;
    mask = ~mask;
    //cout << "SetBitRange Mask(" << mask << "): " << GetBitString(mask) << endl;
    n |= mask;
}

int GetImmediateSmallerNumber(int x)
{
    int n = x,
        p = -1,
        c1 = 0;

    while((n & 1) == 1){ // 1's after trailing zeros
        n >>= 1;
        p++;
        c1++;
    }

    while((n & 1) == 0 && (n != 0)){ // trailing zeros
        n >>= 1;
        p++;
    }

    if(p == 31){
        // no smaller number possible
        return x;
    }
    
    // now p is the left-most LSB index of 0, which has at least one set bit in its left
    ClearBit(x, p+1);
    SetBit(x, p);
    ClearBitRange(x, 0, p-1);
    SetBitRange(x, p-c1, p-1);
    return x;
}

int GetImmediateLargeNumber(int x)
{
    int n = x,
        p = -1,
        c1 = 0;

    while((n & 1) == 0 && (n != 0)){ // trailling zeros
        n >>= 1;
        p++;
    }

    while((n & 1) == 1){ // 1's after trailing zeros
        n >>= 1;
        p++;
        c1++;
    }

    if(p == 31){ // assuming 32-bit integer
        // no valid immediate large number
        return x;
    }

    //next bit must be 0
    p++;

    SetBit(x, p);
    //cout << "After SetBit: " << GetBitString(x) << endl;
    ClearBitRange(x, 0, p-1); //range: [0, p-1]
    //cout << "After ClearBitRange: " << GetBitString(x) << endl;
    SetBitRange(x, 0, c1-2); //range: [0, c1-2]
    //cout << "After SetBitRange: " << GetBitString(x) << endl;

    return x;
}

void solve(int tc)
{
    int n = 13948; //CtCI example
    cin >> n;
    cout << "Number (" << n << "): " << GetBitString(n) << endl;

    int greater = GetImmediateLargeNumber(n);
    cout << "Greater (" << greater << "): " << GetBitString(greater) << endl;
    
    int smaller = GetImmediateSmallerNumber(n);
    cout << "Smaller (" << smaller << "): " << GetBitString(smaller) << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;

    for(int i=1; i<=tc; i++){
        solve(i);
    }
}

/*
4
13948
13967
13946
156
*/