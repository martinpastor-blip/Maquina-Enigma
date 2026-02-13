#pragma once


/**
 * @brief Descifra un mensaje utilizando tres rotores.
 *
 * La función lee los rotores desde archivos, pide un mensaje cifrado
 * y lo procesa letra por letra para obtener el mensaje original.
 * Para que funcione correctamente, las posiciones iniciales de los
 * rotores deben ser las mismas que se usaron al cifrar.
 */

void descifrar(int indice_posicion_primero, int indice_posicion_segundo, int indice_posicion_tercero);

