#include<stdio.h>
#include<string.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[1001];
        gets(arr);
        if(l==0) gets(arr);
        int first = 0, last, i, j, k;
        for(i=0; i<strlen(arr); i++){
            if((arr[i]==' ') && (arr[i+1]!=' ' || arr[i+1]!='\0')) first = i+1;
            if((arr[i+1]==' ' || arr[i+1]=='\0') && ((arr[i]!=' ' || arr[i]!='\0'))){
                last = i;
                int count;
                count = (last - first + 1)/2;
                if(count!=0) for(j=first, k=last; ; j++, k--){
                    char a = arr[j];
                    arr[j] = arr[k];
                    arr[k] = a;
                    count--;
                    if(count==0) break;
                }
            }

        }
        printf("%s\n", arr);
    }
    return 0;
}
