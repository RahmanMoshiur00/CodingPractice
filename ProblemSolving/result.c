#include<stdio.h>
#include<string.h>
int main()
{
    char sub_name[5][30] = {"CIT", "AIE", "SSL", "Math", "Physics"}, grade1[5][5];
    double marks[5], grade[5];
    double total_grade = 0.0, gpa;
    int i, id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    printf("Enter the numbers of subjects of ID %d:\n", id);
    for(i=0; i<5; i++){
        printf("%s: ", sub_name[i]);
        scanf("%lf", &marks[i]);
    }
    /*as i don't know enough of credit result system,i'm using logic of school result system*/
    for(i=0; i<5; i++){
        if(marks[i]>=80.0 && marks[i]<=100.0){
                grade[i] = 5.0;
                strcpy(grade1[i], "A+");
        }
        else if(marks[i]>=70.0 && marks[i]<80.0){
                grade[i] = 4.0;
                strcpy(grade1[i], "A");
        }
        else if(marks[i]>=60.0 && marks[i]<70.0){
                grade[i] = 3.5;
                strcpy(grade1[i], "A-");
        }
        else if(marks[i]>=50.0 && marks[i]<60.0){
                grade[i] = 3.0;
                strcpy(grade1[i], "B");
        }
        else if(marks[i]>=40.0 && marks[i]<50.0){
                grade[i] = 2.0;
                strcpy(grade1[i], "C");
        }
        else if(marks[i]>=33.0 && marks[i]<40.0){
                grade[i] = 1.0;
                strcpy(grade1[i], "D");
        }
        else if(marks[i]<33.0){
            printf("THE STUDENT(ID=%d) IS FAILED!\n", id);
            goto read;
        }
        total_grade = total_grade + grade[i];
    }
    gpa = total_grade / 5;
    printf("ID=%d\tTOTAL_GPA=%.2lf\t", id, gpa); //printing total gpa against id
    if(gpa==5.0) printf("GRADE= 'A+'\n");
    else if(gpa>=4.0 && gpa<5.0) printf("GRADE= 'A'\n");
    else if(gpa>=3.5 && gpa<4.0) printf("GRADE= 'A-'\n");
    else if(gpa>=3.0 && gpa<3.5) printf("GRADE= 'B'\n");
    else if(gpa>=2.0 && gpa<3.0) printf("GRADE= 'C'\n");
    else if(gpa>=1.0 && gpa<2.0) printf("GRADE= 'D'\n");
    printf("\n");
    read:
    /*printing marks and grades of particular subjects*/
    for(i=0; i<5; i++){
        printf("ID:%d; number of '%s' is %.2lf\t and grade '%s'\n", id, sub_name[i], marks[i], grade1[i]);
    }

    return 0;
}
