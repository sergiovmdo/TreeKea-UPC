#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_

#include "Sala.hh"
#include "Inventario.hh"

#ifndef NO_DIAGRAM

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "BinTree.hh"


#endif

/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/

using namespace std;

/**
@class Almacen
 *
@brief Esta es la clase almacén, esta clase contiene las salas del almacén que estan distribuidas mediante un
BinTree. Contiene todas las funciones necesarias para realizar las operaciones sobre las salas.
 */

class Almacen {

public:

    //Constructora

    /** @brief Constructor por defecto

     Se ejecuta automáticamente al declarar el almacén

    \pre cierto
     \post El resultado es un almacén
    */

    Almacen();

    //Modificadoras

    /** @brief Coloca productos en la sala

        \pre ID Sala >0 , ID comienza por letra, x>0
        \post Devuelve un entero con la cantidad de productos que no han podido ser colocados.
    */

    int poner_items(Inventario &inventario, int ID_Sala, string ID, int x, bool &error);

    /** @brief Quita productos de la sala

        \pre ID Sala >0 , ID comienza por letra, x>=0.
        \post Devuelve un entero con la cantidad de productos que no se han quitado.
    */

    int quitar_items(Inventario &inventario, int ID_Sala, string ID, int x, bool &error);

    /** @brief Distribuye el producto

        \pre ID empieza por letra, x>=0
        \post El resultado es la cantidad de productos que no se han
        distribuido
    */

    int distribuir(Inventario &inventario, string ID, int x, bool &error);

    /** @brief Compacta la estantería.

        \pre ID sala > 0
        \post El resultado es una estantería compactada.
    */

    void compactar(int ID_Sala);

    /** @brief Reorganiza la estantería

        \pre ID_Sala >0
        \post El resultado es una estantería reorganizada
     */

    void reorganizar(int ID_Sala);

    /** @brief Redimensiona la estantería

      \pre ID_Sala > 0 , f,c >0
      \post El resultado es una estantería redimensionada con los valores dados
       o un error si no es posible la redimensión.
     */

    void redimensionar(int ID_Sala, int f, int c, bool &error);


    //Lectura y escritura

    /** @brief Escribe

     \pre ID_Sala >0
     \post El resultado es la escritura del contenido de la estantería de la sala y los productos ordenados
     alfabéticamente con la cantidad correspondiente.
    */

    void escribir(int ID_Sala) const;

    /** @brief Escribe el producto de la posición dada

     \pre ID_Sala > 0 , f,c >0
     \post El resultado es el producto que hay en esa
     posición o NULL si no hay producto en la posición.
    */

    string consultar_pos(int ID_Sala, int f, int c) const;


private:

    /**
       @brief Vector que almacena las salas del almacén
     */
    vector <Sala> almacen;

    /**
       @brief BinTree que contiene los IDs de las salas.
     */

    BinTree<int> IDs;


    /** @brief Lectura del arbol y dimensiones de las salas

    \pre cierto
    \post El almacén y las salas leídas.
    */

    void leer_salas();

    /** @brief Función de inmersión de distribuir

     \pre salas != empty, ID válido and cantidad >0
    \post El resultado es la cantidad de productos que no han sido añadidos
    */

    int i_distribuir(BinTree<int> salas, string ID, int cantidad);

};

#endif

