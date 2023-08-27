#include<stdio.h>
#include<string.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[10000];
        if(l==0) gets(arr);
        gets(arr);
        char ch[2];
        gets(ch);
        int count = 0, i;
        for(i=0; i<strlen(arr); i++){
            if(arr[i] == ch[0]) count++;
        }
        if(count>0) printf("Occurrence of '%c' in '%s' = %d\n", ch[0], arr, count);
        else printf("'%c' is not present\n", ch[0]);
    }

    return 0;
}
