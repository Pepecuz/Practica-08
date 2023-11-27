// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 6
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

    // Condici�n sobre el campo Precio
    std::string condicionPrecio;
    std::cout << "Ingrese la condici�n sobre el campo Precio (por ejemplo, 'Precio <= 100'): ";
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

    // Leer cada l�nea del archivo de entrada
    std::string linea;
    while (std::getline(entrada, linea)) {
        std::istringstream iss(linea);
        std::string nombre;
        float precio;

        // Suponemos que el formato es nombre,precio
        if (std::getline(iss, nombre, ',') && (iss >> precio)) {
            // Verificar si la condici�n sobre el campo Precio se cumple
            if (evaluarCondicion(condicionPrecio, precio)) {
                // Escribir la l�nea en el archivo de salida
                salida << linea << std::endl;
            }
        } else {
            std::cerr << "Formato de l�nea incorrecto: " << linea << std::endl;
        }
    }

    // Cerrar los archivos
    entrada.close();
    salida.close();

    std::cout << "Se ha creado el archivo " << archivoSalida << " con los art�culos que cumplen la condici�n." << std::endl;

    return 0;
}

// Funci�n para evaluar la condici�n sobre el campo Precio
bool evaluarCondicion(const std::string& condicion, float precio) {
    // Aqu� puedes implementar la l�gica para evaluar la condici�n
    // Por simplicidad, este ejemplo simplemente verifica si el precio es mayor que 100
    return precio > 100;
}


