/*17*/
#include<stdio.h>

int primeFactors(int num, int arr[])
{
    int i, j=0;
    for(i=2; i<=num; i++){
        if(num%i==0){
            arr[j] = i;
            j++;
            num /= i;
            i = 1;
        }
    }
    return j;
}


int findGCD(int arr1[], int len1, int arr2[], int len2, int arr3[])
{
    int i, j, k;

    for(i=0, k=0; i<len1;i++){
        for(j=0; j<len2; j++){
            if(arr1[i] == arr2[j]){
                arr3[k] = arr1[i];
                arr2[j] = 0;
                k++;
                break;
            }
        }
    }
    return k;
}


main()
{
    int num1, num2, arr1[50], arr2[50], arr3[50], gcd, lcm, sum = 1, i;

    printf("Enter two numbers to find GCD and LCM:");
    scanf("%d%d", &num1, &num2);

    if(num1==0 || num2==0) gcd = 0;
    else{
        int len1 = primeFactors(num1, arr1);
        int len2 = primeFactors(num2, arr2);

        int len3 = findGCD(arr1, len1, arr2, len2, arr3);

        for(i=0; i<len3; i++) sum *= arr3[i];

        gcd = sum;
    }

    if(num1 == 0) lcm = num2;
    else if(num2 == 0) lcm = num1;
    else lcm = (num1 * num2) / gcd;

    printf("GCD(%d,%d) = %d\n", num1, num2, gcd);
    printf("LCM(%d,%d) = %d\n", num1, num2, lcm);

    return 0;
}

