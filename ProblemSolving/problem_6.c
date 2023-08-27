#include<stdio.h>
main()
{
    int j, k;
    scanf("%d", &k);
    for(j=0; j<k; j++){
        int i, vs, vs1, num;
        scanf("%d", &num);
        vs1 = num % 10;
        num = num / 10;

        for(i=1; i<5; i++){
            vs = num % 10;
            num = num / 10;
        }
        vs1 = vs1 + vs;
        printf("Sum = %d\n", vs1);
    }
}
