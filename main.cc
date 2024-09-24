// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo main.cc: programa cliente.
// Contiene la funcion main que hace uso de las clases alfabeto, cadena y lenguaje
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 


#include <iostream> 
#include <fstream>
#include <set>

#include "alfabeto.h"
#include "tools.h"
#include "cadena.h"
#include "lenguaje.h"


/**
 * @brief Funcion main del programa
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
int main(int argc, char* argv[]) { 
  Usage(argc, argv);
  std::string fichero_entrada = argv[1];
  std::string fichero_salida = argv[2];
  std::string opcion = argv[3]; 
  int opcode = stoi(opcion);
  Opcode(fichero_entrada, fichero_salida, opcode);

  return 0;
}