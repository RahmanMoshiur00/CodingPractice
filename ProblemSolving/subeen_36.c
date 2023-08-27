#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d", &n);
    scanf(" ");
    char arr[n][500];
    int mark[n], i, j;
    for(i=0; i<n; i++) gets(arr[i]);
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(strcmp(arr[i], arr[j])>0){
                char ch[500];
                strcpy(ch, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], ch);
            }
        }
    }
    for(i=0; i<n; i++) printf("%s\n", arr[i]);
    return 0;
}
