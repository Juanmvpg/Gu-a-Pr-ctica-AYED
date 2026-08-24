// ============================================================
// EJERCICIO 1 — Clase 'Tiempo': Encapsulamiento, Validaciones y 'this'
// ------------------------------------------------------------
// Enunciado:
// Diseñá una clase 'Tiempo' que represente una hora del día.
//
// 1. Atributos privados (encapsulados):
//    - int hora;     (0 a 23)
//    - int minuto;   (0 a 59)
//    - int segundo;  (0 a 59)
//
// 2. Métodos públicos:
//    - void setTiempo(int hora, int minuto, int segundo);
//      Asigna los valores verificando que sean válidos. Si alguno no es
//      válido, asigna 0 por defecto.
//      *Nota:* Usá el puntero 'this->hora = hora;' para resolver la
//      ambigüedad de nombres entre parámetros y atributos.
//    - void imprimirMilitar() const;
//      Imprime en formato HH:MM:SS (ej: 14:05:09).
//    - void imprimirEstandar() const;
//      Imprime en formato 12 horas con AM/PM (ej: 2:05:09 PM).
//    - void incrementarSegundo();
//      Avanza un segundo el reloj, manejando el desborde de segundos,
//      minutos y horas (ej: 23:59:59 -> 00:00:00).
// ============================================================

#include <iostream>
#include <iomanip>

class Tiempo {
private: // atributos
    int hora;
    int minuto;
    int segundo;

public:
    void setTiempo(int hora, int minuto, int segundo){
            //patrón operador ternario: condición ? valorTrue: valorFalse
        this->hora = (hora>=0 && hora<24) ? hora: 0;
        this->minuto = (minuto >=0 && minuto <60) ? hora : 0;
        this->segundo = (segundo>= 0 && segundo<60) ? hora: 0;

    }

    void imprimirMilitar() const{
        std::cout <<std::setfill('0') 
                  <<std::setw(2)<<hora<<":"
                  <<std::setw(2)<<minuto<<":"
                  <<std::setw(2)<<segundo<<""<<std::endl;
    }

    void imprimirEstandar() const{        
        if(hora>=12){
            
            std::cout<<std::setw(2)<<hora%12<<":";
        }else{
            std::cout<<std::setfill('0')
                    <<std::setw(2)<<hora<<":";
        }
        std::cout<<std::setfill('0')
                 <<std::setw(2)<<minuto<<":"
                 <<std::setw(2)<<segundo;

        if(hora>=12){
            std::cout<<std::setfill('0')
                     <<" PM"<<std::endl;
        }else{
            std::cout<<std::setfill('0')
                     <<" AM"<<std::endl;
        }
    }

    void incrementarSegundo(){
        segundo++;
        if(segundo==60){
            minuto++;
            segundo=0;
                if(minuto==60){
                    hora++;
                    minuto=0;                
                        if(hora==24){
                            hora=00;
                        }
                }
        }   
    }



};

int main() {
    Tiempo t;
    t.setTiempo(12, 0, 0);

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
