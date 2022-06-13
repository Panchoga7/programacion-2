#include <iostream>
#include <fstream>
#include "Personaje.hpp"
#include <string>
#include <array>

using namespace std;

namespace bblProgIIB
{

    Personaje::Personaje() : nombre(), raza(), caracter(), sexo(), pvida(0), pfuerza(0), pdestreza(0), pmagia(0), oro(0), bolsa(nullptr)
    {
    }
    // Constructor específico
    Personaje::Personaje(std::string nnombre, std::string nraza, std::string ncaracter, char nsexo, unsigned npvida, unsigned npfuerza, unsigned npdestreza, unsigned npmagia, double noro, Bolsa &nbolsa) : nombre(nnombre), raza(nraza), caracter(ncaracter), sexo(nsexo), pvida(npvida), pfuerza(npfuerza), pdestreza(npdestreza), pmagia(npmagia), oro(noro), bolsa(nbolsa)
    {
    }
    // Constructor de copia
    Personaje::Personaje(const Personaje &Otro_personaje) : nombre(Otro_personaje.nombre), raza(Otro_personaje.raza), caracter(Otro_personaje.caracter), sexo(Otro_personaje.sexo), pvida(Otro_personaje.pvida), pfuerza(Otro_personaje.pfuerza), pdestreza(Otro_personaje.pdestreza), pmagia(Otro_personaje.pmagia), oro(Otro_personaje.oro), bolsa(Otro_personaje.bolsa)
    {
    }
    // Destructor
    Personaje::~Personaje()
    {
        borrar_bolsa(bolsa);
    }

    // Establece el nombre del personaje.
    void Personaje::asignarNombre(const std::string nomb)
    {
        nombre = nomb;
    }

    // Establece la raza del personaje.
    void Personaje::asignarRaza(const std::string raz)
    {
        raza = raz;
    }

    // Establece el carácter del personaje.
    void Personaje::asignarCaracter(const std::string caract)
    {
        caracter = caract;
    }

    // Establece el sexo del personaje.
    void Personaje::asignarSexo(const char sex)
    {
        sexo = sex;
    }

    // Establece los puntos de vida del personaje
    void Personaje::asignarPvida(const unsigned pv)
    {
        pvida = pv;
    }

    // Establece los puntos de fuerza del personaje
    void Personaje::asignarPfuerza(const unsigned pf)
    {
        pfuerza = pf;
    }

    // Establece los puntos de destreza del personaje
    void Personaje::asignarPdestreza(const unsigned pd)
    {
        pdestreza = pd;
    }

    // Establece los puntos de magia del personaje
    void Personaje::asignarPmagia(const unsigned pm)
    {
        pmagia = pm;
    }

    // Establece las monedas de oro que tiene el personaje
    void Personaje::asignarOro(const double mor)
    {
        oro = mor;
    }

    // Establece los objetos que posee el personaje
    void Personaje::asignarBolsa(const Bolsa &bols)
    {
        bolsa = bols;
    }

    // Muestra el nombre del personaje.
    std::string Personaje::mostrarNombre() const
    {
        return nombre;
    }

    // Muestra la raza del personaje.
    std::string Personaje::mostrarRaza() const
    {
        return raza;
    }

    // Muestra el caracter del personaje.
    std::string Personaje::mostrarCaracter() const
    {
        return caracter;
    }

    // Muestra el sexo del personaje.
    char Personaje::mostrarSexo() const
    {
        return sexo;
    }

    // Muestra los puntos de vida del personaje
    unsigned Personaje::mostrarPvida() const
    {
        return pvida;
    }

    // Muestra los puntos de fuerza del personaje
    unsigned Personaje::mostrarPfuerza() const
    {
        return pfuerza;
    }

    // Muestra los puntos de destreza del personaje
    unsigned Personaje::mostrarPdestreza() const
    {
        return pdestreza;
    }

    // Muestra los puntos de magia del personaje
    unsigned Personaje::mostrarPmagia() const
    {
        return pmagia;
    }

    // Muestra las monedas de oro que tiene el personaje
    double Personaje::mostrarOro() const
    {
        return oro;
    }

    // Muestra los objetos que posee el personaje
    void Personaje::mostrarBolsa() const
    {
        Bolsa ptr = bolsa;
        while (ptr != nullptr)
        {
            cout << "Nombre: " << ptr->nombre << endl;
            cout << "Cantidad: " << ptr->cantidad << endl;
            cout << "Tipo: " << ptr->tipo << endl;
            cout << "Valor: " << ptr->valor << endl;
            cout << "\n";

            ptr = ptr->sig;
        }
    }

    // Crea la bolsa del personaje;
    void Personaje::crearBolsa()
    {
        bolsa = nullptr; // he creado una lista enlazada vacia
    }

    // Número de elementos de la bolsa
    unsigned Personaje::numobjBolsa()
    {
        unsigned cont = 0;
        Bolsa aux = bolsa;

        while (aux != nullptr)
        {
            cont++;
            aux = aux->sig;
        }
        return cont;
    }

    // Copia la bolsa del personaje y la devuelve en bolsac, dejando vacia la bolsa del personaje
    void Personaje::entregarBolsa(Bolsa &bolsac)
    {
        copiar_bolsa(bolsac, bolsa);
        borrar_bolsa(bolsa);
    }

    // Inserta un objeto en la bolsa, si existe, actualiza el objeto existente, número y valor
    void Personaje::insertar_objeto(Objeto &objeto)
    { // tengo que meter el metodo privado de busca()
        // al meter el metodo buscar() me dira la posicion, si es que hay. Si la encuentra pues
        // llamo modificar:objeto y si no lo encuentra llama a insertar:ordenado

        Bolsa pos;
        Bolsa ant;
        buscar_objeto(objeto.nombre, pos, ant);

        double valun = 0; // Valor unitario del objeto si existe en la bolsa

        if ((pos != nullptr) && (objeto.nombre == pos->nombre))
        {
            valun = objeto.valor / objeto.cantidad;

            pos->cantidad++;
            pos->valor = valun * pos->cantidad;
        }
        else
        {

            insertar_ordenado(objeto);
        }
    }
    // Modifica un objeto de la bolsa
    void Personaje::modifica_objeto(Objeto &objeto)
    {

        bolsa->cantidad = objeto.cantidad;
        bolsa->tipo = objeto.tipo;
        bolsa->valor = objeto.valor;
        bolsa->sig = objeto.sig;
    }
    // Elimina un objeto de la bolsa
    void Personaje::eliminar_objeto(Objeto &objeto)
    {
        Bolsa pos;
        Bolsa ant;
        buscar_objeto(objeto.nombre, pos, ant);

        int valor = 0; // va a ser el valor unitario del objeto

        if (pos != nullptr /*&& pos->nombre == objeto.nombre*/)
        {
            valor = objeto.valor / objeto.cantidad;
            pos->cantidad--;
            pos->valor = valor * pos->cantidad;

            if (pos->cantidad == 0)
            {
                eliminar_objeto(objeto);
            }
        }
        else
        {
            eliminar_objeto(objeto);
        }
        cout << "Objeto " << objeto.nombre << " ha sido eliminado" << endl;
    }

    // Operadores
    Personaje &Personaje::operator=(const Personaje &otro)
    {

        if (this != &otro)
        {
            this->nombre = otro.nombre;
            this->oro = otro.oro;
            this->pdestreza = otro.pdestreza;
            this->pfuerza = otro.pfuerza;
            this->pmagia = otro.pmagia;
            this->pvida = otro.pvida;
            this->raza = otro.raza;
            this->sexo = otro.sexo;
            this->bolsa = otro.bolsa;
        }
        return *this;
    }
    bool Personaje::operator==(const Personaje &otro) const
    {
        return (nombre == otro.nombre &&
                raza == otro.raza &&
                caracter == otro.caracter &&
                sexo == otro.sexo &&
                bolsa == otro.bolsa);
    }

    // METODOS PRIVADOS

    void Personaje::buscar_objeto(const std::string nombre, Bolsa &pos, Bolsa &ant) const
    {                  // No serviria para listas ordenadas
        ant = nullptr; // tengo desde un principio valor 0
        pos = bolsa;   // empieze desde la primera parte

        while (pos != nullptr && pos->nombre < nombre)
        {
            ant = pos;
            pos = pos->sig;
        }
    }

    void Personaje::insertar_ordenado(Objeto &objeto)
    {
        Bolsa pos = bolsa;
        Bolsa ant;

        buscar_objeto(objeto.nombre, pos, ant);

        Bolsa nuevo = new Objeto;
        nuevo->nombre = objeto.nombre;
        nuevo->cantidad = objeto.cantidad;
        nuevo->valor = objeto.valor;
        nuevo->tipo = objeto.tipo;

        nuevo->sig = pos;

        if (ant == nullptr)
        {
            bolsa = nuevo;
        }
        else
        {
            ant->sig = nuevo;
        }
    }

    void Personaje::eliminar_ordenado(const std::string &objeto)
    {
        Bolsa aux = bolsa;
        Bolsa ant = nullptr;

        buscar_objeto(objeto, aux, ant);

        if (ant == nullptr)
        {
            bolsa = bolsa->sig;
            delete aux;
        }
        else
        {
            ant->sig = aux->sig;
            delete aux;
        }
    }

    void Personaje::copiar_bolsa(Bolsa &destino, Bolsa origen) const
    {
        destino = NULL;
        Bolsa aux_origen = origen, aux_destino;

        while (aux_origen != NULL)
        {
            if (destino == NULL)
            {
                destino = aux_destino = new Objeto;
            }
            else
            {
                aux_destino->sig = new Objeto;
                aux_destino = aux_destino->sig;
            }

            aux_destino->nombre = aux_origen->nombre;
            aux_destino->cantidad = aux_origen->cantidad;
            aux_destino->tipo = aux_origen->tipo;
            aux_destino->valor = aux_origen->valor;
            aux_origen = aux_origen->sig; // Lo preparo para copiar otro nodo
        }
    }

    // verme esta funcion otra vez a ver si me borra
    void Personaje::borrar_bolsa(Bolsa &bolsap)
    {
        while (bolsap != nullptr)
        {
            Bolsa aux = bolsa;
            aux = aux->sig;
            delete aux;
        }
    }

}