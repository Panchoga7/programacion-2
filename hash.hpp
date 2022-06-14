// -----------------------------------------------------------------------------
// Fichereo hash.hpp para la definición e implementación de la plantilla de
// clase Hash para mantenimiento de tablas hash de elementos de tipo
// Elemento (que tienen funciones miembro operator% para la determinación
// del índice hash).
// -----------------------------------------------------------------------------

#ifndef __CLASE__HASH__
#define __CLASE__HASH__
#include <array>
#include "persona.hpp"

namespace bblProgII
{
    struct Nodo
    {
        Persona dato;
        Nodo *sig;
    };

    typedef Nodo *Ptr;    
class Hash
{
public:
    // Inicializa la tabla hash con NUM_PARTICIONES
    Hash();

    // Constructor de copia
    Hash(const Hash &otraTablaHash);

    // Destructor de la clase
    ~Hash();
  

    // Inserta un nuevo elemento en su entrada correspondiente de la tabla Hash, en orden
    // dentro de la lista correspondiente a su índice hash
    // Precondición: el elemento admite la operación operator%
    // Postcondición: si se cumple la precondición, se inserta el elemento y se devuelve
    //  exito verdadero. Si no, se devuelve exito a falso.
    void insertar_registro(const Persona &elem, bool &exito);


    // Devuelve el elemento que se pasa como parámetro.
    // Postcondición: si el elemento no existe, esta se pone esta a falso. Si no,
    //  se devuelve el elemento (actualizado con el valor
    //  guardado en la tabla) y se pone esta a verdadero.
    Persona consultar_registro(const Persona &elem, bool &esta) const;


    // Indica si un elemento está o no en la tabla Hash
    bool esta(const Persona &elem) const;

    // Elimina un registro de la tabla hash
    // Postcondición: si el Persona exite, se elimina y elminado se pone a true;
    //  si no, eliminado se pone a false;
    void eliminar_registro(const Persona &elem, bool &eliminado);

    // Devuelve el número de registros de la lista
    unsigned numero_registros() const;

    // Devuelve el número de particiones
    unsigned numero_particiones() const;

    Hash &operator=(const Hash &otra_tabla);
 
private:
    static const unsigned MAX_PARTICIONES = 10;
    
    std::array<Ptr,MAX_PARTICIONES> lista;

    // MÉTODOS PRIVADOS
    void copiar_lista(const Ptr original, Ptr &copia) const;


    void insertar_al_final(Ptr &lista, const Persona &dato) const;


    void insertar_al_principio(Ptr &lista, const Persona &dato) const;


    void insertar_ordenada(Ptr &lista, const Persona &dato) const;


    Ptr buscar(const Ptr lista, const Persona &dato) const;


    void borrar_lista(Ptr &lista) const;


    void eliminar_primero(Ptr &lista) const;


    void eliminar_ordenada(Ptr &lista, const Persona &dato) const;


    unsigned obtener_longitud(const Ptr lista) const;

}; // De la clase Hash
} // namespace bblProgII
#endif
