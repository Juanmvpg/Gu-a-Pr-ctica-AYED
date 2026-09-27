// ============================================================
// EJERCICIO 6 — Memoria Dinámica en Atributos
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Punteros como atributos (arreglo dinámico `int* datos`).
// - Reservar con `new[]` y liberar con `delete[]` obligatoriamente.
//
// Enunciado:
// Crear clase `BolsaNumeros`:
// 1. Atributos privados: `int* datos`, `int capacidad`, `int cantidad`.
// 2. Constructor:
//    - Recibe `int cap`. Si `cap <= 0`, fijar capacidad en 5 por defecto.
//    - Reserva: `datos = new int[capacidad];`, `cantidad = 0;`.
// 3. Destructor:
//    - `delete[] datos;` e imprimir "Memoria liberada".
// 4. Métodos:
//    - `bool insertar(int valor)`: agrega si hay lugar y retorna true.
//    - `void mostrar() const`: imprime elementos.
//    - `double calcularPromedio() const`: retorna el promedio.
// ============================================================

#include <iostream>
using namespace std;

// TODO: Definir clase BolsaNumeros
class BolsaNumeros{
int* datos;
int capacidad;
int cantidad;

public:
    BolsaNumeros(int cap){
        if(cap<=0){
            capacidad=5;
        }else{
            capacidad=cap;
        }
        datos= new int[capacidad];
        cantidad=0;
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
        for(int i=0; i<cantidad;i++){
            suma += datos[i];
        }
        return (suma/cantidad);
    }
};

int main() {
    std::cout << "=== EJERCICIO 3: BOLSA CON MEMORIA DINAMICA ===" <<std::endl;

    // TODO: Instanciar BolsaNumeros(4), insertar 5 números, 
    // mostrar elementos y verificar destrucción.

    BolsaNumeros miBolsaNumeros(5);
    int x;
    std::cout<<"Ingresa 5 numeros"<<std::endl;
    for(int i=0; i<5;i++){
        std::cin>>x;
        miBolsaNumeros.insertar(x);
    }

    miBolsaNumeros.mostrar();
    std::cout<<miBolsaNumeros.calcularPromedio()<<std::endl;
    



    return 0;
}
