// ============================================================
// EJERCICIO 5 — Integración: Composición + Polimorfismo
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Clases que administran arreglos de punteros polimórficos.
// - El objeto contenedor se hace cargo de la memoria de sus partes.
//
// Enunciado:
// 1. Clase abstracta `Empleado`: 
//    - Atributo privado `nombre` (string).
//    - Constructor que recibe nombre. Getter para el nombre.
//    - Método virtual puro: `double calcularSueldo() const = 0;`
//    - Destructor virtual.
// 2. Clase `Asalariado` (hereda de Empleado):
//    - Atributo privado `sueldoFijo`.
//    - Constructor que recibe nombre y sueldo.
//    - Sobrescribe `calcularSueldo()` retornando el sueldoFijo.
// 3. Clase `Comisionista` (hereda de Empleado):
//    - Atributos `ventas` (int) y `comisionPorVenta` (double).
//    - Constructor que recibe nombre, ventas y comision.
//    - Sobrescribe `calcularSueldo()` retornando ventas * comision.
// 4. Clase `Empresa`:
//    - Atributo privado: `Empleado* plantilla[5];`
//    - Atributo privado: `int cantidadEmpleados;`
//    - Constructor por defecto (inicializa cantidad en 0).
//    - Método `bool contratar(Empleado* emp)`: agrega al arreglo si hay lugar.
//    - Método `double calcularGastoTotalSueldos() const`: suma los sueldos.
//    - Destructor: OJO, debe hacer `delete` a cada empleado del arreglo.
// ============================================================

#include <iostream>
#include <string>


class Empleado{
std::string nombre;
public:
    Empleado(std::string nombre){
        this->nombre=nombre;
    }    

    virtual double calcularSueldo() const = 0;

    virtual ~Empleado(){};
};

class Asalariado : public Empleado{
double sueldoFijo;
public:
    Asalariado(std::string nombre, double sueldo) : Empleado(nombre){
        sueldoFijo=sueldo;
    }

    virtual double calcularSueldo()const {
        return sueldoFijo;
    }
};

class Comisionista: public Empleado{
    int ventas;
    double comisionPorVenta;
public:
    Comisionista(std::string nombre, int ventas, double comision) : Empleado(nombre){
        this->ventas=ventas;
        comisionPorVenta=comision;
    }

    virtual double calcularSueldo()const {
        return ventas*comisionPorVenta;
    }
};

class Empresa{
Empleado* plantilla[5]; //la empresa tiene 5 empleados
int cantidadEmpleados;
public:
    Empresa(){
        cantidadEmpleados=0;
    }

    ~Empresa(){
        for(int i=0;i<cantidadEmpleados;i++){
            delete plantilla[i];
            std::cout<<"memoria liberada"<<std::endl;
        }
    }
    bool contratar(Empleado* emp){
        if(cantidadEmpleados<5){
            plantilla[cantidadEmpleados] = emp;
            cantidadEmpleados++;
            return true;
        }
        return false;
    }

    double calcularGastoTotalSueldos() const{
        double suma=0;
        for(int i=0; i<cantidadEmpleados;i++){
            suma+= plantilla[i]->calcularSueldo();
        }
        return suma;
    }
};

int main() {
    std::cout << "=== EJERCICIO 5: EMPRESA ===" << std::endl;

    // TODO: Instanciar Empresa, contratar 2 asalariados y 1 comisionista.
    // Mostrar el gasto total en sueldos. 
    // Nota: El main() ya no hace 'delete' de los empleados, de eso 
    // se tiene que encargar el destructor de la Empresa.

    Empresa miEmpresa;
 for(int i=0; i<3; i++){
    std::string nombre;
    std::cout<<"Cómo se llama el entrevistado?"<<std::endl;
    std::cin>>nombre;
    if(i<2){
        Empleado* emp = new Asalariado(nombre, 100);
        miEmpresa.contratar(emp);
    }
    else{
        Empleado* emp2 = new Comisionista(nombre, 20, 30);
        miEmpresa.contratar(emp2);
    }

    
 }
    std::cout<<miEmpresa.calcularGastoTotalSueldos()<<std::endl;
    
    return 0;
}
