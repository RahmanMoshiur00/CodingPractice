#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("Lumberjacks:\n");

    while(n--){
        int arr[10], increase_checker=1, decrease_checker=1, i;
        for(i=0; i<10; i++) scanf("%d", &arr[i]);
        int temp = arr[0];
        for(i=1; i<10; i++){
            if(temp>arr[i]) decrease_checker++;
            else increase_checker++;
            temp = arr[i];
        }
        if(increase_checker==10 || decrease_checker==10) printf("Ordered\n");
        else printf("Unordered\n");
    }

    return 0;
}
