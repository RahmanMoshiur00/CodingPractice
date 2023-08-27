/*09*/
#include<stdio.h>
#include<math.h>
int d = 0;
int RevOfNum(int a, int n)
{
    int b, c;
    double p;
    b = a % 10;
    p = pow(10, n);
    d = d + (b * p);
    c = a / 10;
    if(c==0) return d;
    n--;
    a = c;
    RevOfNum(a, n);

}
int main()
{
    int num, b, i, n=0, temp;
    printf("Enter number:");
    scanf("%d", &num);
    temp = num;
    for(i=0; ;i++){
        b = temp / 10;
        if(b==0) break;
        n++;
        temp = b;
    }
    int m = RevOfNum(num, n);
    printf("The reverse of %d is %d", num, m);
}

