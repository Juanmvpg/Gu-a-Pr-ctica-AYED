// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Unidad 3 - Estructuras Lineales (Listas Enlazadas)
// ============================================================
// En esta guía abandonamos la memoria contigua (Arreglos).
// Deberás construir las estructuras base desde cero, gestionando
// los punteros manualmente para lograr el dinamismo absoluto.
// ============================================================

/*
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
// ============================================================
*/

/*
// ============================================================
// EJERCICIO 2 — ABSTRACCIÓN: LA CLASE LISTA 
// ============================================================
// Objetivo: Encapsular el comportamiento caótico de los nodos dentro
// de una clase controladora, aislando al usuario de la lógica de punteros.
//
// Consigna:
// 1. Reutilizá tu `Nodo` del ejercicio anterior.
// 2. Diseñá una clase `Lista`. ¿Qué atributo fundamental necesita la lista 
//    para no "perder" a sus nodos? (Pista: con conocer a uno solo basta).
// 3. Implementá un método `agregarAlFinal(int valor)`. Pensá cuidadosamente:
//    - ¿Qué pasa si la lista está completamente vacía al agregar?
//    - ¿Qué pasa si ya tiene elementos? ¿Cómo llegás al final para enganchar 
//      el nuevo nodo?
// 4. Implementá un método `mostrar() const` que recorra e imprima los valores.
// 5. (Desafío) Implementá un método `agregarAlPrincipio(int valor)`.
// ============================================================
*/

/*
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
// ============================================================
*/

/*
// ============================================================
// EJERCICIO 4 — CIRUGÍA DE NODOS (Borrado en las puntas)
// ============================================================
// Objetivo: Aprender a desconectar nodos específicos sin romper el tren.
//
// Consigna:
// 1. Copiá tu clase Lista.
// 2. Implementá `void eliminarPrimero()`: Desconecta la cabeza actual y 
//    hace que la nueva cabeza sea el segundo vagón. ¡No olvides hacer delete!
// 3. Implementá `void eliminarUltimo()`: Usá un bucle para viajar hasta 
//    el *anteúltimo* nodo. Desconectá al último y hacé el delete.
//    (Ojo con el caso en que la lista tenga 1 solo elemento).
// ============================================================
*/

/*
// ============================================================
// EJERCICIO 5 — UTILIDADES Y ESCALABILIDAD
// ============================================================
// Objetivo: Implementar métodos clásicos de manejo de colecciones.
//
// Consigna:
// 1. Implementá `int size()`: Recorre la lista y retorna la cantidad de nodos.
// 2. Implementá `void concat(Lista* l1)`: Recibe un puntero a OTRA lista, viaja 
//    hasta el final de la lista actual, y engancha la cabeza de l1.
// 3. Implementá `void vaciar()`: Reutiliza el código de limpieza.
// ============================================================
*/

/*
// ============================================================
// EJERCICIO 6 — RECURSIVIDAD EN LISTAS
// ============================================================
// Objetivo: Abandonar los bucles `while` y usar el poder de la recursión.
//
// Consigna:
// 1. Implementá un método que imprima la lista usando recursividad.
// 2. Implementá `int sumaRecursiva()` que sume los datos de todos los nodos.
// ============================================================
*/
