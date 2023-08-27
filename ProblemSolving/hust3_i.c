#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d",&a)==1 && a!=0){
        if(a>100) b=a-10;
        else b=91;
        printf("f91(%d) = %d\n",a,b);
    }
    return 0;
}
