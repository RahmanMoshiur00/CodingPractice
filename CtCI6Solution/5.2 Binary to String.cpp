#include <string>
#include <iostream>

using namespace std;

void solve(int tc)
{
    double n;
    cin >> n;

    string ans = "";

    while(true){
        n *= 2.0;
        if(n >= 1.0){
            ans += '1';
            n -= 1.0;
            if(n == 0.0)
                break;
        }
        else{
            ans += '0';
        }
        if(ans.size() > 32)
            break;
    }

    if(ans.size() > 32)
        cout << "ERROR" << endl;
    else
        cout << ans << " " << ans.size() << endl;
}

int main()
{
    int tc;
    cin >> tc;
    for(int i=1; i<=tc; i++){
        solve(i);
    }
}
