#include<stdio.h>
int main()
{
    int i, sum=0, count=0, x, z;
    scanf("%d", &x);
    read:
    scanf("%d", &z);
    if(z<=x) goto read;
    for(i=x; i<=z; i++){
        sum += i;
        count++;
        if(sum>z){
            printf("%d\n", count);
            break;
        }
    }

}
