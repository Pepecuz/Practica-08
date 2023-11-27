// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 2
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Persona {
    char nombre[31];
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

int main() {
    ofstream archivoPersonas("PERSONAS.BIN", ios::binary);

    if (!archivoPersonas.is_open()) {
        cerr << "Error al abrir el archivo PERSONAS.BIN" << endl;
        return 1;
    }

    Persona persona;

    cout << "Ingrese la informaci�n de las personas. Para finalizar, ingrese un nombre con solo espacios." << endl;

    while (true) {
        cout << "Nombre: ";
        cin.getline(persona.nombre, 31);

        // Verificar si el nombre contiene solo espacios para finalizar la entrada de datos
        if (strlen(persona.nombre) == 0 || (strlen(persona.nombre) == 1 && persona.nombre[0] == ' '))
            break;

        cout << "Edad: ";
        cin >> persona.edad;

        cout << "Sexo (M/F): ";
        cin >> persona.sexo;

        cout << "Fecha de Nacimiento (dd/mm/yyyy): ";
        cin.ignore(); // Ignorar el salto de l�nea pendiente
        cin.getline(persona.fechaNacimiento, 11);

        // Escribir la informaci�n de la persona en el archivo
        archivoPersonas.write(reinterpret_cast<char*>(&persona), sizeof(Persona));

        // Limpiar el buffer de entrada
        cin.ignore();
    }

    archivoPersonas.close();

    cout << "Informaci�n de personas guardada en PERSONAS.BIN" << endl;

    return 0;
}

