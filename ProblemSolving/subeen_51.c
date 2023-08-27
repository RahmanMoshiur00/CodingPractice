#include<stdio.h>
#include<string.h>
#include<math.h>

int  main()
{
    int t;
    scanf("%d ", &t);
    while(t--){
        char arr[130], sub[130];
        scanf("%s %s", arr, sub);
        int i, j, count=0;
        for(i=0; i<strlen(arr); i++){
            if(sub[0]==arr[i]){
                int k = i+1;
                for(j=1; j<strlen(sub); j++){
                    if(sub[j]!=arr[k++]){
                        goto outer;
                    }
                }
                count++;
            }
            outer:
                printf("");
        }
        printf("%d\n", count);
    }
    return 0;
}
