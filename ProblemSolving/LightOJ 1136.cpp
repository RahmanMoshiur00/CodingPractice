#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int l=1; l<=t; l++){
        int a,b,ans=0;
        scanf("%d %d", &a, &b);
        ans= ( (((b-1)/3)*2) + ((b-1)%3) ) - ( (((a-2)/3)*2) + ((a-2)%3) );
		printf("Case %d: %d\n", l, (a==1)?ans-1:ans);
	}
	return 0;
}
