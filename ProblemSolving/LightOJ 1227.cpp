#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int n, p, q;
        scanf("%d %d %d", &n, &p, &q);
        int arr[n];
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        int counter=0, sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            counter++;
            if(sum>q || counter>p){
                counter--;
                break;
            }
        }

        printf("Case %d: %d\n", l, counter);
    }

    return 0;
}
