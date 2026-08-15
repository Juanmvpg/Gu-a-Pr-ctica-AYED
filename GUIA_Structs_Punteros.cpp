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
