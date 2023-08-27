/*H*/
#include<stdlib.h>

main()
{
    int i, j, k, n, count, num1, br;
    float mid, line[50], count1;

    for(i=1; ;i++){
        count = 0; count1 = 0.0; num1 = 0, br = 0;
        scanf("%d", &n);
        if(n==0) break;
        else if(n>=1 && n<=50){
            for(j=0; j<n; j++){
                scanf("%f", &line[j]);
                if(line[j]>=1.0 && line[j]<=100.0){
                    count += line[j];
                    br++;
                }
            }
        }

        mid = (float)count / (float)br;

        for(k=0; k<n; k++){
            if(line[k]>mid && line[k]<=100.0){
                count1 += line[k];
                num1++;
            }
        }

        printf("Set #%d\nThe minimum number of moves is %.0f.\n", i, floor(count1-(mid*num1)));
    }

    return 0;
}
