#include<stdio.h>
int main()
{
    int a,i,n;
    long int b,c;
    while(scanf("%d",&n)==1 && (n>=0))
    {
        a=0;
        b=1;
        for(i=0;i<=n;i++)
            {c=a+b;
            a=a+1;
            b=c;}
        printf("%ld\n",c);
    }
    return 0;
}

