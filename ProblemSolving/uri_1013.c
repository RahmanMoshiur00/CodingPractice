#include <stdio.h>

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int n[3], i;
     for(i=0; i<3; i++) scanf("%d", &n[i]);
     int max = n[0];
     for(i=1; i<3; i++){
         if(n[i]>max) max = n[i];
     }
     printf("%d eh o maior\n", max);

    return 0;
}
