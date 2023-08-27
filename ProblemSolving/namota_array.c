#include<stdio.h>
int main()
{
    int n, i, m, sum = 0, count1 = 0, count2 = 0;
    printf("Enter the number of namota:");
    scanf("%d", &m);
    int namo[m][10];
    for(n=0; n<m; n++){
        for(i=0; i<10; i++){
            printf("%d x %d = %d\n", n+1, i+1, (n+1)*(i+1));
            sum = sum + (n+1)*(i+1);
            if((n+1)*(i+1) % 2 == 0){
                count1++;
            }
            else if((n+1)*(i+1) % 2 == 1){
                count2++;
            }
        }
    }
    printf("SUM is = %d\n", sum);
    printf("Number of even numbers is %d\n", count1);
    printf("Numbers of odd numbers is %d\n", count2);
}
