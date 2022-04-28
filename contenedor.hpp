// *******************************************************************************
// Fichero de cabecera Contenedor.hpp para la definición de la clase Contenedor
// *******************************************************************************

//....... COMPLETAR TODO LO NECESARIO

// Hay que ponerlo todo en el espacio de nombres bblProgIIB

// ¡IMPORTANTE: ESPECIFICAR LOS MÉTODOS QUE SEAN const!!!


#ifndef __CONTENEDOR_HPP__
#define __CONTENEDOR_HPP__
#include <string>
#include <array>
#include "caja.hpp"

namespace bblProgIIB
{

    class Contenedor
    {
    public:
        // Constructor por defecto: inicializa un Contenedor vacío, sin cajas
        Contenedor();
        // Constructor de copia
        Contenedor(const Contenedor &otro_contenedor);
        // Destructor del Contenedor
        ~Contenedor();
        // Devuelve el número de cajas que tiene el Contenedor
        unsigned numeroCajas();

        // Consulta el identificador del Contenedor.
        std::string consultarIdent() const;

        // Consulta el CIF del dueño del Contenedor.
        std::string consultarCIF() const;

        // Modifica el identificador del Contenedor.
        void modificarIdent(const std::string &id);

        // Modifica el CIF del dueño del Contenedor.
        void modificarCIF(const std::string &id);

        // Inserta una nueva caja en el Contenedor, en la posición indicada.
        // si se puede, devuelve 'true' a través de 'res'. Si no, se devuelve 'false'.
        void insertar(unsigned pos, const Caja &c, bool &res);

        // Elimina una caja del Contenedor.
        // Si la posición es válida, la elimina y devuelve 'true' a través de res.
        // Si no existe, devuelve 'false'
        void eliminar(unsigned pos, bool &res);

        // Consulta una caja de producto.
        // Si la caja existe, la devuelve a través del segundo parámetro y
        // devuelve 'true' a través de 'res'. Si no, devuelve 'false' a través
        // de 'res'.
        void consultarCaja(unsigned numCaja, Caja &cont, bool &res) const;

        // Lee desde fichero los datos de un contenedor y las cajas que tiene.
        void leerFich(const std::string &nomFich);

        // Escribe en fichero los datos del contenedor  y de todas las cajas que tiene

        void escribirFich(const std::string &nomFich);

        // muestra por pantalla los datos del contenedor y de todas las cajas que contiene
        void mostrar() const;

        // Operador de asignación
        Contenedor &operator=(const Contenedor &otroCont);

        // Operador de igualdad
        bool operator==(const Contenedor &otro) const;
        /* OPERADOR DE COMPARACIÓN DE IGUALDAD
           Implementación
        bool Contenedor::operator==(const Contenedor &otro) const
        {
            bool ok = num == otro.num;
            unsigned i = 0;
            while (ok && i < num)
            {
                ok = lista[i] == otro.lista[i];
                i++;
            }
            return ok;
        }
        */

        //....... COMPLETAR TODO LO NECESARIO
    private:
        std::string identificador;
        std::string cif;
        std::array<Caja, 1000>lista;
        unsigned numerocajas;

    };

}
#endif