// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 7
// Problema planteado: 


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int contarPalabras(const std::string& texto) {
    std::istringstream stream(texto);
    std::string palabra;
    int contador = 0;

    while (stream >> palabra) {
        contador++;
    }

    return contador;
}

int main() {
    // Nombre del archivo de entrada
    std::string archivoEntrada;

    std::cout << "Ingrese el nombre del archivo de texto: ";
    std::getline(std::cin, archivoEntrada);

    // Abrir el archivo de entrada
    std::ifstream archivo(archivoEntrada);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // Leer el contenido del archivo
    std::ostringstream contenidoStream;
    contenidoStream << archivo.rdbuf();
    std::string contenido = contenidoStream.str();

    // Contar el n�mero de palabras
    int numPalabras = contarPalabras(contenido);

    // Mostrar estad�sticas
    std::cout << "Estad�sticas del archivo '" << archivoEntrada << "':" << std::endl;
    std::cout << "N�mero de palabras: " << numPalabras << std::endl;

    // Cerrar el archivo
    archivo.close();

    return 0;
}

