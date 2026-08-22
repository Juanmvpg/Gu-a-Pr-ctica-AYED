// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Punteros a Funciones y Callbacks
// ============================================================
// Prerequisitos: punteros, aritmética de punteros, structs.
// Objetivo: aprender a pasar comportamiento como argumento mediante
//           punteros a funciones (callbacks) y tablas de funciones.
//
// Reglas y convenciones:
//   - Evitar 'using namespace std;' (usar std:: explícito).
//   - Uso de aritmética de punteros en algoritmos de recorrido.
//   - Manejo responsable de memoria dinámica (delete / delete[]).
// ============================================================


// ============================================================
// EJERCICIO 1 — Burbuja con Comparador Inyectado (Callback binario)
// ------------------------------------------------------------
// Concepto: bool (*compara)(int, int)
//   Un puntero a función de DOS argumentos permite desacoplar el
//   algoritmo de ordenamiento del criterio de comparación.
//
// Implementar:
//   1. bool esMayor(int a, int b): retorna true si a > b.
//   2. bool esMenor(int a, int b): retorna true si a < b.
//   3. void intercambiar(int* a, int* b): swap por punteros.
//   4. void ordenarBurbuja(int* arr, int n, bool (*compara)(int, int)):
//      Bucle anidado de burbuja usando solo aritmética de punteros.
//      - Bucle externo: n - 1 pasadas.
//      - Bucle interno: j < n - 1 - i comparaciones.
// ============================================================
/*
#include <iostream>

bool esMayor(int a, int b) {
    if (a > b) return true;
    return false;
}

bool esMenor(int a, int b) {
    if (a > b) return false;
    return true;
}

void intercambiar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ordenarBurbuja(int* arr, int n, bool (*compara)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (compara(*(arr + j), *(arr + j + 1))) {
                intercambiar((arr + j), (arr + j + 1));
            }
        }
    }
}

void imprimirArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int datos1[6] = {5, 2, 9, 1, 7, 3};
    int datos2[6] = {5, 2, 9, 1, 7, 3};

    std::cout << "Original:    ";
    imprimirArray(datos1, 6);

    // Inyección de esMayor (ascendente):
    ordenarBurbuja(datos1, 6, esMayor);
    std::cout << "Ascendente:  ";
    imprimirArray(datos1, 6);

    // Inyección de esMenor (descendente):
    ordenarBurbuja(datos2, 6, esMenor);
    std::cout << "Descendente: ";
    imprimirArray(datos2, 6);

    // Resultado esperado:
    // Original:    5 2 9 1 7 3 
    // Ascendente:  1 2 3 5 7 9 
    // Descendente: 9 7 5 3 2 1 

    return 0;
}
*/


// ============================================================
// EJERCICIO 2 — Filtrar Array con Predicado Inyectado (Callback unario)
// ------------------------------------------------------------
// Concepto: bool (*pred)(int)
//   Un predicado evalúa UN elemento de forma aislada y decide si cumple
//   una condición (true) o no (false).
//
// Implementar:
//   1. bool esPar(int n), bool esImpar(int n), bool esPositivo(int n).
//   2. int* filtrar(const int* arr, int n, bool (*pred)(int), int* resultSize):
//      - 1ra pasada: contar cuántos elementos cumplen el predicado.
//      - Asignar memoria dinámica: new int[count].
//      - 2da pasada: copiar los elementos al nuevo array.
//      - Retornar el array dinámico y escribir el tamaño en *resultSize.
//   3. En el main():
//      - Probar filtrado por pares y positivos.
//      - Liberar la memoria con delete[].
// ============================================================
/*
#include <iostream>

bool esPar(int n) {
    return (n % 2 == 0);
}

bool esImpar(int n) {
    return (n % 2 != 0);
}

bool esPositivo(int n) {
    return (n > 0);
}

// RETORNA: nuevo array dinámico. El llamador es responsable de delete[].
int* filtrar(const int* arr, int n, bool (*pred)(int), int* resultSize) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pred(*(arr + i))) {
            ++cont;
        }
    }

    int* arrFilter = new int[cont];
    *resultSize = cont;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (pred(*(arr + i))) {
            *(arrFilter + j) = *(arr + i);
            j++;
        }
    }
    return arrFilter;
}

void imprimirArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int datos[8] = {3, -1, 4, 0, -7, 2, 9, -3};
    int n = 8;

    std::cout << "Original:  ";
    imprimirArray(datos, n);

    int tamPares = 0;
    int* pares = filtrar(datos, n, esPar, &tamPares);
    std::cout << "Pares:     ";
    imprimirArray(pares, tamPares);
    delete[] pares;
    pares = nullptr;

    int tamPos = 0;
    int* positivos = filtrar(datos, n, esPositivo, &tamPos);
    std::cout << "Positivos: ";
    imprimirArray(positivos, tamPos);
    delete[] positivos;
    positivos = nullptr;

    // Resultado esperado:
    // Original:  3 -1 4 0 -7 2 9 -3 
    // Pares:     4 0 2 
    // Positivos: 3 4 2 9 

    return 0;
}
*/


// ============================================================
// EJERCICIO 3 — Transformación In-Place de Array (Map)
// ------------------------------------------------------------
// Concepto: int (*transforma)(int)
//   Un puntero a función que recibe un valor y retorna su versión
//   modificada. Permite transformar arrays sin duplicar lógica de bucle.
//
// Implementar:
//   1. int duplicar(int n): retorna n * 2.
//   2. int cuadrado(int n): retorna n * n.
//   3. int negar(int n):    retorna -n.
//   4. void mapear(int* arr, int n, int (*transforma)(int)):
//      Aplica la transformación in-place a cada elemento: *(arr + i) = transforma(*(arr + i)).
//   5. En el main():
//      Probar las tres transformaciones secuencialmente e imprimir.
// ============================================================
/*
#include <iostream>

int duplicar(int n) {
    // tu código acá
}

int cuadrado(int n) {
    // tu código acá
}

int negar(int n) {
    // tu código acá
}

void mapear(int* arr, int n, int (*transforma)(int)) {
    // tu código acá
}

void imprimirArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int datos[5] = {1, -2, 3, -4, 5};

    std::cout << "Original:  ";
    imprimirArray(datos, 5);

    mapear(datos, 5, duplicar);
    std::cout << "Duplicado: ";
    imprimirArray(datos, 5);

    mapear(datos, 5, cuadrado);
    std::cout << "Cuadrado:  ";
    imprimirArray(datos, 5);

    // Resultado esperado:
    // Original:  1 -2 3 -4 5 
    // Duplicado: 2 -4 6 -8 10 
    // Cuadrado:  4 16 36 64 100 

    return 0;
}
*/


// ============================================================
// EJERCICIO 4 — Tabla de Despacho (Dispatch Table / Menu con Punteros)
// ------------------------------------------------------------
// Concepto: array de punteros a funciones
//   void (*operaciones[3])(int*, int)
//   Permite seleccionar y ejecutar algoritmos por índice en O(1)
//   sin cadenas largas de if / else o switch.
//
// Implementar:
//   1. Funciones con firma uniforme 'void (int* arr, int n)':
//      - void opInvertir(int* arr, int n)
//      - void opDuplicarTodos(int* arr, int n)
//      - void opOrdenarAsc(int* arr, int n)
//   2. En el main():
//      - Declarar el array de punteros: void (*tabla[3])(int*, int) = { ... };
//      - Ejecutar operaciones accediendo por índice: tabla[opcion](datos, n);
// ============================================================
/*
#include <iostream>

void opInvertir(int* arr, int n) {
    // tu código acá
}

void opDuplicarTodos(int* arr, int n) {
    // tu código acá
}

void opOrdenarAsc(int* arr, int n) {
    // tu código acá
}

void imprimirArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int datos[5] = {5, 1, 4, 2, 8};

    // Declaración de la tabla de despacho:
    void (*operaciones[3])(int*, int) = {
        opInvertir,
        opDuplicarTodos,
        opOrdenarAsc
    };

    std::cout << "Original: ";
    imprimirArray(datos, 5);

    // Ejecutar operación 0 (Invertir):
    operaciones[0](datos, 5);
    std::cout << "Invertido: ";
    imprimirArray(datos, 5);

    // Ejecutar operación 2 (Ordenar):
    operaciones[2](datos, 5);
    std::cout << "Ordenado:  ";
    imprimirArray(datos, 5);

    return 0;
}
*/
