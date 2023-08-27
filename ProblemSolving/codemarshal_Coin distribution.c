main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        unsigned long n, count=0, j, l;
        int k;
        scanf("%lu %d", &n, &k);
        int prio[k];
        for(j=0; j<k; j++) scanf("%d", &prio[j]);
        int temp;
        for(j=1; j<=n; j++){
                temp = 0;
            for(l=0; l<k; l++){
                if(j%prio[l]==0){
                    temp = 1;
                    break;
                }
            }
            if(temp==0) count++;
        }
        printf("Case %d: %lu\n", i, count);
    }
}
