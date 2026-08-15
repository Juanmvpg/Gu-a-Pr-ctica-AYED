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


// ============================================================
// EJERCICIO 5 — Copiar un array
// ------------------------------------------------------------
// Escribí una función copiar() que reciba un array origen y
// un array destino (ya reservado) y copie todos sus elementos.
// Verificá que modificar la copia no afecta al original.
// ============================================================
/*
#include <iostream>
using namespace std;

void copiar(int* origen, int* destino, int n) {
    // tu código acá
    // Pista: recorrés origen con un puntero y escribís en destino.
    // Podés usar un índice, un puntero móvil, o ambos.
}

int main() {
    int original[5] = {10, 20, 30, 40, 50};
    int copia[5];

    copiar(original, copia, 5);

    cout << "Original: ";
    for (int i = 0; i < 5; i++) cout << *(original + i) << " ";
    cout << endl;

    cout << "Copia:    ";
    for (int i = 0; i < 5; i++) cout << *(copia + i) << " ";
    cout << endl;

    // Verificación: modificar la copia no afecta al original
    *(copia + 0) = 99;
    cout << "Original tras modificar copia: " << *(original + 0) << endl;

    // Resultado esperado:
    // Original: 10 20 30 40 50
    // Copia:    10 20 30 40 50
    // Original tras modificar copia: 10

    return 0;
}
*/


// ============================================================
// EJERCICIO 6 — Segundo máximo
// ------------------------------------------------------------
// Escribí una función segundoMax() que devuelva un puntero al
// segundo elemento más grande del array.
// Asumí que el array tiene al menos 2 elementos distintos.
// ============================================================
/*
#include <iostream>
using namespace std;

int* segundoMax(int* arr, int n) {
    // tu código acá
    // Pista: inicializá max y segundoMax con los dos primeros elementos
    // ordenados, y luego recorré desde el tercer elemento en adelante.
}

int main() {
    int datos[7] = {3, 7, 2, 19, 4, 1, 11};

    int* seg = segundoMax(datos, 7);

    cout << "Segundo máximo: " << *seg << endl;
    cout << "En posición:    " << (seg - datos) << endl;

    // Resultado esperado:
    // Segundo máximo: 11
    // En posición:    6

    return 0;
}
*/


// ============================================================
// EJERCICIO 7 — Filtrar pares con memoria dinámica
// ------------------------------------------------------------
// Escribí una función filtrarPares() que reciba un array, su tamaño n,
// y un parámetro por referencia cantPares donde guardará cuántos pares encontró.
// La función debe:
//   1. Contar cuántos elementos pares hay.
//   2. Reservar dinámicamente con new[] un nuevo array de ese tamaño exacto.
//   3. Copiar solo los números pares al nuevo array usando aritmética de punteros.
//   4. Devolver el puntero al nuevo array dinámico.
// No olvides liberar la memoria con delete[] en el main.
// ============================================================
/*
#include <iostream>
using namespace std;

int* filtrarPares(int* arr, int n, int& cantPares) {
    // tu código acá
    // 1. Contar pares
    // 2. new int[cantPares]
    // 3. Copiar pares usando punteros
    // 4. return punteroAlNuevoArray
}

int main() {
    int datos[8] = {3, 8, 2, 15, 4, 7, 10, 1};
    int totalPares = 0;

    int* pares = filtrarPares(datos, 8, totalPares);

    cout << "Cantidad de pares encontrados: " << totalPares << endl;
    cout << "Array dinamico de pares: ";
    for (int i = 0; i < totalPares; i++) {
        cout << *(pares + i) << " ";
    }
    cout << endl;

    // Liberar la memoria dinamica solicitada dentro de la función:
    delete[] pares;
    pares = nullptr;

    // Resultado esperado:
    // Cantidad de pares encontrados: 4
    // Array dinamico de pares: 8 2 4 10

    return 0;
}
*/


// ============================================================
// EJERCICIO 8 — Filtrar mayores al promedio (Memoria Dinámica)
// ------------------------------------------------------------
// Escribí una función filtrarMayoresAlPromedio() que:
//   1. Calcule el promedio de todos los elementos del array (double).
//   2. Cuente cuántos elementos son estrictamente mayores que dicho promedio.
//   3. Si no hay elementos mayores (o cantMayores == 0), retorne nullptr.
//   4. Si hay, reserve memoria dinámica exacta con new int[cantMayores],
//      copie los elementos mayores al promedio y retorne el nuevo array.
// Recordá no usar corchetes [] y devolver la cantidad mediante cantMayores (referencia).
// ============================================================
/*
#include <iostream>
using namespace std;

int* filtrarMayoresAlPromedio(int* arr, int n, int& cantMayores) {
    // tu código acá
}

int main() {
    int datos[6] = {10, 20, 30, 40, 50, 60};
    int cantMayores = 0;

    // Promedio de datos: (10+20+30+40+50+60)/6 = 210/6 = 35.0
    // Mayores a 35: 40, 50, 60 (son 3 elementos)

    int* mayores = filtrarMayoresAlPromedio(datos, 6, cantMayores);

    if (mayores != nullptr) {
        cout << "Cantidad de mayores al promedio: " << cantMayores << endl;
        cout << "Elementos: ";
        for (int i = 0; i < cantMayores; i++) {
            cout << *(mayores + i) << " ";
        }
        cout << endl;

        delete[] mayores;
        mayores = nullptr;
    } else {
        cout << "No hay elementos mayores al promedio." << endl;
    }

    // Resultado esperado:
    // Cantidad de mayores al promedio: 3
    // Elementos: 40 50 60

    return 0;
}
*/


// ============================================================
// EJERCICIO 9 — Intercalar dos arrays ordenados (Merge dinámico)
// ------------------------------------------------------------
// Escribí la función intercalarOrdenados() que reciba dos arrays
// ordenados de menor a mayor ('arr1' de tamaño n1, y 'arr2' de tamaño n2).
// La función debe:
//   1. Reservar con new[] un nuevo array de tamaño (n1 + n2).
//   2. Recorrer ambos arrays simultáneamente usando punteros y copiar
//      los elementos en orden ascendente en una sola pasada.
//   3. Retornar el puntero al nuevo array resultante.
// Regla: No usar corchetes [] y no reordenar después (debe construirse en orden).
// ============================================================
/*
#include <iostream>
using namespace std;

int* intercalarOrdenados(int* arr1, int n1, int* arr2, int n2) {
    // tu código acá
}

int main() {
    int a[4] = {2, 5, 8, 12};
    int b[3] = {1, 7, 10};

    int* resultado = intercalarOrdenados(a, 4, b, 3);

    cout << "Array intercalado y ordenado: ";
    for (int i = 0; i < 7; i++) {
        cout << *(resultado + i) << " ";
    }
    cout << endl;

    delete[] resultado;
    resultado = nullptr;

    // Resultado esperado:
    // Array intercalado y ordenado: 1 2 5 7 8 10 12

    return 0;
}
*/

