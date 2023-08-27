#include<stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        int n, j, count=1, l, max=0;
        scanf("%d", &n);
        int tmp[n];
        for(j=0; j<n; j++) scanf("%d", &tmp[j]);
        for(j=0; j<n-1; j++){
            if(tmp[j]<=tmp[j+1]){
                count++;
            }
            else if(count>1 && max<count){
                    max = count;
                    count = 1;
                }
        }
        if(max==0) max = count;
        printf("%d\n", max);
        printf("");
    }
    return 0;
}
