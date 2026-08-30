// ============================================================
// EJERCICIO 1 — Impresión Recursiva: Ida vs Vuelta
// ============================================================
// Enunciado (Basado en 07_Recursion_Introduccion de la cátedra):
//
// Implementar dos funciones de impresión recursiva de un array de enteros:
//   1. void imprimirDirecto(const int* arr, int n):
//      Imprime los elementos de izquierda a derecha (0 a n-1).
//   2. void imprimirInverso(const int* arr, int n):
//      Imprime los elementos de derecha a izquierda (n-1 a 0).
//
// Regla:
//   - Cero bucles (prohibido 'for', 'while', 'do-while').
//   - Solo llamadas recursivas y aritmética de punteros.
// ============================================================

#include <iostream>

// 1. Imprime de izquierda a derecha
void imprimirDirecto(const int* arr, int n) {
    // Pista:
    // Si n == 0, terminamos (caso base).
    // Si no, imprimimos el primer elemento *(arr) y llamamos a imprimirDirecto(arr + 1, n - 1).
    // O bien, llamamos primero a la recursión y luego imprimimos a la vuelta.
    if (n==0){
        //std::cout<<"";
        return; //ambos igual de validos
    }else{
        std::cout<<*arr<<" ";
        imprimirDirecto((arr +1),n-1);//tail recursion aplicada
        //el return es completamente innecesario
    }
}

// 2. Imprime de derecha a izquierda
void imprimirInverso(const int* arr, int n) {
        if(n==0){
            // std::cout<< "";
            return; //ambos igual de válidos
        }else{
            std::cout<< *(arr + n-1)<<" ";
            imprimirInverso((arr), n-1);
        }

    
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
