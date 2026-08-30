// ============================================================
// NIVEL 3 — Composición en Profundidad: Fecha, Persona y Empleado
// ============================================================
// Objetivos de Arquitectura:
//   1. Modelar una jerarquía de composición de 3 niveles:
//        - 'Fecha': dia, mes, anio (0-31, 0-12, anio > 1900).
//        - 'Persona': nombre (std::string), dni (long), fechaNacimiento (Fecha).
//        - 'Empleado': persona (Persona), fechaIngreso (Fecha), sueldoBase (double).
//   2. Uso OBLIGATORIO de la Lista de Inicialización de miembros.
//   3. Métodos 'const' para cálculos de negocio:
//        - int calcularAntiguedad(int anioActual) const;
//        - double calcularSueldoNeto(int anioActual) const; (Bono de 5% por año de antigüedad)
//   4. Impresión jerárquica reutilizando los métodos imprimir() de cada clase.
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>

// ============================================================
// 1. CLASE COMPONENTE BASE: Fecha
// ============================================================
class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(int d = 1, int m = 1, int a = 2000) {
        setFecha(d, m, a);
    }

    void setFecha(int d, int m, int a) {
        this->dia  = (d >= 1 && d <= 31) ? d : 1;
        this->mes  = (m >= 1 && m <= 12) ? m : 1;
        this->anio = (a >= 1900)         ? a : 2000;
    }

    int getDia() const  { return dia; }
    int getMes() const  { return mes; }
    int getAnio() const { return anio; }

    void imprimir() const {
        std::cout << std::setfill('0')
                  << std::setw(2) << dia << "/"
                  << std::setw(2) << mes << "/"
                  << anio;
    }
};

// ============================================================
// 2. CLASE COMPUESTA INTERMEDIA: Persona (Tiene una Fecha de Nacimiento)
// ============================================================
class Persona {
private:
    std::string nombre;
    long dni;
    Fecha nacimiento; // Objeto componente 1

public:
    // Constructor usando Lista de Inicialización:
    Persona(const std::string& nom = "Sin Nombre", long doc = 0, int dNac = 1, int mNac = 1, int aNac = 2000)
        : nombre(nom), dni(doc), nacimiento(dNac, mNac, aNac)
    {
    }

    std::string getNombre() const { return nombre; }
    long getDni() const           { return dni; }
    Fecha getNacimiento() const   { return nacimiento; }

    int calcularEdad(int anioActual) const {
        return (anioActual >= nacimiento.getAnio()) ? (anioActual - nacimiento.getAnio()) : 0;
    }

    void imprimir() const {
        std::cout << nombre << " (DNI: " << dni << ", Nac: ";
        nacimiento.imprimir();
        std::cout << ")";
    }
};

// ============================================================
// 3. CLASE COMPUESTA PRINCIPAL: Empleado (Tiene Persona y Fecha de Ingreso)
// ============================================================
class Empleado {
private:
    Persona datosPersonales; // Objeto compuesto 1
    Fecha fechaIngreso;      // Objeto compuesto 2
    double sueldoBase;       // Atributo primitivo

public:
    // PREGUNTA INDAGATORIA:
    // ¿Cómo se inicializan 'datosPersonales', 'fechaIngreso' y 'sueldoBase'
    // en la lista de inicialización?
    Empleado(const std::string& nom, long doc, int dNac, int mNac, int aNac,
             int dIng, int mIng, int aIng, double sueldo)
             :datosPersonales(nom, doc, dNac, mNac, aNac), fechaIngreso(dIng, mIng, aIng)

    {
        (sueldo>=0) ? sueldoBase=sueldo: sueldoBase=0;
    }

    // Retorna los años trabajados desde el ingreso hasta anioActual
    int calcularAntiguedad(int anioActual) const {
        if(anioActual>=fechaIngreso.getAnio()){ 
            return (anioActual - fechaIngreso.getAnio());
        }
        return 0;
    }

    // Regla de Negocio: Sueldo neto = sueldoBase + (5% del sueldoBase * anios de antiguedad)
    double calcularSueldoNeto(int anioActual) const {
        return (sueldoBase + (0.05*sueldoBase*calcularAntiguedad(anioActual)));
    }

    void mostrarFicha(int anioActual) const {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "EMPLEADO: ";
        datosPersonales.imprimir();
        std::cout << "\nEdad:             " << datosPersonales.calcularEdad(anioActual) << " anios";
        std::cout << "\nFecha de Ingreso: ";
        fechaIngreso.imprimir();
        std::cout << "\nAntiguedad:       " << calcularAntiguedad(anioActual) << " anios";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nSueldo Base:      $" << sueldoBase;
        std::cout << "\nSueldo Neto:      $" << calcularSueldoNeto(anioActual);
        std::cout << "\n--------------------------------------------------" << std::endl;
    }
};

// ============================================================
// main
// ============================================================
int main() {
    const int ANIO_ACTUAL = 2026;

    std::cout << "=== SISTEMA DE GESTION DE EMPLEADOS ===" << std::endl;

    // Creamos dos empleados con composición completa:
    // Empleado 1: Carlos Gomez, DNI 35123456, Nac: 15/05/1990, Ingreso: 01/03/2016, Sueldo: $1000.00
    Empleado emp1("Carlos Gomez", 35123456, 15, 5, 1990, 1, 3, 2016, 1000.0);

    // Empleado 2: Ana Perez, DNI 40987654, Nac: 20/11/1998, Ingreso: 10/08/2021, Sueldo: $1200.00
    Empleado emp2("Ana Perez", 40987654, 20, 11, 1998, 10, 8, 2021, 1200.0);

    emp1.mostrarFicha(ANIO_ACTUAL);
    emp2.mostrarFicha(ANIO_ACTUAL);

    // Resultado esperado:
    // === SISTEMA DE GESTION DE EMPLEADOS ===
    // --------------------------------------------------
    // EMPLEADO: Carlos Gomez (DNI: 35123456, Nac: 15/05/1990)
    // Edad:             36 anios
    // Fecha de Ingreso: 01/03/2016
    // Antiguedad:       10 anios
    // Sueldo Base:      $1000.00
    // Sueldo Neto:      $1500.00 (1000 + 10 años * 5% = 1000 + 500)
    // --------------------------------------------------
    // EMPLEADO: Ana Perez (DNI: 40987654, Nac: 20/11/1998)
    // Edad:             28 anios
    // Fecha de Ingreso: 10/08/2021
    // Antiguedad:       5 anios
    // Sueldo Base:      $1200.00
    // Sueldo Neto:      $1500.00 (1200 + 5 años * 5% = 1200 + 300)
    // --------------------------------------------------

    return 0;
}
