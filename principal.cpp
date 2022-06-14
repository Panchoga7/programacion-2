#include <iostream>
#include <string>
#include "participantes.h"
#include "competicion.h"
#include <vector>

using namespace std;
using namespace prog2;

int main(){
	Participantes p1;
	bool ok;
	string nombre;
	unsigned ne;
	double t;

	p1.inscribir( "Pedro", ok );
	if (ok){
		cout << "Pedro inscrito" << endl;
	}else{
		cout << "Fallo al incribir a Pedro" << endl;
	}

	cout << endl;

	p1.inscribir( "Juan", ok );
	if (ok){
		cout << "Juan inscrito" << endl;
	}else{
		cout << "Fallo al incribir a Juan" << endl;
	}

	cout << endl;

	p1.inscribir( "Pedro", ok );
	if (ok){
		cout << "Pedro inscrito" << endl;
	}else{
		cout << "Fallo al incribir a Pedro" << endl;
	}
	
	cout << endl;

	cout << "Número participantes: " << p1.numParticipantes() << endl;

	cout << endl;

	if (p1.inscrito( "Pedro" )){
		cout << "Pedro esta inscrito" << endl;
	}else{
		cout << "Pedro no esta inscrito" << endl;
	}

	cout << endl;

	if (p1.inscrito( "Juan" )){
		cout << "Juan esta inscrito" << endl;
	}else{
		cout << "Juan no esta inscrito" << endl;
	}

	cout << endl;

	p1.incluirEtapa( "Pedro", 10, ok );
	if (ok){
		cout << "Añadida etapa a Pedro" << endl;
	}else{
		cout << "Fallo al añadir etapa a Pedro" << endl;
	}

	cout << endl;

	p1.incluirEtapa( "Otro", 15, ok );
	if (ok){
		cout << "Añadida etapa a Otro" << endl;
	}else{
		cout << "Fallo al añadir etapa a Otro" << endl;
	}

	cout << endl;

	p1.incluirEtapa( "Juan", 20, ok );
	if (ok){
		cout << "Añadida etapa a Juan" << endl;
	}else{
		cout << "Fallo al añadir etapa a Juan" << endl;
	}
	
	cout << endl;

	p1.incluirEtapa( "Pedro", 25, ok );
	if (ok){
		cout << "Añadida etapa a Pedro" << endl;
	}else{
		cout << "Fallo al añadir etapa a Pedro" << endl;
	}

	cout << endl;

	p1.obtenerPar( "Pedro", ne, t, ok );
	if (ok){
		cout << "Datos Pedro: " << ne << ", " << t << endl;
	}else{
		cout << "No hay datos de Pedro";
	}

	cout << endl;

	for( unsigned k = 0; k < p1.numParticipantes(); k++ ){
		p1.obtenerPos( k, nombre, ne, t, ok );
		if (ok){
			cout << nombre << " : " << ne << ", " << t << endl;
		}else{
			cout << "Fallo al obtener posición " << k << endl;
		}
	}

	Participantes p2( p1 );

	cout << endl;

	cout << "Listado de la copia" << endl;
	for( unsigned k = 0; k < p2.numParticipantes(); k++ ){
		p2.obtenerPos( k, nombre, ne, t, ok );
		if (ok){
			cout << nombre << " : " << ne << ", " << t << endl;
		}else{
			cout << "Fallo al obtener posición " << k << endl;
		}
	}

	cout << endl;

	p2.vaciar();
	cout << "Número participantes " << p2.numParticipantes() << endl;

	cout << endl;

	p1.eliminar( "Otro", ok );
	if (ok){
		cout << "Otro eliminado correctamente" << endl;
	}else{
		cout << "Fallo al eliminar a otro" << endl;	
	}

	cout << endl;

	p1.eliminar( "Pedro", ok );
	if (ok){
		cout << "Pedro eliminado correctamente" << endl;
	}else{
		cout << "Fallo al eliminar a Pedro" << endl;	
	}

	cout << endl;

	for( unsigned k = 0; k < p1.numParticipantes(); k++ ){
		p1.obtenerPos( k, nombre, ne, t, ok );
		if (ok){
			cout << nombre << " : " << ne << ", " << t << endl;
		}else{
			cout << "Fallo al obtener posición " << k << endl;
		}
	}

	Competicion co;

	cout << endl;

	co.leerDatos( "test.txt", ok );
	if (ok){
		cout << "Datos leídos correctamente" << endl;
	}else{
		cout << "Fallo al leer datos" << endl;
	}

	cout << endl;

	co.listar();

	cout << endl;

	vector<string> mejor;

	cout << "Mejores" << endl;
	mejor = co.mejores( 5 );
	for( unsigned k = 0; k < mejor.size(); k++ ){
		cout << mejor[k] << endl;
	}

	return 0;
}

