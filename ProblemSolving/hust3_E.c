#include <stdio.h>

int main()
{
  int i, n, x, total = 0;

  scanf("%d %d", &n, &x);

  for(i = 1; i <= n; i++)
  {
    if(x % i == 0 && x / i <= n) total += 1;
  }

  printf("%d\n", total);
  return 0;
}
