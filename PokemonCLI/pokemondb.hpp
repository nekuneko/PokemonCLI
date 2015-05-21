#ifndef _POKEMONDB_HPP_
#define _POKEMONDB_HPP_

#include "pokemon.hpp"

/* Objetos pokemon predefinidos con stats base */
// Heredan de la clase Pokémon, cada "raza" de Pokémon es una especialización.

// nombre, tipo, salvaje, nivel, ps, ataque, defensa, ataque_esp, defensa_esp, velocidad.
static Pokemon kyogre	("Kyogre", Agua, 0, 50, 310, 205, 185, 305, 285, 185, salpicar, surf, hidrobomba, ventisca );
static Pokemon groudon	("Groudon", Tierra, 0, 50, 310, 305, 285, 205, 185, 185, llamarada, rayoSolar, terremoto, estallido);

#endif // _POKEMONDB_HPP_
