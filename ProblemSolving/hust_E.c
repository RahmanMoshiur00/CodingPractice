/*E*/

int main()
{
    int n, i, j, test, dust, count;

    scanf("%d", &test);

    for(i=1; i<=test; i++){
        printf("\n");
        count = 0;
        scanf("%d", &n);
        if(n>=1 && n<=1000){
            for(j=1; j<=n; j++){
                scanf("%d", &dust);
                if(dust>=0 && dust<100) count += dust;
            }
            printf("Case %d: %d\n", i, count);
        }
    }

    return 0;
}
