#include<stdio.h>
int main()
{
    int i, count=0, max=0, j;
    int arr[10];
    for(i=0; i<10; i++) scanf("%d", &arr[i]);
    for(i=0; i<10; i++){
        if(arr[i]==1){
            count=1;
            for(j=i+1; ; j++){
                if(arr[j]!=1){
                    i=j;
                    if(max<count) max = count;
                    break;
                }
                else count++;
            }
        }
    }
    printf("%d\n", max);
}
