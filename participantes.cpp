#include "participantes.h"

using namespace std;

namespace prog2{

Participantes::Participantes(){
	lista = NULL;
}

Participantes::~Participantes(){
	vaciar();
}


Participantes::Participantes( const Participantes& p ){
	TLista rec, nue, ult;

	lista = NULL;
	ult = NULL;
	rec = p.lista;
	while (rec != NULL){
		// Duplicar un nodo
		nue = new TNodo;
		nue->nombre = rec->nombre;
		nue->nEtapas = rec->nEtapas;
		nue->tiempo = rec->tiempo;
		nue->sig = NULL;

		if (lista == NULL){
			lista = nue;
			ult = nue;
		}else{
			ult->sig = nue;
			ult = nue;
		}

		rec = rec->sig;
	}
}


unsigned Participantes::numParticipantes() const{
	TLista tmp;
	unsigned cont = 0;

	tmp = lista;
	while (tmp != NULL){
		tmp = tmp->sig;
		cont ++;
	}
	
	return cont;
}


void Participantes::inscribir( const std::string& par, bool &ok ){
	TLista tmp;

	if (inscrito( par )){
		ok = false;
	}else{
		ok = true;
		tmp = new TNodo;
		tmp->nombre = par;
		tmp->nEtapas = 0;
		tmp->tiempo = 0;
		tmp->sig = lista;
		lista = tmp;		
	}
}


bool Participantes::inscrito( const std::string& par ) const{
	TLista tmp;

	tmp = lista;
	while ((tmp != NULL) && (tmp->nombre != par)){
		tmp = tmp->sig;
	}

	return tmp != NULL;
}


void Participantes::incluirEtapa( const std::string& par, double t, bool &ok ){
	TLista tmp, ant, nue;
	double tTotal, nEtapas;

	ant = NULL;
	tmp = lista;
	while ((tmp != NULL) && (tmp->nombre != par)){
		ant = tmp;
		tmp = tmp->sig;
	}

	if (tmp == NULL){
		ok = false;
	}else{
		ok = true;

		nEtapas = tmp->nEtapas + 1;
		tTotal = tmp->tiempo + t;

		// Elimina nodo
		if (ant == NULL){
			lista = lista->sig;
		}else{
			ant->sig = tmp->sig;
		}
		delete tmp;

		// Inserta ordenado
		ant = NULL;
		tmp = lista;
		while ((tmp != NULL) && (tmp->tiempo < tTotal)){
			ant = tmp;
			tmp = tmp->sig;
		}

		nue = new TNodo;
		nue->nombre = par;
		nue->nEtapas = nEtapas;
		nue->tiempo = tTotal;
		if (ant == NULL){
			nue->sig = lista;
			lista = nue;
		}else{
			nue->sig = tmp;
			ant->sig = nue;
		}
	}
}


void Participantes::obtenerPar( const std::string& par, unsigned &ne, double &t, bool &ok ) const{
	TLista tmp;

	tmp = lista;
	while ((tmp != NULL) && (tmp->nombre != par)){
		tmp = tmp->sig;
	}

	if (tmp == NULL){
		ok = false;
	}else{
		ok = true;
		ne = tmp->nEtapas;
		t = tmp->tiempo;
	}
}


void Participantes::obtenerPos( unsigned pos, std::string &par, unsigned &ne, double &t, bool &ok ) const{
	TLista rec;
	unsigned k = 0;

	rec = lista;
	while ((rec != NULL) && (k < pos)){
		rec = rec->sig;
		k++;
	}

	if (rec == NULL){
		ok = false;
	}else{
		ok = true;
		par = rec->nombre;
		ne = rec->nEtapas;
		t = rec->tiempo;
	}
}


void Participantes::eliminar( const std::string& par, bool& ok ){
	TLista tmp, ant;
	
	ant = NULL;
	tmp = lista;
	while ((tmp != NULL) && (tmp->nombre != par)){
		ant = tmp;
		tmp = tmp->sig;
	}

	if (tmp == NULL){
		ok = false;
	}else{
		ok = true;

		// Elimina nodo
		if (ant == NULL){
			lista = lista->sig;
		}else{
			ant->sig = tmp->sig;
		}
		delete tmp;
	}
}


void Participantes::vaciar(){
	TLista tmp;

	while(lista != NULL ){
		tmp = lista;
		lista = lista->sig;

		delete tmp;
	}
}

}

