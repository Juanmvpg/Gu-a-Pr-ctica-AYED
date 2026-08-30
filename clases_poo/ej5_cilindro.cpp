// ============================================================
// EJERCICIO 5 — Herencia Multinivel: Punto -> Círculo -> Cilindro
// ------------------------------------------------------------
// Enunciado (Basado en la jerarquía completa de la cátedra):
//
// Concepto: Herencia Multinivel ("Un Cilindro ES UN Círculo con altura")
//
// 1. Clase Base: Punto (x, y)
// 2. Clase Derivada 1: Circulo (hereda de Punto, agrega radio)
// 3. Clase Derivada 2: Cilindro (hereda de Circulo, agrega altura)
//
// Métodos a implementar en Cilindro:
//   - Constructor: Cilindro(int x, int y, double r, double h)
//     *Invoca a Circulo(x, y, r) en la lista de inicialización*
//   - void setAltura(double h) (validación >= 0.0)
//   - double getAltura() const
//   - double getArea() const (Área superficial total = 2 * base + lateral)
//     Fórmula: 2 * Circulo::getArea() + getCircunferencia() * altura
//   - double getVolumen() const (Volumen = base * altura)
//     Fórmula: Circulo::getArea() * altura
//   - void imprimir() const (Reutiliza Circulo::imprimir() y muestra altura)
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
// 2. CLASE DERIVADA 1: Circulo
// ============================================================
class Circulo : public Punto {
private:
    double radio;

public:
    Circulo(int valorX = 0, int valorY = 0, double valorRadio = 0.0) 
        : Punto(valorX, valorY), radio(valorRadio < 0.0 ? 0.0 : valorRadio) {}

    void setRadio(double valorRadio) {
        this->radio = (valorRadio < 0.0) ? 0.0 : valorRadio;
    }

    double getRadio() const          { return radio; }
    double getDiametro() const       { return 2.0 * radio; }
    double getCircunferencia() const { return 3.14159 * getDiametro(); }
    double getArea() const           { return 3.14159 * radio * radio; }

    void imprimir() const {
        std::cout << "Centro = ";
        Punto::imprimir();
        std::cout << "; Radio = " << radio;
    }
};

// ============================================================
// 3. CLASE DERIVADA 2: Cilindro (Hereda de Circulo)
// ============================================================
class Cilindro : public Circulo {
private:
    double altura;

public:
    // 1. Constructor: debe invocar al constructor de Circulo
    Cilindro(int valorX = 0, int valorY = 0, double valorRadio = 0.0, double valorAltura = 0.0)
        // ??? (Lista de inicialización)
    {
        // ???
    }

    // 2. Setter y Getter propios
    void setAltura(double valorAltura) {
        // ???
    }

    double getAltura() const {
        // ???
    }

    // 3. Sobrescritura de Área (Área superficial total del cilindro)
    // Pista: 2 tapas circulares + envolvente lateral
    double getArea() const {
        // ???
    }

    // 4. Cálculo de Volumen
    // Pista: Área de la base circular * altura
    double getVolumen() const {
        // ???
    }

    // 5. Imprimir: reutiliza Circulo::imprimir() y agrega la altura
    void imprimir() const {
        // ???
    }
};

// ============================================================
// main
// ============================================================
int main() {
    std::cout << std::fixed << std::setprecision(2);

    // 1. Objeto Cilindro en el Stack:
    Cilindro cil(12, 23, 2.5, 5.7);

    std::cout << "--- Cilindro en Stack ---" << std::endl;
    std::cout << "Coordenada X (desde Punto):   " << cil.getX() << std::endl;
    std::cout << "Coordenada Y (desde Punto):   " << cil.getY() << std::endl;
    std::cout << "Radio (desde Circulo):        " << cil.getRadio() << std::endl;
    std::cout << "Altura (propia de Cilindro):  " << cil.getAltura() << std::endl;
    
    std::cout << "\nResumen completo: ";
    cil.imprimir();
    std::cout << std::endl;

    std::cout << "Area de la base circular:     " << cil.Circulo::getArea() << std::endl;
    std::cout << "Area superficial total:       " << cil.getArea() << std::endl;
    std::cout << "Volumen:                      " << cil.getVolumen() << std::endl;

    // 2. Modificación de atributos heredados y propios:
    std::cout << "\n--- Modificando Cilindro ---" << std::endl;
    cil.setX(2);
    cil.setY(2);
    cil.setRadio(4.25);
    cil.setAltura(10.0);
    cil.imprimir();
    std::cout << "\nNuevo Volumen: " << cil.getVolumen() << std::endl;

    // 3. Cilindro en el Heap con new / delete:
    std::cout << "\n--- Cilindro en Heap (Puntero) ---" << std::endl;
    Cilindro* ptrCil = new Cilindro(0, 0, 3.0, 4.0);
    ptrCil->imprimir();
    std::cout << "\nVolumen en Heap: " << ptrCil->getVolumen() << std::endl;

    delete ptrCil;
    ptrCil = nullptr;

    return 0;
}
