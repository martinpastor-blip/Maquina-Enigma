#include <iostream>
#include <string>

#include "rotor.h"

/**
 * @brief Descifra un mensaje utilizando tres rotores.
 *
 * La función lee los rotores desde archivos, pide un mensaje cifrado
 * y lo procesa letra por letra para obtener el mensaje original.
 * Para que funcione correctamente, las posiciones iniciales de los
 * rotores deben ser las mismas que se usaron al cifrar.
 */

void descifrar(int indice_posicion_primero,
	int indice_posicion_segundo,
	int indice_posicion_tercero) {

	//  Lee los archivos de rotor
	std::string rotor_primero = leerRotor("rotor1.txt");
	std::string rotor_segundo = leerRotor("rotor2.txt");
	std::string rotor_tercero = leerRotor("rotor3.txt");

	// Si algún rotor no se pudo leer correctamente, se cancela el proceso
	if (rotor_primero.empty() || rotor_segundo.empty() || rotor_tercero.empty()) {
		std::cout << "Error al cargar los rotors." << std::endl;
		return;
	}

	// Estos rotores se usan para hacer el proceso contrario al cifrado y así recuperar el mensaje original.
	std::string inverso_rotor_primero = crearInverso(rotor_primero);
	std::string inverso_rotor_segundo = crearInverso(rotor_segundo);
	std::string inverso_rotor_tercero = crearInverso(rotor_tercero);

	// Leer el mensaje cifrado
	std::string mensaje_cifrado;
	std::cout << "Ingresa el mensaje cifrado: ";
	std::getline(std::cin, mensaje_cifrado);

	// Se convierte todo a mayúsculas y se eliminan los caracteres que no sean letras entre A y Z.
	std::string mensaje_procesado;
	int longitud_cifrado = mensaje_cifrado.length();

	for (int i = 0; i < longitud_cifrado; i++) {
		char letra = toUpper(mensaje_cifrado[i]);
		if (letra >= 'A' && letra <= 'Z') {
			mensaje_procesado += letra;
		}
	}

	// Descifrar letra por letra
	std::string mensaje_descifrado;
	int contador_grupo = 0;
	int longitud_procesado = mensaje_procesado.length();

	for (int i = 0; i < longitud_procesado; i++) {
		char caracter = mensaje_procesado[i];

		// El primer rotor avanza siempre una posición
		indice_posicion_primero = (indice_posicion_primero + 1) % 26;

		// Cuando el primer rotor llega a una posición concreta hace avanzar el segundo rotor		
		if (indice_posicion_primero == ('Q' - 'A')) {
			indice_posicion_segundo = (indice_posicion_segundo + 1) % 26;

			// Si el segundo rotor llega a su posición notch, avanza el tercer rotor
			if (indice_posicion_segundo == ('E' - 'A')) {
				indice_posicion_tercero = (indice_posicion_tercero + 1) % 26;
			}
		}

		// Paso por los rotores inversos 
		int entrada = caracter - 'A';

		int salida3 = inverso_rotor_tercero[
			(entrada + indice_posicion_tercero) % 26] - 'A';

		int salida2 = inverso_rotor_segundo[
			(salida3 + indice_posicion_segundo) % 26] - 'A';

		int salida1 = inverso_rotor_primero[
			(salida2 + indice_posicion_primero) % 26] - 'A';

		// Convierte el resultado final en una letra
		char letra_descifrada = 'A' + salida1;
		mensaje_descifrado += letra_descifrada;

		// Agrupar en bloques de 5
		contador_grupo++;
		if (contador_grupo % 5 == 0) {
			mensaje_descifrado += ' ';
		}
	}

	// Proceso de guardado del archivo descifrado.txt
	std::ofstream archivo("desxifrat.txt");
	if (archivo.is_open()) {

		archivo << mensaje_descifrado;
		archivo.close();
		std::cout << "[OK] Mensaje descifrado a \"desxifrat.txt\" (" << mensaje_descifrado.length() << " letras)" << std::endl;

	}

	// Muestra el resultado
	std::cout << "Mensaje descifrado: " << mensaje_descifrado << std::endl;
}
