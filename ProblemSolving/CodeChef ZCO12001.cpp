#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    int brkt, counter = 0, st, one_two = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0;

    for(int i=1; i<=n; i++){
        cin>>brkt;
        if(brkt==1){
            if(counter==0) st = i;
            counter++;
            one_two++;
            if(counter>a1){
                a1 = counter;
                a2 = i;
            }
        }
        else{
            counter--;
            one_two++;
            if(counter==0){
                if(one_two>a3){
                    a3 = one_two;
                    a4 = st;
                }
                one_two = 0;
            }
        }
    }
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;

    return 0;
}
