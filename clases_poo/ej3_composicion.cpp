// ============================================================
// EJERCICIO 3 — Composición de Clases (Semana Laboral: Día y RangoHorario)
// ------------------------------------------------------------
// Concepto: Composición ("Un objeto TIENE a otro objeto")
//
// En este ejercicio construiremos una jerarquía de composición:
//   1. Clase 'Hora': almacena hora y minuto (0-23, 0-59).
//   2. Clase 'RangoHorario': contiene DOS objetos 'Hora' (horaEntrada y horaSalida).
//   3. Clase 'DiaLaboral': contiene un nombre de día y un objeto 'RangoHorario'.
//
// Reglas y Objetivos:
//   - Uso obligatorio de la Lista de Inicialización de miembros para
//     inicializar los objetos componentes.
//   - Métodos 'const' para imprimir y calcular duración en minutos.
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>

// ============================================================
// 1. CLASE COMPONENTE BÁSICA: Hora
// ============================================================
class Hora {
private:
    int hora;
    int minuto;

public:
    Hora(int h = 0, int m = 0) { //igualados a 0 determinan la condición inicial
        setHora(h);
        setMinuto(m);
    }

    void setHora(int h)     { this->hora = (h >= 0 && h < 24) ? h : 0; }
    void setMinuto(int m)   { this->minuto = (m >= 0 && m < 60) ? m : 0; }

    int getHora() const     { return hora; }
    int getMinuto() const   { return minuto; }

    int aMinutosTotales() const {
        return hora * 60 + minuto;
    }

    void imprimir() const {
        std::cout << std::setfill('0')
                  << std::setw(2) << hora << ":"
                  << std::setw(2) << minuto;
    }
};

// ============================================================
// 2. CLASE COMPUESTA: RangoHorario (Tiene 2 objetos 'Hora')
// ============================================================
class RangoHorario {
private:
    Hora entrada; // Objeto componente 1
    Hora salida;  // Objeto componente 2

public:
    // PREGUNTA INDAGATORIA 1:
    // ¿Cómo se inicializan 'entrada' y 'salida' usando la Lista de Inicialización?
    RangoHorario(int hEnt = 9, int mEnt = 0, int hSal = 17, int mSal = 0)
        : entrada(hEnt, mEnt), salida(hSal, mSal) // <-- Inicialización de objetos miembros
    {
    }

    // Calcula la cantidad de minutos trabajados en el rango
    int calcularMinutosTrabajados() const {
        int minEntrada = entrada.aMinutosTotales();
        int minSalida  = salida.aMinutosTotales();
        
        if (minSalida >= minEntrada) {
            return minSalida - minEntrada;
        }
        return 0; // Si la salida es anterior a la entrada
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

// ============================================================
// 3. CLASE COMPUESTA PRINCIPAL: DiaLaboral (Tiene un RangoHorario)
// ============================================================
class DiaLaboral {
private:
    std::string nombreDia;
    RangoHorario horario; // Objeto compuesto anidado

public:
    // Constructor usando Lista de Inicialización:
    DiaLaboral(const std::string& dia, int hEnt, int mEnt, int hSal, int mSal)
        : nombreDia(dia), horario(hEnt, mEnt, hSal, mSal)
    {
    }

    int getMinutos() const {
        return horario.calcularMinutosTrabajados();
    }

    void mostrarResumen() const {
        /*
        std::cout << std::right;
        std::cout << nombreDia <<std::setw(2)<< ": ";
        horario.imprimir();
        std::cout << std::endl;
        */
        //alineamos a la izquierda el nombre del día, y como setfill esta dentro no afecta al resto.
        std::cout<<std::left<<std::setfill(' ')<< std::setw(12)<<nombreDia<<": ";
        
        //imprimimos el horario, que usará setfill('0') para los numeros. No se escribe todo en una sola linea porque cout espera un dato e imprimir es void.
        std::cout<<std::right;
        horario.imprimir();
        std::cout<<std::endl;

    }
};

// ============================================================
// main: Array de objetos compuestos (Semana completa)
// ============================================================
int main() {
    std::cout << "=== REGISTRO DE SEMANA LABORAL ===" << std::endl;

    // Array de objetos de tipo DiaLaboral en el Stack:
    DiaLaboral semana[5] = {
        DiaLaboral("Lunes",     8, 30, 16, 30),
        DiaLaboral("Martes",    9,  0, 17,  0),
        DiaLaboral("Miercoles", 8, 30, 17, 30),
        DiaLaboral("Jueves",    9,  0, 18,  0),
        DiaLaboral("Viernes",   8,  0, 14,  0)
    };

    int totalMinutosSemana = 0;

    for (int i = 0; i < 5; i++) {
        semana[i].mostrarResumen();
        totalMinutosSemana += semana[i].getMinutos();
    }

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Total semanal trabajado: " 
              << totalMinutosSemana / 60 << " horas y " 
              << totalMinutosSemana % 60 << " minutos." << std::endl;

    return 0;
}
