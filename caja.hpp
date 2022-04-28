// *******************************************************************************
// Fichero de cabecera caja.hpp para la definición de la clase Caja
// *******************************************************************************

//....... COMPLETAR TODO LO NECESARIO

// Hay que ponerlo todo en el espacio de nombres bblProgIIB

// ¡IMPORTANTE: ESPECIFICAR LOS MÉTODOS QUE SEAN const!!!

#ifndef __CAJA_HPP__
#define __CAJA_HPP__

namespace bblProgIIB
{
        class Caja
        {
        public:
                // Constructor por defecto: nombre vacío, precio y peso a cero y aranceles falso.
                Caja();
                // Constructor de copia
                Caja(const Caja &otra_caja);
                // Constructor extendido
                Caja(const std::string &nom, double euros, double kilos, bool aran);
                // Destructor
                ~Caja();

                // Devuelve el nombre del producto
                std::string consultarNombre() const;

                // Devuelve el precio del producto
                double consultarPrecio() const;

                // Devuelve el peso del producto
                double consultarPeso() const;

                // Devuelve si el producto está sujeto a aranceles o no
                bool sujetoAranceles() const;

                // Modifica el nombre del producto
                void asignarNombre(const std::string &n);

                // Modifica el peso del producto
                void asignarPeso(double kilos);

                // Modifica el precio del producto
                void asignarPrecio(double euros);

                // Modifica si está sujeto a aranceles o no
                void asignarAranceles(bool aran);

                // Lee de teclado todos los datos de la caja
                void leer();

                // Lee de fichero los datos de la caja
                //Precondición: El fichero debe estar abierto
                bool leer(std::ifstream &f);

                // Muestra por pantalla todos los datos de la caja
                void escribir() const;

                // escribe en fichero los datos de la caja
                //Precondición: El fichero debe estar abierto
                bool escribir(std::ofstream &f) const;

                // Operadores
                Caja &operator=(const Caja &otra);

                bool operator==(const Caja &otra) const;
                /* Implementación del operador de igualdad. 
        bool Caja::operator==(const Caja &otra) const
        {
        return (nombre == otra.nombre &&
                peso == otra.peso &&
                precio == otra.precio &&
                aranceles == otra.aranceles);
        }
*/

                //....... COMPLETAR TODO LO NECESARIO

        private:
                std::string nombre;
                double precio;
                double peso;
                bool aranceles;
        };
}
#endif