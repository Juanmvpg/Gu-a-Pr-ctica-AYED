// ============================================================
// EJERCICIO 3 — Nivel Avanzado: La Flota
// ============================================================
// Conceptos a evaluar: Clases base, métodos virtuales, herencia, polimorfismo.
//
// Enunciado:
// 1. Crear una clase base abstracta llamada `Vehiculo` con un método virtual puro 
//    llamado `acelerar()` (ej: virtual void acelerar() = 0;). 
//    Agregale un destructor virtual (virtual ~Vehiculo() {}).
// 2. Crear dos clases derivadas: `Auto` y `Bicicleta` que hereden de `Vehiculo`.
// 3. Cada clase derivada debe implementar su propia versión de `acelerar()` 
//    (ej: el Auto imprime "Brum brum..." y la Bicicleta imprime "Pedaleando...").
// 4. En el main(), crear un arreglo estático de 2 punteros a Vehiculo: `Vehiculo* flota[2];`
// 5. Asignar al primer elemento un `new Auto()` y al segundo un `new Bicicleta()`.
// 6. Hacer un bucle for que recorra la flota y llame a `acelerar()` sobre cada puntero. 
//    Al final, no te olvides de liberar cada puntero con `delete`.
// ============================================================

#include <iostream>

using namespace std;

// TODO: Definir la clase base Vehiculo aquí


// TODO: Definir las clases derivadas Auto y Bicicleta aquí


int main() {
    cout << "=== EJERCICIO 3: LA FLOTA ===" << endl;
    
    // TODO: Crear arreglo de punteros, instanciar dinámicamente, recorrer e iterar, liberar memoria.
    
    return 0;
}
