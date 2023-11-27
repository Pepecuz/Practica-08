// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz LLanos
// Fecha creación: 20/11/2023
// Fecha modificación: 27/11/2023
// Número de ejericio: 4
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

// Función de comparación para ordenar por código
bool compararPorCodigo(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}

int main() {
    vector<Articulo> almacen;
    Articulo articulo;

    cout << "Ingrese los datos de los artículos. Para finalizar, ingrese un código igual a 0." << endl;

    while (true) {
        cout << "Código del artículo (0 para finalizar): ";
        cin >> articulo.codigo;

        // Verificar si se debe finalizar la entrada de datos
        if (articulo.codigo == 0) {
            break;
        }

        cout << "Nombre del artículo: ";
        cin.ignore(); // Limpiar el buffer de entrada antes de leer la cadena
        getline(cin, articulo.nombre);

        cout << "Existencias actuales: ";
        cin >> articulo.existencias;

        cout << "Precio: ";
        cin >> articulo.precio;

        almacen.push_back(articulo);
    }

    // Ordenar el vector por código antes de escribir en el fichero
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

    cout << "Fichero ALMACEN.txt creado con éxito." << endl;

    return 0;
}

