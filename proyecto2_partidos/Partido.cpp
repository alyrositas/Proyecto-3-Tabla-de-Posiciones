#include "Partido.h"
#include <iostream>

Partido::Partido(string local, string visitante, Resultado res, string fase)
    : equipoLocal(local), equipoVisitante(visitante), resultado(res), fase(fase) {}

string Partido::getEquipoLocal() const { return equipoLocal; }
string Partido::getEquipoVisitante() const { return equipoVisitante; }
Resultado Partido::getResultado() const { return resultado; }

string Partido::getGanador() const {
    if (resultado.getGolesLocal() > resultado.getGolesVisitante()) return equipoLocal;
    if (resultado.getGolesLocal() < resultado.getGolesVisitante()) return equipoVisitante;
    return "Empate";
}

void Partido::mostrar() const {
    cout << "[" << fase << "] " << equipoLocal << " vs " << equipoVisitante
         << "  ->  " << resultado
         << "  |  Ganador: " << getGanador() << endl;
}

bool Partido::operator>(const Partido& otro) const {
    return resultado > otro.resultado;
}

bool Partido::operator==(const Partido& otro) const {
    return resultado == otro.resultado;
}

ostream& operator<<(ostream& os, const Partido& p) {
    os << p.equipoLocal << " " << p.resultado << " " << p.equipoVisitante;
    return os;
}
