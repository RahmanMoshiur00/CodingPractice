#include<stdio.h>
int main()
{
    int n, i, line=0, count=0;
    scanf("%d", &n);
    for(i=1; ; i++){
        printf("%d ", i);
        count++;
        if(count==3){
            count=0;
            printf("PUM\n");
            i++;
            line++;
        }
        if(line==n) break;
    }
}
