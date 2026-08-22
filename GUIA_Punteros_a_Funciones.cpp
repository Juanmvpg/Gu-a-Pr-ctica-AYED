// ============================================================
// GUÍA PRÁCTICA — Punteros a Funciones y Callbacks
// ============================================================
// Prerequisitos: punteros, aritmética de punteros, structs
// Objetivo: aprender a pasar comportamiento como argumento
//           mediante punteros a funciones (callbacks)
//
// Conceptos clave:
//   - Declaración:  bool (*nombre)(int, int)
//   - Asignación:   nombre = miFuncion;  (sin paréntesis = dirección)
//   - Invocación:   nombre(a, b);        (con paréntesis = ejecutar)
//   - Compatibilidad: retorno Y todos los parámetros deben coincidir
// ============================================================

#include <iostream>

// ============================================================
// EJERCICIO 1 — Burbuja con Comparador Inyectado (COMPLETO)
// ------------------------------------------------------------
// Concepto: bool (*compara)(int, int)
//   Puntero a función de DOS argumentos → comparador.
//   Permite inyectar el criterio de ordenamiento desde afuera.
//
// Lecciones:
//   - Bucle externo: n-1 pasadas
//   - Bucle interno: j < n-1-i (los últimos i elementos ya están ordenados)
//   - intercambiar() recibe punteros (arr+j), no valores *(arr+j)
//   - esMayor/esMenor se pasan sin paréntesis → decaen a dirección
// ============================================================

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

// Tercer argumento: espera la DIRECCIÓN de una función bool(int,int)
// Retorno y tipos de parámetros deben coincidir exactamente.
void ordenarBurbuja(int* arr, int n, bool (*compara)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (compara(*(arr + j), *(arr + j + 1))) {
                intercambiar((arr + j), (arr + j + 1));
            }
        }
    }
}

void imprimirArray_Ej1(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

void ejercicio1() {
    std::cout << "=== Ejercicio 1: Burbuja con comparador inyectado ===" << std::endl;
    int datos1[6] = {5, 2, 9, 1, 7, 3};
    int datos2[6] = {5, 2, 9, 1, 7, 3};

    std::cout << "Original:    ";
    imprimirArray_Ej1(datos1, 6);

    ordenarBurbuja(datos1, 6, esMayor); // Pasa la DIRECCIÓN de esMayor
    std::cout << "Ascendente:  ";
    imprimirArray_Ej1(datos1, 6);

    ordenarBurbuja(datos2, 6, esMenor);
    std::cout << "Descendente: ";
    imprimirArray_Ej1(datos2, 6);
    std::cout << std::endl;
}

// ============================================================
// EJERCICIO 2 — Filtrar Array con Predicado Inyectado
// ------------------------------------------------------------
// Concepto: bool (*pred)(int)
//   Puntero a función de UN argumento → predicado.
//   Un predicado evalúa un elemento y dice si cumple una condición.
//
// Diferencia con Ejercicio 1:
//   Ej1: bool (*compara)(int, int) → compara DOS elementos entre sí
//   Ej2: bool (*pred)(int)         → evalúa UN elemento de forma aislada
//
// Desafíos:
//   - Retornar un array dinámico (new int[...])
//   - Comunicar el tamaño del resultado via int* resultSize
//   - Dos pasadas: 1ra contar, 2da copiar
// ============================================================

bool esPar(int n) {
    // Tu código acá
}

bool esImpar(int n) {
    // Tu código acá
}

bool esPositivo(int n) {
    // Tu código acá
}

// Retorna nuevo array dinámico con elementos que cumplen pred.
// Escribe en *resultSize cuántos elementos tiene el resultado.
// IMPORTANTE: quien llama es responsable de hacer delete[].
int* filtrar(const int* arr, int n, bool (*pred)(int), int* resultSize) {
    // Tu código acá
    // Pista 1ra pasada: contá cuántos elementos cumplen pred(*(arr+i))
    // Pista new:        int* resultado = new int[count];
    // Pista 2da pasada: copiá con un índice escritura separado
    // Pista resultSize: *resultSize = count;
}

void imprimirArray_Ej2(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

void ejercicio2() {
    std::cout << "=== Ejercicio 2: Filtrar con predicado inyectado ===" << std::endl;
    int datos[8] = {3, -1, 4, 0, -7, 2, 9, -3};
    int n = 8;

    std::cout << "Original:  ";
    imprimirArray_Ej2(datos, n);

    int tamPares = 0;
    int* pares = filtrar(datos, n, esPar, &tamPares);
    std::cout << "Pares:     ";
    imprimirArray_Ej2(pares, tamPares);
    delete[] pares;

    int tamPos = 0;
    int* positivos = filtrar(datos, n, esPositivo, &tamPos);
    std::cout << "Positivos: ";
    imprimirArray_Ej2(positivos, tamPos);
    delete[] positivos;
    std::cout << std::endl;
}

// ============================================================
// EJERCICIO 3 — Transformar Array (Map)                [TODO]
// ------------------------------------------------------------
// Concepto: int (*transforma)(int)
//   Puntero a función que transforma un elemento.
//   void mapear(int* arr, int n, int (*transforma)(int))
//   Aplica la transformación sobre cada elemento del array in-place.
//
// Funciones a implementar:
//   - int duplicar(int n)   → retorna n * 2
//   - int cuadrado(int n)   → retorna n * n
//   - int negar(int n)      → retorna -n
// ============================================================

// Tu código acá (Ej 3)

// ============================================================
// EJERCICIO 4 — Tabla de Despacho (Dispatch Table)     [TODO]
// ------------------------------------------------------------
// Concepto: array de punteros a funciones
//   void (*operaciones[4])(int*, int)
//   Permite seleccionar un algoritmo por índice en vez de con if/switch.
//
// Funciones a incluir en la tabla:
//   - imprimirArray, ordenarAsc, ordenarDesc, invertir
// ============================================================

// Tu código acá (Ej 4)

// ============================================================
// main — ejecuta los ejercicios completados
// ============================================================

int main() {
    ejercicio1();
    // ejercicio2();   // Descomentar al completar Ej 2
    // ejercicio3();   // Descomentar al completar Ej 3
    // ejercicio4();   // Descomentar al completar Ej 4
    return 0;
}
