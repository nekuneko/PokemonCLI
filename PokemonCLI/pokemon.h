#ifndef POKEMON_H
#define POKEMON_H

#include <string>			// Para uso de cadenas de caracteres (nombres).
#include "tipos.h"			// Para usar tipos (Planta, Eléctrico, etc.).
#include "movimientos.h"	// Para tener un vector de movimientos.
#include "movimientosdb.h"	// Para movimientos predefinidos.


using namespace std;

// TAD Pokémon, Clase Abstracta

class Pokemon
{
public:
	/* Constructor por defecto */
	Pokemon();	// Pokémon nulo.
	
	/* Constructores alternativos */
	Pokemon (string imagen, string numero, string nombre);
	Pokemon (string nombre, unsigned nivel, bool s);
	
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

// Métodos modificadores
	void levelUp();			// Sube el Pokémon un nivel.
	void verStats();		// Muestra los stats del Pokémon.
	void verMovimientos();	// Lista los movimientos del Pokémon.
	void atacar(Pokemon& rival, int sel);
//	void recibeDaño(Pokemon& rival, int sel);
	
// Métodos observadores
	string numero () { return numero_; }
	string nombre () { return nombre_; }
	tipos  tipo	  () { return tipo_;   }

//private:
	const string imagen_;	// Imagen gráfica del Pokémon.
	const string numero_;	// Número del Pokémon en la Pokédex.
	const string nombre_;	// Nombre del Pokémon.
	const tipos  tipo_;  	// Tipo del Pokémon (Fuego, Agua, Planta, etc.).
	
	bool salvaje_;			// Si el Pokémon es salvaje se puede capturar.
	
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

#endif // POKEMON_H
