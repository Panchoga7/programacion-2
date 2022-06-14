#ifndef PARTICIPANTES_H
#define PARTICIPANTES_H

#include <string>

namespace prog2{

class Participantes{
public:
	Participantes();

	~Participantes();

	Participantes( const Participantes& p );

	unsigned numParticipantes() const;

	void inscribir( const std::string& par, bool& ok );

	bool inscrito( const std::string& par ) const;

	void incluirEtapa( const std::string& par, double t, bool& ok );

	void obtenerPar( const std::string& par, unsigned& ne, double& t, bool& ok ) const;

	void obtenerPos( unsigned pos, std::string& par, unsigned& ne, double& t, bool& ok ) const;

	void eliminar( const std::string& par, bool& ok );

	void vaciar();

private:
	struct TNodo{
		std::string nombre;
		unsigned nEtapas;
		double tiempo;
		TNodo* sig;
	};

	typedef TNodo* TLista;

	TLista lista;
};


}
#endif
