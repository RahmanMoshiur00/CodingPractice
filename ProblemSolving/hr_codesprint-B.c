#include<stdio.h>
#include<string.h>
int main()
{
    char arr[100009];
    int que, n, i, l;
    int mark[27] = {0};
    gets(arr);
    for(i=0; i<strlen(arr); i++){
        mark[arr[i] - 'a' + 1]++;
    }
    scanf("%d", &n);
    for(l=0; l<n; l++){
        scanf("%d", &que);
        for(i=1; i<=26; i++){
            if(que%i==0){
                if((que/i) <= mark[i]){
                    printf("Yes\n");
                    goto outer;
                }
            }
        }
        printf("No\n");
        outer:
            printf("");
    }
    return 0;
}
