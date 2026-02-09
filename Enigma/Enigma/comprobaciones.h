#pragma once

#pragma once

inline bool esLetraMayuscula(char c) {
	return c >= 'A' && c <= 'Z';

}

// Esta función verifica que el rotor tenga exactamente 26 caracteres (uno por letra del alfabeto)
// y que cada letra sea mayúscula y única (sin repeticiones).
bool esRotorValido(std::string rotor) {
	// Verificar que el rotor tenga exactamente 26 letras.
	// Si no tiene 26, no es válido porque faltarían o sobrarían letras.
	if (rotor.length() != 26) return false;

	// Array para marcar si cada letra A-Z ha sido vista (inicialmente todas false).
	// Esto asegura que no haya letras repetidas y que estén todas presentes.
	bool letras_vistas[26] = { false };

	// Recorrer cada carácter del rotor para validar.
	for (size_t indice_caracter = 0; indice_caracter < rotor.length(); ++indice_caracter) {
		char caracter_rotor = rotor[indice_caracter];  // 'caracter_rotor' representa la letra actual del rotor que se está verificando.

		// Verificar que el carácter sea una letra mayúscula (usando la función del header).
		// Si no es mayúscula, el rotor no es válido.
		if (!esLetraMayuscula(caracter_rotor)) return false;

		// Calcular el índice correspondiente a la letra (A=0, B=1, ..., Z=25).
		int indice_letra = caracter_rotor - 'A';

		// Si la letra ya fue vista, significa que está repetida, por lo que el rotor no es válido.
		if (letras_vistas[indice_letra]) return false;

		// Marcar la letra como vista.
		letras_vistas[indice_letra] = true;
	}

	// Verificar que todas las letras A-Z estén presentes (ninguna debe estar en false).
	for (int indice_letra = 0; indice_letra < 26; ++indice_letra) {
		if (!letras_vistas[indice_letra]) return false;
	}

	// Si pasa todas las verificaciones, el rotor es válido.
	return true;
}

