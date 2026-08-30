// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Recursividad (Recursión Básica, Avanzada y Tail Recursion)
// ============================================================
// Prerequisitos: Punteros, Aritmética de Punteros, Call Stack.
// Objetivo: Aprender a modelar problemas dividiéndolos en subproblemas,
//           identificar Casos Base, entender el flujo en el Call Stack
//           y aplicar optimizaciones de Recursión de Cola (Tail Recursion).
//
// Reglas y Estándares:
//   - Uso de 'std::' explícito (sin using namespace std).
//   - Aritmética de punteros pura para recorrer arrays.
//   - Manejo estricto de casos base para evitar Stack Overflow.
// ============================================================


// ============================================================
// EJERCICIO 1 — Impresión Recursiva: Ida vs Vuelta (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Identificación de caso base (n == 0).
//   - Impresión en fase de ida (Tail Recursion) vs fase de vuelta.
// ============================================================
/*
#include <iostream>

void imprimirDirecto(const int* arr, int n) {
    if (n == 0) return;
    std::cout << *arr << " ";
    imprimirDirecto(arr + 1, n - 1);
}

void imprimirInverso(const int* arr, int n) {
    if (n == 0) return;
    std::cout << *(arr + n - 1) << " ";
    imprimirInverso(arr, n - 1);
}

int main() {
    int v[6] = {17, 15, -8, 30, 5, -2};

    std::cout << "Directo: ";
    imprimirDirecto(v, 6);
    std::cout << std::endl;

    std::cout << "Inverso: ";
    imprimirInverso(v, 6);
    std::cout << std::endl;

    // Resultado esperado:
    // Directo: 17 15 -8 30 5 -2
    // Inverso: -2 5 30 -8 15 17

    return 0;
}
*/


// ============================================================
// EJERCICIO 2 — Aritmética y Reducción: Suma, Multiplicación y Tail Recursion (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Multiplicación mediante sumas recursivas.
//   - Reducción de arrays mediante recursión tradicional (No-Tail) vs Tail Recursion con acumulador.
//   - Conteo de elementos recursivo puro con promoción booleana.
// ============================================================
/*
#include <iostream>

int multi(int a, int b) {
    if (b == 0) return 0;
    return a + multi(a, b - 1);
}

int sumaNoTail(const int* arr, int n) {
    if (n == 0) return 0;
    return *(arr + n - 1) + sumaNoTail(arr, n - 1);
}

int sumaTail(const int* arr, int n, int acumulador = 0) {
    if (n == 0) return acumulador;
    return sumaTail(arr + 1, n - 1, acumulador + *arr);
}

int potencia(int base, int exp) {
    if (exp == 0) return 1;
    return base * potencia(base, exp - 1);
}

int contarOcurrencias(const int* arr, int n, int buscado) {
    if (n == 0) return 0;
    return (*arr == buscado) + contarOcurrencias(arr + 1, n - 1, buscado);
}

int main() {
    int v[8] = {4, 2, 7, 2, -3, 2, 5, 1};
    int n = 8;

    std::cout << "Multiplicacion 5 * 7:   " << multi(5, 7) << std::endl;
    std::cout << "Suma Recursiva Común:   " << sumaNoTail(v, n) << std::endl;
    std::cout << "Suma Tail Recursion:    " << sumaTail(v, n) << std::endl;
    std::cout << "Potencia 2^5:           " << potencia(2, 5) << std::endl;
    std::cout << "Veces que aparece el 2: " << contarOcurrencias(v, n, 2) << std::endl;

    return 0;
}
*/


// ============================================================
// EJERCICIO 3 — Máximo Recursivo y Búsqueda Binaria Recursiva
// ------------------------------------------------------------
// Enunciado:
//   1. int buscarMaximoRecursivo(const int* arr, int n):
//      Encuentra el valor máximo comparando el último elemento con el máximo del resto.
//   2. int busquedaBinariaRecursiva(const int* arr, int inicio, int fin, int buscado):
//      Divide el array a la mitad en cada paso recursivo (O(log N)).
// ============================================================
/*
#include <iostream>

// Tu código acá

int main() {
    return 0;
}
*/


// ============================================================
// EJERCICIO 4 — Torres de Hanoi (Recursión Múltiple)
// ------------------------------------------------------------
// Enunciado (El algoritmo clásico de la cátedra):
//
// Resolver el puzzle de las Torres de Hanoi para 'n' discos.
// Mover 'n' discos desde el poste 'origen' hasta el poste 'destino'
// utilizando el poste 'auxiliar'.
//
// Firma: void hanoi(char origen, char destino, char auxiliar, int n);
// ============================================================
/*
#include <iostream>

// Tu código acá

int main() {
    return 0;
}
*/
