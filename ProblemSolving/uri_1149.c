main()
{
    int a, n, i, sum=0;
     scanf("%d %d", &a, &n);
     read:
     if(n<=0) scanf("%d", &n);
     if(n<=0) goto read;
     for(i=a; i<a+n; i++){
         sum += i;
     }
     printf("%d\n", sum);
}
