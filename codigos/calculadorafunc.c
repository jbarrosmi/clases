// Calduladora con funciones
//Voy a usar float en lugar de int porque me parece más interesante
//y tengo curiosidad por lo errores que puedan salir de este uso.
#include <stdio.h>

float SUMA (float x, float y)
{
    return x + y;
}

float RESTA (float x, float y)
{
    return x - y;
}

float MULTIPLICACION (float x, float y)
{
    return x * y;
}   

float DIVISION (float x, float y)
{
    if (y == 0)
    {
        printf("Error: Division por cero no válida.\n");
        return 0;
    }    
    else
    { return x / y ;}
}
// a partir del siguiente código voy a desactivar el copilot.
// me resulta muy útil para recordar los nombres de las instrucciones,
//pero es demasiado avanzado y en cuanto escribo un par de líneas ya sabe
//qué es lo que busco y me escribe todo el código completo. Incluso me está
//sugiriendo qué escribir en este texto y lo hace con bastante precisión.

int main ()
{
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
    float x, y, resultado;
    char operacion;
    printf("Calculadora simple en C usando funciones.\n");
    printf("Puede realizar SUMA, RESTA, MULTIPLICACIÓN y DIVISIÓN.\n Indique qué operación realizar con +, -, * o /:\n");
    scanf(" %c", &operacion);
    if (operacion == '+') {
        printf ("Indique el primer número:\n");
        scanf (" %f", &x);
        printf ("Indique el segundo número:\n");
        scanf (" %f", &y);
        resultado = SUMA(x, y);
        printf("El resultado de sumar %.2f + %.2f es: %.2f\n", x, y, resultado);
    }
    else if (operacion == '-') {
        printf ("Indique el primer número:\n");
        scanf (" %f", &x);
        printf ("Indique el segundo número:\n");
        scanf (" %f", &y);
        resultado = RESTA(x, y);
        printf("El resultado de restar %.2f - %.2f es: %.2f\n", x, y, resultado);
    }
    else if (operacion == '*') {
        printf ("Indique el primer número:\n");
        scanf (" %f", &x);
        printf ("Indique el segundo número:\n");
        scanf (" %f", &y);
        resultado = MULTIPLICACION(x, y);
        printf("El resultado de multiplicar %.2f * %.2f es: %.2f\n", x, y, resultado);
    }
    else if (operacion == '/') {
        printf ("Indique el primer número:\n");
        scanf (" %f", &x);
        printf ("Indique el segundo número:\n");
        scanf (" %f", &y);
        resultado = DIVISION(x, y);
        if (y !=0) {
        printf("El resultado de dividir %.2f / %.2f es: %.2f\n", x, y, resultado);}
    }
    else {
        printf("Operación no válida. Use SUMA, RESTA, MULTIPLICACION o DIVISION.\n");
    }
    printf("¿Desea realizar otra operación? (s/n): ");
    scanf(" %c", &continuar);
}
printf("Gracias por usar la calculadora.\n Pulse Enter para salir");
getchar();
getchar();
return 0;
}