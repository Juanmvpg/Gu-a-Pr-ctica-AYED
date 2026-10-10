// ============================================================
// EJERCICIO 3 — EL DESTRUCTOR DE CADENAS (Memoria Dinámica)
// ============================================================
// Objetivo: Entender que el `delete` sobre el puntero inicial no borra 
// al resto de los elementos de la cadena.
//
// Consigna:
// 1. Tomá tu clase `Lista` del Ejercicio 2.
// 2. Si el programa termina, todos esos Nodos que creaste con `new` quedan
//    flotando en la memoria como basura.
// 3. Implementá el Destructor `~Lista()`. 
//    - Pensá bien la lógica: no podés simplemente borrar el primer nodo y 
//      pasar al siguiente... porque si borrás el primero, ¡perdiste la 
//      dirección de dónde estaba el segundo!
//    - Necesitarás punteros auxiliares para ir borrando de a uno sin perder
//      el rastro del resto de la cadena.

#include <iostream>

// ~Lista(){
//         while(cabeza != nullptr){
//             Nodo* aux = cabeza;
//             cabeza=cabeza->nodoSig;
//             delete aux;
//         }
//     }
//solucionado en ejercicio 2
class
int main(){



    return 0;
}