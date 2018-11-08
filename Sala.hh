#ifndef _SALA_HH
#define _SALA_HH

#ifndef NO_DIAGRAM

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <map>

#endif
/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

using namespace std;

/**
@class Sala
 *
@brief Esta es la clase sala, esta clase contiene la estantería, que es una matriz de productos de tamaño f*c
 y las operaciones relacionadas con dicha sala.
 */


class Sala {
public:

    //Constructores

    /** @brief Constructor por defecto
    
    Se ejecuta automaticamente al declarar la sala
    \pre cierto
   \post El resultado es una sala
    */

    Sala();

    /** @brief Constructor con valores concretos.

   Se ejecuta automáticamente al declarar una sala.

   \pre f,c >=0
   \post El resultado es una sala con una estantería de tamaño f*c.
    */

    Sala(int f, int c);

    //Modificadoras


    /**
   @brief Elimina los productos de la sala

   \pre ID Sala válido, x>=0 
   \post Se eliminan los x productos de la sala

    */

    int eliminar_productos(string ID, int x);

    /**
    @brief Añade productos.

   \pre  ID empieza por letra, x>=0
   \post Devuelve las unidades que no se hayan añadido.

   */

    int add_productos(string ID, int x);

    /**
   @brief Compacta la estantería.

   \pre  cierto
   \post El resultado es una estantería sin espacios entre productos.

   */

    void compactar();

    /**
   @brief Reorganiza la estantería .

   \pre  cierto
   \post El resultado es una estantería con IDs ordenados alfabéticamente y sin espacio entre ellos.

   */

    void reorganizar();

    /**
   @brief Redimensiona la estantería .

   \pre  f,c >0 
   \post Modifica el tamaño de la estantería y si no puede, devuelve un error.

    */

    void redimensionar(int f, int c, bool &error);

    //Consultora

    /**
    @brief Consulta el producto .

     \pre f,c >=0 and f,c < tamaño matriz estanteria
     \post Devuelve el ID del producto de la posición determinada.

     */
    string consultar_producto(int f, int c) const;

    //Lectura y escritura

    /**
   @brief escribe

   \pre cierto
   \post Escribe la estantería y los productos ordenados alfabéticamente con la cantidad correspondiente.

     */

    void escribir() const;

private:

    typedef vector <vector<string>> Estanteria;

    /**
   @brief Mapa que contiene los productos y la cantidad que hay de cada uno en el almacén
    */

    map<string, int> productos;

    /**
   @brief Matriz estantería en la que almacenamos los productos
     */

    Estanteria est;


    /**
   @brief Cantidad de productos
    *
   \pre cierto
   \post Devuelve la cantidad de productos que hay en una estantería
    */

    int total_productos() const;


};

#endif

