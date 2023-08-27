/*23*/
#include<stdio.h>
int intToBin(int n)
{
    int vs = n % 2;
    int vf = n / 2;
    if(vf == 0){
        printf("1");
        return 0;
    }
    n = vf;
    intToBin(n);
    printf("%d", vs);
}
int main()
{
    int n;
    printf("Enter a decimal number to convert in binary:");
    scanf("%d", &n);
    intToBin(n);
}
