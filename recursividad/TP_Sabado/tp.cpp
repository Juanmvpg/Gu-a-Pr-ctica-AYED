/* estructurado limpio de arriba a abajo
Enumeraciones y Constantes (NivelServicio, EstadoEnvio).
Entidad Movimiento y su lista doble (Historial).
Entidad Envio.
Lista simple de prioridad (ListaPendientes).
Colección maestra / Administrador (HubFlow o CentroDistribucion).
Función recursiva por zona.
Menú y casos de prueba en main().
*/

#include <iostream>
#include <string> 

//== ENUMERACIONES (es incorrecto decir que son clases): catálogos de opciones posibles
//atributos de cualquier paquete
enum class NivelServicio{
    EXPRESS,
    PRIORITARIO,
    ESTANDAR
};

enum class EstadoEnvio{
    RECIBIDO,
    CLASIFICADO,
    EN_REPARTO,
    REPROGRAMADO,
    ENTREGADO
};

class Movimiento{
private:    
    int numero;
    EstadoEnvio estado;
    std::string observacion;

public:
    Movimiento(int num, EstadoEnvio est, const std::string& obs) //definimos un "atributo" de la logística de envio
        :numero(num), estado(est), observacion(obs){}

    int getNumero() const {return numero; }
    EstadoEnvio getEstado() const {return estado;}
    const std::string& getObservacion() const {return observacion;}

};

class NodoDoble{ //para historial, permite consultar el historial de cualquier envio (desde el movimiento mas antiguo al mas reciente)
public:
    Movimiento dato;
    NodoDoble* next;
    NodoDoble* prev;

    //constructor para que next y prev nazcan en nullptr
    NodoDoble(const Movimiento& m): dato(m), next(nullptr), prev(nullptr) {}
};

class Historial{// lista doblemente enlazada. Recorrido inverso usará enlaces anteriores de la lista doble, y no se permite copiar previamente los movimientos a otra estructura para invertir el recorrido

private:
    NodoDoble* cabeza; //apunta primer movimiento en el tiempo
    NodoDoble* cola; //apunta al ultimo movimiento registrado

//constructor 
public:
    Historial(): cabeza(nullptr), cola(nullptr){}

    ~Historial(){ // cuando Envio se destruye se debe borrar todos sus NodoDoble del heap para evitar fugas
        NodoDoble* actual = cabeza;
        while(actual != nullptr){
            NodoDoble* siguiente = actual ->next;
            delete actual;
            actual = siguiente;
        }
    }
    void agregar(const Movimiento& m){
        NodoDoble* nuevo = new NodoDoble(m);

        //caso1: lista estaba vacía
        if(cabeza==nullptr){
            cabeza=nuevo;
            cola=nuevo; 

        }else{
            cola->next = nuevo;// el que era ultimo ahora apunta al nuevo
            nuevo->prev = cola; //El nuevo apunta hacia atrás al viejo ultimo
            cola=nuevo;//el ahora "nuevo" es la nueva cola
        }


    }

    void mostrarAdelante() const{
        NodoDoble* actual=cabeza;
        while(actual != nullptr){
            std::cout << actual->dato.getNumero() << " | " << actual->dato.getObservacion() << std::endl;
            actual= actual-> next; //avanza hacia delante
        }
    }

    void mostrarAtras() const {
        NodoDoble* actual = cola;
        while (actual != nullptr) {
            std::cout << actual->dato.getNumero() << " | " << actual->dato.getObservacion() << std::endl;
            actual = actual->prev; // Retrocede hacia atrás
        }
    }

};
//1
class Envio {// representa cada paquete individual
    // TODO:
};


//2
class NodoSimple {
public:
    // TODO:
    // - Envio* dato;        (puntero al envío real, sin adueñarse de él)
    // - NodoSimple* sig;    (enlace al siguiente nodo de la cola)
    NodoSimple(Envio* e) : dato(e), sig(nullptr) {}
};


class ListaPendientes{ //cola de prioridad
private:
    // TODO:
public:
    // TODO:
    
};


class hubFlow{ 
private:
    // TODO:

public:
    // TODO:
  
};

int main(){
    // TODO:
    // 1. Instanciar hubFlow
    // 2. Cargar el dataset inicial obligatorio de la consigna
    // 3. Menú interactivo en consola con las 9 opciones pedidas por el enunciado
    // 4. Pruebas de los 7 casos obligatorios del TP
    return 0;
}


