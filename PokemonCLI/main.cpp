#include <iostream>				// Para E/S (system).
#include <thread>				// std::this_thread::sleep_for
#include <chrono>				// std::chrono::seconds
#include "pokemon.h"			// TAD Pokémon
#include "interfaz.h"			// Interfaz Combate
#include "movimientosdb.h"	// Base de datos de movimientos
//#include "pokemondb.h"		// Base de datos de pokemons
//#include "entrenador.h"

int main(void)
{
	system("afplay music/battle.mp3 &");
	std::this_thread::sleep_for(std::chrono::milliseconds(700));	// Pausa 0.7s seg.
	
	/* Creador de Pokémon */
	// nombre, tipo, salvaje, nivel, ps, ataque, defensa, ataque_esp, defensa_esp, velocidad.
	
	Groudon groudon (0, 100, 310, 305, 285, 205, 185, 185,
					 llamarada, rayoSolar, terremoto, estallido);
	Kyogre kyogre	(1, 50, 310, 205, 185, 305, 285, 185,
					 salpicar, surf, trueno, ventisca);
	
	//Pokemon groudon	("Groudon", Tierra, 0, 100, 310, 305, 285, 205, 185, 185, llamarada, rayoSolar, terremoto, estallido);
	//Pokemon kyogre	("Kyogre", Agua, 1, 50, 310, 205, 185, 305, 285, 185, salpicar, surf, trueno, ventisca);
	
	//groudon.verStats();
	//kyogre.verStats();
	
	//groudon.verMovimientos();
	//kyogre.verMovimientos();
	
	
	menuInicial(groudon, kyogre);

	// IMPLEMENTAR LA PRECISIÓN DE LOS ATAQUES
	// IMPLEMENTAR ESTADOS ALTERADOS
	
//	Entrenador e ("Neku", masculino);
//	e.equipo[0] = groudon;
//	fichaEntrenador(e);
	
//	// Para cambiar de orden los movimientos.
//	Movimiento aux = groudon.movimientos[0];
//	groudon.movimientos[0] = groudon.movimientos[1];
//	groudon.movimientos[1] = aux;

    return 0;
}
