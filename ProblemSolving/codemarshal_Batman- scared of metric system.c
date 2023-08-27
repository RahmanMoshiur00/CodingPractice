main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        double km;
        scanf("%lf",&km);
        printf("%.10lf\n", km*0.621371);
    }
}
