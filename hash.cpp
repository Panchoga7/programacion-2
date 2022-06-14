// -----------------------------------------------------------------------------
// Fichereo hash.hpp para la definición e implementación de la plantilla de
// clase Hash para mantenimiento de tablas hash de Personas de tipo
// Persona (que tienen funciones miembro operator% para la determinación
// del índice hash).
// -----------------------------------------------------------------------------

#include <array>
#include "persona.hpp"
#include "hash.hpp"

using namespace std;

namespace bblProgII
{

    // Inicializa la tabla hash con NUM_PARTICIONES
    Hash::Hash() : lista()
    {
        for (unsigned i = 0; i < numero_particiones(); i++)
        {
            lista[i] = nullptr;
        }
    }

    // Constructor de copia
    Hash::Hash(const Hash &otraTablaHash) : lista()
    {
        for (unsigned i = 0; i < numero_particiones(); i++)
        {
            lista[i] = nullptr;
            copiar_lista(otraTablaHash.lista[i], lista[i]);
        }
    }

    // Destructor de la clase
    Hash::~Hash()
    {
        for (unsigned i = 0; i < numero_particiones(); i++)
        {
            borrar_lista(lista[i]);
        }
    }

    // Inserta un nuevo Persona en su entrada correspondiente de la tabla Hash, en orden
    // dentro de la lista correspondiente a su índice hash
    // Precondición: el Persona admite la operación operator%
    // Postcondición: si se cumple la precondición, se inserta el Persona y se devuelve
    //  exito verdadero. Si no, se devuelve exito a falso.
    void Hash::insertar_registro(const Persona &elem, bool &exito)
    {

        Ptr pos = buscar(lista[elem % numero_particiones()], elem);
        if (pos == nullptr)
        {
            insertar_ordenada(lista[elem % numero_particiones()], elem);
            exito = true;
        }
        else
        {
            exito = false;
        }
    }

    // Devuelve el Persona que se pasa como parámetro.
    // Postcondición: si el Persona no existe, esta se pone esta a falso. Si no,
    //  se devuelve el Persona (actualizado con el valor
    //  guardado en la tabla) y se pone esta a verdadero.
    Persona Hash::consultar_registro(const Persona &elem, bool &esta) const
    {
        Persona res;

        Ptr pos = buscar(lista[elem % numero_particiones()], elem);

        if (pos != nullptr)
        {
            esta = true;
            res = pos->dato;
        }
        else
        {
            esta = false;
        }

        return res;
    }

    // Indica si un Persona está o no en la tabla Hash
    bool Hash::esta(const Persona &elem) const
    {
        return (buscar(lista[elem % numero_particiones()], elem) != nullptr);
    }

    // Elimina un registro de la tabla hash
    // Postcondición: si el Persona exite, se elimina y elminado se pone a true;
    //  si no, eliminado se pone a false;
    void Hash::eliminar_registro(const Persona &elem, bool &eliminado)
    {
        eliminado = buscar(lista[elem % numero_particiones()], elem) != nullptr;

        if (eliminado)
        {
            eliminar_ordenada(lista[elem % numero_particiones()], elem);
        }
    }

    // Devuelve el número de registros de la lista
    unsigned Hash::numero_registros() const
    {
        unsigned int nR = 0;
        for (unsigned i = 0; i < numero_particiones(); i++)
        {
            nR += obtener_longitud(lista[i]);
        }

        return nR;
    }

    // Devuelve el número de particiones
    unsigned Hash::numero_particiones() const
    {
        return unsigned(lista.size());
    }

    Hash &Hash::operator=(const Hash &otra_tabla)
    {
        if (this != &otra_tabla)
        {
            for (unsigned i = 0; i < numero_particiones(); i++)
            {
                borrar_lista(lista[i]);
            }

            for (unsigned i = 0; i < numero_particiones(); i++)
            {
                copiar_lista(otra_tabla.lista[i], lista[i]);
            }
        }

        return *this;
    }


    // MÉTODOS PRIVADOS
    void Hash::copiar_lista(const Ptr original, Ptr &copia) const
    {
        Ptr ptr = original;

        copia = nullptr;

        while (ptr != nullptr)
        {
            insertar_al_final(copia, ptr->dato);
            ptr = ptr->sig;
        }
    }

    void Hash::insertar_al_final(Ptr &lista, const Persona &dato) const
    {
        Ptr ptr; // Puntero auxiliar

        if (lista == nullptr)
        {
            insertar_al_principio(lista, dato);
        }
        else
        {
            ptr = lista;
            while (ptr->sig != nullptr)
            { // Al final
                ptr = ptr->sig;
            }
            ptr->sig = new Nodo;   // 1) Nuevo nodo
            ptr->sig->dato = dato; // 2) Asignar dato
            ptr->sig->sig = nullptr;
        }
    }

    void Hash::insertar_al_principio(Ptr &lista, const Persona &dato) const
    {
        Ptr ptr;

        ptr = new Nodo;
        ptr->dato = dato;
        ptr->sig = lista;
        lista = ptr;
    }

    void Hash::insertar_ordenada(Ptr &lista, const Persona &dato) const
    {
        Ptr nuevoNodo, ptr; // dos punteros auxiliares

        if ((lista == nullptr) || (lista->dato >= dato))
        {
            insertar_al_principio(lista, dato);
        }
        else
        {
            nuevoNodo = new Nodo;
            nuevoNodo->dato = dato;
            ptr = lista;
            while ((ptr->sig != nullptr) && (dato > ptr->sig->dato))
            {
                ptr = ptr->sig;
            }
            nuevoNodo->sig = ptr->sig;
            ptr->sig = nuevoNodo;
        }
    }

    Ptr Hash::buscar(const Ptr lista, const Persona &dato) const
    {
        Ptr ptr;

        ptr = lista;
        while (ptr != nullptr && ptr->dato < dato)
        {
            ptr = ptr->sig;
        }

        if (ptr != nullptr && ptr->dato != dato)
        {
            ptr = nullptr;
        }

        return ptr;
    }

    void Hash::borrar_lista(Ptr &lista) const
    {
        while (lista != nullptr)
        {
            eliminar_primero(lista);
        }
    }

    void Hash::eliminar_primero(Ptr &lista) const
    {
        Ptr ptr;

        if (lista != nullptr)
        {
            ptr = lista;
            lista = lista->sig;
            delete ptr;
        }
    }

    void Hash::eliminar_ordenada(Ptr &lista, const Persona &dato) const
    {
        Ptr ptr, ant = nullptr; // Dos punteros auxiliares

        if (lista != nullptr)
        { // Si no, está vacía
            ptr = lista;
            while (ptr != nullptr && ptr->dato < dato)
            {
                ant = ptr;
                ptr = ptr->sig;
            }
            if (ptr != nullptr && ptr->dato == dato)
            {
                if (ant == nullptr)
                { // Primer Persona
                    lista = lista->sig;
                }
                else
                {
                    ant->sig = ptr->sig;
                }
                delete ptr;
            }
        }
    }

    unsigned Hash::obtener_longitud(const Ptr lista) const
    {
        Ptr ptr = lista;
        unsigned longitud = 0;

        while (ptr != nullptr)
        {
            ptr = ptr->sig;
            ++longitud;
        }
        return longitud;
    }

} // namespace bblProgII