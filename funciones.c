#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opcion = 0;
    do {
        printf("\n\tBiblioteca Digital");
        printf("\n=======================================\n");
        printf("1. Registrar libros\n");
        printf("2. Mostrar la lista de libros\n");
        printf("3. Buscar libros por id\n");
        printf("4. Buscar libros por titulo\n");
        printf("5. Actualizar estado de un libro\n");
        printf("6. Eliminar libro\n");
        printf("7. Salir\n");
        printf("\n=======================================\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 7) {
            printf("Opción inválida. Por favor, intente de nuevo.\n");
        }
    } while (opcion < 1 || opcion > 7);
    return opcion;
}

void registrarLibros(struct Libro libros[], int *n) {
    printf("Registro de libro #%d\n", *n + 1);
    printf("ID (único): ");
    scanf("%d", &libros[*n].id);

    for (int i = 0; i < *n; i++) {
        if (libros[i].id == libros[*n].id) {
            printf("Error: El ID ingresado ya existe. Registro cancelado.\n");
            return;
        }
    }

    printf("Título: ");
    scanf(" %[^\n]", libros[*n].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", libros[*n].autor);
    printf("Año de publicación: ");
    scanf("%d", &libros[*n].anio_publicacion);

    strcpy(libros[*n].estado, "Disponible");
    (*n)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(struct Libro libros[], int n) {
    if (n == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\nLista de libros:\n");
    printf("ID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio_publicacion,
               libros[i].estado);
    }
}

void buscarLibroId(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio_publicacion, libros[i].estado);
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", id);
}

void buscarLibroTitulo(struct Libro libros[], int n, const char *titulo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio_publicacion, libros[i].estado);
            return;
        }
    }
    printf("No se encontró ningún libro con el título \"%s\".\n", titulo);
}

void actualizarEstadoLibro(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("Estado actual del libro: %s\n", libros[i].estado);
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("El estado del libro ha sido actualizado a: %s\n", libros[i].estado);
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", id);
}

void eliminarLibro(struct Libro libros[], int *n, int id) {
    for (int i = 0; i < *n; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                libros[j] = libros[j + 1]; 
            }
            (*n)--;
            printf("Libro con ID %d eliminado exitosamente.\n", id);
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", id);
}
