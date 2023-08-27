#include<stdio.h>

int result[20];
int parties[20];
int taken[20];

void compute(int index, int p, int sum, int limit) {
    int i;
  for(i = 0; i < p; i++) {
    if(taken[i]) {
      continue;
    }

    taken[i] = 1;

    if(sum + parties[i] > limit) {
      result[i]++;
    }
    else{
      if(i >= index) {
        compute(i, p, sum + parties[i], limit);
      }
    }
    taken[i] = 0;
  }
}

void solve(int p, int limit) {
    int i;
  for(i = 0; i < 20; i++) {
    result[i] = 0;
    taken[i] = 0;
  }

  compute(0, p, 0, limit);
}

int main()
{
  int cases, p, total;

  scanf("%d", &cases);

  while(cases){
    scanf("%d", &p);

    total = 0;
    int i;
    for(i = 0; i < p; i++) {
      scanf("%d", &parties[i]);
      total += parties[i];
    }

    solve(p, total/2);

    for(i = 0; i < p; i++) {
      printf("party %d has power index %d\n", i+1, result[i]);
    }

    printf("\n");
    cases--;
  }

  return 0;
}
