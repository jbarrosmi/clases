#include <stdio.h>

int main() {
    float primero, segundo, tercero; //holaholahola
    double promedio;

    printf("Primero:\n");
    scanf("%f", &primero);
    printf("Segundo:\n");
    scanf("%f", &segundo);
    printf("Tercero:\n");
    scanf("%f", &tercero);

    promedio = (primero + segundo + tercero) / 3.0;

    printf("Promedio: %.5f\n", promedio);

    getchar();
    getchar();
    return 0;
}