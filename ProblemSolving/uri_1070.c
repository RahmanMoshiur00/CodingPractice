#include<stdio.h>
int main()
{
    int i, n;
     scanf("%d", &n);
     if(n%2==1){
         for(i=n; i<=(10+n); i+=2) printf("%d\n", i);
     }
     else{
         for(i=n+1; i<=(11+n); i+=2) printf("%d\n", i);
     }
}
