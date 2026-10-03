// ============================================================
// EJERCICIO 6 — La "Regla de los Tres" (Constructor de Copia)
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Copia profunda vs Copia superficial (Deep copy vs Shallow copy).
// - Cuándo es obligatorio crear un Constructor de Copia.
//
// Enunciado:
// Imaginate que tenés un objeto con memoria dinámica (`new`). Si
// igualás un objeto a otro (`obj2 = obj1`), ambos punteros apuntarán
// al mismo lugar. Si se destruye uno, el otro queda apuntando a basura,
// y se produce un "Doble Delete" (el programa crashea).
// 
// Tarea:
// 1. Traé tu clase `BolsaNumeros` del Ejercicio 3 (con su new y delete).
// 2. Agregale un "Constructor de Copia". La firma es:
//    `BolsaNumeros(const BolsaNumeros& otra)`
// 3. Adentro de ese constructor, debes:
//    - Copiar la capacidad y la cantidad de la `otra` bolsa a esta.
//    - Reservar un NUEVO arreglo dinámico (`datos = new int[capacidad]`).
//    - Copiar los números del arreglo de `otra` al arreglo propio con un `for`.
// 4. En el `main`, creá una bolsa, agregale 2 números, y luego creá
//    una segunda bolsa usando copia: `BolsaNumeros copia(bolsaOriginal);`
//    Agregá un número extra a la copia y mostrá ambas para comprobar 
//    que no se mezclan (son independientes).
// ============================================================

#include <iostream>

// TODO: Traer la clase BolsaNumeros del Ejercicio 3 y agregarle 
// el Constructor de Copia.
class BolsaNumeros{
int* datos;
int capacidad;
int cantidad;

public:
//constructor por parámetro
    BolsaNumeros(int cap){
        if(cap<=0){
            capacidad=5;
        }else{
            capacidad=cap;
        }
        datos= new int[capacidad];
        cantidad=0;
    }
//constructor por copia
    BolsaNumeros (const BolsaNumeros& otra){
        capacidad = otra.capacidad;
        cantidad = otra.cantidad;
        datos = new int[capacidad];
        for(int i=0; i<cantidad;i++){
            datos[i]=otra.datos[i];
        }
    }
    ~BolsaNumeros(){
        delete[] datos;
        std::cout<<"Memoria liberada"<<std::endl;
    }

    bool insertar(int valor){
        if(cantidad<capacidad){
            datos[cantidad]=valor;
            cantidad++;
            return true;
        }
        return false;
    }
    void mostrar() const{
        for(int i=0; i<cantidad;i++){
            std::cout<<datos[i]<<" ";
        }
        std::cout<<std::endl;
    }
    double calcularPromedio() const{
        if(cantidad==0){
            std::cout<<"No se puede dividir por 0";
            return 0;
        }
        
        double suma=0;
        for(int i=0; i<cantidad;i++) {suma += datos[i];}
        return (suma/cantidad);
    }
};

int main() {
    std::cout << "=== EJERCICIO 6: COPIA PROFUNDA ===" << std::endl;

    // TODO: Crear original, copiarla, modificar la copia, 
    // mostrar ambas para comprobar independencia.
    int cap;
    std::cout<<"cantidad numeros"<<std::endl;
    std::cin>>cap;
    
    BolsaNumeros original(cap + 10);

    for(int i=0; i<cap; i++){
        int aux;
        std::cout<<"ingrese el valor"<<std::endl;
        std::cin>>aux;
        original.insertar(aux);
    }
    
    std::cout<<std::endl;

    BolsaNumeros copia(original);
    std::cout<<"Cuantos numeros le ingresas a la copia? 0 para no ingresar"<<std::endl;
    int capAux;
    std::cin>>capAux;
    if(capAux != 0){
        int auxCopia;

        for(int i=0; i<=capAux;i++){
        std::cout<<"ingrese el valor"<<std::endl;
        std::cin>>auxCopia;
                copia.insertar(auxCopia);
        }
    }

    std::cout<<"Bolsa original"<<std::endl;
    original.mostrar();
    std::cout<<"Bolsa copia"<<std::endl;
    copia.mostrar();
    return 0;
}