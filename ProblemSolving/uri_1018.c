#include<stdio.h>

int main()
{
    unsigned long tk;
    scanf("%lu", &tk);
    printf("%d nota(s) de R$ 100,00\n", tk/100);
    tk = tk % 100;
    printf("%d nota(s) de R$ 50,00\n", tk/50);
    tk = tk % 50;
    printf("%d nota(s) de R$ 20,00\n", tk/20);
    tk = tk % 20;
    printf("%d nota(s) de R$ 10,00\n", tk/10);
    tk = tk % 10;
    printf("%d nota(s) de R$ 5,00\n", tk/5);
    tk = tk % 5;
    printf("%d nota(s) de R$ 2,00\n", tk/2);
    tk = tk % 2;
    printf("%d nota(s) de R$ 1,00\n", tk/1);

}
