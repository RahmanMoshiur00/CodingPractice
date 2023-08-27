#include<stdio.h>

int main()
{
    int ver, lay;
    scanf("%d %d", &ver, &lay);
    if(ver<lay) printf("-1\n");
    else if(ver>lay) printf("%d\n", ver);
    else printf("%d\n", ver-1);
    return 0;
}
