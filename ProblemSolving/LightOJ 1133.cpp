#include<bits/stdc++.h>
using namespace std;

void process(char str[], int n, int arr[]){

    if(str[0]=='S'){
        int d;
        char c[3];
        sscanf(str, "%s %d", c, &d);
        for(int i=0; i<n; i++) arr[i] += d;
    }
    else if(str[0]=='M'){
        int d;
        char c[3];
        sscanf(str, "%s %d", c, &d);
        for(int i=0; i<n; i++) arr[i] *= d;
    }
    else if(str[0]=='D'){
        int d;
        char c[3];
        sscanf(str, "%s %d", c, &d);
        for(int i=0; i<n; i++) arr[i] /= d;
    }
    else if(str[0]=='P'){
        int d1, d2;
        char c[3];
        sscanf(str, "%s %d %d", c, &d1, &d2);
        swap(arr[d1], arr[d2]);
    }
    else if(str[0]=='R'){
        for(int i=0, j=n-1; i<n/2; i++, j--) swap(arr[i], arr[j]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int l=1; l<=t; l++){

        int n, q;
        scanf("%d %d ", &n, &q);

        int arr[n];
        char cmnd[10];

        for(int i=0; i<n; i++) scanf("%d ", &arr[i]);

        for(int i=0; i<q; i++){
            gets(cmnd);
            process(cmnd, n, arr);
        }

        printf("Case %d:\n", l);
        for(int i=0; i<n; i++){
            printf("%d", arr[i]);
            if(i==n-1) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}
