
#include<stdio.h>
main()
{
    int i, j, k, emp[5];
    for(i=0; i<5; i++){
        printf("Enter employees in Group - %d :", i+1);
        scanf("%d", &emp[i]);
        printf("%d\n", emp[i]);
    }
    printf("\t|\n");
    for(i=0; i<5; i++){
        for(j=1; j<=3; j++){
            if(j==2){
                printf("Group-%d |", i+1);
                for(k=1; k<=emp[i]; k++) printf("*");
                printf("(%d)", emp[i]);
            }
            else{
                printf("\t|");
                for(k=1; k<=emp[i]; k++) printf("*");
            }
            printf("\n");
        }
        printf("\t|\n");
    }
}
