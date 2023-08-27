#include<stdio.h>
int main()
{
	int t, l; scanf("%d", &t);
	for(l=1; l<=t; l++){
		unsigned long long x; scanf("%llu", &x);
		if(x%180==0){
			unsigned long long n = (x/180) + 2;
			unsigned long long angle = x / n;
			printf("Case %d: %llu %llu\n", l, n, angle);
		}
		else printf("Case %d: Impossible\n", l);
	}
}
