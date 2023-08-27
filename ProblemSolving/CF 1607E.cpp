#include <bits/stdc++.h>
using namespace std;

#define debug if(0)

int main()
{
    int tc, n, m;
    cin >> tc;
    string s;

    int row, col;
    int hor_count = 0, ver_count = 0;
    int hor_max = 0, hor_min = 0;
    int ver_max = 0, ver_min = 0;

    while(tc--){
        cin >> n >> m;
        cin >> s;

        hor_count = 0, ver_count = 0;
        hor_max = 0, hor_min = 0;
        ver_max = 0, ver_min = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='R'){
                hor_count++;
            }
            else if(s[i]=='L'){
                hor_count--;
            }
            else if(s[i]=='D'){
                ver_count++;
            }
            else{ // s[i] == 'U'
                ver_count--;
            }

            int hhor_max = max(hor_max, hor_count);
            int hhor_min = min(hor_min, hor_count);

            int vver_max = max(ver_max, ver_count);
            int vver_min = min(ver_min, ver_count);

            if(hhor_max-hhor_min>=m || vver_max-vver_min>=n) break;

            hor_max = max(hor_max, hor_count);
            hor_min = min(hor_min, hor_count);

            ver_max = max(ver_max, ver_count);
            ver_min = min(ver_min, ver_count);

            debug cout << i << ": " << hor_min << ' ' << ver_min << endl;

        }

        col = 1 - hor_min;
        //col = n - hor_max;

        row = 1 - ver_min;
        //row = n - ver_max;

        cout << row << ' ' << col << endl;
    }
}
