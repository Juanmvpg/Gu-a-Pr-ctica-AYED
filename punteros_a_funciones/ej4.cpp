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

#include <iostream>

//invertir el orden
void opInvertir(int* arr, int n) {
    int* arrReturn = arr;
    int* inicio = arrReturn;
    int* final = arrReturn +n -1;
    int aux;
    for(int i=0; i<n/2; i++){
        aux=*(inicio +i);
        *(inicio + i) = *(final - i);
        *(final -i) = aux;
    }
}

void opDuplicarTodos(int* arr, int n) {
    int i=0;
    int* arrReturn = arr;
    while (i<n){
        *(arrReturn+i)=2 * *(arrReturn+i);
        i++;
    }
}

void opOrdenarAsc(int* arr, int n) {
    int aux;
    int* arrReturn = arr;
    for (int i =0; i <n; i++){ //evalua repetir para todos los elementos n
        for(int j=0; j<n-1-i; j++){ //evalua el si es necesario un cambio
            if(*(arrReturn+j)>*(arrReturn+j+1)){
                aux = *(arrReturn + j); //guarda el mayor
                *(arrReturn+j) = *(arrReturn+j +1); // donde estaba el mayor, ahora está el menor
                *(arrReturn+j +1) = aux; //ahora donde estaba el menor, ahora está el mayor
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
    int datos[5] = {5, 1, 4, 2, 8};

    // Declaración de la tabla de despacho (solo nombres de funciones):
    void (*operaciones[3])(int*, int) = {
        opInvertir,
        opDuplicarTodos,
        opOrdenarAsc,
    };

    std::cout << "Original: ";
    imprimirArray(datos, 5);

    // Ejecutar operación 0 (Invertir el orden):
    operaciones[0](datos, 5);
    std::cout << "Invertido: ";
    imprimirArray(datos, 5);

     // Ejecutar operación 0 (Invertir el orden):
    operaciones[1](datos, 5);
    std::cout << "Duplicado: ";
    imprimirArray(datos, 5);

    // Ejecutar operación 2 (Ordenar ascendente):
    operaciones[2](datos, 5);
    std::cout << "Ordenado:  ";
    imprimirArray(datos, 5);

    return 0;
}
