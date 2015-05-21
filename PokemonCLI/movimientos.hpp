#ifndef _MOVIMIENTOS_HPP_
#define _MOVIMIENTOS_HPP_

#include <string>		// Para usar cadenas de caracteres (nombres).
#include "tipos.hpp"	// Para usar tipos (Planta, Agua, etc.).

using namespace std;

class Movimiento
{
public:
	Movimiento();
	Movimiento(string nombre, tipos tipo, string categoria,
			   unsigned potencia, unsigned precision, unsigned pp);

	string nombre;
	tipos tipo;
	string categoria;
	unsigned potencia;
	unsigned precision;
	unsigned pp_tot;
	unsigned pp;
};

#endif //_MOVIMIENTOS_HPP_
