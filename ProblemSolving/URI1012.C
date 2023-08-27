#include<stdio.h>
int main()
{
  float A, B, C;
  scanf("%f%f%f", &A, &B, &C);
  float tri = 0.5 * A * C;
  float cir = 3.14159 * C * C;
  float trapi = (A+B) * C * 0.5;
  float squ = B * B;
  float re =  A * B;
  printf("TRIANGULO: %.3f\n", tri);
  printf("CIRCULO: %.3f\n", cir);
  printf("TRAPEZIO: %.3f\n", trapi);
  printf("QUADRADO: %.3f\n", squ);
  printf("RETANGULO: %.3f\n", re);
}
