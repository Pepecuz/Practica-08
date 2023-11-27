// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Nombre del archivo de entrada
    std::string archivoEntrada;
    std::cout << "Ingrese el nombre del archivo de entrada: ";
    std::getline(std::cin, archivoEntrada);

    // Nombre del archivo de salida binario
    std::string archivoSalida;
    std::cout << "Ingrese el nombre del archivo de salida binario: ";
    std::getline(std::cin, archivoSalida);

    // Abrir el archivo de entrada
    std::ifstream entrada(archivoEntrada);
    if (!entrada.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Leer los números reales desde el archivo de entrada
    std::vector<double> numeros;
    double numero;
    while (entrada >> numero) {
        numeros.push_back(numero);
    }

    // Cerrar el archivo de entrada
    entrada.close();

    // Abrir el archivo binario de salida
    std::ofstream salidaBinaria(archivoSalida, std::ios::binary);
    if (!salidaBinaria.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo binario de salida." << std::endl;
        return 1;
    }

    // Escribir los números en formato binario en el archivo de salida
    salidaBinaria.write(reinterpret_cast<const char*>(numeros.data()), numeros.size() * sizeof(double));

    // Cerrar el archivo binario de salida
    salidaBinaria.close();

    std::cout << "Se ha creado el archivo binario '" << archivoSalida << "' a partir de los datos del archivo de entrada." << std::endl;

    return 0;
}



