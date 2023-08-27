main()
{
    int num[3], i, j;
    for(i=0; i<3; i++) scanf("%d", &num[i]);
    for(i=0; i<=1; i++){
        for(j=i+1; j<3; j++){
            if(num[i]>=num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(i=2; i>=0; i--){
        printf("%d", num[i]);
        if(i != 0) printf(" ");
    }
    printf("\n");
}
