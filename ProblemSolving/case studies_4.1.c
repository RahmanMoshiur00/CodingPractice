#include<stdio.h>

int main()
{
    int n, i;
    printf("Enter number of total products:\n");
    scanf("%d", &n);

    char code[n][10];
    int quantity[n];
    double rate[n], value[n], total = 0.0;

    for(i=0; i<n; i++){
        printf("Enter code, quantity, and rate:");
        scanf("%s %d %lf", code[i], &quantity[i], &rate[i]);
        value[i] = quantity[i] * rate[i];
        total += value[i];
    }
    printf("Code Quantity Rate value\n");
    for(i=0; i<n; i++){
        printf("%s\t%d\t%lf\t%e\n", code[i], quantity[i], rate[i], value[i]);
    }
    printf("\t\tTotal value = %e\n", total);
}
