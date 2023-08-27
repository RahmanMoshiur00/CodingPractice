/*D*/

int main()
{
    int test, i;
    unsigned int n, k, p;

    scanf("%d", &test);

    for(i=1; i<=test; i++){

        scanf("%u %u %u", &n, &k, &p);

        if((n>=2 && n<=23) && (k>=1 && k<=n) && (p>=1 && p<=200)){

            int x = k + p - n;
            if(x == 0) printf("Case %d: %u\n", i, n);
            else if(x < 0) printf("Case %d: %u\n", i, k + p);
            else if(x > 0) printf("Case %d: %d\n", i, x);

        }
    }

    return 0;
}
