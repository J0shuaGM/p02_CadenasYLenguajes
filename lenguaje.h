// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo lenguaje.h: programa cliente.
// Contiene la declaración de la clase lenguaje
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <set>
#include <iostream>
#include <vector>

#include "cadena.h"

class Cadena;

class Lenguaje {
	public:
		// Constructores
		Lenguaje() {} // Por defecto

		// Destructor
		~Lenguaje() {}

		// Metodos
		void insertar(Cadena cadena) { lenguaje_.insert(cadena); }
		void clear(void) { lenguaje_.clear(); }

		// Sobrecarga de operadores de insercion y extreaccion
    friend std::ostream& operator<<(std::ostream& salida, const Lenguaje& lenguaje); 
    friend std::istream& operator>>(std::istream& entrada, Lenguaje& lenguaje);

	private:
		std::set<Cadena> lenguaje_;
		int cardinal_;	
};

#endif