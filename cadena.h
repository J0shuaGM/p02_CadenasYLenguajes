// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo cadena.h: programa cliente.
// Contiene la declaración de la clase cadena
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>
#include <string>

class Lenguaje;

class Cadena {
	public:
    // Contructores
    Cadena(void){} // Predeterminado
    Cadena(std::string cadena); // Parametrizado

    // Destructor
    ~Cadena() {}

    // Metodos
    int longitud(void);
    void reverse(void);
    Lenguaje prefijos(void);
    Lenguaje sufijos(void);
    void clear(void) { cadena_.clear(); }


    // Sobrecarga de operadores
    friend std::istream& operator>>(std::istream& entrada, Cadena& cadena);
    friend std::ostream& operator<<(std::ostream& salida, const Cadena& cadena); 
    friend bool operator<(Cadena cadena, Cadena cadena2);


	private:
    std::vector<char> cadena_; // Vector de caracteres que actua como nuestra cadena
    int longitud_;
};

#endif