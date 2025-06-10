#include <stdio.h>
#include <string.h>
#include "funciones.h"


int main() {
    Datoslibro libros[MAX_LIBROS];
    int cantidad = 0;
    int opcion;

    do {
        menu();
        printf("Selecciona una opcion: ");
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
                getchar(); // Limpiar el buffer de entrada
                eliminarlibro(libros, &cantidad, indice - 1); // Convertir a índice basado en 0
                break;
            }
            case 5:
                actualizarEstadoLibro(libros, cantidad);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción entre 1 y 6.\n");
        }

    } while (opcion != 6);

    return 0;
}

