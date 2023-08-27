#include<stdio.h>
int main()
{
    int s, i, j, l, m, k;
    double sm[14], fm[10], gpa[10];
    double tb = 0.0, te = 0.0, grade, sum_gpa = 0.0, total_gpa;
    char sbjct[12][30] = {"Bangla-1st", "Bangla-2nd", "English-1st", "English-2nd", "Math", "Physics", "Chemistry", "Social Science", "Islam", "H.Math/Bio(m)", "ICT", "4th(H.M/Bio/Agri)"};

    printf("Enter the number of students:\n");
    scanf("%d", &s);

    for(i=0; i<s; i++){
        printf("ROLL:%d\n", i+1);
        for(j=0; j<12; j++){
            printf("Enter the number of %s:\n", sbjct[j]);
            scanf("%lf", &sm[j]);
            sm[12] = (sm[0] + sm[1]) / 2;
            sm[13] = (sm[2] + sm[3]) / 2;
            for(l=4,m=0; l<14; l++, m++){
                fm[m] = sm[l];
                printf("%s", fm[m]);
    }
}
}
}
