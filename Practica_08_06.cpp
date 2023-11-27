// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 6
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // Nombre del archivo de entrada proporcionado en el ejercicio 4
    std::string archivoEntrada = "ejercicio4.txt";

    // Nombre del archivo de salida
    std::string archivoSalida = "salida.dat";

    // Condición sobre el campo Precio
    std::string condicionPrecio;
    std::cout << "Ingrese la condición sobre el campo Precio (por ejemplo, 'Precio <= 100'): ";
    std::getline(std::cin, condicionPrecio);

    // Abrir el archivo de entrada
    std::ifstream entrada(archivoEntrada);
    if (!entrada.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Abrir el archivo de salida
    std::ofstream salida(archivoSalida);
    if (!salida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    // Leer cada línea del archivo de entrada
    std::string linea;
    while (std::getline(entrada, linea)) {
        std::istringstream iss(linea);
        std::string nombre;
        float precio;

        // Suponemos que el formato es nombre,precio
        if (std::getline(iss, nombre, ',') && (iss >> precio)) {
            // Verificar si la condición sobre el campo Precio se cumple
            if (evaluarCondicion(condicionPrecio, precio)) {
                // Escribir la línea en el archivo de salida
                salida << linea << std::endl;
            }
        } else {
            std::cerr << "Formato de línea incorrecto: " << linea << std::endl;
        }
    }

    // Cerrar los archivos
    entrada.close();
    salida.close();

    std::cout << "Se ha creado el archivo " << archivoSalida << " con los artículos que cumplen la condición." << std::endl;

    return 0;
}

// Función para evaluar la condición sobre el campo Precio
bool evaluarCondicion(const std::string& condicion, float precio) {
    // Aquí puedes implementar la lógica para evaluar la condición
    // Por simplicidad, este ejemplo simplemente verifica si el precio es mayor que 100
    return precio > 100;
}


