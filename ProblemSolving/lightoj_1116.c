#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        unsigned long n, i, j, even[100000], k;
        int count = 0;
        scanf("%lu", &n);
        if(n%2==1) printf("Case %d: Impossible\n", l);
        else{
            for(i=1, k=0; i<=n/2; i++){
                for(j=n/2; j>=1; j--){
                    if(i*j==n && ((i%2==0 && j%2==1) || (i%2==1 && j%2==0))){
                        if(i%2==0){
                            even[k] = i;
                            k++;
                        }
                        else if(j%2==0){
                            even[k] = j;
                            k++;
                        }
                        count++;
                    }
                }
            }
            unsigned long min = even[0];
            for(i=1; i<k; i++){
                if(min>even[i]) min = even[i];
            }
            if(count!=0) printf("Case %d: %lu %lu\n", l, n/min, min);
            else printf("Case %d: Impossible\n", l);
        }
    }
}
