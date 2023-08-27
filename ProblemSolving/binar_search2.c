#include<stdio.h>

/*int main()
{
   int n, i, count = 0;
   scanf("%d", &n);
   int num[n], num2[100];
   for(i=0; i<n; i++){
        scanf("%d", &num[i]);
        if(num[i] % 2 == 0){
            count = count + 1;
            num2[count - 1] = num[i];
        }

   }
    num2[count + 1] = '\0';
   for(i=0; i<count; i++){
    printf("%d\n", &num2[i]);
   }
}*/

/*int main()
{
    int n[100] = {0, 1, 2, 3, 4, 5}, i;

    for(i=0; i<100; i++){
            printf("%d\n", n[i]);
    }
}*/
int main()
{
    char ch[9] = {"012345679"};
    if(ch[8]%2 == 0){
        printf("The array is even");
    }
    else{
        printf("The array is odd");
    }
}
