// ============================================================
// EJERCICIO 5 — UTILIDADES Y ESCALABILIDAD
// ============================================================
// Objetivo: Implementar métodos clásicos de manejo de colecciones.
//
// Consigna:
// 1. Copiá tu clase Lista.
// 2. Implementá `int size()`: Recorre la lista y retorna la cantidad de nodos.
// 3. Implementá `void concat(Lista* l1)`: Recibe un puntero a OTRA lista, viaja 
//    hasta el final de la lista actual, y engancha la cabeza de l1.

#include <iostream>

// Pegá tu clase Lista acá abajo y empezá a programar los métodos
class Nodo{
public:
    int dato;
    Nodo* nodoSig;

    Nodo(int valor){
        dato=valor;
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
    }

};

int main() {
    
    Lista miTren;
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(10);

    Lista miTren2;
    miTren2.agregarAlFinal(12);
    miTren2.agregarAlFinal(12);

    miTren.mostrar();
    std::cout<<"El tamanio es: "<<miTren.size()<<std::endl;

    miTren.concat(&miTren2);
    miTren.mostrar();
    return 0;
}
