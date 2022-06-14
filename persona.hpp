// ----------------------------------------------------------------------------
// Fichero persona.hpp para la definición del TAD persona para la gestión
// de los datos personales de un individuo.
// ----------------------------------------------------------------------------

#ifndef __CLASE__PERSONA__
#define __CLASE__PERSONA__

#include <string>
#include <iostream>

namespace bblProgII
{
class Persona
{
public:
    // Constructor por defecto: datos vacíos
    Persona();

    // Constructor para inicializar la persona
    Persona(const std::string &nombre_ini,
            const std::string &direccion_ini,
            const std::string &telefono_ini,
            unsigned dni_ini,
            char letra_dni_ini);

    // Constructor de copia
    Persona(const Persona &otra_persona);

    // Métodos de asignación
    void asignar_nombre(const std::string &otro_nombre);
    void asignar_direccion(const std::string &otra_direccion);
    void asignar_telefono(const std::string &otro_telefono);
    void asignar_DNI(unsigned otro_DNI);
    void asignar_letra_DNI(char otra_letra_DNI);

    // Métodos de consulta
    std::string consultar_nombre() const;
    std::string consultar_direccion() const;
    std::string consultar_telefono() const;
    unsigned consultar_DNI() const;
    char consultar_letra_DNI() const;

    // Entrada salida por pantalla
    void leer_persona();
    void escribir_persona() const;

    // Operadores sobrecargados
    // Para los operadores booleanos empleamos el campo clave (DNI)
    Persona &operator=(const Persona &otra_persona);
    bool operator==(const Persona &otra_persona) const;
    bool operator!=(const Persona &otra_persona) const;
    bool operator<(const Persona &otra_persona) const;
    bool operator<=(const Persona &otra_persona) const;
    bool operator>(const Persona &otra_persona) const;
    bool operator>=(const Persona &otra_persona) const;

    // Operador que me devuelve el valor de la función hash, empleando el valor
    // del DNI como clave
    unsigned operator%(unsigned NUM_PARTICIONES) const;

private:
    std::string nombre, direccion, telefono;
    unsigned DNI; // Campo clave
    char letra_DNI;
};
} // namespace bblProgII
#endif
