#include <iostream>

#include "persona.hpp"
#include "hash.hpp"

using namespace std;

using namespace bblProgII;

int main()
{
    Hash t;

    
    bool ok;

    cout << "Número de registros de la tabla: " << t.numero_registros() << endl;

    Persona pepe("Perez Sanchez, Jose",
                 "C/ Larios, 25, 29001, Malaga",
                 "955555555",
                 55555555,
                 'A'),
        consulta_Pepe;

    t.insertar_registro(pepe, ok);
    if (ok)
    {
        cout << "Registro insertado correctamente" << endl;
        consulta_Pepe = t.consultar_registro(pepe, ok);
        if (ok)
        {
            cout << "Registro encontrado." << endl;
            consulta_Pepe.escribir_persona();
            cout << endl;
        }
    }

    cout << "Número de registros de la tabla: " << t.numero_registros() << endl;

    Persona juan("Palomo Linares, Juan",
                 "C/ Martinez, 2, 29001, Malaga",
                 "92222222",
                 22222222,
                 'W'),
        consulta_Juan;

    t.insertar_registro(juan, ok);
    if (ok)
    {
        cout << "Registro insertado correctamente" << endl;
        consulta_Juan = t.consultar_registro(juan, ok);
        if (ok)
        {
            cout << "Registro encontrado." << endl;
            consulta_Juan.escribir_persona();
            cout << endl;
        }
    }

    cout << "Número de registros de la tabla: " << t.numero_registros() << endl;

    t.eliminar_registro(pepe, ok);
    if (ok)
    {
        cout << "Pepe borrado de la tabla" << endl;
    }

    cout << "Número de registros de la tabla: " << t.numero_registros() << endl;

    return 0;
}
