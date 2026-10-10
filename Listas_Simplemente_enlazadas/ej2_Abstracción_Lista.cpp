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

#include <iostream>

class Nodo{

public:
    int dato;
    Nodo* nodoSig;

    Nodo(int datoNodo){
        dato = datoNodo;
        nodoSig=nullptr;
    }
};

class Lista{
    Nodo* cabeza;
public:
    Lista(){ //La lista nace vacía        
        cabeza=nullptr;
    }

    void agregarAlFinal(int valor){ //no se agregan al principio porque altera quién es la cabeza
        Nodo* nuevoNodo = new Nodo(valor);
        if(cabeza== nullptr){ //
            cabeza = nuevoNodo;
        }else{
            Nodo* aux = cabeza;
            while(aux->nodoSig != nullptr){ //mientras no esté en el ultimo elemento
                aux=aux->nodoSig;
            }        
            aux->nodoSig=nuevoNodo;
        }
    }

    void mostrar() const{
        Nodo* aux = cabeza;
        int i = 0;
        while(aux != nullptr){
            std::cout<<"Valor de Nodo "<<i<<": "<<aux->dato<<std::endl;
            aux = aux->nodoSig;
            i++;
        }
    }

    ~Lista(){
        while(cabeza != nullptr){
            Nodo* aux = cabeza;
            cabeza=cabeza->nodoSig;
            delete aux;
        }
    }

    void agregarAlPrincipio(int valor){
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->nodoSig = cabeza;
        cabeza = nuevoNodo;
    }
};

int main(){
    Lista miTren;
    std::cout<<"Nodo al final"<<std::endl;
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(12);
    miTren.agregarAlFinal(13);
    miTren.agregarAlFinal(14);

    miTren.mostrar();

    std::cout<<"Nodo al Inicio"<<std::endl;
    Lista miTren2;
    miTren2.agregarAlPrincipio(21);
    miTren2.agregarAlPrincipio(22);
    miTren2.agregarAlPrincipio(23);
    miTren2.agregarAlPrincipio(24);

    miTren2.mostrar();


    return 0;
}