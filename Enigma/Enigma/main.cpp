#include <iostream>
#include <fstream>
#include <string>

#include "comprobaciones.h"
#include "rotor.h"
#include "descifrar.h"
#include "editar_rotores.h"



int main() {
	while (true) {  // Bucle infinito hasta que se elija salir
		std::cout << "ENIGMA:" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "1. Cifrar missatge" << std::endl;
		std::cout << "2. DesCifrar missatge" << std::endl;
		std::cout << "3. Editar rotores" << std::endl;
		std::cout << "4. Sortir" << std::endl;
		std::cout << "Elige una opcion: " << std::endl;

		std::string mensajeCifrar;
		int opcion;
		std::cin >> opcion;
		std::cin.ignore(1000, '\n'); // Limpia el buffer para que getline funcione correctamente

		switch (opcion) {
		case 1:  // Cifrar 
		{
			
			std::cout << "Introduce el mensaje a cifrar" << std::endl;
			std::cin >> mensajeCifrar;

			while (mensajeCifrar == "")
			{
				std::cout << "Error el mensaje no puede estar vacio";
				break;
			}

			std::string posicion_primer_rotor;
			std::cout << "Indica la posicion del primer rotor A-Z " << std::endl;
			std::cin>>posicion_primer_rotor;

			std::string posicion_segundo_rotor;
			std::cout << "Indica la posicion del segundo rotor (A-Z): " << std::endl;
			std::getline(std::cin, posicion_segundo_rotor);

			std::string posicion_tercer_rotor;
			std::cout << "Indica la posicion del tercer rotor (A-Z): " << std::endl;
			std::getline(std::cin, posicion_tercer_rotor);






















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

			descifrar(indice_posicion_primero, indice_posicion_segundo, indice_posicion_tercero);
		}
		break;

		// Editar rotores
		case 3: {

			editar_rotor();
			break;

		}

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

