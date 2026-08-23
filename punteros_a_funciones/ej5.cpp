// ============================================================
// EJERCICIO 5 — Tabla de Despacho Inmutable (Memoria Dinámica)
// ------------------------------------------------------------
// Objetivo: Adaptar la tabla de despacho para trabajar con funciones
//           puras/inmutables que NO modifiquen el array original.
//
// Conceptos en juego:
//   - Firma uniforme: int* (*operaciones[N])(const int*, int)
//   - Copia profunda en el Heap (new int[n]) vs copia superficial de puntero.
//   - Gestión de memoria dinámica en el llamador (delete[]).
// ============================================================

#include <iostream>

// ============================================================
// Funciones de Operación Inmutables
// ============================================================

// 1. Invertir el orden de los elementos generando un nuevo array en Heap
int* opInvertirInmutable(const int* arr, int n) {
    // PREGUNTA INDAGATORIA 1:
    // ¿Por qué necesitamos 'new int[n]' aquí en lugar de hacer 'int* res = arr;'?
        //porque el argumento es solo de lectura, la transformación es previamente una copia

    // ¿Qué ocurriría si intentamos modificar a través de 'arr'?
        //hacer int* res = arr; es copiar la dirección de memoria. No se puede dado const
    int* res = new int[n];

    for (int i = 0; i < n; i++) {
        // PREGUNTA INDAGATORIA 2:
        // Si 'i' va desde 0 hasta n-1, ¿cuál es la posición espejada en 'arr'
            //La posición espejada es la ultima posicion
        // que debemos copiar en *(res + i)? Completa la fórmula.
            //se debe copiar la ultima posición -1, esto es *(arr+n-1-i)
        *(res + i) = *(arr + n-1 -i); 
    }
    return res;
}

// 2. Duplicar todos los elementos generando un nuevo array en Heap
int* opDuplicarInmutable(const int* arr, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++) {
        *(res + i) = *(arr + i) * 2;
    }
    return res;
}

// 3. Ordenar ascendente generando un nuevo array en Heap
int* opOrdenarInmutable(const int* arr, int n) {
    // Paso A: Crear la copia en memoria dinámica
    int* res = new int[n];
    for (int i = 0; i < n; i++) {
        *(res + i) = *(arr + i);
    }

    // Paso B: Ordenar sobre la copia 'res' (burbuja)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(res + j) > *(res + j + 1)) {
                int aux = *(res + j);
                *(res + j) = *(res + j + 1);
                *(res + j + 1) = aux;
            }
        }
    }
    return res;
}

void imprimirArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

// ============================================================
// main
// ============================================================

int main() {
    const int N = 5;
    int datos[N] = {5, 1, 4, 2, 8};

    std::cout << "Original inicial: ";
    imprimirArray(datos, N);
    std::cout << "-----------------------------------" << std::endl;

    // PREGUNTA INDAGATORIA 3:
    // ¿Cómo se declara el array de punteros a funciones para esta nueva firma?
        //el tipo y el retorno de la implementación debe ser igual a la callback., en este caso son int* y const arr
    // Debe almacenar 3 funciones que reciben (const int*, int) y retornan int*.
    int* (*tabla[3])(const int*, int) = {
        opInvertirInmutable,
        opDuplicarInmutable,
        opOrdenarInmutable,
    };

    // Prueba Operación 0: Invertir
    int* resultadoInvertido = tabla[0](datos, N);
    std::cout << "Invertido (nuevo array):   ";
    imprimirArray(resultadoInvertido, N);
    
    // PREGUNTA INDAGATORIA 4:
    // ¿Qué debemos hacer aquí con 'resultadoInvertido' para evitar memory leaks?
        //claramente delete[]
    delete[] resultadoInvertido;

    // Prueba Operación 1: Duplicar
    int* resultadoDuplicado = tabla[1](datos, N);
    std::cout << "Duplicado (nuevo array):   ";
    imprimirArray(resultadoDuplicado, N);
    delete[] resultadoDuplicado;

    // Prueba Operación 2: Ordenar
    int* resultadoOrdenado = tabla[2](datos, N);
    std::cout << "Ordenado (nuevo array):    ";
    imprimirArray(resultadoOrdenado, N);
    delete[] resultadoOrdenado;

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Original final (sigue intacto): ";
    imprimirArray(datos, N);

    // Resultado esperado en consola:
    // Original inicial: 5 1 4 2 8 
    // -----------------------------------
    // Invertido (nuevo array):   8 2 4 1 5 
    // Duplicado (nuevo array):   10 2 8 4 16 
    // Ordenado (nuevo array):    1 2 4 5 8 
    // -----------------------------------
    // Original final (sigue intacto): 5 1 4 2 8 

    return 0;
}
