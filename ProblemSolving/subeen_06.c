#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char arr[10];
        sprintf(arr, "%d", n);
        printf("Sum = %d\n", (arr[0]-'0') + (arr[strlen(arr)-1] - '0'));
    }
    return 0;
}
