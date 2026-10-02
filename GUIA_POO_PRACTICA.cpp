// ============================================================
//   GUÍA DE EJERCICIOS PRÁCTICOS
//   Tema: Programación Orientada a Objetos (Desde Cero)
// ============================================================
// Esta guía complementaria está pensada para que construyas cada 
// clase desde cero, fijando conceptos teóricos y patrones típicos 
// de parciales.
//
// Reglas de Trabajo:
//   - Nada de copiar código resuelto: Leé el enunciado.
//   - Planteá las clases en papel o mentalmente: Pensá qué 
//     atributos son privados y qué métodos públicos necesita.
//   - Iteramos juntos: Extraé el código comentado de cada 
//     ejercicio a un nuevo archivo .cpp, descomentalo y 
//     resolvelo.
// ============================================================


// ============================================================
// EJERCICIO 4 — Sobrecarga de Constructores, Validaciones y Métodos const
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
/*
#include <iostream>
#include <string>
using namespace std;

// TODO: Definir la clase BilleteraDigital aquí

int main() {
    cout << "=== EJERCICIO 1: BILLETERA DIGITAL ===" << endl;

    // TODO: Crear billetera, intentar extraer más de lo disponible,
    // depositar dinero válido y verificar saldos por consola.

    return 0;
}
*/


// ============================================================
// EJERCICIO 5 — Composición de Clases ("Tiene-un")
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Composición: una clase contiene instancias de otra clase.
// - Arreglos estáticos de objetos como atributo.
//
// Enunciado:
// 1. Crear clase `Item`:
//    - Atributos privados: `nombre` (string) y `precio` (double).
//    - Constructores: por defecto ("", 0.0) y con parámetros.
//    - Getters `const` para ambos atributos.
// 2. Crear clase `Pedido`:
//    - Atributos privados: `Item items[5]` y `int cantidad` (inicia en 0).
//    - Constructor por defecto: inicializa `cantidad` en 0.
//    - `bool agregarItem(string nombre, double precio)`:
//      Crea un Item en la posición actual si hay lugar, aumenta 
//      cantidad y retorna true. Si está lleno, retorna false.
//    - `double calcularTotal() const`: Devuelve la suma de precios.
//    - `void mostrarResumen() const`: Imprime nombre y precio de cada item.
// ============================================================
/*
#include <iostream>
#include <string>
using namespace std;

// TODO: Definir clase Item

// TODO: Definir clase Pedido

int main() {
    cout << "=== EJERCICIO 2: COMPOSICION DE CLASES ===" << endl;

    // TODO: Crear Pedido, agregar items y mostrar resumen

    return 0;
}
*/


// ============================================================
// EJERCICIO 6 — Memoria Dinámica en Atributos
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Punteros como atributos (arreglo dinámico `int* datos`).
// - Reservar con `new[]` y liberar con `delete[]` obligatoriamente.
//
// Enunciado:
// Crear clase `BolsaNumeros`:
// 1. Atributos privados: `int* datos`, `int capacidad`, `int cantidad`.
// 2. Constructor:
//    - Recibe `int cap`. Si `cap <= 0`, fijar capacidad en 5 por defecto.
//    - Reserva: `datos = new int[capacidad];`, `cantidad = 0;`.
// 3. Destructor:
//    - `delete[] datos;` e imprimir "Memoria liberada".
// 4. Métodos:
//    - `bool insertar(int valor)`: agrega si hay lugar y retorna true.
//    - `void mostrar() const`: imprime elementos.
//    - `double calcularPromedio() const`: retorna el promedio.
// ============================================================
/*
#include <iostream>
using namespace std;

// TODO: Definir clase BolsaNumeros

int main() {
    cout << "=== EJERCICIO 3: BOLSA CON MEMORIA DINAMICA ===" << endl;

    // TODO: Instanciar BolsaNumeros(4), insertar 5 números, 
    // mostrar elementos y verificar destrucción.

    return 0;
}
*/


// ============================================================
// EJERCICIO 7 — Jerarquía Polimórfica con Retorno
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Clase abstracta, métodos virtuales puros (`double`).
// - Arreglo de punteros polimórficos.
//
// Enunciado:
// 1. Clase abstracta `Figura`:
//    - Virtuales puros: `calcularArea() const`, `calcularPerimetro() const`,
//      y `mostrarInfo() const`.
//    - Destructor virtual.
// 2. Clase `Rectangulo` (hereda de Figura):
//    - Base y altura privadas. Sobrescribir los 3 métodos.
// 3. Clase `Circulo` (hereda de Figura):
//    - Radio privado. Sobrescribir los 3 métodos (usar pi=3.14159).
// 4. En main():
//    - Crear `Figura* figuras[3];`. 
//    - Asignar dinámicamente (`new`) Rectángulos y Círculos.
//    - Bucle para mostrarInfo() y acumular el área total.
//    - Imprimir área total y liberar con `delete` cada figura.
// ============================================================
/*
#include <iostream>
using namespace std;

// TODO: Definir clase abstracta Figura

// TODO: Definir clase Rectangulo

// TODO: Definir clase Circulo

int main() {
    cout << "=== EJERCICIO 4: POLIMORFISMO DE FIGURAS ===" << endl;

    // TODO: Crear arreglo de punteros, recorrer, sumar áreas y hacer delete

    return 0;
}
*/


// ============================================================
// EJERCICIO 5 — Integración: Composición + Polimorfismo
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Clases que administran arreglos de punteros polimórficos.
// - El objeto contenedor se hace cargo de la memoria de sus partes.
//
// Enunciado:
// 1. Clase abstracta `Empleado`: 
//    - Atributo privado `nombre` (string).
//    - Constructor que recibe nombre. Getter para el nombre.
//    - Método virtual puro: `double calcularSueldo() const = 0;`
//    - Destructor virtual.
// 2. Clase `Asalariado` (hereda de Empleado):
//    - Atributo privado `sueldoFijo`.
//    - Constructor que recibe nombre y sueldo.
//    - Sobrescribe `calcularSueldo()` retornando el sueldoFijo.
// 3. Clase `Comisionista` (hereda de Empleado):
//    - Atributos `ventas` (int) y `comisionPorVenta` (double).
//    - Constructor que recibe nombre, ventas y comision.
//    - Sobrescribe `calcularSueldo()` retornando ventas * comision.
// 4. Clase `Empresa`:
//    - Atributo privado: `Empleado* plantilla[5];`
//    - Atributo privado: `int cantidadEmpleados;`
//    - Constructor por defecto (inicializa cantidad en 0).
//    - Método `bool contratar(Empleado* emp)`: agrega al arreglo si hay lugar.
//    - Método `double calcularGastoTotalSueldos() const`: suma los sueldos.
//    - Destructor: OJO, debe hacer `delete` a cada empleado del arreglo.
// ============================================================
/*
#include <iostream>
#include <string>
using namespace std;

// TODO: Definir Empleado, Asalariado y Comisionista

// TODO: Definir Empresa

int main() {
    cout << "=== EJERCICIO 5: EMPRESA ===" << endl;

    // TODO: Instanciar Empresa, contratar 2 asalariados y 1 comisionista.
    // Mostrar el gasto total en sueldos. 
    // Nota: El main() ya no hace 'delete' de los empleados, de eso 
    // se tiene que encargar el destructor de la Empresa.

    return 0;
}
*/


// ============================================================
// EJERCICIO 6 — La "Regla de los Tres" (Constructor de Copia)
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Copia profunda vs Copia superficial (Deep copy vs Shallow copy).
// - Cuándo es obligatorio crear un Constructor de Copia.
//
// Enunciado:
// Imaginate que tenés un objeto con memoria dinámica (`new`). Si
// igualás un objeto a otro (`obj2 = obj1`), ambos punteros apuntarán
// al mismo lugar. Si se destruye uno, el otro queda apuntando a basura,
// y se produce un "Doble Delete" (el programa crashea).
// 
// Tarea:
// 1. Traé tu clase `BolsaNumeros` del Ejercicio 3 (con su new y delete).
// 2. Agregale un "Constructor de Copia". La firma es:
//    `BolsaNumeros(const BolsaNumeros& otra)`
// 3. Adentro de ese constructor, debes:
//    - Copiar la capacidad y la cantidad de la `otra` bolsa a esta.
//    - Reservar un NUEVO arreglo dinámico (`datos = new int[capacidad]`).
//    - Copiar los números del arreglo de `otra` al arreglo propio con un `for`.
// 4. En el `main`, creá una bolsa, agregale 2 números, y luego creá
//    una segunda bolsa usando copia: `BolsaNumeros copia(bolsaOriginal);`
//    Agregá un número extra a la copia y mostrá ambas para comprobar 
//    que no se mezclan (son independientes).
// ============================================================
/*
#include <iostream>
using namespace std;

// TODO: Traer la clase BolsaNumeros del Ejercicio 3 y agregarle 
// el Constructor de Copia.

int main() {
    cout << "=== EJERCICIO 6: COPIA PROFUNDA ===" << endl;

    // TODO: Crear original, copiarla, modificar la copia, 
    // mostrar ambas para comprobar independencia.

    return 0;
}
*/

// ============================================================
// EJERCICIO 7 — Sistema de Notificaciones (Diseño Libre)
// ------------------------------------------------------------
// Conceptos a evaluar:
// - Herencia, Clases Abstractas y Polimorfismo (sin guías estrictas).
//
// Enunciado:
// Diseñá un sistema de notificaciones polimórfico. Deberás tener 
// una clase base abstracta `Notificacion` que defina el contrato, y 
// al menos dos clases hijas (ej: `NotificacionEmail`, `NotificacionSMS`).
// En el `main`, deberás crear un arreglo de punteros polimórficos 
// con distintas notificaciones mezcladas y, usando un solo bucle for, 
// enviarlas todas mostrando sus detalles particulares en pantalla.
// 
// Nota: Vos decidís los atributos (a quién va dirigido, mensaje, etc.), 
// los constructores, y cómo se llama el método virtual.
// ============================================================
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== EJERCICIO 7: NOTIFICACIONES ===" << endl;

    return 0;
}
*/


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
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== EJERCICIO 8: HOSPITAL ===" << endl;

    return 0;
}
*/
