//Menú inicial del juego hundir la flota.
#include <stdio.h>
#include <stdlib.h>

void limpiarPantalla() {
    printf("\033[2J\033[H");
    printf("\x1b[2J");
    printf("\x1b[H");
    fflush(stdout);
}

int main()
{
    int respuestamenu;
    while (1){
    limpiarPantalla();
    printf ("Bienvenido al juego Hundir la flota.\n");
    printf ("Por favor selecciona una de las siguientes opciones.\n");
    printf ("1. Jugar\n");
    printf ("2. Ver puntuaciones\n");
    printf ("3. Salir\n");
    scanf (" %d", &respuestamenu);
        if (respuestamenu == 3) {
            limpiarPantalla();
            printf ("Gracias por jugar.\n Pulse cualquier tecla para salir\n");
            getchar ();
            getchar (); 
            break;
        }
        if (respuestamenu == 2) {
            limpiarPantalla();
            //LAS PUNTUACIONES NO ESTÁN IMPLEMENTADAS
            //PROBABLEMENTE DEBERÍA CREARSE UN ARCHIVO AL TERMINAR LA PARTIDA QUE GUARDASE EN LA MEMORIA
            //LAS PUNTUACIONES DE LAS PARTIDAS Y UNA ORDEN PARA LLAMAR AL ARCHIVO Y MOSTRAR SU TEXTO EN PANTALLA
            //EN ESTE PUNTO.
            printf ("No hay puntuaciones que mostrar\n Pulse cualquier tecla para volver al menú.\n");
            getchar();
            getchar();
            limpiarPantalla();   
        }
        if (respuestamenu == 1) {
                            limpiarPantalla();

                          // SE GENERA UNA MATRIZ CHAR PARA EL JUGADOR
                    char PLAYER[13][13] = {
                {'X','A','B','C','D','E','F','G','H','I','J','K','L',},
                {'A','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'B','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'C','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'D','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'E','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'F','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'G','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'H','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'I','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'J','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'K','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                {'L','O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                };

                //EN ESTE PASO SE GENERARÍA UNA MATRIZ ALEATORIA PARA LA COMPUTADORA PERO SE OBVIA POR FALTA
                //DE CONOCIMIENTOS

                //SE GENERA AHORA LA MATRIZ FALSA QUE EL JUGADOR VERÁ COMO TABLERO ENEMIGO
                char FAKE[13][13] = {
                    {'X','A','B','C','D','E','F','G','H','I','J','K','L',},
                    {'A','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'B','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'C','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'D','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'E','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'F','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'G','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'H','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'I','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'J','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'K','?','?','?','?','?','?','?','?','?','?','?','?'},
                    {'L','?','?','?','?','?','?','?','?','?','?','?','?'},
                };
                limpiarPantalla();
                printf("\n");
                printf ("Este es tu tablero:\n");
                printf ("\n");
                  // Bucle for para recorrer las filas (primera dimensión)
                for (char i = 0; i < 13; i++)
                {
                    // Bucle for para recorrer las columnas (segunda dimensión)
                    for (char j = 0; j < 13; j++)
                    {
                    printf("%c, ", PLAYER[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf("Este es el tablero enemigo:\n");
                printf("\n");

                  // Bucle for para recorrer las filas (primera dimensión)
                for (char i = 0; i < 13; i++)
                {
                    // Bucle for para recorrer las columnas (segunda dimensión)
                    for (char j = 0; j < 13; j++)
                    {
                    printf("%c, ", FAKE[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf ("Ahora coloca tus barcos.\n");
                printf ("Indica FILA y COLUMNA y ORIENTACIÓN (H/V) y pulsa ENTER. Por ejemplo CFV.\n");
                //SIN EMBARGO, MIS CONOCIMIENTOS NO ME PERMITEN CONTINUAR PROGRAMANDO, DE MOMENTO.
                printf ("Si deseas salir y regresar al menú escribe s.\n");
                char SALIR;
                scanf(" %c", &SALIR);
                if (SALIR == 's') {
                    limpiarPantalla();
                }
                }


        }
    
}