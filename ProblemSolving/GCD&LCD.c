#include <stdio.h>
int gcd(int a, int b)
{
    int t;
    if(a==0) return a;
    else if(b == 0) return b;
    else{
        while(a != 0){
            t = a;
            a = b % a;
            b = t;
        }
        return b;
    }
}
int lcd(int a, int b)
{
    if(a==0) return b;
    else if(b == 0) return a;
    else{int lcd = (a*b) / gcd(a, b);
    return lcd;
    }
}
int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = gcd(a, b);
    printf("gcd is %d\n", c);
    c = lcd(a, b);
    printf("lcd is %d\n", c);
}
