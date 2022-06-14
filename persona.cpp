// ----------------------------------------------------------------------------
// Fichero Persona.cpp para la implementación del TAD persona para la gestión
// de los datos personales de un individuo.
// ----------------------------------------------------------------------------

#include <string>
#include <iostream>
#include "persona.hpp"

using namespace std;

namespace bblProgII
{
Persona::Persona() : nombre(), direccion(), telefono(), DNI(), letra_DNI() {}

// Constructor para inicializar la persona
Persona::Persona(const string &nombre_ini,
                 const string &direccion_ini,
                 const string &telefono_ini,
                 unsigned dni_ini,
                 char letra_dni_ini) : nombre(nombre_ini),
                                       direccion(direccion_ini),
                                       telefono(telefono_ini),
                                       DNI(dni_ini),
                                       letra_DNI(letra_dni_ini) {}

// Constructor de copia
Persona::Persona(const Persona &otra_persona) : nombre(otra_persona.nombre),
                                                direccion(otra_persona.direccion),
                                                telefono(otra_persona.telefono),
                                                DNI(otra_persona.DNI),
                                                letra_DNI(otra_persona.letra_DNI) {}

// Métodos de asignación
void Persona::asignar_nombre(const string &otro_nombre)
{
    nombre = otro_nombre;
}

void Persona::asignar_direccion(const string &otra_direccion)
{
    direccion = otra_direccion;
}

void Persona::asignar_telefono(const string &otro_telefono)
{
    telefono = otro_telefono;
}

void Persona::asignar_DNI(unsigned otro_DNI)
{
    DNI = otro_DNI;
}

void Persona::asignar_letra_DNI(char otra_letra_DNI)
{
    letra_DNI = otra_letra_DNI;
}

// Métodos de consulta

string Persona::consultar_nombre() const
{
    return nombre;
}

string Persona::consultar_direccion() const
{
    return direccion;
}

string Persona::consultar_telefono() const
{
    return telefono;
}

unsigned Persona::consultar_DNI() const
{
    return DNI;
}

char Persona::consultar_letra_DNI() const
{
    return letra_DNI;
}

// Entrada salida por pantalla

void Persona::leer_persona()
{
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Dirección: ";
    getline(cin, direccion);
    cout << "Teléfono: ";
    getline(cin, telefono);
    cout << "DNI: ";
    cin >> DNI;
    cin.ignore();
    cout << "Letra DNI: ";
    letra_DNI = cin.get();

}

void Persona::escribir_persona() const
{
    cout << "Nombre: " << nombre << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "DNI: " << DNI << "-" << letra_DNI;
}

// Operadores sobrecargados

Persona &Persona::operator=(const Persona &otra_persona)
{
    if (this != &otra_persona)
    {
        nombre = otra_persona.nombre;
        direccion = otra_persona.direccion;
        telefono = otra_persona.telefono;
        DNI = otra_persona.DNI;
        letra_DNI = otra_persona.letra_DNI;
    }

    return *this;
}

// Para los operadores booleanos empleamos el campo clave (DNI)
bool Persona::operator==(const Persona &otra_persona) const
{
    return DNI == otra_persona.DNI;
}

bool Persona::operator!=(const Persona &otra_persona) const
{
    return !((*this) == otra_persona);
}

bool Persona::operator<(const Persona &otra_persona) const
{
    return DNI < otra_persona.DNI;
}

bool Persona::operator<=(const Persona &otra_persona) const
{
    return DNI <= otra_persona.DNI;
}

bool Persona::operator>(const Persona &otra_persona) const
{
    return DNI > otra_persona.DNI;
}

bool Persona::operator>=(const Persona &otra_persona) const
{
    return DNI >= otra_persona.DNI;
}

// Operador que me devuelve el valor de la función hash, empleando el valor
// del DNI como clave
unsigned int Persona::operator%(const unsigned int NUM_PARTICIONES) const
{
    return DNI % NUM_PARTICIONES;
}
} // namespace bblProgII
