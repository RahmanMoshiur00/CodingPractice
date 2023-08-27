main()
{
    int t, x, y, z, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
            scanf("%d %d %d", &x, &y, &z);
        if(x>=y){
            if(x>=z) printf("Case %d: %d\n", i, x);
            else if(z>=x) printf("Case %d: %d\n", i, z);
        }
        else if(y>=x){
            if(y>=z) printf("Case %d: %d\n", i, y);
            else if(z>=y) printf("Case %d: %d\n", i, z);
        }
    }
}
