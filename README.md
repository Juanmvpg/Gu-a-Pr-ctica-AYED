# Guía Práctica AYED

Guía integral de ejercicios prácticos de **Algoritmos y Estructuras de Datos (AYED)** en C++.  
Construida de forma incremental, siguiendo estándares de arquitectura de software, gestión estricta de memoria (sin *memory leaks*) y buenas prácticas modernas en C++ (sin `using namespace std;`).

---

## 🗺️ Mapa de Contenidos y Guías

| Archivo de Guía | Unidad / Tema | Estado | Ejercicios |
| :--- | :--- | :---: | :---: |
| [`GUIA_Arrays_Aritmetica_Punteros.cpp`](GUIA_Arrays_Aritmetica_Punteros.cpp) | **1. Arrays y Aritmética de Punteros** (Recorridos, Inversión, Máximos, Filtros, Merge dinámico) | ✅ Completo | 9 / 9 |
| [`GUIA_Structs_Punteros.cpp`](GUIA_Structs_Punteros.cpp) | **2. Estructuras (`struct`) y Punteros** (Acceso `.` vs `->`, anidación, arrays dinámicos en Heap) | ✅ Completo | 3 / 3 |
| [`GUIA_Punteros_a_Funciones.cpp`](GUIA_Punteros_a_Funciones.cpp) | **3. Punteros a Funciones y Callbacks** (Comparadores binarios, predicados unarios, Map, Dispatch Tables) | ✅ Completo | 5 / 5 |
| [`GUIA_Clases_POO.cpp`](GUIA_Clases_POO.cpp) | **4. Programación Orientada a Objetos (POO)** (Encapsulamiento, `this`, constructores/destructores, composición) | 🔄 En Progreso | 3 / 5 |

---

## 🛠️ Cómo utilizar las Guías

Cada ejercicio se encuentra encapsulado en un bloque comentado `/* ... */` con su propio `main()` y resultado esperado en consola.

1. **Abrir el archivo de la guía deseada** o el archivo individual de trabajo en las subcarpetas (`clases_poo/`, `punteros_a_funciones/`, etc.).
2. **Descomentar el bloque** del ejercicio a practicar.
3. **Compilar y ejecutar** con `g++`:
   ```bash
   g++ -g mi_ejercicio.cpp -o mi_ejercicio.exe
   ./mi_ejercicio.exe
   ```
4. **Verificar** que la salida por consola coincida exactamente con el bloque de *Resultado esperado*.

---

## 📐 Convenciones y Lineamientos de Arquitectura

- **Cero fugas de memoria (RAII & Heap):** Toda memoria solicitada con `new` o `new[]` es liberada estrictamente con `delete` o `delete[]`, reseteando punteros a `nullptr`.
- **Aritmética de Punteros:** En las unidades de bajo nivel se prioriza la manipulación directa de memoria `*(ptr + i)`, `ptr++`, `ptr--` sobre corchetes.
- **Calificadores `const`:** Uso estricto de `const` en parámetros de solo lectura y métodos de consulta (*getters*) para garantizar invariantes.
- **Espacios de nombres:** Uso explícito de `std::cout`, `std::endl`, `std::setw`, etc., evitando `using namespace std;`.
