// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo lenguaje.cc: programa cliente.
// Contiene la implementación de la clase lenguaje
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 


#include <iostream>
#include <set>
#include <string>

#include "lenguaje.h"



/**
 * @brief Sobrecarga del operador de insercion para la clase Cadena
 * @param salida Variable que contiene la salida de escritura
 * @param cadena Objeto alfabeto que sera escrito
*/
std::ostream& operator<<(std::ostream& salida, const Lenguaje& lenguaje) { 
  salida << "{"; 
  for(auto it = lenguaje.lenguaje_.begin(); it != lenguaje.lenguaje_.end(); it++) { 
    if(it != lenguaje.lenguaje_.begin()) {
      salida << ", ";
    }
    salida << *it;
  }
  salida << "}"; 
  return salida; 
}



/**
 * @brief Sobrecarga del operador de extraccion para el objeto Lenguaje
 * @param entrada Variable para recibir la entrada de datos
 * @param lenguaje Objeto Lenguaje que va a ser sobreescrito
 * @return entrada Retornamos el nuevo valor 
*/
std::istream& operator>>(std::istream& entrada, Lenguaje& otro) {
  std::string cadena; 
  entrada >> cadena; 
  otro.lenguaje_.insert(cadena);
  return entrada;
}