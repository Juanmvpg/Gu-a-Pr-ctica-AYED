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

#include <iostream>

int duplicar(int n) {
    return n*2;
}

int cuadrado(int n) {
    return n*n;
}

int negar(int n) {
    return n*(-1);
}
//feedback arqui. soft; In-Place(mutación): mute al array original. Ventaba en bajo nivel, pero se pierde el array original. ALternativa inmutable es generar un array en heap y declarar el argumento como const int* arr de la función mapear.
void mapear(int* arr, int n, int (*transforma)(int)) { //aplica los elementos de un array en una función del tipo int que retorna int.
    for(int i=0; i<n;i++){
        *(arr +i)=transforma (*(arr+i));
    }
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