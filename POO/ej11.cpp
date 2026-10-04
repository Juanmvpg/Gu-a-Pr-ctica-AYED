// ============================================================
// EJERCICIO 8 — El Hospital (El Jefe Final)
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Todo el cuatrimestre junto: Composición, Arreglos Dinámicos de 
//   Punteros, Destructores y Regla de los Tres.
//
// Enunciado:
// Construí una clase `Hospital` que administre objetos `Paciente`. 
// A diferencia de la Empresa del Ej. 5, el arreglo interno de pacientes 
// del Hospital NO debe ser estático (de tamaño fijo 5). El tamaño 
// máximo del hospital debe definirse por parámetro en su constructor, 
// obligándote a reservar un arreglo dinámico de punteros con `new`.
// 
// Tareas críticas:
// 1. Deberás implementar un Destructor en el Hospital muy cuidadoso 
//    para limpiar toda esa memoria sin dejar fugas.
// 2. Debes implementar el Constructor de Copia del Hospital para 
//    evitar un crash por "Doble Delete" si alguien en el main hace: 
//    `Hospital hosp2 = hosp1;`
//
// Nota: El diseño de los atributos del Paciente queda a tu criterio.
// ============================================================

#include <iostream>
#include <string>

class paciente{
std::string nombre;

public:
    paciente(){
        nombre = "Libre";
    }
    paciente(std::string nombrePaciente){
        nombre=nombrePaciente;
    }

    void setPaciente(std::string nombrePaciente){

        nombre=nombrePaciente;
    }

    std::string getPaciente() const{
        return nombre;
    }
};

class hospital{
    paciente* camas;
    int cantidadMaxima;
    int cantidadActual;
public:
    hospital(int max){
        cantidadMaxima=max;
        camas = new paciente[cantidadMaxima];
        cantidadActual=0;
    }

    hospital(const hospital& otro){
        cantidadMaxima = otro.cantidadMaxima;
        camas = new paciente[cantidadMaxima];
        cantidadActual = otro.cantidadActual;
        
        for(int i=0; i<cantidadActual;i++){
            camas[i]=otro.camas[i];
        }
    }

    void agendarPaciente(std::string nombrePaciente){
        if(cantidadActual<cantidadMaxima){
            camas[cantidadActual].setPaciente(nombrePaciente);
            cantidadActual++;
        }else{
            std::cout<<"No hay cupo"<<std::endl;
        }
    }

    void mostrarPacientes() const{
        std::cout<<std::endl<<"Los pacientes actuales son: "<<std::endl;
        for(int i =0; i< cantidadActual; i++){
            std::cout<<camas[i].getPaciente()<<std::endl;
        }
    }

    ~hospital(){
        delete[] camas;
    };
};
int main() {
    std::cout << "=== EJERCICIO 8: HOSPITAL ===" << std::endl;

    std::cout<<"Cuantos pacientes ingresaran?"<<std::endl;
    int conth1;
    std::cin>>conth1;
    hospital* h1 = new hospital(conth1 + 1);
    std::string name;
    for(int i=0; i<conth1; i++){
        std::cout<<"Cómo se llama el paciente "<<i<<"?"<<std::endl;    
        std::cin>>name;
        h1->agendarPaciente(name);
    }
    std::cout<<"Pacientes en original";
    h1->mostrarPacientes();

    hospital* h2 = new hospital(*h1);
    std::cout<<"Agregas alguien a al copia? Ingresa el nombre o 'No':"<<std::endl;
    std::cin>>name;
    while(name!="no"){
        h2->agendarPaciente(name);
        std::cout<<"Agregas alguien a al copia? Ingresa el nombre o 'No':"<<std::endl;
        std::cin>>name;
    }
    std::cout<<"Pacientes en copia";
    h2->mostrarPacientes();
    

    delete h1;
    delete h2;
    return 0;
}

