// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo alfabeto.cc: programa cliente.
// Contiene la implementación de la clase alfebeto
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "alfabeto.h"

/**
 * @brief Constructor parametrizado de la clase Alfabeto. Usa los simbolos de una cadena para obtener el alfabeto
 * sobre el que estan formadas
 * @param simbolos Objeto Cadena que va a servir para obtener los simbolos del alfabeto
*/
Alfabeto::Alfabeto(std::string simbolos) {
  for (const char caracteres : simbolos) {
    simbolos_.insert(caracteres);
  }
}



/**
 * @brief Sobrecarga del operador de extraccion de la clase Alfabeto
 * @param entrada Variable para recibir la entrada de datos
 * @param simbolos Objeto Alfabeto que va a ser sobreescrito
 * @return entrada Retornamos el nuevo valor  
*/
std::istream& operator>>(std::istream& entrada, Alfabeto& simbolos) {
  char elemento; 
  entrada >> elemento; 
  simbolos.simbolos_.insert(elemento); 
  return entrada;
}



/**
 * @brief Sobrecarga del operador de insercion para la clase Alfabeto
 * @param salida Variable que contiene la salida de escritura
 * @param simbolos Objeto alfabeto que sera escrito
*/
std::ostream& operator<<(std::ostream& salida, const Alfabeto& simbolos) {
  salida << "{";
  // Iteramos por el set de símbolos
  for (auto it = simbolos.simbolos_.begin(); it != simbolos.simbolos_.end(); ++it) {
    if (it != simbolos.simbolos_.begin()) {
      // Añadimos la coma antes de los siguientes elementos, pero no antes del primero
      salida << ", ";
    }
    salida << *it;
  }
  salida << "}";
  return salida;
} 