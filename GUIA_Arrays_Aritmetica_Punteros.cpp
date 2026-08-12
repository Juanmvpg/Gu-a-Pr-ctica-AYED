// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Arrays y Aritmética de Punteros
// ============================================================
// Regla general de todos los ejercicios:
//   - No usar corchetes [] dentro de las funciones pedidas.
//   - Solo aritmética de punteros: *(arr + i), ptr++, ptr--, etc.
// ============================================================


// ============================================================
// EJERCICIO 1 — Suma de elementos
// ------------------------------------------------------------
// Escribí una función sumar() que calcule la suma de todos los
// elementos de un array sin usar corchetes [].
// ============================================================
/*
#include <iostream>
using namespace std;

int sumar(int* arr, int n) {
    // tu código acá
}

int main() {
    int datos[6] = {3, 7, 2, 9, 4, 1};

    cout << "Suma: " << sumar(datos, 6) << endl;
    // Resultado esperado: 26

    return 0;
}
*/


// ============================================================
// EJERCICIO 2 — Invertir un array en el lugar
// ------------------------------------------------------------
// Escribí una función invertir() que invierta el array original
// sin crear uno nuevo. Usá dos punteros: uno desde el inicio
// y otro desde el final, acercándose al centro.
// ============================================================
/*
#include <iostream>
using namespace std;

void invertir(int* arr, int n) {
    // tu código acá
    // Pista: dos punteros + variable auxiliar para el swap
}

int main() {
    int datos[6] = {3, 7, 2, 9, 4, 1};

    invertir(datos, 6);

    for (int i = 0; i < 6; i++) {
        cout << *(datos + i) << " ";
    }
    cout << endl;
    // Resultado esperado: 1 4 9 2 7 3

    return 0;
}
*/


// ============================================================
// EJERCICIO 3 — Encontrar el máximo
// ------------------------------------------------------------
// Escribí una función buscarMax() que devuelva un PUNTERO
// al elemento más grande del array.
// La resta (pMax - datos) da la posición en el array.
// ============================================================
/*
#include <iostream>
using namespace std;

int* buscarMax(int* arr, int n) {
    // tu código acá
    // Pista: un puntero "campeón" que se actualiza cuando
    // encontrás un elemento mayor al actual campeón.
}

int main() {
    int datos[7] = {3, 7, 2, 19, 4, 1, 11};

    int* pMax = buscarMax(datos, 7);

    cout << "Valor máximo: "      << *pMax          << endl;
    cout << "Posición en memoria: " << pMax          << endl;
    cout << "Posición en el array: " << (pMax - datos) << endl;
    // Resultado esperado:
    // Valor máximo: 19
    // Posición en el array: 3

    return 0;
}
*/


// ============================================================
// EJERCICIO 4 — Buscar un valor
// ------------------------------------------------------------
// Escribí una función buscar() que devuelva un puntero al
// primer elemento que coincida con el valor buscado.
// Si no existe, devolvé nullptr.
// ============================================================
/*
#include <iostream>
using namespace std;

int* buscar(int* arr, int n, int valor) {
    // tu código acá
    // Pista: recorrés el array; si *p == valor, retornás p.
    // Si terminás sin encontrarlo, retornás nullptr.
}

int main() {
    int datos[7] = {3, 7, 2, 19, 4, 1, 11};

    int* resultado = buscar(datos, 7, 19);
    if (resultado != nullptr) {
        cout << "Encontrado: " << *resultado << endl;
        cout << "En posición: " << (resultado - datos) << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    int* resultado2 = buscar(datos, 7, 99);
    if (resultado2 != nullptr) {
        cout << "Encontrado: " << *resultado2 << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    // Resultado esperado:
    // Encontrado: 19
    // En posición: 3
    // No encontrado

    return 0;
}
*/
