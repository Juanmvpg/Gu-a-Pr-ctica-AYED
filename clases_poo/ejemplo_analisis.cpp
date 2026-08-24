// ============================================================
// EJERCICIO PREVIO — Análisis Guiado de una Clase Completa
// ============================================================
// Vamos a estudiar paso a paso cómo se estructura una clase
// con atributos privados, métodos públicos, el puntero 'this'
// y métodos 'const'.
// ============================================================

#include <iostream>

class CuentaBancaria {
private:
    // ------------------------------------------------------------
    // 1. ATRIBUTOS PRIVADOS (Estado interno protegido)
    // Solo los métodos de esta clase pueden verlos o modificarlos.
    // ------------------------------------------------------------
    int numeroCuenta;
    double saldo;

public:
    // ------------------------------------------------------------
    // 2. MÉTODO DE INICIALIZACIÓN / CONFIGURACIÓN (Setter múltiple)
    // ## - Recibe parámetros con los mismos nombres que los atributos.
    // - Usa 'this->' para distinguir el atributo del parámetro.
    // ------------------------------------------------------------
    void configurarCuenta(int numeroCuenta, double saldoInicial) {
        this->numeroCuenta = numeroCuenta; // this->numeroCuenta es el atributo; numeroCuenta es el parámetro
        
        // Validación de invariante: el saldo no puede ser negativo al inicio
        if (saldoInicial >= 0.0) {
            this->saldo = saldoInicial;
        } else {
            this->saldo = 0.0;
        }
    }

    // ------------------------------------------------------------
    // 3. MÉTODOS DE COMPORTAMIENTO (Mutadores / Modifican el estado)
    // Cambian los valores de los atributos bajo reglas estrictas.
    // ------------------------------------------------------------
    void depositar(double monto) {
        if (monto > 0.0) {
            saldo += monto; // Equivalente a: this->saldo += monto;
            std::cout << "Deposito exitoso de: $" << monto << std::endl;
        } else {
            std::cout << "Error: Monto de deposito invalido." << std::endl;
        }
    }

    bool extraer(double monto) {
        // Regla de negocio: solo extrae si hay fondos suficientes y monto positivo
        if (monto > 0.0 && monto <= saldo) {
            saldo -= monto;
            std::cout << "Extraccion exitosa de: $" << monto << std::endl;
            return true;
        }
        std::cout << "Error: Fondos insuficientes o monto invalido." << std::endl;
        return false;
    }

    // ------------------------------------------------------------
    // 4. MÉTODOS DE CONSULTA (Accesores / Solo Lectura -> const)
    // Llevan 'const' al final porque GARANTIZAN que no modifican
    // ningún atributo del objeto.
    // ------------------------------------------------------------
    double obtenerSaldo() const {
        return saldo; // Solo lee 'saldo', no lo altera
    }

    int obtenerNumeroCuenta() const {
        return numeroCuenta;
    }

    void mostrarEstado() const {
        std::cout << "Cuenta Nro: " << numeroCuenta 
                  << " | Saldo actual: $" << saldo << std::endl;
    }
};

// ============================================================
// FUNCIÓN PRINCIPAL (main)
// Observá cómo interactúa el mundo exterior con el objeto
// ============================================================
int main() {
    // 1. Instanciamos el objeto en el Stack:
    CuentaBancaria miCuenta;

    // 2. Intentar hacer: miCuenta.saldo = 50000; DARÍA ERROR DE COMPILACIÓN
    // porque 'saldo' es privado. El mundo exterior debe usar métodos públicos:
    miCuenta.configurarCuenta(1024, 500.0);

    // 3. Consultamos el estado inicial (método const):
    miCuenta.mostrarEstado();

    // 4. Ejecutamos comportamientos (métodos mutadores):
    miCuenta.depositar(250.0);
    miCuenta.extraer(100.0);
    miCuenta.extraer(9000.0); // Intento de extracción que viola la validación

    // 5. Estado final:
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Saldo final consultado con getter: $" << miCuenta.obtenerSaldo() << std::endl;
    miCuenta.mostrarEstado();

    return 0;
}
