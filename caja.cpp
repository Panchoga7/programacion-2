#include <iostream>
#include "caja.hpp"
#include <array>
#include <fstream>
#include <string>

using namespace std;

namespace bblProgIIB
{

    // Constructor por defecto: nombre vacío, precio y peso a cero y aranceles falso.
    Caja::Caja() : nombre(), precio(0.0), peso(0.0), aranceles(false)
    {
    }

    // Constructor de copia
    Caja::Caja(const Caja &otra_caja) : nombre(otra_caja.nombre), precio(otra_caja.precio), peso(otra_caja.peso), aranceles(otra_caja.aranceles)
    {
    }
    // Constructor extendido
    Caja::Caja(const std::string &nom, double euros, double kilos, bool aran) : nombre(nom), precio(euros), peso(kilos), aranceles(aran)
    {
    }
    // Destructor
    Caja::~Caja()
    {
    }

    // Devuelve el nombre del producto
    std::string Caja::consultarNombre() const
    {
        return nombre;
    }

    // Devuelve el precio del producto
    double Caja::consultarPrecio() const
    {
        return precio;
    }

    // Devuelve el peso del producto
    double Caja::consultarPeso() const
    {
        return peso;
    }

    // Devuelve si el producto está sujeto a aranceles o no
    bool Caja::sujetoAranceles() const
    {
        return aranceles;
    }

    // Modifica el nombre del producto
    void Caja::asignarNombre(const std::string &n)
    {
        nombre = n;
    }

    // Modifica el peso del producto
    void Caja::asignarPeso(double kilos)
    {
        peso = kilos;
    }

    // Modifica el precio del producto
    void Caja::asignarPrecio(double euros)
    {
        precio = euros;
    }

    // Modifica si está sujeto a aranceles o no
    void Caja::asignarAranceles(bool aran)
    {
        aranceles = aran;
    }

    // Lee de teclado todos los datos de la caja
    void Caja::leer()
    {
        char a;
        Caja c;

        cout << "Introduzca el nombre: ";
        cin >> nombre;
        c.asignarNombre(nombre);
        cout << "Introduzca el precio: ";
        cin >> precio;
        c.asignarPrecio(precio);
        cout << "Introduzca el peso: ";
        cin >> peso;
        c.asignarPeso(peso);
        cout << "Tiene aranceles (S/N): ";
        cin >> a;
        if (a == 'S')
        {
            aranceles = true;
        }
        else
        {
            aranceles = false;
        }
        c.asignarAranceles(aranceles);
    }

    // Lee de fichero los datos de la caja
    //Precondición: El fichero debe estar abierto
    bool Caja::leer(std::ifstream &f)
    {
        bool correcto=false;
        string n, pe, pr, a;

        if (!f.fail())
        {

            while (!f.eof())
            {
                getline(f, n, '\n');
                nombre = n;
                getline(f, pr, ' ');
                peso = atof(pr.c_str());
                getline(f, pe, ' ');
                precio = atof(pe.c_str());
                getline(f, a, ' ');
                if (a == "S")
                {
                    aranceles = true;
                }
                else
                {
                    aranceles = false;
                }
                correcto=true;
            }
        }
        return correcto;
    }

    // Muestra por pantalla todos los datos de la caja
    void Caja::escribir() const
    {
        cout << "El nombre es: " << consultarNombre() << endl;
        cout << "El precio es: " << consultarPrecio() << endl;
        cout << "El peso es: " << consultarPeso() << endl;
        if (aranceles == true)
        {
            cout << "Tiene aranceles." << endl;
        }
        else
        {
            cout << "No tiene aranceles." << endl;
        }
    }

    // escribe en fichero los datos de la caja
    //Precondición: El fichero debe estar abierto
    bool Caja::escribir(std::ofstream &f) const
    {
        bool correcto=false;
        if (!f.fail())
        { //si no da fallo devuelve OK

            while(!f.eof())
            {
                f << consultarNombre() << endl;
                f << consultarPrecio() << endl;
                f << consultarPeso() << endl;
                f << sujetoAranceles() << endl;
            }
            correcto = true;
        }
        return correcto;
    }

    // Operadores
    Caja &Caja::operator=(const Caja &otra)
    {
        if(this != &otra){
            nombre = otra.consultarNombre();
            precio = otra.consultarPrecio();
            peso = otra.consultarPeso();
            aranceles = otra.sujetoAranceles();
        }
        
        return *this;
    }

    
    bool Caja::operator==(const Caja &otra) const
        {
        return (nombre == otra.nombre &&
                peso == otra.peso &&
                precio == otra.precio &&
                aranceles == otra.aranceles);
        }
}