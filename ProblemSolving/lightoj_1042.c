#include<stdio.h>

int main()
{
    int t, j;
    scanf("%d", &t);

    for(j=1; j<=t; j++){
        int num;
        scanf("%d", &num);

        int i, ones1=0, ones2=0, n=num;

        for(i=0; n!=0; i++){
            int mod = n%2;
            ones1 += mod;
            n = n/2;
        }

        int k;

        for(k=num+1; ;k++){
                n = k; ones2 = 0;
            for(i=0; n!=0; i++){
                int mod = n%2;
                ones2 += mod;
                n = n/2;
            }
            if(ones1==ones2){
                printf("Case %d: %d\n", j, k);
                break;
            }
        }
    }
    return 0;
}
