#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *Buff;
    char **listadoNombres;
    int cantidadNombres;

    // Ingresar la cantidad de nombres
    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d", &cantidadNombres);
    fflush(stdin);

    listadoNombres = (char **) malloc(sizeof(char) * cantidadNombres);

    // Ingresar nombres
    for (int i = 0; i < cantidadNombres; i++) {

        Buff = (char *) malloc(100 * sizeof(char));
        printf("Ingrese un nombre: ");
        gets(Buff);
        listadoNombres[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(listadoNombres[i], Buff);
    };

    // Mostrar nombres
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < cantidadNombres; i++) {
        puts(listadoNombres[i]);
    };

    free(listadoNombres);
    free(Buff);

    return 0;
};