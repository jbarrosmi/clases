#include <stdio.h>

int main(){
    int resto;
    int primero;
    printf("Primero:\n");
    scanf("%d", &primero);
    resto = primero % 2;

    if (resto == 0){
        printf ("El numero indicado es par.\n");
    }
    else {
        printf ("El numero indicado es impar.\n");
    }
    getchar();
    getchar();
    return 0;
}