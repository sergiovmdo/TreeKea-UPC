#include "Almacen.hh"
#include "Sala.hh"
#include "BinTreeIOint.hh"
#include <iostream>
#include <map>

using namespace std;

/*Leemos lo necesario para la creación de nuestro almacén.

 */

Almacen::Almacen() {
    leer_salas();
}

/*Se Realizan las comprobaciones necesarias, se añaden los productos añadidos al inventario y devuelve la cantidad
  de productos que no se han añadido.

 */

int Almacen::poner_items(Inventario &inventario, const int ID_Sala, const string ID, const int x, bool &error) {
    error = false;

    if (not inventario.existe_prod(ID)) {
        error = true;
        return x;
    }
    int n = almacen[ID_Sala - 1].add_productos(ID, x);
    inventario.add_productos_inv(ID, x - n);
    return n;

}

/*Se Realizan las comprobaciones necesarias, se quitan los productos del inventario y devuelve la cantidad
  de productos que no se han eliminado.

 */

int Almacen::quitar_items(Inventario &inventario, const int ID_Sala, const string ID, const int x, bool &error) {
    error = false;

    if (not inventario.existe_prod(ID)) {
        error = true;
        return x;
    }

    int n = almacen[ID_Sala - 1].eliminar_productos(ID, x);
    inventario.eliminar_productos_inv(ID, x - n);
    return n;

}

/*Tras ver si existe el producto, accedemos a nuestra función privada de inmersión que devuelve la cantidad de
 * productos que no se han podido distribuir y añadimos al inventario los distribuidos.

 */

int Almacen::distribuir(Inventario &inventario, const string ID, const int x, bool &error) {
    error = false;

    if (not inventario.existe_prod(ID)) {
        error = true;
        return x;
    }
    int n = i_distribuir(IDs, ID, x);
    inventario.add_productos_inv(ID, x - n);
    return n;

}

void Almacen::compactar(const int ID_Sala) {
    almacen[ID_Sala - 1].compactar();
}

void Almacen::reorganizar(const int ID_Sala) {
    almacen[ID_Sala - 1].reorganizar();
}

void Almacen::redimensionar(const int ID_Sala, const int f, const int c, bool &error) {
    almacen[ID_Sala - 1].redimensionar(f, c, error);
}

void Almacen::escribir(const int ID_Sala) const {
    almacen[ID_Sala - 1].escribir();
}

string Almacen::consultar_pos(const int ID_Sala, const int f, const int c) const {
    return almacen[ID_Sala - 1].consultar_producto(f, c);
}


/*Función privada que lee el número de salas, lee el BinTree y el tamaño de la estantería de cada sala.

 */
void Almacen::leer_salas() {
    //Número de salas
    int num;
    cin >> num;

    this->almacen = vector<Sala>(num);

    //leer arbol y guardarlo
    read_bintree_int(IDs, 0);

    int f, c;

    for (int i = 0; i < num; ++i) {
        cin >> f >> c;
        almacen[i] = Sala(f, c);

    }
}


/*Función de inmersión que sigue los criterios de distribución aportados por el enunciado y devuelve la cantidad
  de productos no distribuidos.

 */
int Almacen::i_distribuir(BinTree<int> salas, const string ID, int cantidad) {

    if (salas.empty() or salas.value() == 0) {
        return cantidad;
    }

    cantidad = almacen[salas.value() - 1].add_productos(ID, cantidad);
    if (cantidad > 0) {
        int left = i_distribuir(salas.left(), ID, cantidad - cantidad / 2);
        int right = i_distribuir(salas.right(), ID, cantidad / 2);
        return left + right;
    }

    return cantidad;
}

