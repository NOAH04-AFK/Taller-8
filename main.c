#include <stdio.h>
#include <string.h>
#include "funciones.h"


int main() {
    Datoslibro libros[MAX_LIBROS];
    int cantidad = 0;
    int opcion;

    do {
        menu();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                registrarLibros(libros, &cantidad);
                break;
            case 2:
                listaLibros(libros, cantidad);
                break;
            case 3:
                buscarlibro(libros, cantidad);
                break;
            case 4: {
                listaLibros(libros, cantidad);
                int indice;
                printf("Ingrese el índice del libro a eliminar: ");
                scanf("%d", &indice);
                eliminarlibro(libros, &cantidad, indice);
                break;
            }
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 5);

}
