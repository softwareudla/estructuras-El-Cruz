#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[20]; 
    int n = 0;               
    int opc;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                if (n < 20) {
                    registrarLibros(libros, &n);
                } else {
                    printf("No se pueden registrar más libros. Límite alcanzado.\n");
                }
                break;
            case 2:
                mostrarLibros(libros, n);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, n, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el título del libro a buscar: ");
                scanf(" %[^\n]", titulo);
                buscarLibroTitulo(libros, n, titulo);
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del libro para actualizar su estado: ");
                scanf("%d", &id);
                actualizarEstadoLibro(libros, n, id);
                break;
            }
            case 6: {
                int id;
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &id);
                eliminarLibro(libros, &n, id);
                break;
            }
            case 7:
                printf("Saliendo del programa. ¡Hasta pronto!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opc != 7);

    return 0;
}
