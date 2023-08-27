/*B*/

int main()
{
    int test, i;
    unsigned int x, y, z;

    scanf("%d", &test);

    for(i=1; i<=test; i++){
        scanf("%u %u %u", &x, &y, &z);
        if((x>=y && x<=z) || (x>=z && x<=y)) printf("Case %d: %u\n", i, x);
        else if((y>=x && y<=z) || (y>=z && y<=x)) printf("Case %d: %u\n", i, y);
        else printf("Case %d: %u\n", i, z);
    }

    return 0;
}
