/**
@mainpage Práctica pro2. Primavera 2018, TreeKea

Desarrollo de la práctica TreeKEA en la cual se simula un Almacen compuesto por salas, las cuales estan
 distribuidas en forma de BinTree, es decir, desde una sala solo podemos acceder a 3 salas cómo máximo, las 2 hijas y la
 raiz. Cada sala contiene una estantería, que se corresponde a una matriz de string en la cual están almacenados
 los productos.
*/

/** @file main.cc
    @brief Programa principal para la práctica <em>TreeKea</em>.
*/

#include "Almacen.hh"
#include "Inventario.hh"
#include "Sala.hh"

#ifndef NO_DIAGRAM

#include <iostream>
#include <string>
#include <vector>


using namespace std;




#endif

/** @brief Programa principal para la práctica TreeKea
*/
int main() {

    //Declaración de las variables,el almacén, la sala y el inventario.

    Almacen A;
    Inventario inventario;
    string ID; //ID del producto
    string comando; // string para llamada a operaciones.
    int x; // Cantidad del producto.
    int ID_Sala, f, c;
    int cosas = 0;
    string cos;
    bool error;

    cin >> comando;

    while (comando != "fin") {

        error = false;

        cout << comando;

        if (comando == "poner_prod") {

            cin >> ID;

            cout << " " << ID << endl;

            error = not inventario.add_producto_inv(ID);

            if (error) {
                cout << "  error" << endl;
            }

        } else if (comando == "quitar_prod") {

            cin >> ID;

            cout << " " << ID << endl;

            error = not inventario.eliminar_producto_inv(ID);

            if (error) {
                cout << "  error" << endl;
            }

        } else if (comando == "poner_items") {

            cin >> ID_Sala >> ID >> x;

            cout << " " << ID_Sala << " " << ID << " " << x << endl;

            cosas = A.poner_items(inventario, ID_Sala, ID, x, error);

            if (error) {
                cout << "  error" << endl;
            } else if (cosas >= 0) {
                cout << "  " << cosas << endl;
            }

        } else if (comando == "quitar_items") {

            cin >> ID_Sala >> ID >> x;

            cout << " " << ID_Sala << " " << ID << " " << x << endl;

            cosas = A.quitar_items(inventario, ID_Sala, ID, x, error);

            if (error) {
                cout << "  error" << endl;
            } else if (cosas >= 0) {
                cout << "  " << cosas << endl;
            }

        } else if (comando == "distribuir") {

            cin >> ID >> x;

            cout << " " << ID << " " << x << endl;

            cosas = A.distribuir(inventario, ID, x, error);

            if (error) {
                cout << "  error" << endl;
            } else if (cosas >= 0) {
                cout << "  " << cosas << endl;
            }


        } else if (comando == "compactar") {

            cin >> ID_Sala;

            cout << " " << ID_Sala << endl;

            A.compactar(ID_Sala);

        } else if (comando == "reorganizar") {

            cin >> ID_Sala;

            cout << " " << ID_Sala << endl;

            A.reorganizar(ID_Sala);

        } else if (comando == "redimensionar") {

            cin >> ID_Sala >> f >> c;

            cout << " " << ID_Sala << " " << f << " " << c << endl;

            A.redimensionar(ID_Sala, f, c, error);

            if(error) {
                cout << "  error"<<endl;
            }

        } else if (comando == "inventario") {

            cout << endl;

            inventario.inventario();

        } else if (comando == "escribir") {

            cin >> ID_Sala;

            cout << " " << ID_Sala << endl;

            A.escribir(ID_Sala);

        } else if (comando == "consultar_pos") {

            cin >> ID_Sala >> f >> c;

            error=false;

            cout << " " << ID_Sala << " " << f << " " << c << endl;

            cos = A.consultar_pos(ID_Sala, f - 1, c - 1);

            cout << "  " << cos << endl;

        } else if (comando == "consultar_prod") {

            cin >> ID;

            cout << " " << ID << endl;

            cosas = inventario.cantidad(ID, error);

            if (error) {
                cout << "  error" << endl;
            } else {
                cout << "  " << cosas << endl;
            }
        }

        cin >> comando;
    }
    cout << "fin" << endl;
}

