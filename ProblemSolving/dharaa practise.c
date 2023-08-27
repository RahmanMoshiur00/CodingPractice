#include <stdio.h>

int main()
{
    int start, sum = 0, diff, end;

    printf("enter start,then different amd then end-\n");
    scanf("%d%d%d", &start, &diff, &end);

    for(start;start <= end;start = start + diff){
        printf("%d\n", start);
        sum = sum + start;
    }

        printf("sum is %d\n", sum);
    return 0;
}
