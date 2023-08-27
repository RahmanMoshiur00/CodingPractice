#include<stdio.h>
#include<conio.h>
int main()
{
    int i, count = 0;
    char num[11];
    scanf("%s", num);
    for(i=0; i<11; i++){
        if(num[i] != '\0'){
            count = count + 1;
        }
    }
    if((int)num[count-1] % 2 == 0){
        printf("even\n");
    }
    else printf("odd\n");
}
