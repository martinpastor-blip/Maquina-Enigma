#include <iostream>
#include <fstream>
#include <string>

#include "comprobaciones.h"
#include "rotor.h"



int main() {
	while (true) {  // Bucle infinito hasta que se elija salir
		std::cout << "ENIGMA:" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "1. Xifrar missatge" << std::endl;
		std::cout << "2. Desxifrar missatge" << std::endl;
		std::cout << "3. Editar rotors" << std::endl;
		std::cout << "4. Sortir" << std::endl;
		std::cout << "Elige una opcion: " << std::endl;
		
		std::string mensajeCifrar;
		int opcion_menu;
		std::cin >> opcion_menu;
		std::cin.ignore();  // Limpiar el buffer para getline

		switch (opcion_menu) {
		case 1:  // Cifrar mensaje

			std::cout << "Funcionalidad de cifrado no implementada aún." << std::endl;

			std::cout << "Introduce el mensaje a cifrar" << std::endl;
			std::cin >> mensajeCifrar;

			while (mensajeCifrar == "")
			{
				std::cout << "Error el mensaje no puede estar vacio";
				break;
			}

			
		

		case 2:  // Descifrar mensaje

		{
			std::string posicion_primer_rotor;
			std::cout << "Indica la posicion del primer rotor " << std::endl;
			std::getline(std::cin, posicion_primer_rotor);

			std::string posicion_segundo_rotor;
			std::cout << "Indica la posicion del segundo rotor " << std::endl;
			std::getline(std::cin, posicion_segundo_rotor);

			std::string posicion_tercer_rotor;
			std::cout << "Indica la posicion del tercer rotor " << std::endl;
			std::getline(std::cin, posicion_tercer_rotor);

			// Validacion de posiciones
			if (posicion_primer_rotor.length() != 1 || !esLetraMayuscula(posicion_primer_rotor[0]) ||
				posicion_segundo_rotor.length() != 1 || !esLetraMayuscula(posicion_segundo_rotor[0]) ||
				posicion_tercer_rotor.length() != 1 || !esLetraMayuscula(posicion_tercer_rotor[0])) {
				std::cout << "Error: Cada posicion debe ser exactamente una letra mayúscula." << std::endl;
				break;  // Volver al menú
			}

			// Convertir a índices y llamar a descifrar().
			int indice_posicion_primero = posicion_primer_rotor[0] - 'A';
			int indice_posicion_segundo = posicion_segundo_rotor[0] - 'A';
			int indice_posicion_tercero = posicion_tercer_rotor[0] - 'A';

			// descifrar(indice_posicion_primero, indice_posicion_segundo, indice_posicion_tercero);
		}
		break;

		case 3:  // Editar rotors

			break;

		case 4:  // Saliendo
			std::cout << "Saliendo..." << std::endl;
			return 0;  // Salir del programa

		default:  // Opción inválida
			std::cout << "Opcion invalida. Intenta de nuevo." << std::endl;
			break;
		}
	}

	return 0;
}

