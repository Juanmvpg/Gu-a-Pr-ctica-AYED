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

