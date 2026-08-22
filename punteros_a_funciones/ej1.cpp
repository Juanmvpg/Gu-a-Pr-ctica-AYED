#include <iostream>

// ============================================================
// GUÍA — Punteros a Funciones y Callbacks
// ------------------------------------------------------------
// EJERCICIO 1 — Ordenamiento con Comparador Inyectado
//
// 1. Implementá dos funciones de comparación:
//    - bool esMayor(int a, int b): retorna true si a > b.
//    - bool esMenor(int a, int b): retorna true si a < b.
//
// 2. Implementá la función de ordenamiento:
//    void ordenarBurbuja(int* arr, int n, bool (*compara)(int, int));
//    - Debe recorrer el array comparando elementos adyacentes usando:
//      if (compara(*(arr + j), *(arr + j + 1))) -> intercambiar
//
// 3. En el main():
//    - Usar std::cout y std::endl (sin using namespace std).
//    - Probar ordenando un array de forma ascendente con esMayor.
//    - Probar ordenando otro array de forma descendente con esMenor.
// ============================================================

bool esMayor(int a, int b) {
    if (a> b) return true;
    return false;
}

bool esMenor(int a, int b) {
    if (a>b) return false;
    return true;
}

void intercambiar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ordenarBurbuja(int* arr, int n, bool (*compara)(int, int)) { //el tercer argumento espera una DIRECCIÓN de una función con esa firma, cuales son esMenor y esMayor
    // Tu código acá
    // Bucle anidado clásico de burbuja usando aritmética de punteros
    for(int i=0; i<n-1;i++){ //bucle que recorre el array
        for(int j=0; j<n-1-i; j++){//es i2 porque los ultimos elementos se quedan ordenados, no hace falta volver a compararlos. Es -2 porque
            if(compara(*(arr +j), *(arr + j+1))){
                intercambiar((arr +j), (arr + j+1));
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

    std::cout << "Original: ";
    imprimirArray(datos1, 6);

    // Ordenamiento Ascendente:
    ordenarBurbuja(datos1, 6, esMayor); //esMayor es la firma, es un bool de argumentos int. Ambos deben coincidir para ser compatibles
    std::cout << "Ascendente: ";
    imprimirArray(datos1, 6);

    // Ordenamiento Descendente:
    ordenarBurbuja(datos2, 6, esMenor);
    std::cout << "Descendente: ";
    imprimirArray(datos2, 6);

    return 0;
}
