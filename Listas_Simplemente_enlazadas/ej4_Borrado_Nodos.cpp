// ============================================================
// EJERCICIO 4 — CIRUGÍA DE NODOS (Borrado en las puntas)
// ============================================================
// Objetivo: Aprender a desconectar nodos específicos sin romper el tren.
//
// Consigna:
// 1. Copiá tu clase Lista (con el Nodo).
// 2. Implementá `void eliminarPrimero()`: Desconecta la cabeza actual y 
//    hace que la nueva cabeza sea el segundo vagón. ¡No olvides hacer delete!
// 3. Implementá `void eliminarUltimo()`: Usá un bucle para viajar hasta 
//    el *anteúltimo* nodo. Desconectá al último y hacé el delete.
//    (Ojo con el caso en que la lista tenga 1 solo elemento).

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
            cabeza = nuevoNodo;
        }else{
            Nodo* aux =cabeza;
            while(aux->nodoSig != nullptr){
                aux=aux->nodoSig;
            }
            aux->nodoSig =nuevoNodo;
        }
    }

    void mostrar() const {
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

    void eliminarPrimero(){
        Nodo* aux = cabeza;
        if(cabeza==nullptr){
            return;
        }
        cabeza = cabeza->nodoSig;
        delete aux;
        
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
};

int main() {
    
    // Probá acá tus métodos creando una lista, borrando de las puntas y mostrando
    Lista miTren;
    std::cout<<"Nodo al final"<<std::endl;
    miTren.agregarAlFinal(11);
    miTren.agregarAlFinal(12);
    miTren.agregarAlFinal(13);
    miTren.agregarAlFinal(14);

    miTren.mostrar();
    miTren.eliminarPrimero();
    std::cout<<"Borrado el primero: "<<std::endl;
    miTren.mostrar();

    miTren.eliminarUltimo();
    std::cout<<"Borrado el ultimo: "<<std::endl;
    miTren.mostrar();

    Lista miTrenCorto;
    miTrenCorto.agregarAlFinal(1);
    miTrenCorto.eliminarUltimo();
    miTrenCorto.eliminarUltimo();
    miTrenCorto.mostrar();

    Lista trenFantasma;
    trenFantasma.eliminarPrimero();
    trenFantasma.eliminarUltimo();
    return 0;
}
