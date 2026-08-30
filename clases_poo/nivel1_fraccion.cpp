// ============================================================
// NIVEL 1 — Clase 'Fraccion': Operaciones entre Objetos
// ============================================================
// Objetivos:
//   1. Constructor con validación (el denominador NUNCA puede ser 0).
//   2. Método privado de utilidad 'simplificar()' que use el MCD.
//   3. Métodos que reciben otro objeto como parámetro por referencia constante:
//        Fraccion sumar(const Fraccion& otra) const;
//        Fraccion multiplicar(const Fraccion& otra) const;
//   4. Métodos 'const' de consulta.
// ============================================================

#include <iostream>

class Fraccion { //define reglas matemáticas de una fracción
private:
    //Si fueran públicos entonces se puede acceder mediante el punto (ej: f1.den) y asignar el valor den=0, que rompe la matemática. En private garantizo a través del constructor que nunca será 0.
    int num;
    int den;

    // Función auxiliar para calcular el Máximo Común Divisor (mcd-Euclides)
    //mcd y simplificar privadas para simplmente aplicar, es decir, que sean herramientas. NO SE PUEDEN ACCEDER MEDIANTE MAIN
    int mcd(int a, int b) const {//const, es inmutable.
        a = (a < 0) ? -a : a;
        b = (b < 0) ? -b : b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a == 0) ? 1 : a;
    }

    // Simplifica la fracción dividiendo num y den por su MCD
    void simplificar() {
        int divisor = mcd(num, den);
        num /= divisor;
        den /= divisor;
        
        // Convención: el signo negativo siempre queda en el numerador
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public: //API, funciones que se usarán en Main. Servicios que ofrece la fracción al resto del programa.
    // 1. Constructor: si den es 0, asigna den = 1. Al final llama a simplificar();

    //una función es constructor si y solo si 
    Fraccion(int n = 0, int d = 1) {
        //se necesita guardar el valor de n en num y d en den
        this->num = n;
        this->den = (d==0 ? 1: d); //evita que pongan el denominador=0, en tal caso le pone 1.
        simplificar();
    }

    // 2. Getters
    int getNumerador() const   { return num; }
    int getDenominador() const { return den; }

    // 3. Suma: (a/b) + (c/d) = (a*d + b*c) / (b*d)
    // Retorna una NUEVA Fraccion con el resultado.
    Fraccion sumar(const Fraccion& otra) const {
    //const Fracción& para evitar duplicar el objeto en memoria, permite que se trabaje con alias del propio objeto.
        //obtiene el valor del atributo, que lo definen los Getters
        int nuevoNum = this->num * otra.den + this->den * otra.num;
        int nuevoDen = this->den * otra.den;
        return Fraccion(nuevoNum, nuevoDen);
        // Tu código acá
    }

    // 4. Multiplicación: (a/b) * (c/d) = (a*c) / (b*d)
    Fraccion multiplicar(const Fraccion& otra) const {
        // Tu código acá
        int nuevoNum = this->num * otra.num;
        int nuevoDen = this->den * otra.den;
        return Fraccion(nuevoNum, nuevoDen);
    }

    // 5. Imprimir en formato "num/den" (o solo "num" si den es 1)
    void imprimir() const {
           (den==1) ? std::cout<<getNumerador(): (std::cout<<getNumerador()<<"/"<<getDenominador());
    }
};

int main() {
    //objetos que nacen en tiempo de ejecución: f1, f2, f3
    Fraccion f1(1, 2);  // 1/2
    Fraccion f2(2, 4);  // Debe simplificarse automáticamente a 1/2
    Fraccion f3(3, 4);  // 3/4

    std::cout << "f1: "; f1.imprimir(); std::cout << std::endl;
    std::cout << "f2 (simplificada): "; f2.imprimir(); std::cout << std::endl;
    std::cout << "f3: "; f3.imprimir(); std::cout << std::endl;

    // Operaciones
    //fSuma es otro objeto, nace como resultado de la operación
    Fraccion fSuma = f1.sumar(f3); // 1/2 + 3/4 = 5/4
    std::cout << "\nSuma (f1 + f3): ";
    fSuma.imprimir(); 
    std::cout << std::endl;

    Fraccion fMult = f1.multiplicar(f3); // 1/2 * 3/4 = 3/8
    std::cout << "Multiplicacion (f1 * f3): ";
    fMult.imprimir(); 
    std::cout << std::endl;

    Fraccion fCero(5, 0); // Denominador 0 inválido -> debe quedar 5/1
    std::cout << "\nFraccion con den=0: ";
    fCero.imprimir();
    std::cout << std::endl;

    // Resultado esperado:
    // f1: 1/2
    // f2 (simplificada): 1/2
    // f3: 3/4
    // 
    // Suma (f1 + f3): 5/4
    // Multiplicacion (f1 * f3): 3/8
    // 
    // Fraccion con den=0: 5

    return 0;
}
