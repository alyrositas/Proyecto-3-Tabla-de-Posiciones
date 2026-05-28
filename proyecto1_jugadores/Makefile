CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = jugadores
SRCS = main.cpp Persona.cpp Jugador.cpp Delantero.cpp Portero.cpp DT.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
