#include <stdio.h>

int noz(int x)
{
    if(x<10){
        if(x==0) return 1;
        else return 0;
    }

    int d = x % 10;
    if(d == 0){
        return 1 + noz(x/10);
    }
    else{
        return noz(x/10);
    }
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);



    return 0;
}



