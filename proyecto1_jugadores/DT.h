#ifndef DT_H
#define DT_H

#include "Persona.h"

class DT : public Persona {
private:
    string seleccionDirigida;
    int mundialísGanados;

public:
    DT(string nombre, int edad, string nacionalidad, string seleccion, int mundiales = 0);

    string getSeleccion() const;

    string getRol() const override;
    void mostrarInfo() const override;
};

#endif
