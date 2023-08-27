#include<stdio.h>
#include<string.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        int n, j, k;
        scanf("%d", &n);
        char word[n][101];
        int count=n;
        for(j=0; j<n; j++) scanf("%s", word[j]);
        for(j=0; j<n; j++){
            for(k=j+1; k<n; k++){
                if(strcmp(word[j], word[k])==0 && word[j][0]!='\0'){
                    word[k][0] = '\0';
                    count--;
                }
            }
        }
        printf("%d\n", count);
    }
}
