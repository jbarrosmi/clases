#include <stdio.h>
#include <ctype.h>



int main() {
    char palabra[100];
    int vocales = 0;

    printf("Ingrese una palabra para contar el numero de vocales en ella:\n");
    scanf("%s", palabra);

    for (int i = 0; palabra[i] != '\0'; i++) {
        char c = (char)tolower(palabra[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vocales++;
        }
    }

    printf("Numero de vocales: %d\n", vocales);
    return 0;
}