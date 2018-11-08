#include "Sala.hh"
#include <utility>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

Sala::Sala() {

}


Sala::Sala(int f, int c) {
    est = Estanteria(f, vector<string>(c, "NULL"));
}

/*Recorre la matriz estantería elimando los productos hasta haber eliminado todos o
  hasta que no hayan más para eliminar.

 */

int Sala::eliminar_productos(const string ID, const int x) {

    if (productos.find(ID) == productos.end()) {
        return x;
    }

    //Variable que hace parar a la función cuando se han eliminado todos los productos.
    int stop = 0;

    for (int i = est.size() - 1; i >= 0 and stop < x; --i) {
        for (int j = 0; j < est[0].size() and stop < x; ++j) {
            if (est[i][j] == ID) {
                est[i][j] = "NULL";
                ++stop;
                --productos[ID];  //Quitamos una unidad del inventario interno.
            }
        }
    }

    if (productos[ID] <= 0) {
        productos.erase(ID);
    }
    //Devuelve la cantidad  de productos que no se han eliminado.
    return x - stop;

}

/*Recorre la matriz estantería añadiendo ,los productos hasta haber añadido todos o
  hasta que no hayan más huecos libres..

 */

int Sala::add_productos(const string ID, const int x) {
    //Variable que hace parar a la función cuando se han añadido todos los productos.
    int stop = 0;

    for (int i = est.size() - 1; i >= 0 and stop < x; --i) {
        for (int j = 0; j < est[0].size() and stop < x; ++j) {
            if (est[i][j] == "NULL") {
                est[i][j] = ID;
                ++stop;
                ++productos[ID];  //Añadimos una unidad al inventario interno .
            }
        }
    }
    //Devuelve la cantidad  de productos que no se han añadido
    return x - stop;
}


/*Se copia el contenido de la estanteria en una cola y luego se inserta en otra matriz de manera que queda compactada
  y al final de la operación se substituye la matriz auxiliar por la original.

 */
void Sala::compactar() {
    Estanteria aux(est.size(), vector<string>(est[0].size(), "NULL"));
    //Cola que contiene los elementos de la estantería original en orden de posición
    queue <string> orden;

    for (int i = est.size() - 1; i >= 0; --i) {
        for (int j = 0; j < est[0].size(); ++j) {
            if (est[i][j] != "NULL") {
                orden.push(est[i][j]);
            }
        }
    }

    for (int k = est.size() - 1; k >= 0 and not orden.empty(); --k) {
        for (int l = 0; l < est[0].size() and not orden.empty(); ++l) {
            aux[k][l] = orden.front();
            orden.pop();
        }
    }
    est = aux;

}

/*Se utiliza el mapa de productos de la sala que tenemos y que ya esta ordenado alfabeticamente y se van añadiendo
 * tantos elementos en la matriz nueva como elementos indique el mapa que tiene ese producto.
  Al final se copia la matriz auxiliar a la estanteria de la clase

 */

void Sala::reorganizar() {

    Estanteria aux(est.size(), vector<string>(est[0].size(), "NULL"));
    int i = aux.size() - 1;
    int j = 0;
    for (map<string, int>::const_iterator it = productos.begin(); it != productos.end(); ++it) {
        for (int k = 0; k < it->second; ++k) {
            aux[i][j] = it->first;
            if (j + 1 >= aux[0].size()) {
                j = 0;
                --i;
            } else {
                ++j;
            }
        }
    }

    est = aux;

}

/*Se copia el contenido de la matriz original en una auxiliar con el tamaño nuevo y luego volvemos a intercambiar
  a la hora de copiar los productos realizamos la operación de compactar.

 */

void Sala::redimensionar(const int f, const int c, bool &error) {
    error = false;

    int productos = total_productos();

    if (productos <= (f * c)) {

        Estanteria aux(f, vector<string>(c, "NULL"));

        //Cola que contiene los elementos de la estantería original en orden de posición
        queue <string> orden;

        for (int i = est.size() - 1; i >= 0; --i) {
            for (int j = 0; j < est[0].size(); ++j) {
                if (est[i][j] != "NULL") {
                    orden.push(est[i][j]);
                }
            }
        }

        for (int k = f - 1; k >= 0 and not orden.empty(); --k) {
            for (int l = 0; l < c and not orden.empty(); ++l) {
                aux[k][l] = orden.front();
                orden.pop();
            }
        }
        est = aux;
    } else {
        error = true;
    }
}

/*Se comprueba que los datos de entrada son correctos y devolvemos lo que haya en dicha posición

 */

string Sala::consultar_producto(const int f, const int c) const {
    if (f >= 0 and c >= 0 and f < est.size() and c < est[0].size()) {
        return est[f][c];
    } else {
        return "NULL";
    }
}

/*Se escribe por el canal de salida el contenido de la estanería y los productos que hay en dicha sala ordenados
  alfabéticamente y su cantidad.

 */

void Sala::escribir() const {

    for (int i = 0; i < est.size(); ++i) {
        cout << "  ";
        for (int j = 0; j < est[0].size(); ++j) {
            cout << est[i][j];
            if (j + 1 < est[0].size()) cout << " ";
        }
        cout << endl;
    }

    int total = total_productos();
    cout << "  " << total << endl;

    for (map<string, int>::const_iterator it = productos.begin(); it != productos.end(); ++it) {
        cout << "  " << it->first << " " << it->second << endl;
    }

}


/*Accedemos al mapa y devolvemos la cantidad de productos que tiene dicho producto.

 */

int Sala::total_productos() const {
    int total = 0;

    for (map<string, int>::const_iterator it = productos.begin(); it != productos.end(); ++it) {
        total += it->second;
    }
    return total;
}







