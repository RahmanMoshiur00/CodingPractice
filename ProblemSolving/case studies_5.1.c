#include<stdio.h>

int main()
{
    int i, count=0;
    float num[100], sum=0.0, high, low;

    printf("Enter numbers; input NEGATIVE number to end:\n");
    for(i=0; i<100; i++){
        scanf("%f", &num[i]);
        if(num[i] < 0) break;
        else{
            sum += num[i];
            count++;
            if(i==0) high = low = num[i];
            else{
                if(num[i]>high) high = num[i];
                else if(num[i] < low) low = num[i];
            }
        }
    }

    printf("Total values  : %d\n", count);
    printf("Highest-value : %f\n", high);
    printf("Lowest-value  : %f\n", low);
    printf("Range         : %f\n", high - low);
    printf("Average       : %f\n", sum / count);
}

