#include <iostream>
#include <cstring> // Para strcpy
using namespace std;

// ============================================================
// EJERCICIO 2 — Estructuras Anidadas y Manejo Integral
// ------------------------------------------------------------
    // 1. Reutilizá la estructura 'Fecha' (dia, mes, anio).
    // 2. Creá la estructura 'Persona' con campos:
    //      - char nombre[30];
    //      - long dni;
    //      - Fecha nac; (Estructura anidada)
    // 3. Implementá las funciones:
    //      - void cargarPersona(Persona* p, const char* nom, long doc, int d, int m, int a);
    //        (Pista: usá strcpy(p->nombre, nom); para copiar el string)
    //      - void imprimirPersona(const Persona* p);
    //        (Debe mostrar: Nombre, DNI y fecha "DD/MM/AAAA")
    // 4. En el main():
    //      - Creá una Persona 'p1' en el Stack y cargala con tus datos.
    //      - Creá una Persona dinámica 'p2' en el Heap con new y cargala.
    //      - Imprimí ambas personas con imprimirPersona.
    //      - Modificá directamente en el main el año de nacimiento de 'p1' usando '.'
    //      - Modificá directamente en el main el año de nacimiento de 'p2' usando '->'
    //      - Volvé a imprimir ambas para verificar los cambios.
    //      - Liberá la memoria dinámica correctamente.
    // ============================================================

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[30];
    long dni;
    struct Fecha nac; //se llama estructura anidada!
    
};

// Funciones a implementar:
void cargarPersona(Persona* p, const char* nom, long doc, int d, int m, int a) {
        strcpy(p->nombre, nom);// la función strcpy es string copy, comia el string en la estructura persona al puntero nom
    p-> dni=doc;
    p-> nac.dia = d; //es erroneo poner p->nac->dia, dado que esto necesita que nac sea puntero.
    p-> nac.mes = m;
    p-> nac.anio = a;


}

void imprimirPersona(const Persona* p) { //        (Debe mostrar: Nombre, DNI y fecha "DD/MM/AAAA")
    cout << p-> nombre<< ", ";
    cout << p->dni << " y ";
    cout << p->nac.dia << "/";
    cout << p->nac.mes << "/";
    cout << p->nac.anio << endl;
}

int main() {
    // en stack
    Persona p1;
    cargarPersona (&p1, "Juan", 46354281, 16, 1, 2006);
    imprimirPersona(&p1);

    // en heap
    Persona* p2 = new Persona;
    cargarPersona (p2, "Fran", 45454545, 12, 4, 1946);
    imprimirPersona(p2);

    p1.nac.anio = 2000; //uso el punto porque p1 es una variable del tipo persona. no un puntero a persona y está creada en el main
    p2->nac.anio = 1999; //uso la flecha porque p2 es un puntero a persona y está creada en el heap
    imprimirPersona(&p1);
    imprimirPersona(p2);

    //liberación de memoria dinámica
    delete p2;
    p2 = nullptr;


    return 0;
}
