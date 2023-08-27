#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        long long w, h;
        scanf("%lld %lld", &w, &h);
        long long res = w*h;
        if(res%2==0) printf("Hasan\n");
        else if(res%2==1) printf("Hussain\n");
    }
}
