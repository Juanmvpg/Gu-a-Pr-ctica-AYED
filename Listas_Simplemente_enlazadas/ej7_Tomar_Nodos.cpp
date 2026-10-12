// ============================================================
// EJERCICIO 7 — TOMAR NODOS (Truncamiento de Lista)
// ============================================================
// Objetivo: Implementar una operación avanzada que modifica la
// estructura original preservando solo una cantidad específica de nodos.
//
// Consigna:
// 1. Copiá tu clase Lista.
// 2. Implementá el método `void tomar(int n)`. Este método debe dejar
//    "vivos" únicamente los primeros `n` nodos de la lista, y borrar 
//    todo el resto hacia atrás.
// 3. Pista: Es ideal resolverlo combinando la función `size()`, la función
//    `eliminarUltimo()` y la recursividad. 

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

    void eliminarUltimo(){
        Nodo* aux = cabeza;
        if(cabeza== nullptr){
            return;
        }else if(cabeza ->nodoSig == nullptr){
            delete cabeza;
            cabeza=nullptr;
        }else{
            while(aux->nodoSig->nodoSig != nullptr){ //aux->nodoSig hace que nos paremos en el anteultimo
                aux = aux->nodoSig;
            }
        Nodo* aBorrar = aux->nodoSig; //nos paramos en el anteultimo, copiamos su dirección
        aux->nodoSig =nullptr; //le decimos al anteultimo que será el ultimo
        delete aBorrar; 
        }            
        
    }

    void tomar(int n){
    if(size() > n){
        eliminarUltimo();
        tomar(n);
    }
        return;
    }
};


int main() {
    Lista miTren;
    miTren.agregarAlFinal(10);
    miTren.agregarAlFinal(11);
    miTren.agregarAlFinal(12);
    miTren.agregarAlFinal(13);

    miTren.mostrar();

    std::cout<<std::endl<<"Filtrado"<<std::endl;
    miTren.tomar(0);
    miTren.mostrar();
    
    return 0;
}
