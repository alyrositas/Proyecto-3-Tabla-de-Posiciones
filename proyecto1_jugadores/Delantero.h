#ifndef DELANTERO_H
#define DELANTERO_H

#include "Jugador.h"

class Delantero : public Jugador {
private:
    int asistencias;

public:
    Delantero(string nombre, int edad, string nacionalidad, int numeroCamiseta);

    void darAsistencia();
    int getAsistencias() const;

    string getPosicion() const override;
    void mostrarInfo() const override;
};

#endif
