#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int n, i;
        scanf("%d", &n);
        int arr[n];
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        printf("Set %d: ", l);
        for(i=0; i<n; i++){
            if(i%2==0) printf("%d", arr[i]);
            else printf(" ");

        }
        printf("\n");
    }
    return 0;
}
