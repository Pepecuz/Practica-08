// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 3
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
            cerr << "Error: Sexo no v�lido para la persona " << persona.nombre << endl;
            continue;
        }

        int nacDia, nacMes, nacAnio;

        // Validar que la fecha de nacimiento se pueda analizar correctamente
        if (sscanf(persona.fechaNacimiento, "%d/%d/%d", &nacDia, &nacMes, &nacAnio) != 3) {
            cerr << "Error: Fecha de nacimiento no v�lida para la persona " << persona.nombre << endl;
            continue;
        }

        // Obtener el mes y a�o actual
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int actualMes = now->tm_mon + 1; // tm_mon es 0-based
        int actualAnio = now->tm_year + 1900; // tm_year es el a�o desde 1900

        // Verificar si la persona cumple con los criterios de aceptaci�n
        if (persona.sexo != 'F' && nacMes == actualMes && nacAnio == actualAnio) {
            cout << "Candidato aceptado: " << persona.nombre << endl;

            // Escribir la informaci�n del candidato aceptado en el archivo ACEPTADOS.DAT
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

