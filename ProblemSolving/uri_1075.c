main()
{
    int i, n;
    scanf("%d", &n);
    for(i=0; ; i++){
        if(((n*i)+2)<=10000) printf("%d\n", (n*i)+2);
        else break;
    }
}
