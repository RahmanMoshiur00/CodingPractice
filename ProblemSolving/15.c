/*15*/
#include<stdio.h>
int findgcd(int a, int b, int low)
{
    if(a==0) return b;
    else if(b==0) return a;
    if(a%low==0 && b%low==0){
            return low;
    }
    low--;
    findgcd(a, b, low);
}
int main()
{
    int a, b, gcd, low;
    printf("Enter two numbers to find gcd:");
    scanf("%d%d", &a, &b);
    if(a>b) low = b;
    else low = a;
    gcd = findgcd(a, b, low);
    printf("GCD(%d,%d)=%d", a, b, gcd);


}
