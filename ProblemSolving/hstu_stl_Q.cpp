#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d ", &n);
    map<string, int> email;
    for(int i=0; i<n; i++){
        string name;
        cin>>name;
        email[name]++;
        if(email[name]==1) printf("OK\n");
        else{
            int occurance = email[name] - 1;
            stringstream ss;
            ss<<occurance;
            string add = ss.str();
            name += add;
            cout<<name<<endl;
        }
    }

    return 0;
}
