// ============================================================
// NIVEL 2 — Clase 'ArraySeguro': Memoria Dinámica, Destructores y RAII
// ============================================================
// Objetivos:
//   1. Implementar una clase que envuelva un array dinámico en el Heap.
//   2. Constructor: solicita memoria con 'new int[capacidad]'.
//   3. DESTRUCTOR (~ArraySeguro): libera la memoria con 'delete[]' automáticamente.
//   4. Encapsulamiento de acceso seguro con validación de límites:
//        - bool set(int indice, int valor);
//        - int get(int indice, bool& exito) const;
//   5. Métodos de utilidad: capacidadActual(), imprimir().
// ============================================================

#include <iostream>

class ArraySeguro {
private:
    int* datos;     // Puntero al bloque en el Heap
    int capacidad;  // Cantidad máxima de elementos

public:
    // 1. Constructor: reserva memoria en el Heap e inicializa en ceros
    ArraySeguro(int cap = 5) {
        this->capacidad = (cap > 0) ? cap : 5;//Minimo 5 elementos en el array datos
        this->datos = new int[capacidad];
        
        // Inicializamos todos los elementos en 0
        for (int i = 0; i < capacidad; i++) {
            *(this->datos + i) = 0;
        }
        std::cout << "[Constructor] Array creado en Heap con capacidad: " << capacidad << std::endl;
    }

    // 2. DESTRUCTOR (El corazón de RAII):
    // Se ejecuta automáticamente al salir de scope.
    // Libera la memoria dinámica para que el programador no tenga que hacer delete[].
    ~ArraySeguro() {
        delete[] datos;
        datos = nullptr; //buena práctica, evita dangling pointers
        std::cout<<"[Destructor] Memoria en Heap liberada correctamente."<<std::endl;
    }

    // 3. Setter seguro: asigna solo si el índice está dentro de [0, capacidad - 1]
    // Retorna true si fue exitoso, false si el índice era inválido (fuera de rango).
    bool set(int indice, int valor) {
        if(indice>=0 && indice<=(this->capacidad -1)){
             *(this->datos + indice)= valor;
              return true;
        }
        return false;
    }

    // 4. Getter seguro: lee solo si el índice es válido
    // Escribe 'true' en la variable de referencia 'exito' si pudo leer, o 'false' si no.
    int get(int indice, bool& exito) const {
        if(indice>=0 && indice<=(this->capacidad -1)){
             exito=true; 
             return *(this->datos + indice);        
        }
        exito=false;
        return 0;
    }

    int getCapacidad() const {
        return capacidad;
    }

    void imprimir() const {
        std::cout << "[ ";
        for (int i = 0; i < capacidad; i++) {
            std::cout << *(datos + i) << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::cout << "--- Inicio del bloque principal ---" << std::endl;

    { // Bloque delimitador {} para observar el ciclo de vida
        ArraySeguro miArray(4);

        // Escrituras válidas
        miArray.set(0, 10);
        miArray.set(1, 20);
        miArray.set(2, 30);
        miArray.set(3, 40);

        // Intento de escritura fuera de rango (debe ser rechazada)
        bool pudoEscribir = miArray.set(99, 999);
        std::cout << "¿Pudo escribir en indice 99?: " << (pudoEscribir ? "SI" : "NO (Rechazado)") << std::endl;

        std::cout << "Contenido de miArray: ";
        miArray.imprimir();

        // Lecturas
        bool ok = false;
        int valor = miArray.get(2, ok);
        if (ok) {
            std::cout << "Elemento en indice 2: " << valor << std::endl;
        }

        int valorInvalido = miArray.get(10, ok);
        if (!ok) {
            std::cout << "Lectura en indice 10 rechazada correctamente." << std::endl;
        }

        std::cout << "--- Fin del bloque delimitador (el objeto muere aca) ---" << std::endl;
    } // <-- ¡Al llegar acá se destruye miArray y se libera el Heap automáticamente!

    std::cout << "--- Fin del programa (Memoria ya liberada sin fugas) ---" << std::endl;

    // Resultado esperado en consola:
    // --- Inicio del bloque principal ---
    // [Constructor] Array creado en Heap con capacidad: 4
    // ¿Pudo escribir en indice 99?: NO (Rechazado)
    // Contenido de miArray: [ 10 20 30 40 ]
    // Elemento en indice 2: 30
    // Lectura en indice 10 rechazada correctamente.
    // --- Fin del bloque delimitador (el objeto muere aca) ---
    // [Destructor] Memoria en Heap liberada correctamente.
    // --- Fin del programa (Memoria ya liberada sin fugas) ---

    return 0;
}
