#include <iostream>
using namespace std;

struct Alumno {
    int legajo;
    int notaFinal;
};

void cargar(Alumno* a, int leg, int nota) {
    a->legajo = leg;
    a->notaFinal = nota;
}

void mostrar(const Alumno* a) {
    cout << "Legajo: " << a->legajo << " | Nota: " << a->notaFinal << endl;
}   

int main() {
    Alumno a1;
    cargar(&a1, 1001, 8);
    mostrar(&a1);

    Alumno* a2 = new Alumno;
    cargar(a2, 1002, 9);
    mostrar(a2);

    delete a2;
    a2 = nullptr;

    return 0;
}
