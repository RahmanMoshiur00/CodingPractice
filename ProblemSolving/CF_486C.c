#include <iostream>

using namespace std;

int p[5009];
int n;

int paint(int l, int r, int h) {
  if (l >= r) return 0;
  int m = l;
  int i;
  for(i = l; i < r; i++) if (p[m] > p[i]) m = i;
  return min(r-l, p[m]-h + paint(l, m, p[m]) + paint(m+1, r, p[m]));
}

int main() {
  scanf("%d", &n);
  int i;
  for(i = 0; i < n; i++) scanf("%d", &p[i]);
  printf("%d", paint(0, n+1, 0);

  return 0;
}
