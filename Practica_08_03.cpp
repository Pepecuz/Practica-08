// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 3
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

struct Persona {
    char nombre[31];
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

void procesarCandidatos(istream& archivoEntrada, ostream& archivoAceptados) {
    Persona persona;

    while (archivoEntrada.read(reinterpret_cast<char*>(&persona), sizeof(Persona))) {
        // Verificar si la persona es aceptable como candidato
        if (persona.sexo != 'M' && persona.sexo != 'F') {
            cerr << "Error: Sexo no válido para la persona " << persona.nombre << endl;
            continue;
        }

        int nacDia, nacMes, nacAnio;

        // Validar que la fecha de nacimiento se pueda analizar correctamente
        if (sscanf(persona.fechaNacimiento, "%d/%d/%d", &nacDia, &nacMes, &nacAnio) != 3) {
            cerr << "Error: Fecha de nacimiento no válida para la persona " << persona.nombre << endl;
            continue;
        }

        // Obtener el mes y año actual
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int actualMes = now->tm_mon + 1; // tm_mon es 0-based
        int actualAnio = now->tm_year + 1900; // tm_year es el año desde 1900

        // Verificar si la persona cumple con los criterios de aceptación
        if (persona.sexo != 'F' && nacMes == actualMes && nacAnio == actualAnio) {
            cout << "Candidato aceptado: " << persona.nombre << endl;

            // Escribir la información del candidato aceptado en el archivo ACEPTADOS.DAT
            archivoAceptados.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
        }
    }
}

int main() {
    ifstream archivoPersonas("PERSONAS.DAT", ios::binary);

    if (!archivoPersonas.is_open()) {
        cerr << "Error al abrir el archivo PERSONAS.DAT" << endl;
        return 1;
    }

    ofstream archivoAceptados("ACEPTADOS.DAT", ios::binary);

    if (!archivoAceptados.is_open()) {
        cerr << "Error al abrir el archivo ACEPTADOS.DAT" << endl;
        return 1;
    }

    cout << "Procesando candidatos..." << endl;
    procesarCandidatos(archivoPersonas, archivoAceptados);

    archivoPersonas.close();
    archivoAceptados.close();

    cout << "Proceso completado. Verifica el archivo ACEPTADOS.DAT para ver los candidatos aceptados." << endl;

    return 0;
}

