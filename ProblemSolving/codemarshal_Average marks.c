main()
{
    int t, std, i, j, n, avg=0;
    scanf("%d", &t);

    for(i=1; i<=t; i++){
        scanf("%d", &n);
        avg=0;
        for(j=1; j<=n; j++){
            scanf("%d", &std);
            avg += std;
        }
        printf("Case %d: %d\n", i, avg/n);
    }
}
