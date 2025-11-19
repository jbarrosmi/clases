#include <stdio.h>
// programilla que pregunta una tontería nerd//
int main() {
    int respuesta;
    printf("¿Cuál es el sentido de la vida, el universo y todo lo demás?\n");
    scanf("%d", &respuesta);
    if (respuesta == 42) {
        printf("¡Correcto!\n");
    } else {
        printf("Incorrecto. Te recomiendo La guía del autoestopista galáctico,de Douglas Adams.\n");
    }
    return 0;
}