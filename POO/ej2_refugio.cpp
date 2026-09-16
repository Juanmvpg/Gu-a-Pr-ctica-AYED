// ============================================================
// EJERCICIO 2 — Nivel Intermedio: El Refugio
// ============================================================
// Conceptos a evaluar: Punteros a objetos, memoria dinámica (new/delete).
//
// Enunciado:
// 1. Crear una clase `Mascota` que tenga un atributo `nombre` (string). 
//    Su constructor debe recibir el nombre y mostrar en consola "Nacio la mascota [nombre]". 
//    Su destructor debe mostrar "La mascota [nombre] se fue a dormir".
// 2. Crear una clase `Adoptante` que tenga como atributo privado un puntero a 
//    Mascota (`Mascota* miMascota`).
// 3. El constructor de `Adoptante` debe recibir un nombre (string) y, dentro de su bloque, 
//    instanciar dinámicamente a la mascota (`new Mascota(nombre)`).
// 4. El destructor de `Adoptante` debe encargarse de liberar la memoria de su mascota usando `delete`.
// 5. En el main(), creá un Adoptante estáticamente y dejá que termine el programa. 
//    Deberías ver en consola cómo los constructores y destructores se llaman en cascada.
// ============================================================

#include <iostream>
#include <string>

using namespace std;

// TODO: Definir la clase Mascota aquí
class mascota{
private:
    std::string nombre;

public:
    mascota(std::string name){
    std::cout<<"Nacio la mascota "<<name<<std::endl;
    this->nombre=name;
    }    

    ~mascota(){
        std::cout<<"La mascota "<<nombre<<" se fue a dormir"<<std::endl;
    }
};

// TODO: Definir la clase Adoptante aquí
class adoptante{
private:    
    mascota* miMascota;

public:
    adoptante(std::string nombre){
        miMascota = new mascota(nombre);        
    }

    ~adoptante(){
        delete miMascota;
    }

};

int main() {
std::cout << "=== EJERCICIO 2: EL REFUGIO ===" <<std::endl;
std::string nombre= "Benja";    

adoptante miAdoptante(nombre);//instancia adoptante pasandole el nombre del perro



    
    return 0;
}
