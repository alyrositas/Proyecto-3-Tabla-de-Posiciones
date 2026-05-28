#include <iostream>
#include <vector>
#include "EstadisticaEquipo.h"
#include "EstadisticaException.h"
using namespace std;

int main() {
    // Crear equipos
    EstadisticaEquipo argentina("Argentina");
    EstadisticaEquipo francia("Francia");

    // Registrar jugadores
    argentina.agregarJugador("Messi");
    argentina.agregarJugador("Di Maria");
    argentina.agregarJugador("Martinez");

    francia.agregarJugador("Mbappe");
    francia.agregarJugador("Griezmann");
    francia.agregarJugador("Lloris");

    // Simular Final Argentina 3 - 3 Francia (Argentina gana en penales)
    argentina.registrarResultado(3, 3);
    francia.registrarResultado(3, 3);

    // Estadísticas de la final — Argentina
    argentina.getJugador("Messi").registrarGol();
    argentina.getJugador("Messi").registrarGol();
    argentina.getJugador("Messi").registrarAsistencia();
    argentina.getJugador("Messi").agregarMinutos(120);
    argentina.getJugador("Messi").incrementarPartidos();

    argentina.getJugador("Di Maria").registrarGol();
    argentina.getJugador("Di Maria").registrarTarjeta(false);
    argentina.getJugador("Di Maria").agregarMinutos(64);
    argentina.getJugador("Di Maria").incrementarPartidos();

    argentina.getJugador("Martinez").agregarMinutos(120);
    argentina.getJugador("Martinez").incrementarPartidos();

    // Estadísticas de la final — Francia
    francia.getJugador("Mbappe").registrarGol();
    francia.getJugador("Mbappe").registrarGol();
    francia.getJugador("Mbappe").registrarGol();
    francia.getJugador("Mbappe").agregarMinutos(120);
    francia.getJugador("Mbappe").incrementarPartidos();

    francia.getJugador("Griezmann").registrarAsistencia();
    francia.getJugador("Griezmann").agregarMinutos(120);
    francia.getJugador("Griezmann").incrementarPartidos();

    // Mostrar estadísticas
    cout << "=== ESTADISTICAS DE LA FINAL ===" << endl;
    argentina.mostrarResumen();
    argentina.mostrarTablajugadores();
    francia.mostrarResumen();
    francia.mostrarTablajugadores();

    // Comparación usando operator>
    cout << "\n=== COMPARACION ===" << endl;
    IEstadistica* mejor = (argentina > francia)
        ? static_cast<IEstadistica*>(&argentina)
        : static_cast<IEstadistica*>(&francia);
    cout << "Mejor rendimiento: " << mejor->getNombre() << endl;

    // Demostrar excepciones
    cout << "\n=== PRUEBA DE EXCEPCIONES ===" << endl;

    try {
        argentina.getJugador("Messi").agregarMinutos(-5);
    } catch (const ValorNegativoException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    try {
        argentina.registrarResultado(-1, 0);
    } catch (const ValorNegativoException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    try {
        EstadisticaJugador jugadorSinPartidos("Suplente");
        cout << "Promedio: " << jugadorSinPartidos.getPromedioGoles() << endl;
    } catch (const DivisionPorCeroException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    try {
        argentina.getJugador("Ronaldo"); // No existe
    } catch (const JugadorNoExisteException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    // Demostrar operator+=: acumular estadísticas de dos torneos
    cout << "\n=== ACUMULADO MESSI (dos torneos, operator+=) ===" << endl;
    EstadisticaJugador torneo1("Messi");
    torneo1.registrarGol(); torneo1.registrarGol(); torneo1.registrarGol();
    torneo1.registrarAsistencia();
    torneo1.agregarMinutos(630);

    EstadisticaJugador torneo2("Messi");
    torneo2.registrarGol(); torneo2.registrarGol();
    torneo2.registrarAsistencia(); torneo2.registrarAsistencia();
    torneo2.agregarMinutos(480);

    torneo1 += torneo2;
    torneo1.mostrarResumen();

    return 0;
}
