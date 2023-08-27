#include<stdio.h>
int main()
{
    int i, n[100];
    for(i=0; i<100; i++) scanf("%d", &n[i]);
    int max = n[0], maxind=0;
    for(i=1; i<100; i++){
        if(max<n[i]){
            maxind = i+1;
            max = n[i];
        }
    }
    printf("%d\n%d\n", max, maxind);
}
