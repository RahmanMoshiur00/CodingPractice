/*47*/
#include<stdio.h>
int main()
{
    int n, i, li=0, hi=5, mid, find = 0, a[5] = {6,8,11,15,23};
    printf("Enter a number to search in the given array:");
    scanf("%d", &n);

    for(i=0; i<5;i++){
        mid = (li + hi) / 2;
        if(a[mid]==n){find=1; break;}
        else if(a[mid]>n) hi = mid;
        else if(a[mid]<n) li = mid;
    }

    if(find==1) printf("%d is found", n);
    else printf("%d is not found", n);
}
/*if you want to search a number between given range, the code is given bellow(not essential)*/
/*
int main()
{
    int n, i, hr, lr, mid, find = 0;

    printf("Enter lower range:");
    scanf("%d", &lr);
    printf("Enter higher range:");
    scanf("%d", &hr);
    printf("Enter a number to search in the range:");
    scanf("%d", &n);

    mid = (hr+lr) / 2;
    int temp = mid;

    for(i=0; i<=temp;i++){
        if(n==lr){find = 1; break;}
        else if(n==hr){find = 1; break;}
        else if(n==mid){find = 1; break;}
        else if(n>mid){
            lr = mid;
            mid = (lr + hr)/2;}
        else if(n<mid){
            hr = mid;
            mid = (lr + hr)/2;}
    }

    if(find==1) printf("%d is found in the range", n);
    else printf("%d is not found in the range", n);

}
*/
