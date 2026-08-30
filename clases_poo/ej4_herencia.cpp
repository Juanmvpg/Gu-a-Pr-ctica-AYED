// ============================================================
// EJERCICIO 4 — Herencia: Jerarquía Punto -> Círculo
// ------------------------------------------------------------
// Enunciado (Basado en 'Clase 02 2024 Herencia.cpp' de la cátedra):
//
// Concepto: Herencia ("Un Círculo ES UN Punto con radio")
//
// 1. Clase Base 'Punto':
//    - Atributos privados: int x, y;
//    - Constructor con valores por defecto: Punto(int = 0, int = 0);
//    - Métodos: setX(int), setY(int), getX() const, getY() const, imprimir() const.
//
// 2. Clase Derivada 'Circulo' (sintaxis: class Circulo : public Punto):
//    - Atributo privado propio: double radio;
//    - Constructor: Circulo(int x = 0, int y = 0, double r = 0.0)
//      *Obligatorio:* invocar al constructor de Punto en la lista de inicialización:
//      Circulo(int x, int y, double r) : Punto(x, y), radio(r < 0.0 ? 0.0 : r) {}
//    - Métodos propios:
//        void setRadio(double);
//        double getRadio() const;
//        double getDiametro() const;
//        double getCircunferencia() const;
//        double getArea() const;
//        void imprimir() const; // Imprime Centro reutilizando Punto::imprimir() y su radio
// ============================================================

#include <iostream>
#include <iomanip>

// ============================================================
// 1. CLASE BASE: Punto
// ============================================================
class Punto {
private:
    int x;
    int y;

public:
    Punto(int valorX = 0, int valorY = 0) : x(valorX), y(valorY) {}

    void setX(int valorX)       { this->x = valorX; }
    void setY(int valorY)       { this->y = valorY; }

    int getX() const            { return x; }
    int getY() const            { return y; }

    void imprimir() const {
        std::cout << "[" << x << ", " << y << "]";
    }
};

// ============================================================
// 2. CLASE DERIVADA: Circulo (Hereda públicamente de Punto)
// ============================================================
class Circulo : public Punto {
private:
    double radio;

public:
    // Tu constructor acá (invocando a Punto en la lista de inicialización)
    Circulo(int valorX = 0, int valorY = 0, double valorRadio = 0.0) 
        :Punto(valorX, valorY), radio(valorRadio<0.0 ? 0: valorRadio)
    {
        // ???
    }

    // Setters y Getters propios
    void setRadio(double valorRadio) {
        radio=valorRadio;
    }

    double getRadio() const {
        return radio;
    }

    // Cálculos geométricos (Usar Pi = 3.14159)
    double getDiametro() const {
        return 2*radio;
    }

    double getCircunferencia() const {
        return 2*3.41*radio;
    }

    double getArea() const {
        return 3.14*radio*radio;
    }

    // Imprimir el círculo reutilizando la impresión del Punto base:
    void imprimir() const {
        std::cout << "Centro = ";
        Punto::imprimir(); // <-- ¡Llama al método de la clase base!
        std::cout << "; Radio = " << radio;
    }
};

// ============================================================
// main
// ============================================================
int main() {
    // 1. Objeto Circulo en el Stack:
    Circulo c1(10, 15, 4.5);

    std::cout << "--- Circulo en Stack (c1) ---" << std::endl;
    std::cout << "Coordenada X (heredada): " << c1.getX() << std::endl;
    std::cout << "Coordenada Y (heredada): " << c1.getY() << std::endl;
    std::cout << "Radio (propio):          " << c1.getRadio() << std::endl;
    std::cout << "Resumen:                 ";
    c1.imprimir();
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Diametro:                " << c1.getDiametro() << std::endl;
    std::cout << "Circunferencia:          " << c1.getCircunferencia() << std::endl;
    std::cout << "Area:                    " << c1.getArea() << std::endl;

    // 2. Modificamos tanto la base como la derivada:
    std::cout << "\n--- Modificando c1 ---" << std::endl;
    c1.setX(20);         // Método heredado
    c1.setY(30);         // Método heredado
    c1.setRadio(10.0);   // Método propio
    c1.imprimir();
    std::cout << "\nNueva Area: " << c1.getArea() << std::endl;

    // 3. Objeto Circulo dinámico en el Heap (Puntero):
    std::cout << "\n--- Circulo en Heap (puntero) ---" << std::endl;
    Circulo* ptrC = new Circulo(5, 5, 2.0);
    ptrC->imprimir();
    std::cout << "\nArea en Heap: " << ptrC->getArea() << std::endl;

    delete ptrC;
    ptrC = nullptr;

    return 0;
}
