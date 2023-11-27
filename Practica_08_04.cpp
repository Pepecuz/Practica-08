// Materia: Programaci�n I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 27/11/2023
// N�mero de ejericio: 4
// Problema planteado: 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

// Funci�n de comparaci�n para ordenar por c�digo
bool compararPorCodigo(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}

int main() {
    vector<Articulo> almacen;
    Articulo articulo;

    cout << "Ingrese los datos de los art�culos. Para finalizar, ingrese un c�digo igual a 0." << endl;

    while (true) {
        cout << "C�digo del art�culo (0 para finalizar): ";
        cin >> articulo.codigo;

        // Verificar si se debe finalizar la entrada de datos
        if (articulo.codigo == 0) {
            break;
        }

        cout << "Nombre del art�culo: ";
        cin.ignore(); // Limpiar el buffer de entrada antes de leer la cadena
        getline(cin, articulo.nombre);

        cout << "Existencias actuales: ";
        cin >> articulo.existencias;

        cout << "Precio: ";
        cin >> articulo.precio;

        almacen.push_back(articulo);
    }

    // Ordenar el vector por c�digo antes de escribir en el fichero
    sort(almacen.begin(), almacen.end(), compararPorCodigo);

    // Crear el fichero y escribir los datos
    ofstream archivoAlmacen("ALMACEN.txt");

    if (!archivoAlmacen.is_open()) {
        cerr << "Error al abrir el archivo ALMACEN.txt" << endl;
        return 1;
    }

    for (const auto& a : almacen) {
        archivoAlmacen << a.codigo << " " << a.nombre << " " << a.existencias << " " << a.precio << endl;
    }

    archivoAlmacen.close();

    cout << "Fichero ALMACEN.txt creado con �xito." << endl;

    return 0;
}

