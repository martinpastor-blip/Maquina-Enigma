#include <iostream>
#include <fstream>
#include <string>

#include "rotor.h"
#include "cifrar.h"

/**
 * @brief Cifra un mensaje utilizando tres rotores.
 *
 * La función lee los rotores desde archivos, toma un mensaje en texto plano
 * y lo procesa letra por letra para obtener el mensaje cifrado.
 * Las posiciones iniciales de los rotores deben ser guardadas para
 * poder descifrar el mensaje posteriormente.
 */

void cifrar(std::string mensaje_original, int indice_posicion_primero, int indice_posicion_segundo, int indice_posicion_tercero) {

    // Lee los archivos de rotor
    std::string primer_rotor = leerRotor("Rotor1.txt");
    std::string segundo_rotor = leerRotor("Rotor2.txt");
    std::string tercer_rotor = leerRotor("Rotor3.txt");

    // Si algún rotor no se pudo leer correctamente, se cancela el proceso
    if (primer_rotor.empty() || segundo_rotor.empty() || tercer_rotor.empty()) {
        std::cout << "Error al cargar los rotores." << std::endl;
        return;
    }

    // Separar el cableado del notch (guardados como "cableado|notch")
    std::string::size_type pos_separador_primero = primer_rotor.find('|');
    std::string::size_type pos_separador_segundo = segundo_rotor.find('|');
    std::string::size_type pos_separador_tercero = tercer_rotor.find('|');

    std::string cableado_primer_rotor = primer_rotor.substr(0, pos_separador_primero);
    std::string cableado_segundo_rotor = segundo_rotor.substr(0, pos_separador_segundo);
    std::string cableado_tercer_rotor = tercer_rotor.substr(0, pos_separador_tercero);

    // Se convierte todo a mayúsculas y se eliminan los caracteres que no sean letras entre A y Z.
    std::string mensaje_procesado;
    int longitud_original = mensaje_original.length();

    for (int i = 0; i < longitud_original; i++) {
        char letra = toUpper(mensaje_original[i]);
        if (letra >= 'A' && letra <= 'Z') {
            mensaje_procesado += letra;
        }
    }

    // Cifrar letra por letra
    std::string mensaje_cifrado;
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

        // Paso por los rotores hacia adelante (CIFRADO)
        int entrada = caracter - 'A';

        // Primer rotor
        int salida1 = cableado_primer_rotor[
            (entrada + indice_posicion_primero) % 26] - 'A';

        // Segundo rotor
        int salida2 = cableado_segundo_rotor[
            (salida1 + indice_posicion_segundo) % 26] - 'A';

        // Tercer rotor
        int salida3 = cableado_tercer_rotor[
            (salida2 + indice_posicion_tercero) % 26] - 'A';

        // Convierte el resultado final en una letra
        char letra_cifrada = 'A' + salida3;
        mensaje_cifrado += letra_cifrada;
    }

    // Proceso de guardado del archivo cifrado.txt
    std::ofstream archivo("Cifrado.txt");
    if (archivo.is_open()) {

        archivo << mensaje_cifrado;
        archivo.close();
        std::cout << "[OK] Mensaje cifrado a \"Cifrado.txt\" (" << mensaje_cifrado.length() << " letras)" << std::endl;
    }
}