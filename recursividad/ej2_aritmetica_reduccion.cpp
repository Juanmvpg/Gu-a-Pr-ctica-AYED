// ============================================================
// EJERCICIO 2 — Aritmética y Reducción: Suma, Multiplicación y Tail Recursion
// ============================================================
// Enunciado (Ejercicios oficiales de cátedra):
//
// 1. int multi(int a, int b):
//    Multiplica 'a * b' usando sumas recursivas.
//    (Manejar casos: b == 0 -> 0; b > 0 -> a + multi(a, b - 1)).
//
// 2. int sumaNoTail(const int* arr, int n):
//    Suma los elementos de un array con recursión tradicional (vuelta).
//    - Caso base: si n == 0 retorna 0.
//    - Caso recursivo: *(arr + n - 1) + sumaNoTail(arr, n - 1).
//
// 3. int sumaTail(const int* arr, int n, int acumulador = 0):
//    Misma suma pero transformada a Tail Recursion (acumulador a la ida).
//
// 4. int potencia(int base, int exp):
//    Calcula base^exp usando multiplicaciones recursivas (exp >= 0).
//
// 5. int contarOcurrencias(const int* arr, int n, int buscado):
//    Cuenta cuántas veces aparece un número 'buscado' en el array de forma recursiva.
// ============================================================

#include <iostream>

// 1. Multiplicación recursiva por sumas sucesivas
int multi(int a, int b) {
    if(b==0){
        return 0;
    }else{
        return a + multi(a, b-1);
    }
    return a;
}

// 2. Suma recursiva tradicional (No-Tail)
int sumaNoTail(const int* arr, int n) {
    if(n==0){
        return 0;
    }else{
        return *(arr +n -1) + sumaNoTail(arr, n-1);
    }
}

// 3. Suma recursiva de cola (Tail Recursion)
int sumaTail(const int* arr, int n, int acumulador = 0) {
    if(n==0){
        return acumulador;
    }else {
        acumulador = acumulador + *arr;
        return sumaTail((arr + 1), n-1, acumulador);
    }
}

// 4. Potencia recursiva: base^exp
int potencia(int base, int exp) {
    if(exp == 1){
        return base;
    }else{
        return (base*potencia(base, exp-1));
    }
}

// 5. Contar ocurrencias recursivo
int contarOcurrencias(const int* arr, int n, int buscado) {
    if(n==0){
        return 0;
    }else{
        return (*arr == buscado) + contarOcurrencias(arr+1, n-1, buscado);
    }
}

int main() {
    int v[11] = {4, 2, 6, 1,2,2,2, -3, 2, 5, 1};
    int n = 11;

    std::cout << "=== EJERCICIO 2: ARITMETICA Y REDUCCION RECURSIVA ===" << std::endl;

    std::cout << "Multiplicacion 6 * 7:  " << multi(6, 7) << std::endl;
    std::cout << "Suma No-Tail:          " << sumaNoTail(v, n) << std::endl;
    std::cout << "Suma Tail:             " << sumaTail(v, n) << std::endl;
    std::cout << "Potencia 2^5:          " << potencia(2, 5) << std::endl;
    std::cout << "Veces que aparece el 2: " << contarOcurrencias(v, n, 2) << std::endl;

    // Resultado esperado:
    // === EJERCICIO 2: ARITMETICA Y REDUCCION RECURSIVA ===
    // Multiplicacion 6 * 7:  42
    // Suma No-Tail:          20
    // Suma Tail:             20
    // Potencia 2^5:          32
    // Veces que aparece el 2: 3

    return 0;
}
