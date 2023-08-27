#include<stdio.h>
#include<string.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char num[1000000];
        if(l==0) gets(num);
        gets(num);
        int count = 0, i;
        for(i=0; i<strlen(num); i++){
            if(num[i]>='0' && num[i]<='9' && (num[i+1]==' ' || num[i+1]=='\0')) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
