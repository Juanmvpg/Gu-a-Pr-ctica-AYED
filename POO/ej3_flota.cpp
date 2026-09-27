// ============================================================
// EJERCICIO 3 — Nivel Avanzado: La Flota
// ============================================================
// Conceptos a evaluar: Clases base, métodos virtuales, herencia, polimorfismo.
//
// Enunciado:
// 1. Crear una clase base abstracta llamada `Vehiculo` con un método virtual puro 
//    llamado `acelerar()` (ej: virtual void acelerar() = 0;). 
//    Agregale un destructor virtual (virtual ~Vehiculo() {}).
// 2. Crear dos clases derivadas: `Auto` y `Bicicleta` que hereden de `Vehiculo`.
// 3. Cada clase derivada debe implementar su propia versión de `acelerar()` 
//    (ej: el Auto imprime "Brum brum..." y la Bicicleta imprime "Pedaleando...").
// 4. En el main(), crear un arreglo estático de 2 punteros a Vehiculo: `Vehiculo* flota[2];`
// 5. Asignar al primer elemento un `new Auto()` y al segundo un `new Bicicleta()`.
// 6. Hacer un bucle for que recorra la flota y llame a `acelerar()` sobre cada puntero. 
//    Al final, no te olvides de liberar cada puntero con `delete`.
// ============================================================

#include <iostream>

// TODO: Definir la clase base Vehiculo aquí
class Vehiculo {
public:
    virtual void acelerar()=0; //el =0 hace que sea una función virtual pura -> le dice al compilador que esta función no lleva codigo en esta misma clase.
    virtual ~Vehiculo() {};

};

class Auto : public Vehiculo {
public: //toda clase es por defecto privada, si no se aclara
    void acelerar(){
        std::cout<<"Brum brum"<<std::endl;
    }
};

class Bicicleta : public Vehiculo {
public:    
    void acelerar(){
        std::cout<<"Pedaleando"<<std::endl;
    }
};




int main() {
    std::cout << "=== EJERCICIO 3: LA FLOTA ===" << std::endl;
    
    // TODO: Crear arreglo de punteros, instanciar dinámicamente, recorrer e iterar, liberar memoria.
    Vehiculo* flota[2];
    flota[0] = new Auto();
    flota[1]= new Bicicleta();

    for(int i=0; i<2; i++){
        flota[i] -> acelerar(); //acelerar es un método, por ende se llama con la flecha
        delete flota[i];
    }


    // 5. Asignar al primer elemento un `new Auto()` y al segundo un `new Bicicleta()`.
// 6. Hacer un bucle for que recorra la flota y llame a `acelerar()` sobre cada puntero. 
//    Al final, no te olvides de liberar cada puntero con `delete`.
    
    return 0;
}
