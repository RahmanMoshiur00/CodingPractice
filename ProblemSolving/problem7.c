#include<stdio.h>
#include<stdlib.h>
main()
{
    char ara[] = "1 -2 10000 -50 20 7 445";
    char* ptr;
    char* a = ara;
    long input;
    int i, count = 0;
    while(1){
        input = strtol(a, &ptr, 10);
        printf("input = %ld\n", input);
        printf("ptr = %s\n", ptr);
        if(a == ptr) break;
        count++;
        a = ptr;
    }
    printf("count=%d\n", count);
}
