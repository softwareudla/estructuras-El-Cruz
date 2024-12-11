struct Libro{
    int id;
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    char estado[15];
};
int menu();
void registrarLibros(struct Libro libros[], int *n);
void mostrarLibros(struct Libro libros[], int n);
void buscarLibroId(struct Libro libros[], int n, int id);
void buscarLibroTitulo(struct Libro libros[], int n, const char *titulo);
void actualizarEstadoLibro(struct Libro libros[], int n, int id);
void eliminarLibro(struct Libro libros[], int *n, int id);