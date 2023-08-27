#include<stdio.h>

int find_min(int array[], int n)
{
    int min, i;
    min = array[0];

    for(i=0; i<n; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}

int main()
{
    int c, n, i;
    printf("Enter the number of elements of the array;\n");
    scanf("%d", &n);
    int ara[n];

    for(i=0; i<n; i++)
        scanf("%d", &ara[i]);

    c = find_min(ara, n);
    printf("min element is %d", c);
}
