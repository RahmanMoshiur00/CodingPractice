main()
{
    int age, sum=0, count=0;
    while(scanf("%d", &age)==1){
        if(age<0) break;
        else{
            sum += age;
            count++;
        }
    }
    printf("%.2lf\n", (double)sum / (double)count);
}
