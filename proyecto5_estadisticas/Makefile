CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = estadisticas
SRCS = main.cpp EstadisticaBase.cpp EstadisticaJugador.cpp EstadisticaEquipo.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
