#include <iostream>
#include <string>
using namespace std;


int GetBitValue(int n, int idx)
{
     if((n & (1<<idx)) != 0)
          return 1;
     else
          return 0;
}

int GetMsbIndex(int n)
{
     int ans = 0;
     while(n){
          n /= 2;
          ans++;
     }
     return (ans - 1);
}

void solve(int tc)
{
     int n;
     cin >> n;

     if(~n == 0){
          int sz = sizeof(n);
          cout << n << " -> " << sz * 8 << endl;
          return;
     }
     else if(n == 0){
          cout << n << " -> " << 1 << endl;
          return;
     }



     int msbIndex = GetMsbIndex(n);

     if(msbIndex < (sizeof(n) * 8) - 1)
          msbIndex++;
     
     int ans = 0, prev = 0, current = 0;
     for(int i=0; i<=msbIndex; i++){
          int bit = GetBitValue(n, i);
          if(bit == 0){
               ans = max(ans, prev + current + 1);
               prev = current;
               current = 0;
          }
          else{
               current++;
          }
     }

     cout << n << " -> " << ans << endl;
}



int main()
{
     int tc;
     cin >> tc;

     for(int i=1; i<=tc; i++){
          solve(i);
     }
}


/* input
8

1775
6492
156
15
2147483647
60
1
0
*/

/* output
1175 -> 8
6492 -> 5
156 -> 4
15 -> 5
2147483647 -> 32
60 -> 5
1 -> 2
0 -> 1
*/