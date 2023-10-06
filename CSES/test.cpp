#include <bits/stdc++.h>
using namespace std;

int FindTheIntersectionPoint(int n)
{
    if(n == 1 || n == 2)
        return 1;

    int pointer1 = 2, pointer2 = 3;

    while(pointer1 != pointer2){
        cout << pointer1 << ' ' << pointer2 << endl;

        pointer1 += 1;
        if(pointer1 > n) pointer1 -= n;

        pointer2 += 2;
        if(pointer2 > n) pointer2 -= n;
    }

    return pointer1;
}

int main() {
	// your code goes here

	int tc;
	cin >> tc;

	for(int i=1; i<=tc; i++){
	    cout << "#" << i << ": " << FindTheIntersectionPoint(i) << endl << endl;
	}

	return 0;
}
