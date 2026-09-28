// ============================================================
// EJERCICIO 7 — Jerarquía Polimórfica con Retorno
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Clase abstracta, métodos virtuales puros (`double`).
// - Arreglo de punteros polimórficos.
//
// Enunciado:
// 1. Clase abstracta `Figura`:
//    - Virtuales puros: `calcularArea() const`, `calcularPerimetro() const`,
//      y `mostrarInfo() const`.
//    - Destructor virtual.
// 2. Clase `Rectangulo` (hereda de Figura):
//    - Base y altura privadas. Sobrescribir los 3 métodos.
// 3. Clase `Circulo` (hereda de Figura):
//    - Radio privado. Sobrescribir los 3 métodos (usar pi=3.14159).
// 4. En main():
//    - Crear `Figura* figuras[3];`. 
//    - Asignar dinámicamente (`new`) Rectángulos y Círculos.
//    - Bucle para mostrarInfo() y acumular el área total.
//    - Imprimir área total y liberar con `delete` cada figura.
// ============================================================

#include <iostream>
using namespace std;

// TODO: Definir clase abstracta Figura
class Figura{
public:    
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrarInfo() const =0;
    virtual ~Figura(){} //destructor virtual
    
};

// TODO: Definir clase Rectangulo
class Rectangulo: public Figura{
    double altura;
    double base;
public:
    //pedimos los datos en el constructor
    Rectangulo(){
        std::cout<<"ingrese la altura y la base"<<std::endl;
        std::cin>>altura>>base;
        this->altura=altura;
        this->base=base;
    }


    double calcularArea() const{
        double area=base*altura;
        return area;
    }
    double calcularPerimetro() const{
        double perimetro=2*altura + 2*base;;
        return perimetro;
    }

    virtual void mostrarInfo() const {
        std::cout<<"Area rectangulo: "<<calcularArea()<<std::endl;
        std::cout<<"Perimetro rectangulo: "<<calcularPerimetro()<<std::endl;
    }
};

// TODO: Definir clase Circulo
class Circulo: public Figura{
double radio;
public:
    Circulo(){
        std::cout<<"Ingrese el radio"<<std::endl;
        std::cin>>radio;
        this->radio=radio;
    }

    double calcularArea() const{
        double area=3.14159*radio*radio;
        return area;
    }

    double calcularPerimetro() const{
        double perimetro = 2*3.14159*radio;
        return perimetro;
    }

    virtual void mostrarInfo() const {
    std::cout<<"Area circulo: "<<calcularArea()<<std::endl;
    std::cout<<"Perimetro circulo: "<<calcularPerimetro()<<std::endl;
    }
};

int main() {
    std::cout << "=== EJERCICIO 4: POLIMORFISMO DE FIGURAS ===" << std::endl;

    // TODO: Crear arreglo de punteros, recorrer, sumar áreas y hacer delete
    Figura* misFiguras[2];
    misFiguras[0]= new Rectangulo();
    misFiguras[1]=new Circulo();
    double areaTotal=0;
    for(int i=0; i<2; i++){
        areaTotal += misFiguras[i]->calcularArea();//no lleva . porque misFiguras es un puntero
        misFiguras[i]->calcularPerimetro();
        misFiguras[i]->mostrarInfo();

        delete misFiguras[i];
    }

    std::cout<<std::endl<<"Area total: "<<areaTotal;

    return 0;
}

