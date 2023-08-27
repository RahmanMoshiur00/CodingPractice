/*16*/
#include<stdio.h>
int findhcm(int a, int b, int low)
{
    if(a==0) return b;
    else if(b==0) return a;
    if(a%low==0 && b%low==0){
            return low;
    }
    low--;
    findhcm(a, b, low);
}
int main()
{
    int a, b, hcm, low;
    printf("Enter two numbers to find hcm:");
    scanf("%d%d", &a, &b);
    if(a>b) low = b;
    else low = a;
    hcm = findhcm(a, b, low);
    printf("HCM(%d,%d)=%d", a, b, hcm);


}
