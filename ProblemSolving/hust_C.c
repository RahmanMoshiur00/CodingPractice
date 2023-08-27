/*C*/

int main()
{
    int i, k, j, m, count, found;
    unsigned int num, a[20];

    for(k=1; ;k++){
        scanf("%u", &num);
        if(num==0) break;
        else if(num<=1000){
            found = 0; m=0;
            for(j=1; j<=num; j++){

                count = 0;

                for(i=1; i<=j; i++){
                    if(j%i==0) count+=i;
                }

                if(count == num){
                    a[m] = j;
                    m++;
                    found = 1;
                }

            }

            if(found == 0) printf("Case %d: -1\n", k);
            else{
                int max = a[0], o;
                for(o=0; o<m; o++){
                    if(a[o] > max) max = a[o];
                }
                printf("Case %d: %d\n", k, max);
            }
        }

    }

    return 0;

}
