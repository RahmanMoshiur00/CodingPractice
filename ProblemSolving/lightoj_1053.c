#include<math.h>
main()
{
    int t, j;
    scanf("%d", &t);
    for(j=1; j<=t; j++){
        int bahu[3], i, k;
        scanf("%d %d %d", &bahu[0], &bahu[1], &bahu[2]);
        for(i=0; i<2; i++){
            for(k=i+1; k<3; k++){
                if(bahu[i]>bahu[k]){
                    int a =  bahu[i];
                    bahu[i] = bahu[k];
                    bahu[k] = a;
                }
            }
        }

        if(bahu[2] == (int)sqrt((double)((bahu[0]*bahu[0]) + (bahu[1]*bahu[1])))) printf("Case %d: yes\n", j);
        else printf("Case %d: no\n", j);
    }
}
