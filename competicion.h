#ifndef COMPETICION_H
#define COMPETICION_H

#include "participantes.h"
#include <string>
#include <vector>

namespace prog2{

class Competicion{
public:
	void leerDatos( const std::string& nombre, bool &ok );

	void listar() const;

	std::vector<std::string> mejores( unsigned n ) const;

private:
	Participantes par;

	std::vector<std::string> elim;
};


}

#endif


