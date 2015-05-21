#ifndef  MOVIMIENTOS_H
#define  MOVIMIENTOS_H

#include <string>		// Para usar cadenas de caracteres (nombres).
#include "tipos.h"	// Para usar tipos (Planta, Agua, etc.).

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

#endif // MOVIMIENTOS_HPP
