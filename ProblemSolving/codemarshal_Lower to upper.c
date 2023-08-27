#include<stdio.h>
#include<string.h>
int main()
{
    char name[101];
    int t, i, j;

    scanf("%d", &t);

    for(i=0; i<t; i++){
            if(i==0) gets(name);
        gets(name);
        for(j=0; j<strlen(name); j++){
            if(name[j]>='a' && name[j]<='z') name[j] = name[j] - 32;
        }
        printf("Case %d: %s\n", i+1, name);
    }
}
