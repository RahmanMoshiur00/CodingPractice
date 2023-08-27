#include<math.h>

main()
{
    int t, j;
    scanf("%d", &t);
    for(j=1; j<=t; j++){
        int std, lft;
        scanf("%d %d", &std, &lft);
        printf("Case %d: %d\n", j, (std + abs(std-lft))*4 + (19));
    }
}
