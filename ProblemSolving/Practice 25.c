/*33*/
#include<stdio.h>
int main()
{
    int s, i, j, space = 5;
    for(s=1; s<=5; s++){

        for(i=1; i<=s; i++){
            printf("*");
        }

        for(j = space; j>1; j--){
            printf(" ");
        }

        for(i=1; i<=s; i++){
            printf("*");
        }

        printf("\n");
        space--;
    }
}
