#ifndef PARTIDO_H
#define PARTIDO_H

#include "Resultado.h"
#include <string>
using namespace std;

class Partido {
private:
    string equipoLocal;
    string equipoVisitante;
    Resultado resultado;
    string fase;

public:
    Partido(string local, string visitante, Resultado resultado, string fase = "Grupos");

    string getEquipoLocal() const;
    string getEquipoVisitante() const;
    Resultado getResultado() const;

    string getGanador() const;
    void mostrar() const;

    // Sobrecarga: comparar partidos por diferencia de goles
    bool operator>(const Partido& otro) const;
    bool operator==(const Partido& otro) const;

    // Sobrecarga: imprimir partido
    friend ostream& operator<<(ostream& os, const Partido& p);
};

#endif
