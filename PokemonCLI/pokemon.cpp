#include <iostream>
#include <cassert>			// Para controlar las precondiciones.
#include <cstdlib>			// Para srand, rand
#include <ctime>			// Para time
#include <cmath>			// Para cálculo de daño. (floor)
#include "efectividad.h"	// Calculo de la efectividad de ataques.
#include "pokemon.h"		// TAD Pokemon


Pokemon::Pokemon()	// Pokemon nulo.
{
	nombre = "Missingno.";
	tipo   = Normal;
	*nivel			= 5;
	*ps_tot         = 15;
	*ps				= *ps_tot;
	*ataque			= 10;
	*defensa		= 10;
	*ataque_esp		= 5;
	*defensa_esp	= 5;
	*velocidad		= 12;
	
	salvaje         = 1;
	
	movimientos[0] = placaje;
}

Pokemon::Pokemon(string nombre, unsigned lvl = 5, bool s = 1)
{
	assert(nombre.length() <= 14);
	
	this->nombre		= nombre;
	this->tipo          = Normal;
	this->salvaje		= 1;
	
	// Stats base
	*this->nivel		= 5;
	*this->ps_tot       = 15;
	*this->ps			= *ps_tot;
	*this->ataque		= 10;
	*this->defensa		= 10;
	*this->ataque_esp	= 5;
	*this->defensa_esp	= 5;
	*this->velocidad	= 12;
	
	movimientos[0] = placaje;
		
	if (lvl > 5)
	{
		for (int i=1; i<= lvl-5; ++i)
			levelUp();
	}
}

Pokemon::Pokemon(string nombre, tipos tipo, bool salvaje, unsigned nivel,
		unsigned ps, unsigned ataque, unsigned defensa,
		unsigned ataque_esp, unsigned defensa_esp, unsigned velocidad,
		Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4)
{
	assert(nombre.length() <= 14);
	
	this->nombre		= nombre;
	this->tipo          = tipo;
	this->salvaje		= salvaje;
	
	// Stats base
	*this->nivel		= nivel;
	*this->ps_tot		= ps;
	*this->ps			= ps;
	*this->ataque		= ataque;
	*this->defensa		= defensa;
	*this->ataque_esp	= ataque_esp;
	*this->defensa_esp	= defensa_esp;
	*this->velocidad	= velocidad;
	
	movimientos[0] = mov1;
	movimientos[1] = mov2;
	movimientos[2] = mov3;
	movimientos[3] = mov4;
}


// ESTO NO TIENE QUE ESTAR AQUI, NO DEBE HABER E/S EN LA CLASE
void Pokemon::verStats()
{
	cout << "\t" << nombre << endl;
	cout << "Nivel:        "	<< *nivel		<< endl
	<< "PS_TOTAL:     "	<< *ps_tot		<< endl
	<< "PS:           "	<< *ps			<< endl
	<< "Ataque:       "	<< *ataque		<< endl
	<< "Ataque Esp.:  "	<< *ataque_esp	<< endl
	<< "Defensa:      "	<< *defensa		<< endl
	<< "Defensa Esp.: "	<< *defensa_esp << endl
	<< "Velocidad:    "	<< *velocidad	<< endl << endl;
}

void Pokemon::verMovimientos()
{
	for (int i=0; i<=3; ++i)
		cout << movimientos[i].nombre << endl;
}

void Pokemon::levelUp()
{
	++*nivel;
	for (int i=1; i<=7; ++i)
		stats[i] = ceil(stats[i] * 1.02);	// Al subir de nivel los stats suben un 2%
}

void Pokemon::atacar(Pokemon& rival, int sel)
{
	Movimiento mov = this->movimientos[sel];
	float b, e, v;
	
	srand((unsigned) time(0));
	
	if (mov.tipo == this->tipo)
		b = 1.5;
	else
		b = 1;
	
	e = efectividad(mov.tipo, rival.tipo);
	
	v = (85 + (rand() % (100 - 85 + 1))); // Tiene que ser un valor discreto entre 85 y 100
	
	unsigned daño = 0;
	if (mov.categoria == "Físico  ")
		daño = floor(0.01 * b * e * v * (((0.2 * *this->nivel + 1) * *this->ataque  * mov.potencia) / (25 * *rival.defensa) + 2));
	if (mov.categoria == "Especial")
		daño = floor(0.01 * b * e * v * (((0.2 * *this->nivel + 1) * *this->ataque_esp * mov.potencia) / (25 * *rival.defensa_esp) + 2));
	
//	cout << "Daño de " << mov.nombre << ": " << daño << endl;
//	getchar(); getchar();

	
	// Aplicación del cálculo de daño
	if (*rival.ps <=  daño)
		*rival.ps = 0;
	else
		*rival.ps -= daño;
	
	// Disminuyen los pp del ataque.
	--mov.pp;
}
