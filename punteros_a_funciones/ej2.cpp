// ============================================================
// Ejercicio 2 — Filtrar array con predicado inyectado
// ============================================================
// Concepto nuevo: puntero a función con UN solo argumento
//   bool (*predicado)(int)   → recibe un int, devuelve bool
//
// Diferencia con el ejercicio anterior:
//   Antes:  bool (*compara)(int, int)  → dos argumentos (comparador)
//   Ahora:  bool (*pred)(int)          → un argumento  (predicado)
//
// Un predicado es una función que "evalúa" un elemento y dice
// si cumple o no una condición.
// ============================================================

#include <iostream>

// ============================================================
// Predicados disponibles para inyectar
// ============================================================

bool esPar(int n) {
    return (n%2==0);
}

bool esImpar(int n) {
    return (n%2!=0);
}

bool esPositivo(int n) {
    return (n>0);
}

// ============================================================
// Función principal del ejercicio
//
// Recibe un array de entrada, su tamaño, y un predicado.
// Devuelve un NUEVO array dinámico con solo los elementos
// que cumplen el predicado, y escribe en *resultSize cuántos son.
//
// Pista: necesitás dos pasadas sobre el array de entrada:
//   1ra pasada: contá cuántos elementos cumplen el predicado (para hacer new)
//   2da pasada: copiá esos elementos al nuevo array
// ============================================================

//Retorna memoria dinámica, no olvidar el delete[]
int* filtrar(const int* arr, int n, bool (*pred)(int), int* resultSize) {//frst arg permite solo lectura, no se modifica

    int cont=0;
    for(int i=0; i<n;i++){
        if(pred(*(arr+i))){
            ++cont;
        }
    }
    int* arrFilter = new int [cont];
    *resultSize = cont;
    int j=0;
    for(int i=0; i<n; i++){
        if(pred(*(arr+i))){
            *(arrFilter + j) = *(arr+i);
            j++;
        }
    }
    return arrFilter;
}

// ============================================================
// Utilidad
// ============================================================

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
    int datos[8] = {3, -1, 4, 0, -7, 2, 9, -3};
    int n = 8;

    std::cout << "Original: ";
    imprimirArray(datos, n);

    int tamPares = 0;
    int* pares = filtrar(datos, n, esPar, &tamPares);
    std::cout << "Pares:     ";
    imprimirArray(pares, tamPares);
    delete[] pares;

    int tamPos = 0;
    int* positivos = filtrar(datos, n, esPositivo, &tamPos);
    std::cout << "Positivos: ";
    imprimirArray(positivos, tamPos);
    delete[] positivos;

    return 0;
}
