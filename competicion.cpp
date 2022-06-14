#include "competicion.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace prog2{

void Competicion::leerDatos( const std::string& nombre, bool &ok ){
	ifstream fi;
	string n;
	double t;
	unsigned ne, nEtap;
	bool ok2;

	ok = false;

	fi.open( nombre );
	if (fi.good()){
		ok = true;

		par.vaciar();
		elim.resize( 0 );

		fi >> nEtap;
		fi.ignore( 1 );

		getline( fi, n ),
		fi >> t;
		fi.ignore( 1 );
		while (!fi.eof() && ok){
			if (!par.inscrito( n )){
				par.inscribir( n, ok );
			}

			par.incluirEtapa( n, t, ok );

			getline( fi, n ),
			fi >> t;
			fi.ignore( 1 );
		}

		for( unsigned k = 0; k < par.numParticipantes(); k++ ){
			par.obtenerPos( k, n, ne, t, ok2 );
			ok = ok && ok2;
			if (ne < nEtap){
				elim.push_back( n );
			}
		}

		for( unsigned k = 0; k < elim.size(); k++ ){
			par.eliminar( elim[k], ok2 );
			ok = ok && ok2;
		}

		fi.close();
	}
}

void Competicion::listar() const{
	string nombre;
	unsigned ne;
	double tTotal;
	bool ok;

	cout << "Participantes que han completado la prueba" << endl;
	for( unsigned k = 0; k < par.numParticipantes(); k++ ){
		par.obtenerPos( k, nombre, ne, tTotal, ok );
		cout << nombre << " : " << ne << ", " << tTotal << endl;
	}

	cout << "Participantes eliminados" << endl;
	for( unsigned k = 0; k < elim.size(); k++ ){
		cout << elim[k] << endl;
	}
}


std::vector<std::string> Competicion::mejores( unsigned n ) const{
	string nombre;
	unsigned ne;
	double tTotal;
	bool ok;
	vector<string> re;

	if (n > par.numParticipantes()){
		n = par.numParticipantes();
	}

	for( unsigned k = 0; k < n; k++ ){
		par.obtenerPos( k, nombre, ne, tTotal, ok );
		re.push_back( nombre );
	}

	return re;
}


}
