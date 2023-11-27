// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 5
// Problema planteado: 

#include <iostream>
#include <fstream>

using namespace std;

struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

bool compararPorCodigo(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}

void leerArchivo(const string& nombreArchivo, Articulo almacen[], int& tamano) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    tamano = 0;
    while (archivo >> almacen[tamano].codigo >> ws && getline(archivo, almacen[tamano].nombre) >> almacen[tamano].existencias >> almacen[tamano].precio) {
        tamano++;
    }

    archivo.close();
}

void escribirArchivo(const string& nombreArchivo, const Articulo almacen[], int tamano) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    for (int i = 0; i < tamano; ++i) {
        archivo << almacen[i].codigo << " " << almacen[i].nombre << " " << almacen[i].existencias << " " << almacen[i].precio << endl;
    }

    archivo.close();
}

void mezclarArchivos(const Articulo almacen1[], int tamano1, const Articulo almacen2[], int tamano2, Articulo resultado[], int& tamanoResultado) {
    int i = 0, j = 0, k = 0;

    while (i < tamano1 && j < tamano2) {
        if (almacen1[i].codigo < almacen2[j].codigo) {
            resultado[k++] = almacen1[i++];
        } else {
            resultado[k++] = almacen2[j++];
        }
    }

    while (i < tamano1) {
        resultado[k++] = almacen1[i++];
    }

    while (j < tamano2) {
        resultado[k++] = almacen2[j++];
    }

    tamanoResultado = k;
}

int main() {
    const int MAX_TAMANO = 1000;  // Puedes ajustar este tamaño según tus necesidades
    Articulo almacen1[MAX_TAMANO], almacen2[MAX_TAMANO], resultado[2 * MAX_TAMANO];
    int tamano1, tamano2, tamanoResultado;

    cout << "Ingrese el nombre del primer archivo ordenado: ";
    string archivo1;
    cin >> archivo1;

    cout << "Ingrese el nombre del segundo archivo ordenado: ";
    string archivo2;
    cin >> archivo2;

    leerArchivo(archivo1, almacen1, tamano1);
    leerArchivo(archivo2, almacen2, tamano2);

    mezclarArchivos(almacen1, tamano1, almacen2, tamano2, resultado, tamanoResultado);

    cout << "Ingrese el nombre del archivo de salida para el resultado ordenado: ";
    string archivoSalida;
    cin >> archivoSalida;

    escribirArchivo(archivoSalida, resultado, tamanoResultado);

    cout << "Fichero " << archivoSalida << " creado con éxito." << endl;

    return 0;
}

