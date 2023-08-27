#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int grade;
        scanf("%d", &grade);
        if((grade%5!=0) && (grade>=38 && grade<=100)){
            if(grade%5<3) grade = ((grade/5)+1) * 5;
        }
        printf("%d\n", grade);
    }
    return 0;
}
