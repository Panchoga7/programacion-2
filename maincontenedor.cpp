#include <iostream>
#include<fstream>
#include<string>
#include<array>
#include "contenedor.hpp"
#include "caja.hpp"

using namespace std;
using namespace bblProgIIB;

void pintaMenu()
{
    cout << "MENU DE OPCIONES" << endl;
    cout << "1:Leer de fichero los datos del contenedor A" << endl;
    cout << "2: Añadir una caja al final de contenedor A" << endl;
    cout << "3:añadir una caja en la posicion central del contendero A" << endl;
    cout << "4: Mostrar todos los datos del contenedor A" << endl;
    cout << "5: Sacar de A las cajas sujetas a aranceles y meterlas en B" << endl;
    cout << "6: Mostrar todos los datos del contenedor B" << endl;
    cout << "7: Mostrar el precio total del contenedor B" << endl;
    cout << "8: Escribir en fichero todos los datos del contenedor B" << endl;
    cout << "0: salir del programa" << endl;
}

int main()
{
    Contenedor cont;
    Contenedor contb;
    Caja caja, c;
    char opc;
    string fichero = "ContenedorBasico.txt";
    string fichero_a_escribir = "contenedor.txt";
    bool res;
    double sumapreciob = 0;


    do
    {

        pintaMenu();
        cin>>opc;
        cin.ignore(100,'\n');
        switch (opc)
        {
        case '1':
            cont.leerFich(fichero);
            cout<<endl;
            break;
        case '2':
            caja.leer();
            cont.insertar(cont.numeroCajas()+1, caja, res);
            cout<<endl;
            break;
        case '3':
            c.leer();
            cont.insertar(cont.numeroCajas()/2, c, res);
            cout<<endl;
            break;
        case '4':
            cont.mostrar();
            cout<<endl;
            break;
        case '5':
            for (unsigned i = 0; i < cont.numeroCajas(); ++i)
            {
                cont.consultarCaja(i, caja, res);
                if (caja.sujetoAranceles() == true)
                {
                    contb.insertar(contb.numeroCajas()+1, caja, res);
                    cont.eliminar(i, res);
                }
            }
            cout<<endl;
            break;
        case '6':
            contb.mostrar();
            cout<<endl;
            break;
        case '7':

            for (unsigned i = 0; i < contb.numeroCajas(); ++i)
            {
                contb.consultarCaja(i, caja, res);
                sumapreciob += caja.consultarPrecio();
            }
            cout << "El precio total de todas las cajas del contenedor B es: " << sumapreciob << " euros" << endl;
            cout << endl;
            break;
        case '8':
            contb.escribirFich(fichero_a_escribir);
            cout<<endl;
            break;
        }
    } while (opc != '0');

    return 0;
}
