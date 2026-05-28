#include "Resultado.h"

Resultado::Resultado(int local, int visitante)
    : golesLocal(local), golesVisitante(visitante) {}

int Resultado::getGolesLocal() const { return golesLocal; }
int Resultado::getGolesVisitante() const { return golesVisitante; }

Resultado Resultado::operator+(const Resultado& otro) const {
    return Resultado(golesLocal + otro.golesLocal, golesVisitante + otro.golesVisitante);
}

// Compara diferencia de goles (quién ganó)
bool Resultado::operator>(const Resultado& otro) const {
    return (golesLocal - golesVisitante) > (otro.golesLocal - otro.golesVisitante);
}

bool Resultado::operator<(const Resultado& otro) const {
    return (golesLocal - golesVisitante) < (otro.golesLocal - otro.golesVisitante);
}

bool Resultado::operator==(const Resultado& otro) const {
    return (golesLocal - golesVisitante) == (otro.golesLocal - otro.golesVisitante);
}

ostream& operator<<(ostream& os, const Resultado& r) {
    os << r.golesLocal << " - " << r.golesVisitante;
    return os;
}
