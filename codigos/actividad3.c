#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10   // Tamaño del tablero (10x10)

// Valores del tablero:
// 0 = Agua
// 1 = Barco
// 2 = Disparo fallido
// 3 = Barco tocado

// --------------------------------------------------
// TABLEROS
// --------------------------------------------------

// Inicia un tablero poniendo todas las casillas a 0 (agua)
void inicializar_tablero(int tablero[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tablero[i][j] = 0;
}

// Crea el tablero de la CPU colocando los barcos
void crear_tablero_cpu(int tablero[TAM][TAM]) {
    inicializar_tablero(tablero);

    // Barco de 4 casillas
    for (int i = 0; i < 4; i++) tablero[0][i] = 1;

    // Barcos de 3 casillas
    for (int i = 0; i < 3; i++) tablero[1][i] = 1;
    for (int i = 0; i < 3; i++) tablero[2][i] = 1;

    // Barcos de 2 casillas
    for (int i = 0; i < 2; i++) tablero[3][i] = 1;
    for (int i = 0; i < 2; i++) tablero[4][i] = 1;
    for (int i = 0; i < 2; i++) tablero[5][i] = 1;
}

// Muestra el tablero del jugador completo (con barcos)
void mostrar_tablero_jugador(int tablero[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++)
            printf("%2d ", tablero[i][j]);
        printf("\n");
    }
}

// Muestra el tablero enemigo oculto, solo se muestran los disparos (2 y 3)
void mostrar_tablero_oculto(int tablero[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tablero[i][j] == 2 || tablero[i][j] == 3)
                printf("%2d ", tablero[i][j]);
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// --------------------------------------------------
// COLOCACIÓN DE BARCOS
// --------------------------------------------------

/*
 Comprueba si un barco se puede colocar:
 - No se sale del tablero
 - No choca con otro barco
*/
int puede_colocar(int tablero[TAM][TAM], int fila, int col, int tam, char dir) {

    // Dirección horizontal
    if (dir == 'H') {
        if (col + tam > TAM) return 0;
        for (int i = 0; i < tam; i++)
            if (tablero[fila][col + i] != 0)
                return 0;
    }
    // Dirección vertical
    else if (dir == 'V') {
        if (fila + tam > TAM) return 0;
        for (int i = 0; i < tam; i++)
            if (tablero[fila + i][col] != 0)
                return 0;
    }
    else return 0;

    return 1;
}

// Coloca el barco en el tablero
void colocar_barco(int tablero[TAM][TAM], int fila, int col, int tam, char dir) {
    if (dir == 'H')
        for (int i = 0; i < tam; i++)
            tablero[fila][col + i] = 1;
    else
        for (int i = 0; i < tam; i++)
            tablero[fila + i][col] = 1;
}

// Permite al jugador colocar todos sus barcos
void colocar_barcos_jugador(int tablero[TAM][TAM]) {

    int barcos[] = {4, 3, 3, 2, 2, 2};

    char *nombres[] = {
        "Portaviones (Cuatro casillas)",
        "Crucero 1 (Tres casillas)",
        "Crucero 2 (Tres casillas)",
        "Patrullero 1 (Dos casillas)",
        "Patrullero 2 (Dos casillas)",
        "Patrullero 3 (Dos casillas)"
    };

    int fila, col;
    char dir;

    for (int i = 0; i < 6; i++) {
        mostrar_tablero_jugador(tablero);
        printf("\nColocando %s\n", nombres[i]);

        do {
            printf("Fila inicial: ");
            scanf("%d", &fila);
            printf("Columna inicial: ");
            scanf("%d", &col);
            printf("Direccion (H/V): ");
            scanf(" %c", &dir);
        } while (!puede_colocar(tablero, fila, col, barcos[i], dir));

        colocar_barco(tablero, fila, col, barcos[i], dir);
    }
}

// --------------------------------------------------
// PUNTUACIONES
// --------------------------------------------------

// Carga las mejores puntuaciones desde un archivo
void cargar_puntuaciones(int top[3]) {
    FILE *f = fopen("puntuaciones.dat", "r");

    if (!f) {
        for (int i = 0; i < 3; i++)
            top[i] = 0;
        return;
    }

    for (int i = 0; i < 3; i++)
        fscanf(f, "%d", &top[i]);

    fclose(f);
}

// Guarda las mejores puntuaciones en un archivo
void guardar_puntuaciones(int top[3]) {
    FILE *f = fopen("puntuaciones.dat", "w");

    for (int i = 0; i < 3; i++)
        fprintf(f, "%d\n", top[i]);

    fclose(f);
}

// Muestra el ranking de puntuaciones
void mostrar_puntuaciones() {
    int top[3];
    cargar_puntuaciones(top);

    printf("\n--- MEJORES PUNTUACIONES ---\n");
    for (int i = 0; i < 3; i++)
        printf("%dº -> %d puntos\n", i + 1, top[i]);

    printf("\nPulsa Enter para volver...");
    while (getchar() != '\n');
    getchar();
}

// --------------------------------------------------
// LÓGICA DE JUEGO
// --------------------------------------------------

// Comprueba si todavía quedan barcos en el tablero
int quedan_barcos(int tablero[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (tablero[i][j] == 1)
                return 1;
    return 0;
}

// Disparo del jugador
void disparo_jugador(int tablero[TAM][TAM], int *puntos) {
    int fila, col;

    do {
        printf("Fila: ");
        scanf("%d", &fila);
        printf("Columna: ");
        scanf("%d", &col);
    } while (fila < 0 || fila >= TAM || col < 0 || col >= TAM);

    if (tablero[fila][col] == 1) {
        tablero[fila][col] = 3;
        printf("¡TOCADO!\n");
    }
    else if (tablero[fila][col] == 0) {
        tablero[fila][col] = 2;
        printf("Agua...\n");
        *puntos -= 100;
    }
    else {
        printf("Ya disparaste ahi.\n");
    }
}

// Disparo aleatorio de la CPU
void disparo_cpu(int tablero[TAM][TAM]) {
    int fila, col;

    do {
        fila = rand() % TAM;
        col = rand() % TAM;
    } while (tablero[fila][col] == 2 || tablero[fila][col] == 3);

    printf("La CPU dispara a (%d, %d)\n", fila, col);

    if (tablero[fila][col] == 1) {
        tablero[fila][col] = 3;
        printf("La CPU ha TOCADO un barco!\n");
    }
    else {
        tablero[fila][col] = 2;
        printf("La CPU falla.\n");
    }
}

// --------------------------------------------------
// PARTIDA
// --------------------------------------------------

// Función principal del juego
void jugar() {
    int tablero_jugador[TAM][TAM];
    int tablero_cpu[TAM][TAM];
    int puntos = 5000;

    inicializar_tablero(tablero_jugador);
    crear_tablero_cpu(tablero_cpu);
    colocar_barcos_jugador(tablero_jugador);

    srand(time(NULL));

    while (1) {

        printf("\n--- TU TABLERO ---\n");
        mostrar_tablero_jugador(tablero_jugador);

        printf("\n--- TABLERO ENEMIGO ---\n");
        mostrar_tablero_oculto(tablero_cpu);

        printf("Puntos: %d\n", puntos);

        printf("\nTU TURNO\n");
        disparo_jugador(tablero_cpu, &puntos);

        if (!quedan_barcos(tablero_cpu)) {
            printf("\n¡¡HAS GANADO!!\n");

            int top[3];
            cargar_puntuaciones(top);

            for (int i = 0; i < 3; i++) {
                if (puntos > top[i]) {
                    for (int j = 2; j > i; j--)
                        top[j] = top[j - 1];
                    top[i] = puntos;
                    break;
                }
            }

            guardar_puntuaciones(top);
            break;
        }

        printf("\nTURNO DE LA CPU\n");
        disparo_cpu(tablero_jugador);

        if (!quedan_barcos(tablero_jugador)) {
            printf("\nHAS PERDIDO...\n");
            break;
        }
    }

    printf("\nPulsa Enter para volver al menu...");
    while (getchar() != '\n');
    getchar();
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------

// Menú principal del programa
int main() {
    int opcion;

    do {
        printf("\n----------------------------------------\n");
        printf("          HUNDIR LA FLOTA\n");
        printf("----------------------------------------\n");
        printf("1. Jugar\n");
        printf("2. Ver mejores puntuaciones\n");
        printf("3. Salir\n");
        printf("----------------------------------------\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            jugar();
            break;
        case 2:
            mostrar_puntuaciones();
            break;
        case 3:
            printf("\nGracias por jugar.\n");
            break;
        default:
            printf("\nOpcion no valida.\n");
        }

    } while (opcion != 3);

    return 0;
}