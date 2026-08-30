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
// EJERCICIO 2 — Suma y Multiplicación Recursiva
// ------------------------------------------------------------
// Enunciado (Basado en 08_Recursion_Solucion_Ejercicios de la cátedra):
//
// Implementar:
//   1. int multiplicacionRusa(int a, int b):
//      Multiplica 'a * b' utilizando solo SUMAS sucesivas recursivas.
//      (Caso base: si b == 0 retorna 0; Caso recursivo: a + multi(a, b-1)).
//   2. int sumaArray(const int* arr, int n):
//      Suma todos los elementos de un array de forma recursiva.
//   3. int sumaArrayTail(const int* arr, int n, int acumulador = 0):
//      Versión Tail Recursion con acumulador (O(1) memoria en compiladores modernos).
// ============================================================
/*
#include <iostream>

// Tu código acá

int main() {
    int v[6] = {17, 15, -8, 30, 5, -2};

    std::cout << "Multiplicacion 5 * 7: " << multiplicacionRusa(5, 7) << std::endl;
    std::cout << "Suma Recursiva Común: " << sumaArray(v, 6) << std::endl;
    std::cout << "Suma Tail Recursion:  " << sumaArrayTail(v, 6) << std::endl;

    // Resultado esperado:
    // Multiplicacion 5 * 7: 35
    // Suma Recursiva Común: 57
    // Suma Tail Recursion:  57

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
