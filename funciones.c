#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu(){
    printf("1. Agregar libro\n");
    printf("2. Listar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Eliminar libro\n");
    printf("5. Salir\n");
}

void registrarLibros(Datoslibro libros[], int *cantidad) {
    int n;
    printf("¿Cuántos libros deseas registrar? ");
    scanf("%d", &n);

    if (*cantidad + n > MAX_LIBROS) {
        printf("Solo puedes registrar hasta %d libros.\n", MAX_LIBROS);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nLibro #%d\n", *cantidad + 1);
        printf("ID: ");
        scanf("%d", &libros[*cantidad].ID);
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
    fgets(tituloBuscar, MAX_TITULOS, stdin);
    tituloBuscar[strcspn(tituloBuscar, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(libros[i].titulo, tituloBuscar) == 0) {
            printf("Libro encontrado:\n");
            printf("ID: %d\n", libros[i].ID);
            printf("Titulo: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año de publicacion: %d\n", libros[i].añoPublicacion);
            printf("Estado: %s\n", libros[i].disponible ? "Disponible" : "No disponible");
            encontrado = 1;
            break;
        }
    }

        if (!encontrado)
    {
        printf("Libro no encontrado.\n");
    }
}

void eliminarlibro(Datoslibro libros[], int *cantidad,int ind){

    if (cantidad <= 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    if (ind < 0 || ind >= *cantidad) {
        printf("Indice invalido.\n");
        return;
    }

    for (int i = ind; i < *cantidad; i++)
    {
        libros[i] = libros[i + 1];
    }
    
    int idx = ind - 1;
    if (!libros[idx].disponible){
        printf("Ese libro a sido eliminado.\n");
        return;
    }
    libros[idx].ID = 0;
    (*cantidad)--;

    printf("Libro eliminado exitosamente.\n");

}
    
