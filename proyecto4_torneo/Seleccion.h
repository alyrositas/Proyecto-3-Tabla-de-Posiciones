#ifndef SELECCION_H
#define SELECCION_H

#include <string>
#include <iostream>
using namespace std;

class Seleccion {
protected:
    string nombre;
    string continente;
    int rankingFIFA;

public:
    Seleccion(string nombre, string continente, int ranking);
    virtual ~Seleccion() = default;

    string getNombre() const;
    int getRanking() const;

    // Fuerza simulada basada en ranking y atributos propios
    virtual double calcularFuerza() const;
    virtual void mostrar() const;

    // Sobrecarga: comparar selecciones por ranking
    bool operator<(const Seleccion& otra) const;
    bool operator==(const Seleccion& otra) const;
    friend ostream& operator<<(ostream& os, const Seleccion& s);
};

// Seleccion con ventaja de local
class SeleccionLocal : public Seleccion {
public:
    SeleccionLocal(string nombre, string continente, int ranking);
    double calcularFuerza() const override;
    void mostrar() const override;
};

// Seleccion con jugadores estrella
class SeleccionEstrella : public Seleccion {
private:
    int numEstrellas;
public:
    SeleccionEstrella(string nombre, string continente, int ranking, int estrellas);
    double calcularFuerza() const override;
    void mostrar() const override;
};

#endif
