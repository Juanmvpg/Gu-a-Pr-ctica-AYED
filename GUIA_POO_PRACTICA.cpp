// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Programación Orientada a Objetos (Desde Cero)
// ============================================================
// Esta guía complementaria está pensada para que construyas cada 
// clase desde cero, fijando conceptos teóricos y patrones típicos 
// de parciales.
//
// Reglas de Trabajo:
//   - Nada de copiar código resuelto: Leé el enunciado.
//   - Planteá las clases en papel o mentalmente: Pensá qué 
//     atributos son privados y qué métodos públicos necesita.
//   - Iteramos juntos: Extraé el código comentado de cada 
//     ejercicio a un nuevo archivo .cpp, descomentalo y 
//     resolvelo.
// ============================================================


// ============================================================
// EJERCICIO 4 — Sobrecarga de Constructores, Validaciones y Métodos const
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Constructores sobrecargados (por defecto y con parámetros).
// - Métodos `const` (garantizan que no modifican atributos).
// - Validaciones de reglas de negocio en métodos.
//
// Enunciado:
// Crear una clase `BilleteraDigital`:
// 1. Atributos privados: `titular` (string) y `saldo` (double).
// 2. Constructores:
//    - Constructor por defecto: inicializa titular en "Anonimo" y saldo en 0.0.
//    - Constructor con parámetros: recibe titular y saldo inicial.
//      (Si el saldo inicial recibido es negativo, inicializar en 0.0).
// 3. Métodos:
//    - `void depositar(double monto)`: suma al saldo solo si monto > 0.
//    - `bool extraer(double monto)`: si monto > 0 y hay saldo suficiente,
//      descuenta y retorna true. En caso contrario, retorna false.
//    - `double getSaldo() const`: retorna el saldo actual.
//    - `string getTitular() const`: retorna el titular.
// ============================================================
/*
#include <iostream>
#include <string>
using namespace std;

// TODO: Definir la clase BilleteraDigital aquí

int main() {
    cout << "=== EJERCICIO 1: BILLETERA DIGITAL ===" << endl;

    // TODO: Crear billetera, intentar extraer más de lo disponible,
    // depositar dinero válido y verificar saldos por consola.

    return 0;
}
*/


// ============================================================
// EJERCICIO 5 — Composición de Clases ("Tiene-un")
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Composición: una clase contiene instancias de otra clase.
// - Arreglos estáticos de objetos como atributo.
//
// Enunciado:
// 1. Crear clase `Item`:
//    - Atributos privados: `nombre` (string) y `precio` (double).
//    - Constructores: por defecto ("", 0.0) y con parámetros.
//    - Getters `const` para ambos atributos.
// 2. Crear clase `Pedido`:
//    - Atributos privados: `Item items[5]` y `int cantidad` (inicia en 0).
//    - Constructor por defecto: inicializa `cantidad` en 0.
//    - `bool agregarItem(string nombre, double precio)`:
//      Crea un Item en la posición actual si hay lugar, aumenta 
//      cantidad y retorna true. Si está lleno, retorna false.
//    - `double calcularTotal() const`: Devuelve la suma de precios.
//    - `void mostrarResumen() const`: Imprime nombre y precio de cada item.
// ============================================================
/*
#include <iostream>
#include <string>
using namespace std;

// TODO: Definir clase Item

// TODO: Definir clase Pedido

int main() {
    cout << "=== EJERCICIO 2: COMPOSICION DE CLASES ===" << endl;

    // TODO: Crear Pedido, agregar items y mostrar resumen

    return 0;
}
*/


// ============================================================
// EJERCICIO 6 — Memoria Dinámica en Atributos
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Punteros como atributos (arreglo dinámico `int* datos`).
// - Reservar con `new[]` y liberar con `delete[]` obligatoriamente.
//
// Enunciado:
// Crear clase `BolsaNumeros`:
// 1. Atributos privados: `int* datos`, `int capacidad`, `int cantidad`.
// 2. Constructor:
//    - Recibe `int cap`. Si `cap <= 0`, fijar capacidad en 5 por defecto.
//    - Reserva: `datos = new int[capacidad];`, `cantidad = 0;`.
// 3. Destructor:
//    - `delete[] datos;` e imprimir "Memoria liberada".
// 4. Métodos:
//    - `bool insertar(int valor)`: agrega si hay lugar y retorna true.
//    - `void mostrar() const`: imprime elementos.
//    - `double calcularPromedio() const`: retorna el promedio.
// ============================================================
/*
#include <iostream>
using namespace std;

// TODO: Definir clase BolsaNumeros

int main() {
    cout << "=== EJERCICIO 3: BOLSA CON MEMORIA DINAMICA ===" << endl;

    // TODO: Instanciar BolsaNumeros(4), insertar 5 números, 
    // mostrar elementos y verificar destrucción.

    return 0;
}
*/


// ============================================================
// EJERCICIO 7 — Jerarquía Polimórfica con Retorno
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Clase abstracta, métodos virtuales puros (`double`).
// - Arreglo de punteros polimórficos.
//
// Enunciado:
// 1. Clase abstracta `Figura`:
//    - Virtuales puros: `calcularArea() const`, `calcularPerimetro() const`,
//      y `mostrarInfo() const`.
//    - Destructor virtual.
// 2. Clase `Rectangulo` (hereda de Figura):
//    - Base y altura privadas. Sobrescribir los 3 métodos.
// 3. Clase `Circulo` (hereda de Figura):
//    - Radio privado. Sobrescribir los 3 métodos (usar pi=3.14159).
// 4. En main():
//    - Crear `Figura* figuras[3];`. 
//    - Asignar dinámicamente (`new`) Rectángulos y Círculos.
//    - Bucle para mostrarInfo() y acumular el área total.
//    - Imprimir área total y liberar con `delete` cada figura.
// ============================================================
/*
#include <iostream>
using namespace std;

// TODO: Definir clase abstracta Figura

// TODO: Definir clase Rectangulo

// TODO: Definir clase Circulo

int main() {
    cout << "=== EJERCICIO 4: POLIMORFISMO DE FIGURAS ===" << endl;

    // TODO: Crear arreglo de punteros, recorrer, sumar áreas y hacer delete

    return 0;
}
*/
