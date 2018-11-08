/** @file Inventario.hh
    @brief Especificación de la clase Inventario
*/


#ifndef _INVENTARIO_HH_
#define _INVENTARIO_HH_

#ifndef NO_DIAGRAM

#include <iostream>
#include <utility>
#include <string>
#include <map>

#endif

/** @file Inventario.hh
    @brief Especificación de la clase Inventario
*/

using namespace std;

/**
@class Inventario
 *
@brief Esta es la clase inventario, esta sala contiene los productos del sistema y las operaciones relacionadas.
 */

class Inventario {

public:

    //Constructor

    /** @brief Constructor por defecto

   Se ejecuta automáticamente al declarar el inventario

    \pre cierto
   \post El resultado es el inventario
    */

    Inventario();

    //Modificadores

    /** @brief Añade un producto

    \pre ID Empieza por letra 
    \post El resultado es si el producto se ha añadido al inventario.
    */

    bool add_producto_inv(string ID);

    /** @brief Elimina un producto

     \pre ID válido 
    \post El resultado es si se ha podido eliminar el producto del inventario.
    */

    bool eliminar_producto_inv(string ID);

    /** @brief Añade una cantidad de un producto

     \pre ID válido , x>=0 
    \post El resultado es si se han podido añadir las x cantidades del producto.
    */

    bool add_productos_inv(string ID, int x);

    /** @brief Elimina una cantidad de un producto

    \pre ID válido , x>0 
   \post El resultado es si se han podido eliminar las x cantidades del producto.
     */

    bool eliminar_productos_inv(string ID, int x);


   //Consultores

    /** @brief Cantidad del producto

     \pre ID válido  
    \post El resultado es la cantidad de ese producto en la estantería
    */

    int cantidad(string ID, bool &error);

    /** @brief Consulta su existencia

    \pre ID válido 
   \post El resultado es si existe o no el producto en el inventario.
    */

    bool existe_prod(string ID) const ;

    //Escribir

    /** @brief Inventario
     *
    \pre  cierto 
    \post El resultado es la escritura del inventario.
    */

    void inventario() const ;

private:

    /**
    @brief Mapa que contiene los productos y la cantidad que hay de cada uno en el almacén
    */

    map<string, int> productos;

};

#endif


