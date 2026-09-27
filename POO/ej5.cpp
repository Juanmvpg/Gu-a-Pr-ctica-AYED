// ============================================================
// EJERCICIO 5 — Composición de Clases ("Tiene-un")
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Composición: una clase contiene instancias de otra clase.
// - Arreglos estáticos de objetos como atributo.
//
// Enunciado:
// 1. Crear clase `Item`:
//    - Atributos privados: `nombre` (string) y `precio` (double).
//    - Constructores: por defecto ("", 0.0) y con parámetros.
//    - Getters `const` para ambos atributos.
// 2. Crear clase `Pedido`:
//    - Atributos privados: `Item items[5]` y `int cantidad` (inicia en 0).
//    - Constructor por defecto: inicializa `cantidad` en 0.
//    - `bool agregarItem(string nombre, double precio)`:
//      Crea un Item en la posición actual si hay lugar, aumenta 
//      cantidad y retorna true. Si está lleno, retorna false.
//    - `double calcularTotal() const`: Devuelve la suma de precios.
//    - `void mostrarResumen() const`: Imprime nombre y precio de cada item.
// ============================================================

#include <iostream>
#include <string>


// TODO: Definir clase Item
class Item {
    std::string nombre;
    double precio;

public:
    Item(){
        nombre="";
        precio=0;
    }

    Item(std::string name, double price){
        nombre=name;
        precio=price;
    }

    //getters
    std::string getNombre() const{ //recordar que getters llevan const para que sean unicamente de lectura
        return nombre;
    }
    double getPrecio() const{
        return precio;
    }
};

// TODO: Definir clase Pedido
class pedido{
    Item items[5];
    int cantidad;
public:
    pedido(){
        cantidad=0;
    }    

    bool agregarItem(std::string nombre, double precio){
        if(cantidad>=0 && cantidad<5){
            items[cantidad]=Item(nombre, precio);
            cantidad++;
            return true;
        }
        return false;
    }
    double calcularTotal() const{//const para solo lectura
        double suma=0;;
        for(int i=0; i<5; i++){
        suma += items[i].getPrecio();
        }        
        return suma;
    }
    void mostrarResumen() const{ //imprime nombre y precio de cada producto
        for(int i=0; i<cantidad;i++){ //puedo usar "cantidad" porque es atributo de la misma clase
            std::cout<<items[i].getNombre()<<", "<<items[i].getPrecio()<<std::endl;
        }
    }
};

int main() {
    std::cout << "=== EJERCICIO 2: COMPOSICION DE CLASES ===" << std::endl;

    // TODO: Crear Pedido, agregar items y mostrar resumen
    pedido miPedido; //SIEMPRE CREAR EL OBJETO (INSTANCIAR EL OBJETO)!

    std::string nombre;
    double precio;
    int cantidad;
    std::cout<<"Cuantos productos quieres agregar?"<<std::endl;
    std::cin>>cantidad;
    for(int i=0; i<cantidad; i++){
        std::cout<<"Qué producto deseas agregar?"<<std::endl;
        std::cin>>nombre;
        std::cout<<"cuánto cuesta?"<<std::endl;
        std::cin>>precio;

        miPedido.agregarItem(nombre, precio);
    }

    std::cout<<std::endl<<"Costo total: "<<miPedido.calcularTotal()<<std::endl;
    miPedido.mostrarResumen();
    

    return 0;
}