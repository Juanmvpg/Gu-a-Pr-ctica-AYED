// ============================================================
// EJERCICIO 1 — Nivel Básico: El Podómetro
// ============================================================
// Conceptos a evaluar: Encapsulamiento, constructores, métodos públicos.
//
// Enunciado:
// Crear una clase `Podometro` (contador de pasos).
// 1. Debe tener un atributo privado entero llamado `pasos`.
// 2. Un constructor que inicialice los pasos en 0.
// 3. Un método `registrarPasos(int cantidad)` que sume esa cantidad al total. 
//    Si la cantidad ingresada es negativa, no debe sumar nada (validación).
// 4. Un método `leerPasos()` que retorne el total actual.
// 5. Un método `resetear()` que vuelva el contador a 0.
// 6. En la función main(), instanciá un objeto Podometro estáticamente 
//    (sin new), registrá pasos válidos e inválidos, y mostrá el total 
//    por consola para verificar.
// ============================================================

#include <iostream>

using namespace std;

// TODO: Definir la clase Podometro aquí
class podometro {
private:
    int pasos;

public:
    podometro(){this->pasos=0;} //constructor: sin tipo de retorno, mismo nombre que la clase y en el cuerpo se dan valores iniciales a los atributos



    void registrarPasos(int cantidad){
        if(cantidad >0){ 
            pasos +=cantidad; //al poner pasos=cantidad no permite que el registro sea acumulativo: por la mañana 100 y por la tarde 50, entonces registro=150
        }
    }
    void leerPasos(){
        std::cout<<"Cantidad de pasos: "<<this->pasos;
    };
    void resetear(){
        this->pasos = 0;
    };
};


int main() {
    std::cout << "=== EJERCICIO 1: EL PODOMETRO ===" << std::endl;
    
    // TODO: Instanciar un Podometro y probar sus métodos

    podometro miPodrometro; //asi se instancia el objeto
    int pasos = 100;
    miPodrometro.registrarPasos(pasos);
    miPodrometro.leerPasos();
    std::cout<<std::endl<<"reseteo"<<std::endl;
    miPodrometro.resetear();
    miPodrometro.leerPasos();

    
    return 0;
}
