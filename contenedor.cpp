#include <iostream>
#include "contenedor.hpp"
#include <array>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

namespace bblProgIIB
{
    // Constructor por defecto: inicializa un Contenedor vacío, sin cajas
    Contenedor::Contenedor() : identificador(), cif(), lista(), numerocajas(0)
    {
    }
    // Constructor de copia
    Contenedor::Contenedor(const Contenedor &otro_contenedor) : identificador(otro_contenedor.identificador), cif(otro_contenedor.cif), lista(otro_contenedor.lista), numerocajas(otro_contenedor.numerocajas)
    {
    }
    // Destructor del Contenedor
    Contenedor::~Contenedor()
    {
    }
    // Devuelve el número de cajas que tiene el Contenedor
    unsigned Contenedor::numeroCajas()
    {
        return numerocajas;
    }

    // Consulta el identificador del Contenedor.
    std::string Contenedor::consultarIdent() const
    {
        return identificador;
    }

    // Consulta el CIF del dueño del Contenedor.
    std::string Contenedor::consultarCIF() const
    {
        return cif;
    }

    // Modifica el identificador del Contenedor.
    void Contenedor::modificarIdent(const std::string &id)
    {
        identificador = id;
    }

    // Modifica el CIF del dueño del Contenedor.
    void Contenedor::modificarCIF(const std::string &id)
    {
        cif = id;
    }

    // Inserta una nueva caja en el Contenedor, en la posición indicada.
    // si se puede, devuelve 'true' a través de 'res'. Si no, se devuelve 'false'.
    void Contenedor::insertar(unsigned pos, const Caja &c, bool &res)
    {
        assert((pos >= 1) && (pos <= 999));
        if (numeroCajas()<=1000)
        {
            unsigned indice = pos - 1;
            //abrir hueco
            for (unsigned i = numeroCajas(); i>pos; i--)
            {
                lista[i] = lista[i-1];
            }
            lista[indice] = c;
            numerocajas++;
            res = true;
        }
        else
        {
            res = false;
        }
    }

    // Elimina una caja del Contenedor.
    // Si la posición es válida, la elimina y devuelve 'true' a través de res.
    // Si no existe, devuelve 'false'
    void Contenedor::eliminar(unsigned pos, bool &res)
    {
        assert(numeroCajas()>pos-1);
        if (numeroCajas()!=1000)
        {
            for (unsigned i = pos - 1; i < numerocajas - 1; ++i)
            {
                lista[i] = lista[i+1];
            }
            numerocajas--;
            res = true;
        }
        else
        {
            res = false;
        }
    }

    // Consulta una caja de producto.
    // Si la caja existe, la devuelve a través del segundo parámetro y
    // devuelve 'true' a través de 'res'. Si no, devuelve 'false' a través
    // de 'res'.
    void Contenedor::consultarCaja(unsigned numCaja, Caja &cont, bool &res) const
    {
        if (numCaja - 1 < numerocajas)
        {
            cont = lista[numCaja - 1];
            res = true;
        }
        else
        {
            res = false;
        }
    }

    // Lee desde fichero los datos de un contenedor y las cajas que tiene.
    void Contenedor::leerFich(const std::string &nomFich)
    {
        ifstream fichero;
        string ident, ci, lista_nombre, lista_precio, lista_peso, lista_aranceles;

        fichero.open(nomFich.c_str());

        if (!fichero.fail())
        {
            getline(fichero, ident, '\n');
            identificador = ident;
            getline(fichero, ci, '\n');
            cif = ci;

            while (!fichero.eof())
            {
                getline(fichero, lista_nombre, '\n');
                lista[numerocajas].asignarNombre(lista_nombre);
                getline(fichero, lista_precio, ' ');
                lista[numerocajas].asignarPrecio(atof(lista_precio.c_str()));
                getline(fichero, lista_peso, '\n');
                lista[numerocajas].asignarPeso(atof(lista_peso.c_str()));
                getline(fichero, lista_aranceles, '\n');
                if (lista_aranceles == "S")
                {
                    lista[numerocajas].asignarAranceles(true);
                }
                else
                {
                    lista[numerocajas].asignarAranceles(false);
                }
                numerocajas++;
            }
        }
    }

    // Escribe en fichero los datos del contenedor  y de todas las cajas que tiene

    void Contenedor::escribirFich(const std::string &nomFich)
    {
        ofstream fichero;

        fichero.open(nomFich.c_str());

        if (!fichero.fail())
        {
            fichero << consultarIdent() << endl;
            fichero << consultarCIF() << endl;
            for (unsigned i = 0; i < numerocajas; ++i)
            {
                fichero << lista[i].consultarNombre() << endl;
                fichero << lista[i].consultarPrecio() << endl;
                fichero << lista[i].consultarPeso() << endl;
                fichero << lista[i].sujetoAranceles() << endl;
            }
        }
    }

    // muestra por pantalla los datos del contenedor y de todas las cajas que contiene
    void Contenedor::mostrar() const
    {
        cout << "El identificador es: " << consultarIdent() << endl;
        cout << "El CIF del contenedor es: " << consultarCIF() << endl;
        for (unsigned i = 0; i < numerocajas; ++i)
        {
            cout << "Nombre: " << lista[i].consultarNombre() << endl;
            cout << "Precio: " << lista[i].consultarPrecio() << endl;
            cout << "Peso: " << lista[i].consultarPeso() << endl;
            if (lista[i].sujetoAranceles() == true)
            {
                cout << "Esta sujeto a Aranceles." << endl
                     << endl;
            }
            else
            {
                cout << "No esta sujeto a Aranceles." << endl
                     << endl;
            }
        }
    }

    // Operador de asignación
    Contenedor &Contenedor::operator=(const Contenedor &otroCont)
    {
        if (this != &otroCont)
        {
            identificador = otroCont.consultarIdent();
            cif = otroCont.consultarCIF();
            lista = otroCont.lista;
            numerocajas = otroCont.numerocajas;
        }
        return *this;
    }

    // Operador de igualdad
    bool Contenedor::operator==(const Contenedor &otro) const
    {
        {
            bool ok = numerocajas == otro.numerocajas;
            unsigned i = 0;
            while (ok && i < numerocajas)
            {
                ok = lista[i] == otro.lista[i];
                i++;
            }
            return ok;
        }
    }
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

}