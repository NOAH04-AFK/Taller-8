#define MAX_LIBROS 10
#define MAX_TITULOS 100
#define MAX_AUTORES 50


typedef struct{
    int ID;
    char titulo[MAX_TITULOS];
    char autor[MAX_AUTORES];
    int añoPublicacion;
    int disponible; 
}Datoslibro;

void menu();
void registrarLibros(Datoslibro libros[], int *cantidad);
void listaLibros(Datoslibro libros[], int cantidad);
void buscarlibro(Datoslibro libros[], int cantidad);
void eliminarlibro(Datoslibro libros[], int *cantidad,int id);