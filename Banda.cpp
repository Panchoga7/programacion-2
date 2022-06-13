#include <iostream>
#include <fstream>
#include "Banda.hpp"
#include "Personaje.hpp"
#include <string>
#include <array>
#include <cstdlib>

using namespace std;

namespace bblProgIIB
{
    Banda::Banda()
    {
        banda = nullptr;
    }
    // Constructor por defecto
    Banda::Banda(const Banda &Otra_banda)
    {
        copiar_lista(banda, Otra_banda.banda);
    }

    // Constructor de copia
    Banda::~Banda()
    {
        borrar_lista(banda);
    }
    // Destructor

    void Banda::crear_Banda()
    {
        banda = nullptr;
    }
    // Crea la banda de personajes vacia;
    // -------------------------------------
    void Banda::insertar_personaje(const Personaje &personaje)
    {
        insertar_ordenado(personaje);
    }
    // Inserta un personaje en la banda en la posición correcta.
    void Banda::eliminar_personaje(const std::string &nombre)
    {
        Lista pos = banda;
        Lista ant = nullptr;
        buscar_personaje(nombre, pos, ant);

        if (pos != nullptr && pos->personaje.mostrarNombre() == nombre)
        {
            eliminar_ordenado(nombre);
        }
        cout << "Objeto " << nombre << " ha sido eliminado" << endl;
    }
    // Elimina un personaje de la banda
    // -------------------------------------
    void Banda::consultar_personaje(const std::string &nombre, Personaje &personaje, bool &esta) const
    {
        
        esta = false;

        Lista pos = banda;
        Lista ant = nullptr;

        buscar_personaje(nombre, pos, ant);

        if (pos == nullptr)
        {

            cout << "El personaje " << nombre << "no existe" << endl;
        }
        else
        {
            
            
            if (pos->personaje.mostrarNombre()== nombre)
            {
                esta = true;
                cout << "El personaje " << nombre << "existe" << endl;
                personaje.mostrarNombre();
                personaje.mostrarRaza();
                personaje.mostrarCaracter();
                personaje.mostrarSexo();
                personaje.mostrarPvida();
                personaje.mostrarPfuerza();
                personaje.mostrarPdestreza();
                personaje.mostrarPmagia();
                personaje.mostrarOro();

                cout << "        Personaje Consultado" << endl;
            }
        }
    }
    // Consulta si un personaje está en la banda, por el nombre del mismo, si está se
    // devuelve el personaje en personaje y esta se pone a true, si no está, esta se
    // pone a false y no se devuelve nada.
    // -------------------------------------
    unsigned Banda::integrantes_Banda() const
    {
        unsigned integrantes = 0;
        Lista puntero = banda;

        while (puntero != nullptr)
        {
            integrantes++;
            puntero = puntero->sig;
        }

        return integrantes;
    }
    // Muestra el número total de integrantes de la banda
    // -------------------------------------
    void Banda::mostrar_Banda() const
    {
        Lista puntero;
        puntero = banda;

        while (puntero != nullptr)
        {
            cout << "Nombre: " << puntero->personaje.mostrarNombre() << endl;
            cout << "Raza: " << puntero->personaje.mostrarRaza() << endl;
            cout << "Caracter: " << puntero->personaje.mostrarCaracter() << endl;
            cout << "Sexo: " << puntero->personaje.mostrarSexo() << endl;
            cout << "Vida: " << puntero->personaje.mostrarPvida() << endl;
            cout << "Fuerza: " << puntero->personaje.mostrarPfuerza() << endl;
            cout << "Destreza: " << puntero->personaje.mostrarPdestreza() << endl;
            cout << "magia: " << puntero->personaje.mostrarPmagia() << endl;
            cout << "oro: " << puntero->personaje.mostrarOro() << endl;
            cout << "oro: " << puntero->personaje.mostrarOro() << endl;

            cout<<"Numero de objetos que hay en la bolsa: "<<puntero->personaje.numobjBolsa();

            puntero->personaje.mostrarBolsa();

            puntero = puntero->sig;
        }
    }
    // Muestra por pantalla todos los miembros de la banda y sus atributos, incluida la bolsa
    // -------------------------------------
    void Banda::leer_de_fichero(const std::string &nom_fic, bool &leido)
    {
        ifstream f;
        string nombre;
        Personaje personaj;
        Objeto o;
        char sexo;
        double oro,valor;
        unsigned p, i, cantidad,nobjetos;
        
        f.open(nom_fic.c_str());
        if (!f.fail())
        {
            leido = true;
            cout<<"borro la lista";
            borrar_lista(banda);

            while (!f.eof())
            {
                getline(f, nombre, '\n');
                personaj.asignarNombre(nombre);

                getline(f, nombre, '\n');
                personaj.asignarRaza(nombre);

                getline(f, nombre, '\n');
                personaj.asignarCaracter(nombre);

                f >> sexo;
                
                personaj.asignarSexo(sexo);

                f >> p;
                
                personaj.asignarPvida(p);

                f >> p;
                
                personaj.asignarPfuerza(p);

                f >> p;
                
                personaj.asignarPdestreza(p);

                f >> p;
                
                personaj.asignarPmagia(p);

                f >> oro;
                
                personaj.asignarOro(oro);

                f >> nobjetos;
                f.ignore(100,'\n');

                personaj.crearBolsa();
                i = 0;
                //miro la nobjetos y los leo dichas veces
                while (nobjetos > i)
                {

                    getline(f, nombre, '\n');

                    o.nombre = nombre;
                    getline(f, nombre, '\n');
                    o.tipo = nombre;

                    f >> valor;
                    f.ignore(1);
                    o.valor = valor;
                    

                    f >> cantidad;
                    f.ignore(1);
                    o.cantidad = cantidad;
                    

                    personaj.insertar_objeto(o);
                    i++;
                }
                insertar_personaje(personaj);
            }
        }
        
        f.close();
    }
    // Inicializa la banda de personajes a partir de los datos leídos desde fichero.
    // Los personajes se insertan en orden alfabético por nombre de personaje, es decir, a partir de llamadas
    // al método insertar(...) de la propia clase. La banda actual debe
    // eliminarse antes de la lectura (es decir, debe borrarse completamente toda la lista
    // enlazada). El método recibe el nombre de fichero. Si el fichero puede abrirse
    // correctamente, leido se pone a true y se leen los datos desde fichero. Si no,
    // leido se pone a false y la banda quedará vacía.
    // El formato de fichero coincide con el de salida por pantalla (véase más arriba).
    // -------------------------------------
    void Banda::escribir_a_fichero(const std::string &nom_fic, bool &escrito) const
    {
        escrito = false;
        ofstream fichero;

        Lista ptr = banda;

        Bolsa bolsa;

        string escribir;

        fichero.open(nom_fic.c_str());

        if (!fichero.fail())
        {

            escrito = true;
            while ((ptr != nullptr))
            {
                fichero << ptr->personaje.mostrarNombre() << std::endl;
                fichero << ptr->personaje.mostrarRaza() << std::endl;
                fichero << ptr->personaje.mostrarCaracter() << std::endl;
                fichero << ptr->personaje.mostrarSexo() << std::endl;
                fichero << ptr->personaje.mostrarPvida() << std::endl;
                fichero << ptr->personaje.mostrarPfuerza() << std::endl;
                fichero << ptr->personaje.mostrarPdestreza() << std::endl;
                fichero << ptr->personaje.mostrarPmagia() << std::endl;
                fichero << ptr->personaje.mostrarOro() << std::endl;

                ptr->personaje.entregarBolsa(bolsa);
                while ((ptr != nullptr))
                {
                    fichero << bolsa->nombre << std::endl;
                    fichero << bolsa->tipo << std::endl;
                    fichero << bolsa->valor << std::endl;
                    fichero << bolsa->cantidad << std::endl;

                    bolsa = bolsa->sig;
                }

                ptr = ptr->sig;
            }
            cout << "Fichero escrito" << endl;
            fichero.close();
        }
    }
    // Escribe en fichero la banda de personajes actual. El método recibe el identificador de fichero.
    // Si el fichero puede abrirse correctamente, escrito se pone a true y se escriben los datos a
    // fichero. Si no, escrito se pone a false. El formato de fichero coincide con el de salida
    // por pantalla (véase más arriba).

    // Operadores
    Banda &Banda::operator=(const Banda &otra)
    {
        if (this != &otra)
        {
            Lista ptr = otra.banda;
            Lista ptr2;

            while (banda != nullptr)
            {
                ptr2 = banda;
                banda = banda->sig;
                delete ptr2;
            }

            while (ptr != nullptr)
            {
                if (banda == nullptr)
                {
                    banda = new Miembro;
                    ptr2 = banda;
                }
                else
                {
                    ptr2->sig = new Miembro;
                    ptr2 = ptr2->sig;
                }

                ptr2->sig = nullptr;
                ptr2->personaje = ptr->personaje;

                ptr = ptr->sig;
            }
        }
        return *this;
    }

    bool Banda::operator==(const Banda &otra) const
    {

        bool operador = true;

        Lista ptr = banda;
        Lista ptr2 = otra.banda;

        while (operador && ptr != nullptr && ptr2 != nullptr)
        {
            operador = ptr->personaje == ptr2->personaje;
            ptr = ptr->sig;
            ptr2 = ptr2->sig;
        }

        return (operador && ptr != nullptr && ptr2 != nullptr);
    }

    // Métodos privados

    void Banda::buscar_personaje(const std::string &nombre, Lista &pos, Lista &ant) const
    {
        pos = banda;
        ant = nullptr;

        while (pos != nullptr && pos->personaje.mostrarNombre() == nombre)
        {
            ant = pos;
            pos = pos->sig;
        }
    }
    // Busca un personaje en la banda.
    // ---------------------------------------------------------------------------
    void Banda::insertar_ordenado(const Personaje &personaje)
    {
        Lista ptr;

        ptr = new Miembro;

        ptr->personaje = personaje;

        Lista pos = banda;
        Lista ant = nullptr;

        buscar_personaje(personaje.mostrarNombre(), pos, ant);
        ptr->sig = pos;

        if (ant == nullptr)
        {
            banda = ptr;
        }
        else
        {
            ant->sig = ptr;
        }
    }
    // Inserta en la banda el personaje que se pasa como parámetro.
    // La lista debe quedar ordenada en orden creciente de nombres.
    // ---------------------------------------------------------------------------
    void Banda::eliminar_ordenado(const std::string &nombre)
    {
        Lista pos = banda;
        Lista ant = nullptr;

        buscar_personaje(nombre, pos, ant);

        if (pos != nullptr && pos->personaje.mostrarNombre() == nombre)
        {
            if (ant == nullptr)
            {
                banda = banda->sig;
                delete pos;
            }
            else
            {
                ant->sig = pos->sig;
                delete pos;
            }
        }
    }
    // Elimina de la lista el personaje cuyo nombre se pasa como parámetro.
    // ---------------------------------------------------------------------------
    void Banda::copiar_lista(Lista &destino, Lista origen) const
    {
        Lista copia;
        Lista puntero = origen;

        while (puntero != nullptr)
        {
            if (destino == nullptr)
            {
                destino = new Miembro;
                copia = destino;
            }
            else
            {
                copia->sig = new Miembro;
                copia = copia->sig;
            }

            copia->personaje = puntero->personaje; // copiamos los datos de un sitio a otro
            copia->sig = nullptr;
            puntero = puntero->sig;
        }
    }
    // Hace una copia de la lista que cuelga del puntero origen en el puntero destino.
    // ---------------------------------------------------------------------------
    void Banda::borrar_lista(Lista &lista) const
    {
        Lista puntero; // apunto sobre la lista

        while (lista != nullptr)
        {
            puntero = lista;
            lista = lista->sig;
            delete puntero;
        }
    }
    // Elimina todos los nodos de la lista que se pasa como parámetro, poniendo
    // lista finalmente a NULL (o nullptr).

}
