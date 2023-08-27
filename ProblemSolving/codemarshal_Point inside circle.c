main()
{
    long long int i, t, x, y, r, cx, cy, ans;
    scanf("%lld", &t);

    for(i=1; i<=t; i++){
        scanf("%lld %lld %lld %lld %lld", &cx, &cy, &r, &x, &y);
        ans = (x-cx)*(x-cx) + (y-cy)*(y-cy) - (r*r);
        if(ans<0) printf("Case %lld: yes\n", i);
        else printf("Case %lld: no\n", i);
    }
    return 0;
}
