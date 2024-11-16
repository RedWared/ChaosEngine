#include <iostream>
#include <strings.h>  // Para strcasecmp

int main() {
	const char* str1 = "hola";
	const char* str2 = "uwu";

	if (strcasecmp(str1, str2) == 0) {
		std::cout << "Las cadenas son iguales.\n";
	} else {
		std::cerr << "Las cadenas son diferentes.\n";
	}

	return 0;
}
