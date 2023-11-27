// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 1
// Problema planteado: 

#include <iostream>
#include <fstream>

using namespace std;

void encriptarArchivo(const string& nombreArchivoEntrada, const string& nombreArchivoSalida) {
    ifstream archivoEntrada(nombreArchivoEntrada, ios::binary);
    ofstream archivoSalida(nombreArchivoSalida, ios::binary);

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        return;
    }

    char caracter;
    while (archivoEntrada.get(caracter)) {
        caracter = caracter + 3;  // Encriptar: reemplazar cada carácter por el tercero siguiente en la tabla ASCII
        archivoSalida.put(caracter);
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Encriptación completada. Archivo encriptado: " << nombreArchivoSalida << endl;
}

void desencriptarArchivo(const string& nombreArchivoEntrada, const string& nombreArchivoSalida) {
    ifstream archivoEntrada(nombreArchivoEntrada, ios::binary);
    ofstream archivoSalida(nombreArchivoSalida, ios::binary);

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        return;
    }

    char caracter;
    while (archivoEntrada.get(caracter)) {
        caracter = caracter - 3;  // Desencriptar: recuperar cada carácter original
        archivoSalida.put(caracter);
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Desencriptación completada. Archivo desencriptado: " << nombreArchivoSalida << endl;
}

int main() {
    int opcion;
    string nombreArchivoEntrada, nombreArchivoSalida;

    cout << "Seleccione una opción:" << endl;
    cout << "1. Encriptar archivo" << endl;
    cout << "2. Desencriptar archivo" << endl;
    cout << "Opción: ";
    cin >> opcion;

    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> nombreArchivoEntrada;

    if (opcion == 1) {
        nombreArchivoSalida = nombreArchivoEntrada + ".COD";
        encriptarArchivo(nombreArchivoEntrada, nombreArchivoSalida);
    } else if (opcion == 2) {
        // Verificar si el archivo tiene la extensión .COD
        if (nombreArchivoEntrada.size() > 4 && nombreArchivoEntrada.substr(nombreArchivoEntrada.size() - 4) == ".COD") {
            nombreArchivoSalida = nombreArchivoEntrada.substr(0, nombreArchivoEntrada.size() - 4);
            desencriptarArchivo(nombreArchivoEntrada, nombreArchivoSalida);
        } else {
            cerr << "Error: El archivo de entrada no tiene la extensión correcta (.COD)." << endl;
        }
    } else {
        cerr << "Opción no válida." << endl;
    }

    // Hacer una pausa antes de salir para que el usuario pueda ver los mensajes
    cout << "Presiona Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}

