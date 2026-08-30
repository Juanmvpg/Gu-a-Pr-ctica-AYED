// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Programación Orientada a Objetos (POO) en C++
// ============================================================
// Conceptos clave de esta unidad:
//   - De 'struct' a 'class': Encapsulamiento (public vs private).
//   - Atributos (estado interno) y Métodos (comportamiento).
//   - Constructores (por defecto, con parámetros, lista de inicialización).
//   - Destructores (~Clase) y gestión de memoria RAII.
//   - Composición de Clases (Relación "Tiene un").
//   - Herencia (Relación "Es un" -> Base y Derivada).
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
// EJERCICIO 2 — Separación Interfaz/Implementación (::) y Constructores (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Prototipos dentro de la clase y definiciones fuera con 'Tiempo2::'.
//   - Parámetros por defecto en el constructor: Tiempo2(int = 0, int = 0, int = 0);
//   - Ciclo de vida y llamadas automáticas al destructor.
// ============================================================
/*
#include <iostream>
#include <iomanip>

class Tiempo2 {
public:
    Tiempo2(int = 0, int = 0, int = 0);
    ~Tiempo2();

    void setHoraFull(int, int, int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);

    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;

    void imprimeUniversal() const;
    void imprimeEstandar() const;

private:
    int hora;
    int minuto;
    int segundo;
};

Tiempo2::Tiempo2(int hr, int min, int seg) {
    std::cout << "[Constructor invocado]" << std::endl;
    setHoraFull(hr, min, seg);
}

Tiempo2::~Tiempo2() {
    std::cout << "[Destructor invocado]" << std::endl;
}

void Tiempo2::setHoraFull(int h, int m, int s) {
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

void Tiempo2::setHora(int h)       { this->hora = (h >= 0 && h < 24) ? h : 0; }
void Tiempo2::setMinuto(int m)     { this->minuto = (m >= 0 && m < 60) ? m : 0; }
void Tiempo2::setSegundo(int s)    { this->segundo = (s >= 0 && s < 60) ? s : 0; }

int Tiempo2::getHora() const       { return hora; }
int Tiempo2::getMinuto() const     { return minuto; }
int Tiempo2::getSegundo() const     { return segundo; }

void Tiempo2::imprimeUniversal() const {
    std::cout << std::setfill('0')
              << std::setw(2) << getHora() << ":"
              << std::setw(2) << getMinuto() << ":"
              << std::setw(2) << getSegundo() << std::endl;
}

void Tiempo2::imprimeEstandar() const {
    int hora12 = (getHora() == 0 || getHora() == 12) ? 12 : getHora() % 12;
    std::cout << std::setfill('0')
              << std::setw(2) << hora12 << ":"
              << std::setw(2) << getMinuto() << ":"
              << std::setw(2) << getSegundo() << " "
              << ((getHora() < 12) ? "AM" : "PM") << std::endl;
}

int main() {
    Tiempo2 t1;
    Tiempo2 t2(2);
    Tiempo2 t3(21, 34);
    Tiempo2 t4(12, 25, 42);

    t1.imprimeUniversal();
    t2.imprimeUniversal();
    t3.imprimeEstandar();
    t4.imprimeEstandar();

    return 0;
}
*/


// ============================================================
// EJERCICIO 3 — Composición de Clases (Semana Laboral) (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Relación "Tiene un" (Has-a).
//   - Inicialización de objetos componentes mediante la Lista de Inicialización.
// ============================================================
/*
#include <iostream>
#include <iomanip>
#include <string>

class Hora {
private:
    int hora;
    int minuto;

public:
    Hora(int h = 0, int m = 0) {
        setHora(h);
        setMinuto(m);
    }

    void setHora(int h)     { this->hora = (h >= 0 && h < 24) ? h : 0; }
    void setMinuto(int m)   { this->minuto = (m >= 0 && m < 60) ? m : 0; }

    int getHora() const     { return hora; }
    int getMinuto() const   { return minuto; }

    int aMinutosTotales() const { return hora * 60 + minuto; }

    void imprimir() const {
        std::cout << std::setfill('0')
                  << std::setw(2) << hora << ":"
                  << std::setw(2) << minuto;
    }
};

class RangoHorario {
private:
    Hora entrada;
    Hora salida;

public:
    RangoHorario(int hEnt = 9, int mEnt = 0, int hSal = 17, int mSal = 0)
        : entrada(hEnt, mEnt), salida(hSal, mSal) {}

    int calcularMinutosTrabajados() const {
        int minEntrada = entrada.aMinutosTotales();
        int minSalida  = salida.aMinutosTotales();
        return (minSalida >= minEntrada) ? (minSalida - minEntrada) : 0;
    }

    void imprimir() const {
        std::cout << "De ";
        entrada.imprimir();
        std::cout << " a ";
        salida.imprimir();
        std::cout << " (" << calcularMinutosTrabajados() / 60 << "hs " 
                  << calcularMinutosTrabajados() % 60 << "min)";
    }
};

class DiaLaboral {
private:
    std::string nombreDia;
    RangoHorario horario;

public:
    DiaLaboral(const std::string& dia, int hEnt, int mEnt, int hSal, int mSal)
        : nombreDia(dia), horario(hEnt, mEnt, hSal, mSal) {}

    int getMinutos() const { return horario.calcularMinutosTrabajados(); }

    void mostrarResumen() const {
        std::cout << std::left << std::setfill(' ') << std::setw(12) << nombreDia << ": ";
        std::cout << std::right;
        horario.imprimir();
        std::cout << std::endl;
    }
};

int main() {
    DiaLaboral semana[5] = {
        DiaLaboral("Lunes",     8, 30, 16, 30),
        DiaLaboral("Martes",    9,  0, 17,  0),
        DiaLaboral("Miercoles", 8, 30, 17, 30),
        DiaLaboral("Jueves",    9,  0, 18,  0),
        DiaLaboral("Viernes",   8,  0, 14,  0)
    };

    int totalMinutos = 0;
    for (int i = 0; i < 5; i++) {
        semana[i].mostrarResumen();
        totalMinutos += semana[i].getMinutos();
    }
    std::cout << "Total semanal: " << totalMinutos / 60 << "hs " << totalMinutos % 60 << "min." << std::endl;
    return 0;
}
*/


// ============================================================
// EJERCICIO 4 — Herencia: Jerarquía Punto -> Círculo (COMPLETO)
// ------------------------------------------------------------
// Concepto:
//   - Relación "Es un" (Is-a).
//   - Herencia pública: class Circulo : public Punto.
//   - Constructor derivado invocando al constructor base en la lista.
//   - Reutilización de métodos heredados (Punto::imprimir()).
// ============================================================
/*
#include <iostream>
#include <iomanip>

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

int main() {
    Circulo c1(10, 15, 4.5);
    c1.imprimir();
    std::cout << "\nArea: " << c1.getArea() << std::endl;

    Circulo* ptrC = new Circulo(5, 5, 2.0);
    ptrC->imprimir();
    std::cout << "\nArea Heap: " << ptrC->getArea() << std::endl;

    delete ptrC;
    ptrC = nullptr;
    return 0;
}
*/


// ============================================================
// EJERCICIO 5 — Herencia Multinivel: Punto -> Círculo -> Cilindro
// ------------------------------------------------------------
// Enunciado (Jerarquía de 3 niveles de la cátedra):
//
// 1. Reutilizar 'Punto' y 'Circulo'.
// 2. Crear la clase 'Cilindro' que hereda públicamente de 'Circulo':
//    class Cilindro : public Circulo
//
// 3. Atributo privado propio:
//    - double altura;
//
// 4. Constructor con lista de inicialización multinivel:
//    Cilindro(int x = 0, int y = 0, double r = 0.0, double h = 0.0)
//        : Circulo(x, y, r), altura(h < 0.0 ? 0.0 : h) {}
//
// 5. Métodos propios y sobrescritos:
//    - void setAltura(double);
//    - double getAltura() const;
//    - double getArea() const;    // Área total: 2 * Circulo::getArea() + getCircunferencia() * altura
//    - double getVolumen() const; // Volumen: Circulo::getArea() * altura
//    - void imprimir() const;     // Reutiliza Circulo::imprimir() y agrega la altura
//
// 6. En el main():
//    - Probar un Cilindro en Stack y otro en Heap con new/delete.
//    - Verificar el cálculo de área total y volumen.
// ============================================================
/*
#include <iostream>
#include <iomanip>

// Implementar Punto, Circulo y Cilindro acá

int main() {
    return 0;
}
*/
