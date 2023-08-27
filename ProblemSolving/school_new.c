#include<stdio.h>
int main()
{
    double sub[9], gpa[9];
    double s4;
    char ject[9][20] = {"Bangla", "English", "Math", "Physics", "Chemistry", "H.M/Bio(m)", "Islam", "Social Science", "ICT"};
    int n, i, m, k;
    double grade, g4, total_gpa;
    restart:
    printf("Enter the number of students:\n");
    scanf("%d", &m);
    for(i=0; i<m; i++){
            printf("Roll:%d\n", i+1);
    for(n=0; n<9; n++){
        printf("Enter number of %s : \n", ject[n]);
        scanf("%d", &sub[n]);
        if(sub[n]>79.0){
             grade = 5.0;
        }
        else if(sub[n]>69){
            grade = 4.0;
        }
        else if(sub[n]>59.0){
            grade = 3.5;
        }
        else if(sub[n]>49.0){
            grade = 3.0;
        }
        else if(sub[n]>39.0){
            grade = 2.0;
        }
        else if(sub[n]>32.0){
            grade = 1.0;
        }
        else if(sub[n]<33.0){
            grade = 0.0;
        }
        gpa[n] = grade;
    }
        if(gpa[0]!=0.0 && gpa[1]!=0.0 && gpa[2]!=0.0 && gpa[3]!=0.0  && gpa[4]!=0.0 && gpa[5]!=0.0 && gpa[6]!=0.0 && gpa[7]!=0.0 && gpa[8]!=0.0){
            printf("Enter the number of 4th subject:\n");
            scanf("%lf", &s4);
             if(s4>79.0){
             g4 = 3.0;
        }
        else if(s4>69){
            g4 = 2.0;
        }
        else if(s4>59.0){
            g4 = 1.5;
        }
        else if(s4>49.0){
            g4 = 1.0;
        }
        else{
            g4 = 0.0;
        }
            total_gpa = ( gpa[0] + gpa[1] + gpa[2] + gpa[3] + gpa[4] + gpa[5] + gpa[6] + gpa[7] + gpa[8] - g4 ) / 9.0;
        printf("Roll:%d\tGPA=%.2lf\n", i+1, total_gpa);
        }
        else{
            printf("GPA='FAIL'!\n");
        }
    printf("\n\n");
    }

    return 0;
}
