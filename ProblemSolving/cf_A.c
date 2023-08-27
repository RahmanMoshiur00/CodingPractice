#include<stdio.h>
int main()
{
    int month, day;
    scanf("%d %d", &month, &day);

    int d, i, j;

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) d = 31;
    else if(month==2) d = 28;
    else d = 30;

    int count = 1, mark=0;

    for(i=1, j=day; i<=d; i++, j++){
        if(j==1 && mark==1){
            count++;
            mark = 0;
        }
        if(j%7==0){
            j=0;
            mark=1;
        }
    }
    printf("%d\n", count);
    return 0;
}
