#include "EquipoGrupo.h"
#include "MundialException.h"

EquipoGrupo::EquipoGrupo(string nombre)
    : nombre(nombre), puntos(0), pj(0), pg(0), pe(0), pp(0), gf(0), gc(0) {}

int EquipoGrupo::diferenciaGoles() const { return gf - gc; }

void EquipoGrupo::registrarVictoria(int gfP, int gcP) {
    if (gfP < 0 || gcP < 0) throw PuntosNegativosException();
    pj++; pg++; puntos += 3; gf += gfP; gc += gcP;
}

void EquipoGrupo::registrarEmpate(int gfP, int gcP) {
    if (gfP < 0 || gcP < 0) throw PuntosNegativosException();
    pj++; pe++; puntos += 1; gf += gfP; gc += gcP;
}

void EquipoGrupo::registrarDerrota(int gfP, int gcP) {
    if (gfP < 0 || gcP < 0) throw PuntosNegativosException();
    pj++; pp++; gf += gfP; gc += gcP;
}

bool EquipoGrupo::operator>(const EquipoGrupo& otro) const {
    if (puntos != otro.puntos) return puntos > otro.puntos;
    if (diferenciaGoles() != otro.diferenciaGoles()) return diferenciaGoles() > otro.diferenciaGoles();
    return gf > otro.gf;
}

bool EquipoGrupo::operator==(const EquipoGrupo& otro) const {
    return puntos == otro.puntos &&
           diferenciaGoles() == otro.diferenciaGoles() &&
           gf == otro.gf;
}
