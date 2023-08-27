#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char num[101] = "1", num_up[101], num_low[101];
    int n, t, i;
    long long j;
    scanf("%d %d", &n, &t);

    for(i=1; i<n; i++){
        strcat(num, "0");
    }

    strcpy(num_low, num);
    strcat(num, "0");
    strcpy(num_up, num);
    //printf("%s\n%s\n", num_low, num_up);

    long long up = atoll(num_up);
    long long low = atoll(num_low);

        for(j=low; j<=up; j++){
            if(j%t==0){
                printf("%lld\n", j);
                goto end;
            }
        }

    printf("-1\n");

    end:
    return 0;
}
