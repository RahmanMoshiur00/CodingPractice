#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int main()
{
    int t;
    scanf("%d", &t);

    int n;
    scanf("%d", &n);

    string str = "";
    for(int i=0; ; i++){
        str += '1';
        for(int j=1; j<=i; j++){

            str += '0';
        }
        if((str.end() - str.begin()) == MAX){
                break;
            }
    }
    cout<<str[n-1];

    for(int i=2; i<=t; i++){
        int n;
        scanf("%d", &n);
        if(i!=t) printf(" ");
        cout<<str[n-1];
    }
    printf("\n");

    return 0;
}
