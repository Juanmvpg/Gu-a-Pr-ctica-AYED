// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Programación Orientada a Objetos (POO) en C++
// ============================================================
// Conceptos clave de esta unidad:
//   - De 'struct' a 'class': Encapsulamiento (public vs private).
//   - Atributos (estado interno) y Métodos (comportamiento).
//   - Constructores (por defecto, con parámetros, lista de inicialización).
//   - Destructores (~Clase) y gestión de memoria RAII.
//   - El puntero implícito 'this'.
//   - Métodos 'const' (de solo lectura de estado).
// ============================================================


// ============================================================
// EJERCICIO 1 — Clase 'Tiempo': Encapsulamiento, Validaciones y 'this' (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Encapsulamiento con private: (hora, minuto, segundo).
//   - Métodos públicos mutadores y de consulta (const).
//   - Validación de estados válidos con operador ternario.
//   - El puntero implícito 'this->'.
// ============================================================
/*
#include <iostream>
#include <iomanip>

class Tiempo {
private:
    int hora;
    int minuto;
    int segundo;

public:
    void setTiempo(int hora, int minuto, int segundo) {
        this->hora    = (hora >= 0 && hora < 24)       ? hora    : 0;
        this->minuto  = (minuto >= 0 && minuto < 60)   ? minuto  : 0;
        this->segundo = (segundo >= 0 && segundo < 60) ? segundo : 0;
    }

    void imprimirMilitar() const {
        std::cout << std::setfill('0')
                  << std::setw(2) << hora << ":"
                  << std::setw(2) << minuto << ":"
                  << std::setw(2) << segundo << std::endl;
    }

    void imprimirEstandar() const {
        int hora12 = (hora == 0 || hora == 12) ? 12 : hora % 12;
        std::cout << std::setfill('0')
                  << std::setw(2) << hora12 << ":"
                  << std::setw(2) << minuto << ":"
                  << std::setw(2) << segundo
                  << ((hora >= 12) ? " PM" : " AM") << std::endl;
    }

    void incrementarSegundo() {
        if (++segundo == 60) {
            segundo = 0;
            if (++minuto == 60) {
                minuto = 0;
                if (++hora == 24) {
                    hora = 0;
                }
            }
        }
    }
};

int main() {
    Tiempo t;
    t.setTiempo(23, 59, 58);

    std::cout << "Militar inicial:  ";
    t.imprimirMilitar();
    std::cout << "Estandar inicial: ";
    t.imprimirEstandar();

    t.incrementarSegundo();
    std::cout << "Tras 1 segundo:   ";
    t.imprimirMilitar();

    t.incrementarSegundo();
    std::cout << "Tras 2 segundos:  ";
    t.imprimirMilitar();

    // Resultado esperado:
    // Militar inicial:  23:59:58
    // Estandar inicial: 11:59:58 PM
    // Tras 1 segundo:   23:59:59
    // Tras 2 segundos:  00:00:00

    return 0;
}
*/


// ============================================================
// EJERCICIO 2 — Separación Interfaz/Implementación (::) y Constructores
// ------------------------------------------------------------
// Enunciado (Basado en el archivo 04_POO_Objeto_Tiempo de la cátedra):
//
// 1. Declarar la clase 'Tiempo2' con:
//    - Atributos privados: int hora, minuto, segundo.
//    - Constructor con parámetros por defecto: Tiempo2(int = 0, int = 0, int = 0);
//    - Destructor: ~Tiempo2(); (muestra un mensaje al ejecutarse).
//    - Métodos setters individuales:
//        void setHora(int);
//        void setMinuto(int);
//        void setSegundo(int);
//        void setHoraFull(int, int, int);
//    - Métodos getters individuales (const):
//        int getHora() const;
//        int getMinuto() const;
//        int getSegundo() const;
//    - Métodos de visualización (const):
//        void imprimeUniversal() const;
//        void imprimeEstandar() const;
//
// 2. Definir TODAS las funciones miembro fuera de la clase usando
//    el operador de resolución de ámbito (Tiempo2::nombreFuncion).
//
// 3. En el main():
//    - Probar la creación de objetos con 0, 1, 2 y 3 argumentos.
//    - Observar el momento exacto en que se ejecutan el constructor y el destructor.
// ============================================================
/*
#include <iostream>
#include <iomanip>

class Tiempo2 {
public:
    Tiempo2(int = 0, int = 0, int = 0); // Constructor predeterminado
    ~Tiempo2();                         // Destructor

    // Setters
    void setHoraFull(int, int, int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);

    // Getters
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;

    // Métodos de impresión
    void imprimeUniversal() const;
    void imprimeEstandar() const;

private:
    int hora;
    int minuto;
    int segundo;
};

// Implementar acá afuera usando Tiempo2::...

int main() {
    // Probar objetos t1, t2(2), t3(21, 34), t4(12, 25, 42)
    return 0;
}
*/
