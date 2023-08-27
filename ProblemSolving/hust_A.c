/*A*/

int main()
{
    int i, test;
    long int a, b;
    scanf("%d", &test);

    for(i=1; i<=test; i++){
        scanf("%ld", &a);
        scanf("%ld", &b);
        if(a>b) printf(">\n");
        else if(a<b) printf("<\n");
        else if(a==b) printf("=\n");
    }

    return 0;
}
