#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long num, i;
        scanf("%lld", &num);
        if(num==2) printf("2 is a prime\n");
        else if(num==1) printf("1 is not a prime\n");
        else{
            for(i=2; i<=sqrt(num); i++){
                if(num%i==0){
                    printf("%lld is not a prime\n", num);
                    goto end;
                }
            }
            printf("%lld is a prime\n", num);
            end:
                printf("");
        }
    }
    return 0;
}
