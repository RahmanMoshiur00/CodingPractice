#include<stdio.h>
int main()
{
    int marks[3][10];
    int i, n;
    for(i=0; i<3; i++){
        for(n=0; n<10; n++){
            printf("Enter the number of Exam:%d, Roll:%d\n", i+1, n+1);
            scanf("%d", &marks[i][n]);
        }
    }
    for(i=0; i<3; i++){
        for(n=0; n<10; n++){
            printf("Exam:%d, Roll:%d, Marks%d", i+1, n+1, marks[i][n]);
        }
    }

}
