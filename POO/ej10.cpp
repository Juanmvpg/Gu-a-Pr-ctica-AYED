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

#include <iostream>
#include <string>

class Notificacion{
std::string mensaje;

public:
    Notificacion(){
        mensaje="vacio";
    }
    Notificacion(std::string mensaje){
        this->mensaje=mensaje;
    }

    virtual void mostrarMensaje() const = 0;

    //getter
    std::string getMensaje () const{
        return mensaje;
    }
    virtual ~Notificacion(){};
};

class NotificacionEmail : public Notificacion{
std::string Email;
public:
    NotificacionEmail(std::string emailRemitente, std::string msjRemitente) : Notificacion(msjRemitente){
        this->Email = emailRemitente;
    }    

    //getters
    virtual void mostrarMensaje() const{
        std::cout<< "Email de ["
                 <<Email<<"]: "
                 <<getMensaje()
                 <<std::endl;
    }
};

class NotificacionSMS : public Notificacion{
long long numero;
public:
    NotificacionSMS(long long numeroRemitente, std::string mensajeRemitente) : Notificacion(mensajeRemitente){
        this->numero=numeroRemitente;
    }

    virtual void mostrarMensaje() const{
        std::cout<< "SMS de ["
                 <<numero<<"]: "
                 <<getMensaje()
                 <<std::endl;
    }
};



int main() {
    std::cout << "=== EJERCICIO 7: NOTIFICACIONES ===" << std::endl;

    Notificacion* miNotificacion[2];
    miNotificacion[0] = new NotificacionEmail("juanceo01@gmail.com", "hola_papucho");
    miNotificacion[1] = new NotificacionSMS(3515053904, "Hi_guys");

    miNotificacion[0]->mostrarMensaje();
    miNotificacion[1]->mostrarMensaje();

    delete miNotificacion[0];
    delete miNotificacion[1];

    return 0;
}
