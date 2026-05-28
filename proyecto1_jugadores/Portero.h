#ifndef PORTERO_H
#define PORTERO_H

#include "Jugador.h"

class Portero : public Jugador {
private:
    int atajadas;

public:
    Portero(string nombre, int edad, string nacionalidad, int numeroCamiseta);

    void atajar();
    int getAtajadas() const;

    string getPosicion() const override;
    void mostrarInfo() const override;
};

#endif
