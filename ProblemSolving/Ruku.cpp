#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ruku[115], cnt[115] = {0};
    for(int i=1; i<=114; i++) cin >> ruku[i], cnt[i] = cnt[i-1] + ruku[i];

    int l = 1, r;
    while(l){
        cout << "Query: ";
        cin >> l >> r;
        if(l==0 || r==0) break;
        if(r<l) continue;
        cout << "Result: " << cnt[r] - cnt[l-1] << endl;
    }
}

/*
1
40
20
24
16
20
24
10
16
11
10
12
6
7
6
16
12
12
6
8
7
10
6
9
6
11
7
9
7
6
4
3
9
6
5
5
5
5
8
9
6
5
7
3
4
4
4
4
2
3
3
2
3
3
3
3
4
3
3
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
2
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
*/
