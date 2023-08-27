#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int x, val, sz = s.size();
    string p = "";
    for(int i=0; p.size() < 11; i++){
        i = i % sz;
        x = (int) s[i];
        val = ((i+1)*x*x*x*x) + ((i+1)*x*x*x) + ((i+1)*x*x) + ((i+1)*x) + (i+1);
        if(i%3==0){
            val = val % 26;
            p += (val + 'A');
        }
        else if(i%3==1){
            val = val % 26;
            p += (val + 'a');
        }
        else{
            val = val % 10;
            p += (val + '0');
        }
    }

    cout << p << endl;

    return 0;
}
