// ============================================================
// NIVEL 4 — Herencia: Jerarquía Vehículo, Automóvil y Camión
// ============================================================
// Objetivos de Aprendizaje:
//   1. Comprender la visibilidad 'protected:' vs 'private:' en la clase Base.
//   2. Invocar constructores de la clase Base desde la clase Derivada.
//   3. Sobrescritura de métodos (calcularPeaje, mostrarDatos).
//   4. Jerarquía de Clases:
//        - Base: 'Vehiculo' (patente, marca, modelo).
//        - Derivada 1: 'Automovil' (hereda de Vehiculo, agrega cantidadPuertas).
//        - Derivada 2: 'Camion' (hereda de Vehiculo, agrega cantidadEjes y cargaToneladas).
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>

// ============================================================
// 1. CLASE BASE: Vehiculo
// ============================================================
class Vehiculo {
protected:
    // 'protected' permite que las clases hijas (Automovil, Camion)
    // accedan a estos atributos directamente, pero siguen ocultos para el main().
    std::string patente;
    std::string marca;
    int modeloAnio;

public:
    Vehiculo(const std::string& pat = "S/P", const std::string& mar = "Genérica", int anio = 2000)
        : patente(pat), marca(mar), modeloAnio(anio > 1900 ? anio : 2000)
    {
    }

    std::string getPatente() const { return patente; }
    std::string getMarca() const   { return marca; }
    int getModeloAnio() const      { return modeloAnio; }

    // Tarifa base de peaje para cualquier vehículo
    double calcularPeajeBase() const {
        return 500.0;
    }

    void mostrarDatos() const {
        std::cout << "Patente: " << patente 
                  << " | Marca: " << marca 
                  << " | Anio: " << modeloAnio;
    }
};

// ============================================================
// 2. CLASE DERIVADA 1: Automovil (ES UN Vehiculo con puertas)
// ============================================================
class Automovil : public Vehiculo {
private:
    int cantidadPuertas;

public:
    // Constructor: Invoca al constructor de Vehiculo en la lista de inicialización
    Automovil(const std::string& pat, const std::string& mar, int anio, int puertas)
        : Vehiculo(pat, mar, anio), cantidadPuertas(puertas > 0 ? puertas : 4)
    {
    }

    int getCantidadPuertas() const { return cantidadPuertas; }

    // Regla de Peaje para Automóvil: Peaje Base + $100 fijo
    double calcularPeaje() const {
        return calcularPeajeBase() + 100.0;
    }

    void mostrarDatos() const {
        Vehiculo::mostrarDatos(); // Reutiliza la impresión de la clase base
        std::cout << " | Puertas: " << cantidadPuertas 
                  << " | Peaje: $" << calcularPeaje() << std::endl;
    }
};

// ============================================================
// 3. CLASE DERIVADA 2: Camion (ES UN Vehiculo con ejes y carga)
// ============================================================
class Camion : public Vehiculo {
private:
    int cantidadEjes;
    double cargaToneladas;

public:
    // Constructor: Invoca a Vehiculo en la lista de inicialización
    Camion(const std::string& pat, const std::string& mar, int anio, int ejes, double carga)
        : Vehiculo(pat, mar, anio), 
          cantidadEjes(ejes >= 2 ? ejes : 2),
          cargaToneladas(carga >= 0.0 ? carga : 0.0)
    {
    }

    // Regla de Peaje para Camión: Peaje Base + ($200 por cada eje) + ($50 por cada tonelada de carga)
    double calcularPeaje() const {
        return calcularPeajeBase() + cantidadEjes*200.0 + 50*cargaToneladas;
    }

    void mostrarDatos() const {
        Vehiculo::mostrarDatos();
        std::cout << " | Ejes: " << cantidadEjes 
                  << " | Carga: " << cargaToneladas << "tn"
                  << " | Peaje: $" << calcularPeaje() << std::endl;
    }
};

// ============================================================
// main
// ============================================================
int main() {
    std::cout << "=== SISTEMA DE CONTROL DE PEAJES (HERENCIA) ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    // 1. Automóvil en el Stack:
    Automovil auto1("AF123JK", "Toyota", 2022, 5);
    std::cout << "\n[Automovil]" << std::endl;
    auto1.mostrarDatos();

    // 2. Camión en el Stack:
    Camion camion1("AE987ZX", "Scania", 2020, 4, 18.5);
    std::cout << "\n[Camion]" << std::endl;
    camion1.mostrarDatos();

    // 3. Camión en el Heap con new / delete:
    std::cout << "\n[Camion en Heap]" << std::endl;
    Camion* ptrCamion = new Camion("AC555TT", "Mercedes-Benz", 2018, 6, 25.0);
    ptrCamion->mostrarDatos();

    delete ptrCamion;
    ptrCamion = nullptr;

    // Resultado esperado en consola:
    // === SISTEMA DE CONTROL DE PEAJES (HERENCIA) ===
    // 
    // [Automovil]
    // Patente: AF123JK | Marca: Toyota | Anio: 2022 | Puertas: 5 | Peaje: $600.00
    // 
    // [Camion]
    // Patente: AE987ZX | Marca: Scania | Anio: 2020 | Ejes: 4 | Carga: 18.50tn | Peaje: $2225.00 (500 + 4*200 + 18.5*50)
    // 
    // [Camion en Heap]
    // Patente: AC555TT | Marca: Mercedes-Benz | Anio: 2018 | Ejes: 6 | Carga: 25.00tn | Peaje: $2950.00 (500 + 6*200 + 25*50)

    return 0;
}
