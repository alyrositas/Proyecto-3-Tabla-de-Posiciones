#include "EstadisticaBase.h"

EstadisticaBase::EstadisticaBase(string nombre)
    : nombre(nombre), partidosJugados(0) {}

string EstadisticaBase::getNombre() const { return nombre; }
int EstadisticaBase::getPartidosJugados() const { return partidosJugados; }

void EstadisticaBase::incrementarPartidos() { partidosJugados++; }

EstadisticaBase& EstadisticaBase::operator+=(const EstadisticaBase& otro) {
    partidosJugados += otro.partidosJugados;
    return *this;
}

bool EstadisticaBase::operator>(const EstadisticaBase& otro) const {
    return calcularRendimiento() > otro.calcularRendimiento();
}

bool EstadisticaBase::operator==(const EstadisticaBase& otro) const {
    return calcularRendimiento() == otro.calcularRendimiento();
}

ostream& operator<<(ostream& os, const EstadisticaBase& e) {
    os << e.nombre << " | PJ: " << e.partidosJugados
       << " | Rendimiento: " << e.calcularRendimiento();
    return os;
}
