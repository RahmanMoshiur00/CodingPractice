#include<stdio.h>
#include<math.h>
int i = 2;
int findPrime(int n)
{
   if(n==2 || n==3) return 1;
   else if(n % i == 0) return 0;
   double root = sqrt(n);
   if(i == (int)root) return 1;
   i++;
   findPrime(n);
}
int main()
{
    int num, n;
    printf("Enter number:");
    scanf("%d", &num);
    n = findPrime(num);
    if(n == 1) printf("%d is prime", num);
    else if(n == 0) printf("%d is not prime", num);
}
