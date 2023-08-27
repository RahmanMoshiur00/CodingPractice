#include<stdio.h>
int main()
{
    int a, b, sum=0, i;
    while(scanf("%d %d", &a, &b)==2){
            sum=0;
        if(a==0 || b==0) goto end;
        else if(a>b){
            for(i=b; i<=a; i++){
                sum += i;
                printf("%d ", i);
            }
            printf("Sum=%d\n", sum);
        }
        else{
            for(i=a; i<=b; i++){
                sum += i;
                printf("%d ", i);

            }
            printf("Sum=%d\n", sum);
        }
    }
    end:
        return 0;
}
