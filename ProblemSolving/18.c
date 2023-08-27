/*18*/
#include <stdio.h>
int main()
{
    int a, b, t, x, gcd;
    scanf("%d %d", &a, &b);
    int product = a * b;
    if(a == 0) gcd = b;
    else if(b == 0) gcd = a;
    else{
        while(b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        gcd = a;
    }
    int lcm  = product / gcd;
    printf("GCD is %d\n", gcd);
    printf("LCM is %d", lcm);
    return 0;
}
