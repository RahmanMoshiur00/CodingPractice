/*53*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[15];
    printf("Enter a numerical string:");
    scanf("%s", str);
    int l = strlen(str);
    int i, j, sum = 0, n[l];

    for(i=0; i<l; i++){
        n[i] = (int)str[i] - 48;
    }

    for(i=0, j=l; i<l; i++){
        double p = pow(10, j-1);
        sum += n[i] * ((int)p);
        j--;
    }

    printf("conversion of numeric string '%s' in integer is %d", str, sum);
}
