// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo tools.h: implementacion de funciones extras
// Contiene las declaraciones de las funciones que no pertenecen a metodos
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#include <iostream>
#include <fstream>
#include <string>

#include "tools.h"
#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"


/**
 * @brief Funcion que asegura el correcto uso de la linea de ejecucion
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
void Usage(int argc, char *argv[]) {
  if (argc == 1) {
		std::cerr << argv[0] << ": Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
		std::cout << "Pruebe " << argv[0] << " --help para obtener mas informacion" << std::endl;
		exit(EXIT_SUCCESS);
	}
	std::string parametro{argv[1]};
	if (parametro == "--help") {
    std::string TextHelp = "Este programa realiza determinadas operaciones con alfabetos, cadenas y lenguajes";
    std::cout << TextHelp << std::endl;
    std::cout << "Estas son algunas de las operaciones (opcodes) que puede realizar:" << std::endl;
    std::cout << "1: Alfabeto: escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada" << std::endl;
    std::cout << "2: Longitud : escribir en el fichero de salida la longitud de cada cadena de entrada" << std::endl;
    std::cout << "3: Inversa: escribir en el fichero de salida la inversa de cada cadena de entrada." << std::endl;
    std::cout << "4: Prefijos: escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente." << std::endl;
    std::cout << "5: Sufijos: escribir en el fichero de salida el conjunto de cadenas que son sufijos de cada cadena de entrada correspondiente." << std::endl;
    exit(EXIT_SUCCESS);
	}
}



/**
 * @brief Switch para realizar la funcion indicada en la linea de comandos
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
 * @param opcion Numero de la opcion a realizar
*/
void Opcode(std::string fichero_entrada, std::string fichero_salida, int opcion) {
  switch (opcion) {
  case 1: 
    OpcionAlfabeto(fichero_entrada, fichero_salida);
    break;
  case 2: 
    OpcionLongitud(fichero_entrada, fichero_salida); 
    break;
  case 3: 
    OpcionInversa(fichero_entrada, fichero_salida); 
    break;
  case 4:
    OpcionPrefijo(fichero_entrada, fichero_salida);
    break;
  case 5: 
    OpcionSufijo(fichero_entrada, fichero_salida);
  default:
    break;
  }
}


/**
 * @brief Opcion que da los alfabetos de las cadenas del fichero de entrada en el fichero de salida
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
*/
void OpcionAlfabeto(std::string fichero_entrada, std::string fichero_salida) {
  std::ifstream input(fichero_entrada); 
  std::ofstream output(fichero_salida); 
  if(!input.is_open()) {
    std::cerr << "No se ha podido abrir el archivo" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string caracteres;
  int iterador{1};
  Alfabeto objeto;
  while(input >> caracteres) {
    if (iterador % 2 == 0) {
      objeto = Alfabeto(caracteres);
      output << objeto;
      output << std::endl;
    }
    iterador++;
  }
}



/**
 * @brief Opcion que da la longitud de las cadenas del fichero de entrada en el fichero de salida
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
*/
void OpcionLongitud(std::string fichero_entrada, std::string fichero_salida) {
  std::ifstream input(fichero_entrada); 
  std::ofstream output(fichero_salida);
  if(!input.is_open()) {
    std::cerr << "No se ha podido abrir el archivo" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string cadena; 
  int iterador{1}; 
  Cadena objeto;
  int size{0};
  while(input >> cadena) {
    if(iterador % 2 != 0) {
      objeto = Cadena(cadena);
      size = objeto.longitud();
      output << size;
      output << std::endl;
    }
    iterador++;
  }
}



/**
 * @brief Opcion que invierte las cadenas del fichero de entrada en el fichero de salida
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
*/
void OpcionInversa(std::string fichero_entrada, std::string fichero_salida) {
  std::ifstream input(fichero_entrada); 
  std::ofstream output(fichero_salida);
  if(!input.is_open()) {
    std::cerr << "No se ha podido abrir el archivo" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string cadena; 
  int iterador{1}; 
  Cadena objeto;
  while(input >> cadena) {
    if(iterador % 2 != 0) {
      objeto = Cadena(cadena); 
      objeto.reverse(); 
      output << objeto;
      output << std::endl;
    }
    iterador++;
  }
}



/**
 * @brief Opcion que da los prefijos de las cadenas del fichero de entrada en el fichero de salida
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
*/
void OpcionPrefijo(std::string fichero_entrada, std::string fichero_salida) {
  std::ifstream input(fichero_entrada); 
  std::ofstream out(fichero_salida);
  if(!input.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    exit(EXIT_SUCCESS);
  }
  Cadena objeto; 
  std::string elementos;
  Lenguaje prefijo;
  int iterador{1};
  while(input >> elementos) {
    if(iterador % 2 != 0) {
      objeto = Cadena(elementos);
      out << objeto.prefijos(); 
      out << std::endl;
    }
    iterador++;
  }
}


/**
 * @brief Opcion que da los sufijos de las cadenas del fichero de entrada en el fichero de salida
 * @param fichero_entrada Nombre del fichero de entrada que usaremos para trabajar
 * @param fichero_salida Nombre del fichero de salida donde escribiremos los resultados obtenidos
*/
void OpcionSufijo(std::string fichero_entrada, std::string fichero_salida) {
  std::ifstream input(fichero_entrada); 
  std::ofstream out(fichero_salida);
  if(!input.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    exit(EXIT_SUCCESS);
  }
  Cadena objeto; 
  std::string elementos;
  Lenguaje prefijo;
  int iterador{1};
  while(input >> elementos) {
    if(iterador % 2 != 0) {
      objeto = Cadena(elementos);
      out << objeto.sufijos(); 
      out << std::endl;
    }
    iterador++;
  }
}