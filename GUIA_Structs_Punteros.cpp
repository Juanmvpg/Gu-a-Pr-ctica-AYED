// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Estructuras (structs) y Punteros a Structs
// ============================================================
// Conceptos clave:
//   - Definición de tipos de datos compuestos (struct).
//   - Acceso directo a campos con el operador punto (.): variable.campo
//   - Acceso mediante puntero con el operador flecha (->): ptr->campo
//     (Equivalente a (*ptr).campo)
//   - Pasaje de estructuras a funciones por puntero/referencia.
//   - Arrays dinámicos de estructuras y memoria dinámica.
// ============================================================


// ============================================================
// EJERCICIO 1 — Acceso directo (.) vs Acceso por puntero (->)
// ------------------------------------------------------------
// Definí una estructura 'Fecha' con campos: dia, mes, anio (enteros).
// Implementá dos funciones:
//   1. void cargarFecha(Fecha* f, int d, int m, int a):
//      Recibe un puntero a Fecha y asigna los valores a sus campos
//      usando el operador flecha (->).
//   2. void imprimirFecha(const Fecha* f):
//      Recibe un puntero constante e imprime en formato "DD/MM/AAAA".
// ============================================================
/*
#include <iostream>
using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Completá estas funciones:
void cargarFecha(Fecha* f, int d, int m, int a) {
    // tu código acá
}

void imprimirFecha(const Fecha* f) {
    // tu código acá
}

int main() {
    Fecha hoy; // en el Stack
    cargarFecha(&hoy, 15, 8, 2026);

    cout << "Fecha en Stack: ";
    imprimirFecha(&hoy);

    // Con memoria dinámica en el Heap:
    Fecha* pFecha = new Fecha;
    cargarFecha(pFecha, 1, 1, 2027);

    cout << "Fecha en Heap:  ";
    imprimirFecha(pFecha);

    delete pFecha;
    pFecha = nullptr;

    // Resultado esperado:
    // Fecha en Stack: 15/8/2026
    // Fecha en Heap:  1/1/2027

    return 0;
}
*/


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
//      - void imprimirPersona(const Persona* p);
// 4. En el main():
//      - Creá 'p1' en Stack y 'p2' dinámico en Heap con new.
//      - Cargá e imprimí ambas personas.
//      - Modificá el anio de 'p1' usando '.' y el de 'p2' usando '->'.
//      - Imprimí nuevamente para verificar.
//      - Liberá la memoria dinámica en el Heap.
// ============================================================
/*
#include <iostream>
#include <cstring>
using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[30];
    long dni;
    Fecha nac;
};

void cargarPersona(Persona* p, const char* nom, long doc, int d, int m, int a) {
    // tu código acá
}

void imprimirPersona(const Persona* p) {
    // tu código acá
}

int main() {
    // tu código del main acá

    return 0;
}
*/


// ============================================================
// EJERCICIO 3 — Arrays Dinámicos de Estructuras y Aritmética
// ------------------------------------------------------------
// En este ejercicio combinamos:
//   - Array dinámico en el Heap de tipo 'Persona' (new Persona[n]).
//   - Aritmética de punteros aplicada a estructuras: (p + i)->campo
//   - Búsqueda y retorno de puntero a una estructura específica.
//
// Implementar:
//   1. void cargarGrupo(Persona* grupo, int n):
//      Carga 'n' personas en el array usando aritmética de punteros.
//   2. void imprimirGrupo(const Persona* grupo, int n):
//      Muestra todas las personas del grupo.
//   3. Persona* buscarPorDNI(Persona* grupo, int n, long dniBuscado):
//      Busca secuencialmente y devuelve un puntero a la Persona que
//      coincida con el DNI. Si no existe, devuelve nullptr.
//   4. En el main():
//      Crear el array dinámico, cargarlo, imprimirlo, buscar un DNI,
//      modificar un dato a través del puntero retornado y liberar memoria.
// ============================================================
/*
#include <iostream>
#include <cstring>
using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[30];
    long dni;
    Fecha nac;
};

void cargarGrupo(Persona* grupo, int n) {
    // tu código acá
}

void imprimirGrupo(const Persona* grupo, int n) {
    // tu código acá
}

Persona* buscarPorDNI(Persona* grupo, int n, long dniBuscado) {
    // tu código acá
}

int main() {
    // tu código acá

    return 0;
}
*/

