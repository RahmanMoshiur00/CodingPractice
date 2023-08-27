#include<stdio.h>
int fun()
{
    static int count = 0;
    count = 0;
    count = count + 1;
    return count;
}

int main()
{
    int *a = {1, 2, 3};

    int i;
    for(i=0; i<3; i++){
        printf("%d ", &a);
    }

    return 0;
}


/*
10 12 15 20



*/
