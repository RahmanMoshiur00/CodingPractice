#include <stdio.h>

int prime(int n)
{
    if(n == 1) return 0; // 1 is not prime
    if(n == 2) return 1; // 2 is prime

    int i;
    for(i = 2; i*i <= n; i++){
        if(n % i == 0){ // if n is divisible by i, then n is not prime
            return 0;
        }
    }

    return 1;
}


int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    if(prime(a) == 1){
        printf("%d is a prime number\n", a);
    }
    else{
        printf("%d is not a prime number\n", a);
    }

    return 0;
}
