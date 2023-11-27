// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 9
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Nombre del archivo binario de entrada
    std::string archivoEntrada;
    std::cout << "Ingrese el nombre del archivo binario de entrada: ";
    std::getline(std::cin, archivoEntrada);

    // Abrir el archivo binario de entrada
    std::ifstream entradaBinaria(archivoEntrada, std::ios::binary);
    if (!entradaBinaria.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo binario de entrada." << std::endl;
        return 1;
    }

    // Leer la tabla de números desde el archivo binario
    std::vector<std::vector<double>> tabla;
    double numero;
    while (entradaBinaria.read(reinterpret_cast<char*>(&numero), sizeof(double))) {
        tabla.back().push_back(numero);
    }

    // Cerrar el archivo binario de entrada
    entradaBinaria.close();

    // Calcular las sumas horizontales y verticales
    std::vector<double> sumasHorizontales(tabla.size(), 0.0);
    std::vector<double> sumasVerticales(tabla[0].size(), 0.0);

    for (size_t i = 0; i < tabla.size(); ++i) {
        for (size_t j = 0; j < tabla[i].size(); ++j) {
            sumasHorizontales[i] += tabla[i][j];
            sumasVerticales[j] += tabla[i][j];
        }
    }

    // Pedir al usuario que elija el tipo de archivo de salida
    std::cout << "¿Desea guardar los resultados en un archivo de texto (T) o binario (B)? ";
    char tipoArchivo;
    std::cin >> tipoArchivo;

    // Nombre del archivo de salida
    std::string archivoSalida;
    std::cout << "Ingrese el nombre del archivo de salida: ";
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::getline(std::cin, archivoSalida);

    // Guardar los resultados en el archivo de salida
    if (tipoArchivo == 'T' || tipoArchivo == 't') {
        // Guardar en formato de texto
        std::ofstream salidaTexto(archivoSalida);
        for (size_t i = 0; i < tabla.size(); ++i) {
            for (size_t j = 0; j < tabla[i].size(); ++j) {
                salidaTexto << tabla[i][j] << ' ';
            }
            salidaTexto << sumasHorizontales[i] << std::endl;
        }
        for (size_t j = 0; j < sumasVerticales.size(); ++j) {
            salidaTexto << sumasVerticales[j] << ' ';
        }
        salidaTexto << std::endl;
        salidaTexto.close();
    } else if (tipoArchivo == 'B' || tipoArchivo == 'b') {
        // Guardar en formato binario
        std::ofstream salidaBinaria(archivoSalida, std::ios::binary);
        for (size_t i = 0; i < tabla.size(); ++i) {
            salidaBinaria.write(reinterpret_cast<const char*>(tabla[i].data()), tabla[i].size() * sizeof(double));
            salidaBinaria.write(reinterpret_cast<const char*>(&sumasHorizontales[i]), sizeof(double));
        }
        salidaBinaria.write(reinterpret_cast<const char*>(sumasVerticales.data()), sumasVerticales.size() * sizeof(double));
        salidaBinaria.close();
    } else {
        std::cerr << "Error: Opción de archivo no válida." << std::endl;
        return 1;
    }

    std::cout << "Se han calculado las sumas horizontales y verticales y se han guardado en el archivo '" << archivoSalida << "'." << std::endl;

    return 0;
}

