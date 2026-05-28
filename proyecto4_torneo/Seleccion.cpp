#include "Seleccion.h"

Seleccion::Seleccion(string nombre, string continente, int ranking)
    : nombre(nombre), continente(continente), rankingFIFA(ranking) {}

string Seleccion::getNombre() const { return nombre; }
int Seleccion::getRanking() const { return rankingFIFA; }

double Seleccion::calcularFuerza() const {
    // Ranking 1 = más fuerte; invertimos la escala (max 210 equipos FIFA)
    return max(0, 210 - rankingFIFA) * 1.0;
}

void Seleccion::mostrar() const {
    cout << nombre << " (FIFA #" << rankingFIFA << ", " << continente << ")";
}

bool Seleccion::operator<(const Seleccion& otra) const {
    return rankingFIFA < otra.rankingFIFA; // menor ranking = mejor
}

bool Seleccion::operator==(const Seleccion& otra) const {
    return rankingFIFA == otra.rankingFIFA;
}

ostream& operator<<(ostream& os, const Seleccion& s) {
    os << s.nombre << " (#" << s.rankingFIFA << ")";
    return os;
}

// --- SeleccionLocal ---
SeleccionLocal::SeleccionLocal(string nombre, string continente, int ranking)
    : Seleccion(nombre, continente, ranking) {}

double SeleccionLocal::calcularFuerza() const {
    return Seleccion::calcularFuerza() * 1.15; // +15% por localía
}

void SeleccionLocal::mostrar() const {
    Seleccion::mostrar();
    cout << " [LOCAL +15%]";
}

// --- SeleccionEstrella ---
SeleccionEstrella::SeleccionEstrella(string nombre, string continente, int ranking, int estrellas)
    : Seleccion(nombre, continente, ranking), numEstrellas(estrellas) {}

double SeleccionEstrella::calcularFuerza() const {
    return Seleccion::calcularFuerza() + numEstrellas * 5.0;
}

void SeleccionEstrella::mostrar() const {
    Seleccion::mostrar();
    cout << " [ESTRELLAS: " << numEstrellas << "]";
}
