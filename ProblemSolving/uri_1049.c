#include<stdio.h>
#include<string.h>
int main()
{
    char arr1[15], arr2[15], arr3[15];
    gets(arr1);
    gets(arr2);
    gets(arr3);

    if(strcmp(arr1, "vertebrado")==0){
        if(strcmp(arr2, "ave")==0){
            if(strcmp(arr3, "carnivoro")==0) printf("aguia\n");
            else if(strcmp(arr3, "onivoro")==0) printf("pomba\n");

        }
        else if(strcmp(arr2, "mamifero")==0){
            if(strcmp(arr3, "onivoro")==0) printf("homem\n");
            else if(strcmp(arr3, "herbivoro")==0) printf("vaca\n");
        }
    }
    else if(strcmp(arr1, "invertebrado")==0){
        if(strcmp(arr2, "inseto")==0){
            if(strcmp(arr3, "hematofago")==0) printf("pulga\n");
            else if(strcmp(arr3, "herbivoro")==0) printf("lagarta\n");
        }
        else if(strcmp(arr2, "anelideo")==0){
            if(strcmp(arr3, "hematofago")==0) printf("sanguessuga\n");
            else if(strcmp(arr3, "onivoro")==0) printf("minhoca\n");
        }
    }
}
