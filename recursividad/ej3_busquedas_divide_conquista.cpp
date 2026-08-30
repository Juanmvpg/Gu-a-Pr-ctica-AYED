// ============================================================
// EJERCICIO 3 — Búsqueda Recursiva: Máximo y Búsqueda Binaria
// ============================================================
// Enunciado (Ejercicios oficiales de cátedra):
//
// 1. int buscarMaximo(const int* arr, int n):
//    Encuentra el valor máximo de un array de forma recursiva.
//    - Caso Base: Si n == 1, el único elemento *(arr) es el máximo.
//    - Caso Recursivo: Compara el elemento actual *(arr + n - 1)
//      con el máximo del resto del array: buscarMaximo(arr, n - 1).
//
// 2. int busquedaBinaria(const int* arr, int inicio, int fin, int buscado):
//    Algoritmo "Divide y Conquistar" (O(log N)):
//    - El array DEBE estar ordenado.
//    - Si inicio > fin: el elemento no existe, retorna -1 (Caso Base 1).
//    - Calcula el punto medio: medio = inicio + (fin - inicio) / 2.
//    - Si *(arr + medio) == buscado: retorna 'medio' (Caso Base 2).
//    - Si *(arr + medio) > buscado: busca en la mitad izquierda [inicio, medio - 1].
//    - Si *(arr + medio) < buscado: busca en la mitad derecha [medio + 1, fin].
//
// 3. bool esPalindromo(const char* inicio, const char* fin):
//    Verifica si una palabra se lee igual al derecho y al revés usando punteros:
//    - Si inicio >= fin: retorna true (Caso Base 1).
//    - Si *inicio != *fin: retorna false (Caso Base 2).
//    - Si son iguales: avanza inicio+1 y retrocede fin-1.
// ============================================================

#include <iostream>
#include <cstring>

// 1. Búsqueda del Máximo
int buscarMaximo(const int* arr, int n) {
    // Tu código acá
}

// 2. Búsqueda Binaria Recursiva (Divide y Conquistar)
int busquedaBinaria(const int* arr, int inicio, int fin, int buscado) {
    // Tu código acá
}

// 3. Verificación de Palíndromo con punteros
bool esPalindromo(const char* inicio, const char* fin) {
    // Tu código acá
}

int main() {
    std::cout << "=== EJERCICIO 3: BUSQUEDAS Y DIVIDE Y CONQUISTAR ===" << std::endl;

    // 1. Test Máximo:
    int vDesordenado[6] = {17, 15, -8, 30, 5, -2};
    std::cout << "Maximo del vector: " << buscarMaximo(vDesordenado, 6) << std::endl;

    // 2. Test Búsqueda Binaria (Array ORDENADO):
    int vOrdenado[7] = {-8, -2, 5, 15, 17, 30, 99};
    int n = 7;
    int pos1 = busquedaBinaria(vOrdenado, 0, n - 1, 30);
    int pos2 = busquedaBinaria(vOrdenado, 0, n - 1, 100);

    std::cout << "Elemento 30 encontrado en indice: " << pos1 << std::endl;
    std::cout << "Elemento 100 encontrado en indice: " << pos2 << " (-1 = No encontrado)" << std::endl;

    // 3. Test Palíndromo:
    const char palabra1[] = "neuquen";
    const char palabra2[] = "algoritmos";

    bool r1 = esPalindromo(palabra1, palabra1 + std::strlen(palabra1) - 1);
    bool r2 = esPalindromo(palabra2, palabra2 + std::strlen(palabra2) - 1);

    std::cout << "'neuquen' es palindromo?:    " << (r1 ? "SI" : "NO") << std::endl;
    std::cout << "'algoritmos' es palindromo?: " << (r2 ? "SI" : "NO") << std::endl;

    // Resultado esperado:
    // === EJERCICIO 3: BUSQUEDAS Y DIVIDE Y CONQUISTAR ===
    // Maximo del vector: 30
    // Elemento 30 encontrado en indice: 5
    // Elemento 100 encontrado en indice: -1 (-1 = No encontrado)
    // 'neuquen' es palindromo?:    SI
    // 'algoritmos' es palindromo?: NO

    return 0;
}
