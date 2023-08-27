#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Problem A - Arya Stark's Final Assignment
int main()
{
    int n,t, Px,Py,Qx,Qy,Rx,Ry;
    scanf("%d",&n);
    for(t=1; t<=n; t++){
        scanf("%d %d %d %d", &Px,&Py,&Qx,&Qy);
        Rx= 2 * Qx - Px;
        Ry= 2 * Qy - Py;
        printf("%d  %d\n",Rx,Ry);
    }
    return 0;
}



//Problem B - John Snow knows nothing?
int main()
{
    int i,t,n;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        printf("%d\n",n+1);
    }
    return 0;
}



//Problem D - Daenerys Targaryen's "Triangle Monument" in Meereen
int main()
{
    int a,b,x;
    float h;
    scanf("%d%d",&b,&a);

    h=(2*a)/(float)b;
    x=ceil(h);
    printf("%d\n",x);

    return 0;
}



//Problem E - Ramsy Bolton's Army Game
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    if(a%2!=0) a=a+1;
    if(b%2!=0) b=b+1;

    printf("%d\n",(a*b)/4);
    return 0;
}



//Problem F - Game of Operators
int main()
{
    int m,n,i,t;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&m,&n);
        if(m>n)
            printf(">\n");
        if(m<n)
            printf("<\n");
        if(m==n)
            printf("=\n");
    }
    return 0;
}



//Problem G - Tyrion Loves "Four" [modular version]
int main()
{
    int t, i, s, d, n, count;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        count = 0;
        scanf("%ld",&n);
        while(n!=0)
        {
            d=n%10;
            if(d==4)
                count++;
            n=n/10;
        }

        printf("%d\n",count);
    }
    return 0;
}
//Problem G - Tyrion Loves "Four" [string version]
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[100];
        scanf("%s",str);
        int i,count=0;
        for(i=0 ; str[i]!='\0' ; i++)
        {
            if(str[i]=='4') count++;
        }
        printf("%d\n",count);
    }
    return 0;
}



//Problem H - Iron Bank and Bank Notes
int main()
{
    int i,t,n,p;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d", &n);

        p = n/100;
        n = n%100;
        p = p+n/50;
        n = n%50;
        p = p+n/10;
        n = n%10;
        p = p+n/5;
        n = n%5;
        p = p+n/2;
        n = n%2;
        p = p+n;

        printf("%d\n", p);
    }
    return 0;
}



//Problem I - Cersei Lannister’s Debt to Iron Bank
int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if((n*a)<b)
    {
        printf("%d\n",n*a);
    }
    else
    {
        printf("%d\n",b);
    }
    return 0;
}



//Problem J - Grey Worm and Fresh Flowers
int main()
{
    double a,b;
    double x;
    scanf("%lf%lf",&a,&b);
    x=(a+b)/2;
    printf("%.0lf\n",round(x)); //another approach is (a+b+1)/2
    return 0;
}
