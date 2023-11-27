// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 1
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
        caracter = caracter + 3;  // Encriptar: reemplazar cada car�cter por el tercero siguiente en la tabla ASCII
        archivoSalida.put(caracter);
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Encriptaci�n completada. Archivo encriptado: " << nombreArchivoSalida << endl;
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
        caracter = caracter - 3;  // Desencriptar: recuperar cada car�cter original
        archivoSalida.put(caracter);
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Desencriptaci�n completada. Archivo desencriptado: " << nombreArchivoSalida << endl;
}

int main() {
    int opcion;
    string nombreArchivoEntrada, nombreArchivoSalida;

    cout << "Seleccione una opci�n:" << endl;
    cout << "1. Encriptar archivo" << endl;
    cout << "2. Desencriptar archivo" << endl;
    cout << "Opci�n: ";
    cin >> opcion;

    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> nombreArchivoEntrada;

    if (opcion == 1) {
        nombreArchivoSalida = nombreArchivoEntrada + ".COD";
        encriptarArchivo(nombreArchivoEntrada, nombreArchivoSalida);
    } else if (opcion == 2) {
        // Verificar si el archivo tiene la extensi�n .COD
        if (nombreArchivoEntrada.size() > 4 && nombreArchivoEntrada.substr(nombreArchivoEntrada.size() - 4) == ".COD") {
            nombreArchivoSalida = nombreArchivoEntrada.substr(0, nombreArchivoEntrada.size() - 4);
            desencriptarArchivo(nombreArchivoEntrada, nombreArchivoSalida);
        } else {
            cerr << "Error: El archivo de entrada no tiene la extensi�n correcta (.COD)." << endl;
        }
    } else {
        cerr << "Opci�n no v�lida." << endl;
    }

    // Hacer una pausa antes de salir para que el usuario pueda ver los mensajes
    cout << "Presiona Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}

