/*
=== EJERCICIO 1: LA BIBLIOTECA INFINITA (std::vector) ===

Objetivo: Familiarizarse con la sintaxis básica de la clase std::vector 
(Unidad 3.1: Estructuras Lineales Contiguas).

Consigna:
1. Crear una clase `Libro` que tenga como único atributo el título (std::string).
   - Debe tener un constructor para inicializar el título, y un getter (getTitulo).
2. Crear una clase `Biblioteca` que tenga un único atributo privado:
   - Un `std::vector<Libro> estanteria;`
3. Implementar el método `agregarLibro(std::string titulo)` en Biblioteca.
   - Debe instanciar un Libro y agregarlo al final del vector usando `.push_back()`.
4. Implementar el método `mostrarLibros() const` que recorra el vector.
   - Pista: podés usar el método `.size()` del vector para saber su tamaño actual.
5. En el `main()`, instanciar una Biblioteca, agregar 3 libros sin preocuparse
   por definir capacidades máximas, y mostrarlos por pantalla. No hace falta usar punteros 
   ni new/delete en el main.
*/
#include <iostream>
#include <vector>
#include <string>



class Biblioteca{

};
int main(){


    return 0;
}