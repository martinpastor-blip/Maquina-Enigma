#pragma once

#include "comprobaciones.h"  

// Esta función abre un archivo, lee su contenido como un string, y valida que sea un rotor correcto.
inline std::string leerRotor(std::string nombre_archivo) {  // 'nombre_archivo' es el nombre del archivo a leer (e.g., "rotor1.txt").
    std::ifstream archivo_rotor(nombre_archivo);  // 'archivo_rotor' es el objeto para manejar el archivo.

    // Verificar si el archivo se abrió correctamente.
    if (!archivo_rotor.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return "";  // Retornar string vacío si falla.
    }

    std::string contenido_rotor;  // 'contenido_rotor' almacenará el contenido leído del archivo.
    std::getline(archivo_rotor, contenido_rotor);  // Leer una línea completa del archivo.
    archivo_rotor.close();  // Cerrar el archivo después de leer.

    // Validar que el contenido sea un rotor válido (usando la función del header).
    if (!esRotorValido(contenido_rotor)) {
        std::cerr << "Error: El rotor en " << nombre_archivo << " no es válido (debe ser 26 letras mayúsculas únicas)." << std::endl;
        return "";  // Retornar string vacío si no es válido.
    }

    return contenido_rotor;  // Retornar el rotor válido.
}

// Esta función genera un string que representa el "cableado inverso" del rotor,
// necesario para el descifrado.
inline std::string crearInverso(std::string rotor) {
    std::string inverso_rotor(26, ' ');  // 'inverso_rotor' es un string de 26 espacios que se llenará con el mapping inverso.

    // Para cada posición en el rotor (0-25), calcular dónde apunta en el inverso.
    for (int indice_posicion = 0; indice_posicion < 26; ++indice_posicion) {
        // 'salida_original' es el índice al que apunta la letra en la posición 'indice_posicion'.
        int salida_original = rotor[indice_posicion] - 'A';
        // En el inverso, la posición 'salida_original' apunta de vuelta a 'indice_posicion'.
        inverso_rotor[salida_original] = 'A' + indice_posicion;
    }

    return inverso_rotor;
}

// Esta función toma un carácter y lo convierte a mayúscula si es minúscula; de lo contrario, lo deja igual.
inline char toUpper(char caracter_entrada) {  // 'caracter_entrada' es el carácter a convertir.
    if (caracter_entrada >= 'a' && caracter_entrada <= 'z') {
        return caracter_entrada - 'a' + 'A';  // Convertir minúscula a mayúscula.
    }
    return caracter_entrada;  // Ya es mayúscula o no es letra.

