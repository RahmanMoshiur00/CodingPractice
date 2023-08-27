main()
{
    unsigned int t, n, i;
    scanf("%u", &t);
    for(i=1; i<=t; i++){

        scanf("%u", &n);

        unsigned int mark[n], m, j;
        int number[101] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
        unsigned int count[101] = {0};

        for(m=0; m<n; m++){
            scanf("%u", &mark[m]);
            for(j=0; j<101; j++){
                if(mark[m]==number[j]){
                    count[j] += 1;
                    break;
                }
            }
        }

        unsigned int count_max = count[0];

        for(j=1; j<101; j++){
            if(count[j]>count_max){
                count_max = count[j];
            }
        }

        int max;

        for(m=0; m<101; m++){
            if(count_max==count[m]) max = m;
        }

        printf("Case %u: %d %u\n", i, max, count_max);
    }
}
