#include<stdio.h>
int main()
{
    int hnum, num, lnum, half;
    printf("enter thre lowest number:");
    scanf("%d", &lnum);
    printf("enter thre highest number:");
    scanf("%d", &hnum);
    printf("enter the number:");
    scanf("%d", &num);



    while(1){
        half = (hnum + lnum) / 2;
        if(num == half) break;
        else if(num > half) lnum = half;
        else if(num < half) hnum = half;
    }
     printf("desire number is %d\n", half);

}
