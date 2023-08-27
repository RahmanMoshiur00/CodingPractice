
#include<stdio.h>
#include<math.h>

/*finding prime numbers from 1 to n*/

int main()
{
    int i, j, n, count, count1=0;
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        if(i==2 || i==3){
                count = 1;
        }
        else{
            for(j=2; j<=(int)sqrt(i); j++){
                if(i%j == 0){
                    count = 0;
                    break;
                }
                else count = 1;
            }
        }
        if(count == 1){
            count1++;
            printf("%d ", i);
        }
    }

    printf("\nNumber of prime number(1 to %d): %d", n, count1);
}
