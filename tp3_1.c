#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *V[5];
    char *Buff;

    // Ingresar nombres
    for (int i = 0; i < 5; i++) {
        Buff = (char *) malloc(100 * sizeof(char));
        printf("Ingrese un nombre: ");
        gets(Buff);
        V[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(V[i], Buff);
    };

    // Mostrar nombres
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < 5; i++) {
        puts(V[i]);
        free(V[i]);
    };
       
    free(Buff);

    return 0;
};