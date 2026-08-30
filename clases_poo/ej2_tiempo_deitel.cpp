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
//    - Probar la creación de objetos con 0, 1, 2 y 3 argumentos:
//        Tiempo2 t1;             // 00:00:00
//        Tiempo2 t2(2);          // 02:00:00
//        Tiempo2 t3(21, 34);     // 21:34:00
//        Tiempo2 t4(12, 25, 42); // 12:25:42
//    - Imprimir el estado de cada objeto.
// ============================================================

#include <iostream>
#include <iomanip>

class Tiempo2 {
public:
    Tiempo2(int = 0, int = 0, int = 0); // Constructor predeterminado
    ~Tiempo2();                         // Destructor

    // Setters
    void setHoraFull(int, int, int);
    void setHora(int); //esto se le llama firma, es solamente el prototipo, sin codigo. lleva punto y coma.
    void setMinuto(int);
    void setSegundo(int);

    // Getters (const)
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;

    // Métodos de impresión (const)
    void imprimeUniversal() const;
    void imprimeEstandar() const;

private:
    int hora;
    int minuto;
    int segundo;
};

// ============================================================
// DEFINICIÓN DE MÉTODOS FUERA DE LA CLASE (Uso de 'Tiempo2::')
// ============================================================

// 1. Constructor: puede delegar en setHoraFull(hr, min, seg);
Tiempo2::Tiempo2(int hr, int min, int seg) {
    std::cout << "[Constructor invocado]" << std::endl;
    setHoraFull(hr, min, seg);

}

// 2. Destructor
Tiempo2::~Tiempo2() {
    std::cout << "[Destructor invocado]" << std::endl;
}

// 3. Setters
void Tiempo2::setHoraFull(int h, int m, int s) {
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

void Tiempo2::setHora(int h) { this->hora = (h>=0 && h<24) ? h: 0; }

void Tiempo2::setMinuto(int m) { this -> minuto = (m>=0 && m<60) ? m: 0; }

void Tiempo2::setSegundo(int s) { this -> segundo = (s>=0 && s<60) ? s: 0; }

// 4. Getters
int Tiempo2::getHora() const { return hora; }

int Tiempo2::getMinuto() const { return minuto; }

int Tiempo2::getSegundo() const { return segundo; }

// 5. Métodos de Impresión
void Tiempo2::imprimeUniversal() const {
    std::cout<<std::setfill('0')
         <<std::setw(2)<<getHora()<<":"
         <<std::setw(2)<<getMinuto()<<":"
         <<std::setw(2)<<getSegundo()<<std::endl;
}

void Tiempo2::imprimeEstandar() const {
    // tu código acá (formato 12hs HH:MM:SS AM/PM)
int hora12 = (getHora() == 0 || getHora() ==12) ? 12: getHora() % 12;
std::cout<<std::setfill('0')
         <<std::setw(2)<<hora12<<":"
         <<std::setw(2)<<getMinuto()<<":"
         <<std::setw(2)<<getSegundo()<<" ";
            if(getHora() > 0 && getHora()<12){
             std::cout<<std::setfill('0')
             <<std::setw(2)<<"AM"<<std::endl;
         }else{
            std::cout<<std::setfill('0')
             <<std::setw(2)<<"PM"<<std::endl;
        }
}

// ============================================================
// main
// ============================================================

int main() {
    std::cout << "--- Creando t1 (por defecto) ---" << std::endl;
    Tiempo2 t1;
    std::cout << "t1 Universal: ";
    t1.imprimeUniversal();

    std::cout << "\n--- Creando t2 (solo hora = 2) ---" << std::endl;
    Tiempo2 t2(2);
    std::cout << "t2 Universal: ";
    t2.imprimeUniversal();

    std::cout << "\n--- Creando t3 (hora = 21, min = 34) ---" << std::endl;
    Tiempo2 t3(21, 34);
    std::cout << "t3 Universal: ";
    t3.imprimeUniversal();
    std::cout << "t3 Estandar:  ";
    t3.imprimeEstandar();

    std::cout << "\n--- Creando t4 (completo: 12, 25, 42) ---" << std::endl;
    Tiempo2 t4(12, 25, 42);
    std::cout << "t4 Universal: ";
    t4.imprimeUniversal();
    std::cout << "t4 Estandar:  ";
    t4.imprimeEstandar();

    std::cout << "\n--- Fin del main (Observar orden de destruccion) ---" << std::endl;
    return 0;
}
