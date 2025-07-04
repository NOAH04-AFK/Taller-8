#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu() {
    int opcion;
    
        printf("\nMenu:\n");
        printf("1. Agregar libro\n");
        printf("2. Listar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Eliminar libro\n");
        printf("5. Cambiar el estado del libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
    
}

void registrarLibros(Datoslibro libros[], int *cantidad) {
    int n;
    printf("¿Cuántos libros deseas registrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de libros debe ser mayor que 0.\n");
        return;
    }

    if (*cantidad + n > MAX_LIBROS) {
        printf("Solo puedes registrar hasta %d libros en total.\n", MAX_LIBROS);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nLibro #%d\n", *cantidad + 1);

        int idValido = 0;
        while (!idValido) {
            printf("ID: ");
            scanf("%d", &libros[*cantidad].ID);

            
            if (esIDUnico(libros, *cantidad, libros[*cantidad].ID)) {
                idValido = 1; // 
            } else {
                printf("El ID %d ya está registrado. Por favor, ingrese un ID diferente.\n", libros[*cantidad].ID);
            }
        }

        getchar(); 

        printf("Título: ");
        fgets(libros[*cantidad].titulo, sizeof(libros[*cantidad].titulo), stdin);
        strtok(libros[*cantidad].titulo, "\n");

        printf("Autor: ");
        fgets(libros[*cantidad].autor, sizeof(libros[*cantidad].autor), stdin);
        strtok(libros[*cantidad].autor, "\n");

        printf("Año de publicación: ");
        scanf("%d", &libros[*cantidad].añoPublicacion);
        getchar(); 

        libros[*cantidad].disponible = 1; 
        (*cantidad)++;

        printf("Libro registrado exitosamente.\n");
    }
}

void listaLibros(Datoslibro libros[], int cantidad) {
    if (cantidad <= 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n%-5s %-5s %-30s %-20s %-6s %-12s\n", "#", "ID", "Título", "Autor", "Año", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%-5d %-5d %-30s %-20s %-6d %-12s\n",
               i + 1,
               libros[i].ID,
               libros[i].titulo,
               libros[i].autor,
               libros[i].añoPublicacion,
               libros[i].disponible ? "Disponible" : "No disponible");
    }
}

void buscarlibro(Datoslibro libros[], int cantidad) {
    if (cantidad <= 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    char tituloBuscar[MAX_TITULOS];
    printf("Ingrese el titulo del libro a buscar: ");
    getchar(); // Limpiar el buffer
    fgets(tituloBuscar, MAX_TITULOS, stdin);
    tituloBuscar[strcspn(tituloBuscar, "\n")] = 0;

    if (strlen(tituloBuscar) == 0) {
        printf("El título no puede estar vacio.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(libros[i].titulo, tituloBuscar) == 0) {
            printf("Libro encontrado:\n");
            printf("ID: %d\n", libros[i].ID);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año de publicacion: %d\n", libros[i].añoPublicacion);
            printf("Estado: %s\n", libros[i].disponible ? "Disponible" : "No disponible");

            if (!libros[i].disponible) {
                printf("Nota: Este libro no está disponible actualmente.\n");
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Libro no encontrado.\n");
    }
}

void eliminarlibro(Datoslibro libros[], int *cantidad, int ind) {
    if (*cantidad <= 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    if (ind < 0 || ind >= *cantidad) {
        printf("Índice inválido. Debe estar entre 0 y %d.\n", *cantidad - 1);
        return;
    }

    for (int i = ind; i < *cantidad - 1; i++) {
        libros[i] = libros[i + 1];
    }

    (*cantidad)--;

    printf("Libro eliminado exitosamente.\n");
}

void actualizarEstadoLibro(Datoslibro libros[], int cantidad) {
    if (cantidad <= 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    listaLibros(libros, cantidad); 

    int indice;
    printf("Ingrese el índice del libro para actualizar su estado: ");
    scanf("%d", &indice);
    getchar(); 
    if (indice < 1 || indice > cantidad) {
        printf("Índice inválido. Debe estar entre 1 y %d.\n", cantidad);
        return;
    }

    indice--;

    libros[indice].disponible = !libros[indice].disponible;

    printf("El estado del libro '%s' ha sido actualizado a: %s\n",
           libros[indice].titulo,
           libros[indice].disponible ? "Disponible" : "No disponible");
}

int esIDUnico(Datoslibro libros[], int cantidad, int id) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].ID == id) {
            return 0; // El ID ya existe
        }
    }
    return 1; // El ID es único
}

