#include<stdio.h>

int main()
{
    int t, j;
    scanf("%d", &t);

    for(j=1; j<=t; j++){
        long long int Count, low, high, n, num, i, k, temp;
        scanf("%lld %lld", &low, &high);
        temp = high - low + 1;

        for(n=low; n<=high; n++){
            num = n, Count = 0, k = 0;
            if(num==1){
                temp = temp - 1;
                continue;
            }
            else
            for(i=2; i<=num; i++){
                if(i==n && Count==0){
                    temp = temp - 1;
                    break;
                }
                else if(num%i==0){
                    Count++;
                    if(Count==1) k = i;
                    else if(Count>1 && k!=i){
                        temp = temp - 1;
                        break;
                    }
                    num = num / i;
                    i=1;
                }
            }
        }
        printf("%lld\n", temp);
    }

    return 0;
}

