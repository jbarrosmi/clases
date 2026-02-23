#include <stdio.h>
int main(){
    int numero;
    printf("Ingrese un numero para mostrar su tabla de multiplicar:\n");
    scanf("%d",&numero);
    printf("Tabla del %d:\n", numero);
    for (int multiplica = 1; multiplica <= 10; multiplica++) {
        printf("%d x %d = %d\n", numero, multiplica, numero * multiplica);
    }
    getchar();
    getchar();
    return 0;
}