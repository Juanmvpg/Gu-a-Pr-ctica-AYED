# Auditoría del Estado del Proyecto — TP Integrador HubFlow

Este documento analiza el estado actual del repositorio y del archivo fuente [`tp.cpp`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp) frente a las especificaciones oficiales de la consigna (*Trabajo Práctico Integrador — Estructuras de Datos y POO en C++*).

---

## 1. Aspectos Cumplidos Satisfactoriamente ✅

1. **Estructura Arquitectural General y Convención Bottom-Up:**
   - Se definió el orden correcto de dependencias en C++ para un único archivo fuente (Enums → Movimiento → NodoDoble → Historial → Envio → NodoSimple → ListaPendientes → hubFlow → main).
2. **Enumeraciones Fuertes (`enum class`):**
   - [`NivelServicio`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L16-L20) (`EXPRESS`, `PRIORITARIO`, `ESTANDAR`) correctamente tipado.
   - [`EstadoEnvio`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L22-L28) (`RECIBIDO`, `CLASIFICADO`, `EN_REPARTO`, `REPROGRAMADO`, `ENTREGADO`) conforme a la consigna.
3. **Entidad `Movimiento`:**
   - Implementada con encapsulamiento clásico: atributos privados (`numero`, `estado`, `observacion`), constructor con lista de inicialización y getters constantes.
4. **Nodo de la Lista Doble (`NodoDoble`):**
   - Contiene el dato `Movimiento` y los punteros `next` y `prev`.
   - Constructor que garantiza inicialización segura en `nullptr`.
5. **Lista Doblemente Enlazada (`Historial`):**
   - Manejo de dos punteros clave: `cabeza` y `cola`.
   - Constructor por defecto limpio.
   - Destructor `~Historial()` con liberación secuencial de memoria dinámica nodo por nodo (previene Use-After-Free y Memory Leaks).
   - Inserción al final (`agregar`) en complejidad temporal óptima $O(1)$.
   - Recorridos bidireccionales implementados: `mostrarAdelante()` en orden cronológico y `mostrarAtras()` usando los enlaces `prev` sin copiar a estructuras intermedias (requisito estricto de la Sección 7).
6. **Políticas y Restricciones Técnicas:**
   - No se utilizaron contenedores prohibidos de la STL (`std::vector`, `std::list`, `std::queue`, `smart pointers`).
   - Uso estricto de punteros crudos (`raw pointers`).

---

## 2. Aspectos Erróneos y Problemas de Compilación Detectados ⚠️

1. **Error de compilación en [`NodoSimple`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L115-L121):**
   - En la línea 120 se escribió:
     ```cpp
     NodoSimple(Envio* e) : dato(e), sig(nullptr) {}
     ```
     Sin embargo, **los atributos `dato` y `sig` quedaron comentados**, por lo que el compilador arroja error fatal:
     > `error: class 'NodoSimple' does not have any field named 'dato'`  
     > `error: class 'NodoSimple' does not have any field named 'sig'`
2. **Falta de información en el formato de visualización del `Historial`:**
   - El método [`mostrarAdelante()`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L91-L97) y [`mostrarAtras()`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L99-L105) actualmente imprimen:
     ```cpp
     std::cout << actual->dato.getNumero() << " | " << actual->dato.getObservacion() << std::endl;
     ```
     Falta imprimir el **`EstadoEnvio`** (el enunciado solicita ver `1 | RECIBIDO | Ingreso...`). Para esto se necesitará una función auxiliar que convierta el `enum` a texto legible (ej: `"RECIBIDO"`).

---

## 3. Aspectos Pendientes de Implementación ⏳

### A. Entidad [`Envio`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L109-L111)
- Declarar atributos privados obligatorios:
  - `codigo` (`std::string`)
  - `destinatario` (`std::string`)
  - `zona` (`std::string`)
  - `peso` (`double`)
  - `servicio` (`NivelServicio`)
  - `estado` (`EstadoEnvio`)
  - `intentos` (`int`)
  - `historial` (`Historial`, por composición directa)
- Constructor que inicialice los datos, fije `intentos = 0` y registre de manera automática el primer movimiento (`1 | RECIBIDO | Ingreso al centro de distribución`).
- Métodos getters, `registrarMovimiento()`, `incrementarIntentos()` y acceso a su historial.

### B. [`ListaPendientes`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L124-L130) (Cola de Prioridad Estable — Lista Simple)
- Atributo privado: `NodoSimple* cabeza;`
- Inserción ordenada por prioridad (`EXPRESS > PRIORITARIO > ESTANDAR`):
  - Debe ser **estable**: elementos con igual prioridad conservan orden de llegada (FIFO).
  - Manejo de casos de borde: lista vacía, inserción al inicio, en el medio y al final.
- `despacharProximo()`: extracción de la cabeza en $O(1)$ retornando el puntero `Envio*` y haciendo `delete` únicamente del `NodoSimple`.
- **Operación Recursiva Obligatoria (Sección 12):**
  - Función recursiva real que recorra los nodos de la lista sin ciclos `while`/`for` y devuelva un resumen por zona (cantidad de paquetes, peso total acumulado y cantidad de paquetes Express).

### C. [`hubFlow`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L133-L140) (Centro de Distribución y Ownership Central)
- Resolver la propiedad de la memoria (Ownership):
  - Mantener un **Registro Maestro** con todos los `Envio*` creados en el sistema (por ejemplo, mediante otra lista enlazada o arreglo de punteros dinámicos).
  - Su destructor debe ser el responsable definitivo de liberar los `Envio*` con `delete`.
- Métodos de negocio requeridos por el menú:
  - `RF01`: Registrar nuevo envío (validando código único).
  - `RF02`: Mostrar lista de pendientes formateada.
  - `RF03`: Buscar envío por código.
  - `RF04`: Cambiar estado.
  - `RF05`: Despachar próximo (pasa a `EN_REPARTO` y sale de pendientes sin destruir el objeto `Envio`).
  - `RF06`: Reprogramar envío (incrementa intentos, pasa a `REPROGRAMADO` y reinserta en pendientes por prioridad).
  - `RF07`: Finalizar entrega (`ENTREGADO`, no vuelve a pendientes).
  - `RF08`: Mostrar historial en ambos sentidos.

### D. [`main()`](file:///c:/Users/gian9/OneDrive/Desktop/AYED/recursividad/TP_Sabado/tp.cpp#L142-L149), Dataset Inicial y Menú
- Carga del dataset inicial de paquetes exigido por el TP.
- Menú interactivo por consola con bucle de opciones del 1 al 9.
- Demostración de los 7 casos de prueba obligatorios.

---

## 4. Matriz de Progreso Estimado

| Componente / Requerimiento | Estado | Observación |
| :--- | :---: | :--- |
| Enums (`NivelServicio`, `EstadoEnvio`) | **100%** | Completo y sin errores. |
| Clase `Movimiento` | **100%** | Encapsulada y funcional. |
| `NodoDoble` | **100%** | Punteros y constructor listos. |
| `Historial` (Lista Doble) | **95%** | Lógica y memoria completas; falta mapear enum a string en print. |
| Clase `Envio` | **0%** | Pendiente de implementar atributos y métodos. |
| `NodoSimple` | **50%** | Requiere descomentar/declarar atributos `dato` y `sig`. |
| `ListaPendientes` (Lista Simple) | **0%** | Pendiente inserción por prioridad, despacho y recursión. |
| `hubFlow` (Administrador Central) | **0%** | Pendiente lógica de ownership y operaciones de menú. |
| Dataset Inicial y Menú Consola | **0%** | Pendiente integración en `main()`. |
