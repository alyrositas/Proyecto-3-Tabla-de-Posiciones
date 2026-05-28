#ifndef JUGADOR_H
#define JUGADOR_H

#include "Persona.h"

class Jugador : public Persona {
protected:
    int numeroCamiseta;
    int golesAnotados;

public:
    Jugador(string nombre, int edad, string nacionalidad, int numeroCamiseta);

    int getGolesAnotados() const;
    void anotar(int goles = 1);

    string getRol() const override;
    virtual void mostrarInfo() const override;
    virtual string getPosicion() const = 0;
};

#endif
