// ============================================================
// EJERCICIO 1 — EL NODO SOLITARIO (Estructura y Enlace Manual)
// ============================================================
// Objetivo: Comprender la naturaleza autorreferencial de un Nodo y el
// encadenamiento manual de direcciones de memoria.
//
// Consigna:
// 1. Diseñá una clase o struct `Nodo` que almacene un número entero (Dato).
// 2. Agregale el atributo fundamental que le permita conocer quién es el
//    "siguiente" de su misma especie.
// 3. En el `main()`, sin crear una clase Lista, creá dinámicamente (`new`)
//    tres nodos separados.
// 4. Enlazalos manualmente asignando los punteros correspondientes de forma
//    tal que formen una cadena: (Nodo 1 -> Nodo 2 -> Nodo 3 -> nullptr).
// 5. Creá un puntero "cabeza" que apunte al primero, y utilizá un bucle `while`
//    para recorrerlos desde la cabeza, imprimiendo el número de cada uno hasta
//    detectar el final del camino.
// 6. ¡No te olvides de destruir todo lo que creaste!

#include <iostream>

class Nodo {
public:
  int Dato;
  Nodo *NodoSig;
  Nodo(int datoNodo) {
    Dato = datoNodo;
    NodoSig = nullptr;
  }
};

int main() {

  Nodo *n1 = new Nodo(10);
  Nodo *n2 = new Nodo(11);
  Nodo *n3 = new Nodo(12);

  n1->NodoSig = n2;
  n2->NodoSig = n3;

  Nodo *cabeza = n1;
  while (cabeza != nullptr) {
    std::cout << cabeza->Dato << std::endl;
    cabeza = cabeza->NodoSig;
  }
  delete n1;
  delete n2;
  delete n3;
  return 0;
}