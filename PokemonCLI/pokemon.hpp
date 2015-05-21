#ifndef _POKEMON_HPP_
#define _POKEMON_HPP_

#include <string>				// Para uso de cadenas de caracteres (nombres).
#include "tipos.hpp"			// Para usar tipos (Planta, Eléctrico, etc.).
#include "movimientos.hpp"		// Para tener un vector de movimientos.
#include "movimientosdb.hpp"	// Para movimientos predefinidos.


using namespace std;

class Pokemon
{
public:
	/* Constructor por defecto */
	Pokemon();	// Pokémon nulo.
	
	/* Constructores alternativos */
	Pokemon(string nombre, unsigned nivel, bool s);
	
	Pokemon(string nombre, tipos tipo, bool salvaje, unsigned nivel,
			unsigned ps, unsigned ataque, unsigned defensa,
			unsigned ataque_esp, unsigned defensa_esp, unsigned velocidad,
			Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4);
	
	/* Constructor de copia */
//	Pokemon(const Pokemon& p);	// Sirve para copiar un Pokémon.
	
	/* Sobrecarga del operador de asignación */
//	Pokemon& operator =(const Pokemon& p);
	
	/* Destructor */
//	~Pokemon();
	
	void levelUp();			// Sube el Pokémon un nivel.
	void verStats();		// Muestra los stats del Pokémon.
	void verMovimientos();	// Lista los movimientos del Pokémon.
	void atacar(Pokemon& rival, int sel);
	
//private:
	
//	void recibeDaño(Pokemon& rival, int sel);
//	Imagen imagen;	// Imagen gráfica del Pokémon.
	
	string nombre;	// Nombre del Pokémon.
	tipos tipo;  	// Tipo del Pokémon (Fuego, Agua, Planta, etc.).
	bool salvaje;	// Si el Pokémon es salvaje se puede capturar.
	
	// Stats
	unsigned stats[8];
	unsigned* nivel			= &stats[0];
	unsigned* ps_tot		= &stats[1];
	unsigned* ps            = &stats[2];
	unsigned* ataque		= &stats[3];
	unsigned* defensa		= &stats[4];
	unsigned* ataque_esp	= &stats[5];
	unsigned* defensa_esp	= &stats[6];
	unsigned* velocidad		= &stats[7];
	
	// Vector con los movimientos del Pokémon.
	Movimiento movimientos[4];
	
};

#endif //_POKEMON_H_
