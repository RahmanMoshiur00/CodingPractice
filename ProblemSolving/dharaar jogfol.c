#include <stdio.h>

int main()
{
  int m, sum, start, diff, end;

  printf("Enter start number-\n");
  scanf("%d", &start);

  printf("Enter different-\n");
  scanf("%d", &diff);

  printf("Enter the end number-\n");
  scanf("%d", &end);

  for(m = start, sum = 0; m <= end; m = m +diff){
    sum = sum + m;
  }
    printf("%d\n", sum);
    return 0;
}
