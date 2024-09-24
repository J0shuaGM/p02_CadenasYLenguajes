# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Cadenas y Lenguajes
# Autor: Joshua Gomez Marrero
# Correo: alu0101477398@ull.edu.es
# Fecha: 24/10/2023
# Archivo: Makefile

# Nombre del archivo de salida
TARGET = Cadenas

# Lista de archivos fuente(.cc)
SOURCES = main.cc alfabeto.cc cadena.cc lenguaje.cc tools.cc 

# Dependencias de los archivos fuente 
DEPENDENCIES = tools.h alfabeto.h lenguaje.h cadena.h 

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++11

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)