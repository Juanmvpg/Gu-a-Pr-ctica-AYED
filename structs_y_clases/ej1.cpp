#include <iostream>
using namespace std;

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

struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Completá estas funciones:
void cargarFecha(Fecha* f, int d, int m, int a) {
    f-> dia = d;
    f-> mes = m;
    f-> anio = a;
}

void imprimirFecha(const Fecha* f) {
    cout <<f->dia<< "/"<<  f->mes<<"/"<<  f->anio<< endl;
}

int main() {
    // 1. Estructura creada en el Stack:
    Fecha hoy;
    cargarFecha(&hoy, 17, 8, 2026);

    cout << "Fecha en Stack: ";
    imprimirFecha(&hoy);

    // 2. Estructura creada en el Heap (Memoria Dinámica):
    Fecha* pFecha = new Fecha;
    cargarFecha(pFecha, 1, 1, 2027);

    cout << "Fecha en Heap:  ";
    imprimirFecha(pFecha);

    // Liberación de memoria dinámica:
    delete pFecha;
    pFecha = nullptr;

    // Resultado esperado:
    // Fecha en Stack: 17/8/2026
    // Fecha en Heap:  1/1/2027

    return 0;
}
