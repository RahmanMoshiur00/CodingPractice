#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    unsigned long ires, x, p;
    while(scanf("%lu %lu", &x, &p)==2){
        if(x==1) ires = p + 1;
        else{
            ires = (unsigned long)((pow(x, p+1)-1.0) / ((x-1)*1.0));
        }
        char str[2000000];
        sprintf(str, "%lu", ires);
        printf("%c\n", str[strlen(str) - 1]);
    }

    return 0;
}
