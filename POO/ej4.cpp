// ============================================================
// EJERCICIO 1 — Sobrecarga de Constructores, Validaciones y Métodos const
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Constructores sobrecargados (por defecto y con parámetros).
// - Métodos `const` (garantizan que no modifican atributos).
// - Validaciones de reglas de negocio en métodos.
//
// Enunciado:
// Crear una clase `BilleteraDigital`:
// 1. Atributos privados: `titular` (string) y `saldo` (double).
// 2. Constructores:
//    - Constructor por defecto: inicializa titular en "Anonimo" y saldo en 0.0.
//    - Constructor con parámetros: recibe titular y saldo inicial.
//      (Si el saldo inicial recibido es negativo, inicializar en 0.0).
// 3. Métodos:
//    - `void depositar(double monto)`: suma al saldo solo si monto > 0.
//    - `bool extraer(double monto)`: si monto > 0 y hay saldo suficiente,
//      descuenta y retorna true. En caso contrario, retorna false.
//    - `double getSaldo() const`: retorna el saldo actual.
//    - `string getTitular() const`: retorna el titular.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// TODO: Definir la clase BilleteraDigital aquí
class BilleteraDigital{
private:
    string titular;
    double saldo;
public:
//primer constructor
    BilleteraDigital() {//constructor por defecto: sin tipo de retorno, mismo nombre de la clase y con valores iniciales
        this->titular="anonimo";
        this->saldo=0.0;
    }
//segundo constructor: sobrecarga. En vez de estar vacío recibe parámetros
    BilleteraDigital(string titular, double saldo){
        this->titular=titular;
        if(saldo<0){saldo=0.0;}
        this->saldo=saldo;
    }

//setter
    bool depositar(double monto){
        if(monto>0){ 
            this->saldo += monto;
            return true;
        }
        return false;
    }
    bool extraer(double monto){
        if(monto>0 && this->saldo>= monto){ 
        this->saldo -=monto; 
        return true;
        }
        return false;
    }

//getter
    double getSaldo() const{ return saldo; }
    string getTitular()const{ return titular; }
};

int main() {
    std::cout << "=== EJERCICIO 1: BILLETERA DIGITAL ===" << std::endl;

    // TODO: Crear billetera, intentar extraer más de lo disponible,
    // depositar dinero válido y verificar saldos por consola.
    BilleteraDigital* cartera= new BilleteraDigital();
    
    std::cout<<"===========VALORES INICIALES==========="<<std::endl;
    std::cout<<cartera->getTitular()<<std::endl;
    std::cout<<cartera->getSaldo()<<std::endl;

    std::cout<<"===========Billetera 2===================="<<std::endl;
    string nombre;
    double monto;

    std::cout<<"A nombre de?"<<std::endl;
    std::cin>>nombre;
    std::cout<<"con cuanto empieza?"<<std::endl;
    std::cin>>monto;
while(monto<0){
    std::cout<<"No puede ser negativo. Ingresa nuevamente"<<std::endl;
    cin>>monto;
}
    BilleteraDigital* carteraPublica = new BilleteraDigital(nombre, monto);
    std::cout<<carteraPublica->getTitular()<<std::endl;
    std::cout<<carteraPublica->getSaldo()<<std::endl;

    std::cout<<"===========Deposita===================="<<std::endl;
    std::cout<<"Cuanto depositas?"<<std::endl;
    std::cin>>monto;

if(monto<=0){
    std::cout<<"El depósito debe ser mayor a 0"<<std::endl;
}else{
    carteraPublica->depositar(monto);
    std::cout<<"nuevo saldo: "<<carteraPublica->getSaldo()<<std::endl;
}    

    std::cout<<"===========Extrae===================="<<std::endl;
    std::cout<<"Cuanto sacas?"<<std::endl;
    std::cin>>monto;

if(monto> carteraPublica->getSaldo()){
    std::cout<<"No tenes tanto, bro"<<std::endl;
}else{
    carteraPublica->extraer(monto);
    std::cout<<"nuevo saldo: "<<carteraPublica->getSaldo();

}    

    delete cartera;
    delete carteraPublica;
    return 0;
}
