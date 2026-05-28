#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
    string nacionalidad;

public:
    Persona(string nombre, int edad, string nacionalidad);
    virtual ~Persona() = default;

    string getNombre() const;
    int getEdad() const;
    string getNacionalidad() const;

    virtual string getRol() const = 0;
    virtual void mostrarInfo() const = 0;
};

#endif
