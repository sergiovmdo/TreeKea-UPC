#include "Inventario.hh"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

Inventario::Inventario() {
    productos = map<string, int>();
}

//Devuelve la cantidad de un producto si existe.
int Inventario::cantidad(const string ID, bool &error) {

    if (existe_prod(ID)) {
        error = false;
        return productos[ID];
    }
    else {
        error = true;
        return 0;
    }
}

//Añadimos un producto al inventario
bool Inventario::add_producto_inv(const string ID) {

    if (existe_prod(ID)) {
        return false;
    }
    //Variable para añadir un nuevo producto en el mapa con 0 unidades.
    pair<string, int> insert = make_pair(ID, 0);
    productos.insert(insert);
    return true;

}

//Añadimos unidades al inventario
bool Inventario::add_productos_inv(const string ID, const int x) {

    if (not existe_prod(ID)) {
        return false;
    }
    productos[ID] = productos[ID] + x;
    return true;
}

//Eliminamos el producto del inventario
bool Inventario::eliminar_producto_inv(const string ID) {

    if (existe_prod(ID) and productos[ID] == 0) {
        productos.erase(ID);
        return true;
    }
    return false;
}

//Eliminamos x unidades del inventario.
bool Inventario::eliminar_productos_inv(const string ID, const int x) {

    if (existe_prod(ID)) {
        productos[ID] = productos[ID] - x;
        return true;
    }
    return false;
}

//Escribe por el canal de salida todos los productos ordenados alfabéticamente.
void Inventario::inventario() const {

    for (map<string, int>::const_iterator it = productos.begin(); it != productos.end(); ++it) {
        cout << "  " << it->first << " " << it->second << endl;
    }
}

//Devuelve si existe o no el producto
bool Inventario::existe_prod(const string ID) const {

    return productos.find(ID) != productos.end();
}



	

