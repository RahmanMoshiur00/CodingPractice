#include<stdio.h>
#include<string.h>
main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        long long c, k, i, count=0, temp=0;
        scanf("%lld %lld", &c, &k);
        long long frnd = k+1;
        char seat[c+1];
        scanf("%s", seat);
        for(i=0; i<c; i++){
            if(seat[i]=='0'){
                temp++;
                if(temp>=count) count = temp;
            }
            else if(seat[i]=='1'){
                temp = 0;
            }
        }
        if(frnd<=count) printf("yes\n");
        else printf("no\n");
    }
}
