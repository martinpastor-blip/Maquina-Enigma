#include "includes.h"
#include "comprobaciones.h"
#include "rotor.h"

std::string leerRotor(const std::string& nombre_archivo) {
    std::ifstream archivo_rotor(nombre_archivo);

    if (!archivo_rotor.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return "";
    }

    std::string cableado_rotor;
    std::getline(archivo_rotor, cableado_rotor);

    std::string linea_notch;
    std::getline(archivo_rotor, linea_notch);

    char notch_leida;

    if (linea_notch.empty() || linea_notch.length() != 1 || !esLetraMayuscula(linea_notch[0])) {
        notch_leida = 'Z';
    }
    else {
        notch_leida = linea_notch[0];
    }

    archivo_rotor.close();

    if (!esRotorValido(cableado_rotor)) {
        std::cerr << "Error: El rotor en " << nombre_archivo << " no es válido (debe ser 26 letras mayúsculas únicas)." << std::endl;
        return "";
    }

    return cableado_rotor + "|" + notch_leida;
}

std::string crearInverso(const std::string& rotor) {
    // Separar cableado de notch
    int pos_pipe = rotor.find('|');
    std::string solo_cableado;

    if (pos_pipe != std::string::npos) {
        solo_cableado = rotor.substr(0, pos_pipe);
    }
    else {
        solo_cableado = rotor;
    }

    std::string inverso_rotor(26, ' ');

    for (int indice_posicion = 0; indice_posicion < 26; ++indice_posicion) {
        int salida_original = solo_cableado[indice_posicion] - 'A';
        inverso_rotor[salida_original] = 'A' + indice_posicion;
    }

    return inverso_rotor;
}

char toUpper(char caracter_entrada) {
    if (caracter_entrada >= 'a' && caracter_entrada <= 'z') {
        return caracter_entrada - 'a' + 'A';
    }
    return caracter_entrada;
}