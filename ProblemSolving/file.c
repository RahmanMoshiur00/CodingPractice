#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int num;
   FILE *fptr;
   fptr = fopen("/home/moshiur/Downloads/toy.ppm","r+");

   if (fptr == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    char str[10000];
    int count = 0, color_count = 0;
   while(fscanf(fptr,"%s", str) != EOF){
        count++;
        if(count>4 && count%3==1){
            num = atoi(str);
            if(num)
        }
        printf("Value of n count = %s %d\n", str, count);
   }

   fclose(fptr);

   return 0;
}
