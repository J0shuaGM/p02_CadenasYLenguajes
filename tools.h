// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/09/2024
// Archivo tools.h: definición de funciones extras
// Contiene las declaraciones de las funciones que se necesitaran para el correcto funcionamiento
// del programa
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera version) del codigo 

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

void Usage(int argc, char *argv[]);

void OpcionAlfabeto(std::string fichero_entrada, std::string fichero_salida); 
void OpcionLongitud(std::string fichero_entrada, std::string fichero_salida); 
void OpcionInversa(std::string fichero_entrada, std::string fichero_salida);
void OpcionPrefijo(std::string fichero_entrada, std::string fichero_salida);
void OpcionSufijo(std::string fichero_entrada, std::string fichero_salida);
void OpcionN(std::string fichero_entrada, std::string fichero_salida, int numero);

void Opcode(std::string fichero_entrada, std::string fichero_salida, int numero);

#endif