#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void limpiarPantalla() {
    printf("\033[2J\033[H");
    printf("\x1b[2J");
    printf("\x1b[H");
    fflush(stdout);
}

int main()
{
inicio:
    printf("Bienvenido a Piedra, Papel o Tijera.\n");
    printf("Elige una opcion:\n");
    printf("1. Piedra.\n2. Papel.\n3. Tijera.\n");
    int selec;
    scanf("%d", &selec);
    
    int comp = rand() % 3+1;
    if(selec==1 && comp==1)
    {system("cls");
    printf("Empate. Piedra vs Piedra\n");
    goto inicio;}
    else if(selec==1 && comp==2)
    {system("cls");
    printf("Pierdes. Piedra vs Papel.\n");
    goto inicio;}
    else if(selec==1 && comp==3)
    {system("cls");
    printf("Ganas. Piedra vs Tijera.\n");
    goto inicio;}
    else if(selec==2 && comp==1)
    {system("cls");
    printf("Ganas. Papel vs Piedra\n");
    goto inicio;}
    else if(selec==2 && comp==2)
    {system ("cls");
    printf("Empate. Papel vs Papel.\n");
    goto inicio;}
    else if (selec==2 && comp==3)
    {system("cls");
    printf("Pierdes. Papel vs Tijera\n");
    goto inicio;}
    else if (selec==3 && comp==1)
    {system("cls");
    printf("Pierdes. Tijera vs Piedra.\n");
    goto inicio;}
    else if (selec==3 && comp==2)
    {system("cls");
    printf("Ganas. Tijera vs Papel.\n");
    goto inicio;}
    else if (selec==3 && comp==3)
    {system("cls");
    printf("Empate. Tijera vs Tijera.\n");
    goto inicio;}


getchar();
getchar();
return 0;
}