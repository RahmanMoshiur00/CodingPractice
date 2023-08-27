main()
{
    int t, i, n, j, k;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d", &n);
        printf("Case %d:\n", i);
        for(j=1; j<=n; j++){
            for(k=1; k<=j; k++) printf("%d", k);
            printf("\n");
        }
    }
}
