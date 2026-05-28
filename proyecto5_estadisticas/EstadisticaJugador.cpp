#include "EstadisticaJugador.h"
#include <iomanip>

EstadisticaJugador::EstadisticaJugador(string nombre)
    : EstadisticaBase(nombre), goles(0), asistencias(0),
      tarjetasAmarillas(0), tarjetasRojas(0), minutosjugados(0) {}

void EstadisticaJugador::registrarGol() { goles++; }
void EstadisticaJugador::registrarAsistencia() { asistencias++; }

void EstadisticaJugador::registrarTarjeta(bool esRoja) {
    if (esRoja) tarjetasRojas++;
    else tarjetasAmarillas++;
}

void EstadisticaJugador::agregarMinutos(int minutos) {
    if (minutos < 0) throw ValorNegativoException("minutos");
    minutosjugados += minutos;
}

int EstadisticaJugador::getGoles() const { return goles; }
int EstadisticaJugador::getAsistencias() const { return asistencias; }

double EstadisticaJugador::getPromedioGoles() const {
    if (partidosJugados == 0) throw DivisionPorCeroException();
    return static_cast<double>(goles) / partidosJugados;
}

double EstadisticaJugador::calcularRendimiento() const {
    return goles * 3.0 + asistencias * 2.0
         - tarjetasAmarillas * 0.5 - tarjetasRojas * 2.0;
}

void EstadisticaJugador::mostrarResumen() const {
    cout << left << setw(20) << nombre
         << " | Goles: " << setw(3) << goles
         << " | Asist: " << setw(3) << asistencias
         << " | TA: " << tarjetasAmarillas
         << " | TR: " << tarjetasRojas
         << " | Min: " << setw(5) << minutosjugados
         << " | Rendimiento: " << fixed << setprecision(1) << calcularRendimiento()
         << endl;
}

EstadisticaJugador& EstadisticaJugador::operator+=(const EstadisticaJugador& otro) {
    EstadisticaBase::operator+=(otro);
    goles             += otro.goles;
    asistencias       += otro.asistencias;
    tarjetasAmarillas += otro.tarjetasAmarillas;
    tarjetasRojas     += otro.tarjetasRojas;
    minutosjugados    += otro.minutosjugados;
    return *this;
}

ostream& operator<<(ostream& os, const EstadisticaJugador& e) {
    os << e.nombre << " | G:" << e.goles << " A:" << e.asistencias;
    return os;
}
