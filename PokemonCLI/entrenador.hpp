#ifndef _ENTRENADOR_HPP_
#define _ENTRENADOR_HPP_

#include <string>		// Para el nombre.
#include "tipos.hpp"	// Para el género.
#include "pokemon.hpp"	// TAD Pokémon

class Entrenador
{
public:
	
	Entrenador(string nombre, genero genero);
	
	unsigned short int ID;	// Número que identifica al jugador 0...65535
	string nombre;			// Nombre del entrenador pokémon.
	genero genero;			// Si el entrenador es hombre o mujer.
							// Dependiendo del género se mostrará la imagen del hombre o de la mujer.
	// Listas pseudoestáticas
	Pokemon equipo[6];		// Equipo pokémon, siempre habrá 1 y como máximo 6.
	// Objetos mochila[20];	// Puede no tener objetos.
	bool medallas[8];		// Por defecto no tiene medallas.
	
	// NOTA: En un combate pokémon entrará siempre a combatir el primer pokémon
	//       del equipo del entrenador.
};

#endif //_ENTRENADOR_HPP_
