// ============================================================
// EJERCICIO 6 — RECURSIVIDAD EN LISTAS
// ============================================================
// Objetivo: Abandonar los bucles `while` y usar el poder de la recursión.
//
// Consigna:
// 1. Copiá tu clase Lista.
// 2. Implementá un método que imprima la lista usando recursividad.
// 3. Implementá `int sumaRecursiva()` que sume los datos de todos los nodos.

#include <iostream>

// Pegá tu clase Lista acá abajo y empezá a programar los métodos

class Nodo{
public:
    int dato;
    Nodo* nodoSig;
    
    Nodo(int datoNodo){
        dato=datoNodo;
        nodoSig=nullptr;
    }
};

class Lista{
    Nodo* cabeza;
public:
    Lista(){
        cabeza=nullptr;
    }

     void agregarAlFinal(int valor){
        Nodo* nuevoNodo = new Nodo(valor);
        if(cabeza==nullptr){
            cabeza=nuevoNodo;
        }else{
            Nodo* aux = cabeza;
            while(aux->nodoSig != nullptr){
                aux=aux->nodoSig;
            }
            aux->nodoSig=nuevoNodo;
        }

    }

    void mostrar(){
        Nodo* aux = cabeza;
        while(aux != nullptr){
            std::cout<<aux->dato<<std::endl;
            aux=aux->nodoSig;
        }
    }

    Nodo* getCabeza(){
        return cabeza;
    }
    void MostrarxRecursividad(Nodo* aux){ //recursividad es un reemplazo al while
        if(aux==nullptr){
            return;
        }else{
            std::cout<<aux->dato<<std::endl;
            aux = aux->nodoSig;
            MostrarxRecursividad(aux);
        }
    }

    int size(){
        Nodo* aux = cabeza;
        int i=0;
        while(aux != nullptr){
            i++;
            aux=aux->nodoSig;
        }
        
        return i;
    }

   ~Lista(){
        while(cabeza != nullptr){
            Nodo* aux = cabeza;
            cabeza=cabeza->nodoSig;
            delete aux;
        }
    }

    void concat(Lista* l1){
        if(cabeza==nullptr){
            cabeza= l1->cabeza; // la nueva cabeza es directamente l1
        }else{
            Nodo* aux = cabeza;
            while(aux->nodoSig != nullptr){
                aux= aux->nodoSig;
            }
            aux->nodoSig= l1->cabeza;
        }
        l1->cabeza=nullptr;
    }

    int sumaRecursiva(Nodo* aux){
        
        if(aux==nullptr){
            return 0;
        }else{
            return aux->dato + sumaRecursiva(aux->nodoSig);

        }
    }
};

int main() {
        Lista miTren;
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(20);
    miTren.agregarAlFinal(30);

    std::cout << "Imprimiendo de forma recursiva:" << std::endl;
    miTren.MostrarxRecursividad(miTren.getCabeza()); // ¡Acá se usa el getter!

    std::cout << "La suma de todos los vagones es: " 
              << miTren.sumaRecursiva(miTren.getCabeza()) 
              << std::endl
              << miTren.getCabeza()->dato; //para corroborar no se reescriba el dato
    
    return 0;
}
