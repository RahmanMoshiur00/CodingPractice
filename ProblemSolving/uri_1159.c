main()
{
    int n;
    while(scanf("%d", &n)==1){
            if(n==0) break;
        int i, count=0, sum=0;
        for(i=n; ;i++){
            if(i%2==0){
                sum += i;
                count++;
            }
            if(count==5) break;
        }
        printf("%d\n", sum);
    }
}
