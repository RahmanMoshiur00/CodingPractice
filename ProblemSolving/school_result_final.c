#include<stdio.h>
int main()
{
    char sub_name[12][30] = {"Bangla 1st", "Bangla 2nd", "English 1st", "English 2nd", "General Math", "Physics", "Chemistry", "Biology/H.Math(main)", "Social Science", "Islam", "ICT", "4th Subject(H.Math/Bio/Agri)"};
    double marks[14];
    int i, j = 0, k;
    printf("Enter the number of students of the class:");
    scanf("%d", &k);
    printf("\n\n");
    while(j<k){
        double total_grade = 0.0, grade, gpa, total_marks = 0.0;
        printf("Enter the numbers of subjects of roll %d:\n", j+1);
        for(i=0; i<11; i++){
            printf("%s: ", sub_name[i]);
            scanf("%lf", &marks[i]);
        }
        marks[11] = (marks[0] + marks[1]) / 2;
        marks[12] = (marks[2] + marks[3]) / 2;
        printf("%s:  ", sub_name[11]);
        scanf("%lf", &marks[13]);
        for(i=4; i<13; i++){
            if(marks[i]>=80.0 && marks[i]<=100.0){
                    grade = 5.0;
            }
            else if(marks[i]>=70.0 && marks[i]<=79.99){
                    grade = 4.0;
            }
            else if(marks[i]>=60.0 && marks[i]<=69.99){
                    grade = 3.5;
            }
            else if(marks[i]>=50.0 && marks[i]<=59.99){
                    grade = 3.0;
            }
            else if(marks[i]>=40.0 && marks[i]<=49.99){
                    grade = 2.0;
            }
            else if(marks[i]>=33.0 && marks[i]<=39.99){
                    grade = 1.0;
            }
            else if(marks[i]<33.0){
                printf("THE STUDENT IS FAILED!\n");
                goto read;
            }
            total_grade = total_grade + grade;
        }
        while(1){
            if(marks[13]>=80.0 && marks[13]<=100.0){
                    grade = 3.0;
                    break;
            }
            else if(marks[13]>=70.0 && marks[13]<=79.99){
                    grade = 2.0;
                    break;
            }
            else if(marks[13]>=60.0 && marks[13]<=69.99){
                    grade = 1.5;
                    break;
            }
            else if(marks[13]>=50.0 && marks[13]<=59.99){
                    grade = 1.0;
                    break;
            }
            else if(marks[13]<50.0){
                grade = 0.0;
                break;
            }
        }
        total_grade = total_grade + grade;
        gpa = total_grade / 9;
        for(i=0; i<11; i++){
            total_marks = total_marks + marks[i];
        }
        total_marks = total_marks + marks[13];
        printf("ROLL=%d\tGPA=%.2lf\tTOTAL MARKS=%.2lf\n", j+1, gpa, total_marks);
        printf("\n");
        read:
        j++;
        }
    return 0;
}
