#pragma once
#include "includes.h"


/**
 * @brief Cifra un mensaje utilizando tres rotores.
 *
 * La función lee los rotores desde archivos, toma un mensaje en texto plano
 * y lo procesa letra por letra para obtener el mensaje cifrado.
 * Las posiciones iniciales de los rotores deben ser guardadas para
 * poder descifrar el mensaje posteriormente.
 */

void cifrar(std::string mensajeCifrar, int indice_posicion_primero, int indice_posicion_segundo, int indice_posicion_tercero);


