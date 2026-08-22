#include <iostream>
#include <cstring>
using namespace std;

// ============================================================
// EJERCICIO 3 — Arrays Dinámicos de Estructuras y Aritmética
// ------------------------------------------------------------
    // 1. Usá las estructuras 'Fecha' y 'Persona' (con 'Fecha nac').
    // 2. Implementá:
    //    - void cargarGrupo(Persona* grupo, int n):
    //      Carga 'n' personas usando aritmética: (grupo + i)->campo.
    //    - void imprimirGrupo(const Persona* grupo, int n):
    //      Recorre e imprime las 'n' personas.
    //    - Persona* buscarPorDNI(Persona* grupo, int n, long dniBuscado):
    //      Recorre el array. Si encuentra el DNI, retorna el puntero directo
    //      a esa Persona dentro del array. Si no, retorna nullptr.
    // 3. En el main():
    //    - Pedí memoria para un array dinámico de 3 Personas.
    //    - Cargalo e imprimilo.
    //    - Buscá una persona por su DNI.
    //    - Si fue encontrada, modificale el nombre usando el puntero retornado.
    //    - Volvé a imprimir el grupo para comprobar que el array se modificó.
    //    - Liberá la memoria con delete[].
    // ============================================================

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[30];
    long dni;
    Fecha nac;
};

// Implementá las tres funciones:
void cargarGrupo(Persona* grupo, int n) {
    for(int i=0; i<n; i++){
        strcpy((grupo +i)->nombre, "Luisa Castro");
        (grupo +i)-> dni=1000+i;
        (grupo +i)-> nac.dia= 1 +i;
        (grupo +i)-> nac.mes= 5 + i;
        (grupo +i)-> nac.anio= 2000 + i;
    }
}

void imprimirGrupo(const Persona* grupo, int n) { //const nos permite solamente leer datos, no deja modificar. Concepto Mínimo Privilegio (const correctness)
    for(int i=0; i<n; i++){
        cout << (grupo +i)->nombre<< ": ";
        cout << (grupo +i)->dni<< ", ";
        cout << (grupo +i)->nac.dia<< ", "; //para mejorar el código esto podría independizarse en función void imprimirFecha
        cout << (grupo +i)->nac.mes<< ", ";
        cout << (grupo +i)->nac.anio<< endl;
    }
}

Persona* buscarPorDNI(Persona* grupo, int n, long dniBuscado) {
    for(int i =0; i<n; i++){        
        if((grupo +i)->dni == dniBuscado){
            return grupo +i;        
        }
    }
    return nullptr;
}

int main() {
    Persona* arrGrupos = new Persona [3];
    cargarGrupo(arrGrupos, 3);
    imprimirGrupo(arrGrupos, 3);
    Persona* pp; //no hace falta liberar posteriormente porque no está en el heap y apunta dentro de un bloque, de hacerlo borraría una dirección de arrGrupos: Crash (undefined behavior).

    pp = buscarPorDNI (arrGrupos, 3, 1009);    
    ////FALLO ANTE INEXISTENCIA DE DNI, INTENTO 1
        /*        
        strcpy(pp->nombre, "juanceto");
        */
if (pp != nullptr){
    strcpy(pp->nombre, "juanceto"); // importante aprender esto
        imprimirGrupo(arrGrupos, 3);
}else{
    cout<<"No existe persona registrada con este DNI";
}

    
    
    
delete[] arrGrupos;
    arrGrupos = nullptr;
    return 0;
}
