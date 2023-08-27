#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    double money;
    scanf("%lf", &money);
    printf("NOTAS:\n");
    int tk = (int) money;
    printf("%d nota(s) de R$ 100.00\n", tk/100);
    tk = tk % 100;
    printf("%d nota(s) de R$ 50.00\n", tk/50);
    tk %= 50;
    printf("%d nota(s) de R$ 20.00\n", tk/20);
    tk %= 20;
    printf("%d nota(s) de R$ 10.00\n", tk/10);
    tk %= 10;
    printf("%d nota(s) de R$ 5.00\n", tk/5);
    tk %= 5;
    printf("%d nota(s) de R$ 2.00\n", tk/2);
    tk %= 2;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", tk);
    int i;
    char arr[15], deci[3];
    sprintf(arr, "%lf", money);
    for(i=0; i<strlen(arr); i++){
        if(arr[i]=='.'){
            deci[0] = arr[i+1];
            deci[1] = arr[i+2];
            deci[2] = '\0';
            break;
        }
    }
    int decimal = atoi(deci);
    printf("%d moeda(s) de R$ 0.50\n", decimal/50);
    decimal %= 50;
    printf("%d moeda(s) de R$ 0.25\n", decimal/25);
    decimal %= 25;
    printf("%d moeda(s) de R$ 0.10\n", decimal/10);
    decimal %= 10;
    printf("%d moeda(s) de R$ 0.05\n", decimal/5);
    decimal %= 5;
    printf("%d moeda(s) de R$ 0.01\n", decimal/1);
    return 0;
}
