//
//  382_kyogre.h
//  PokemonCLI
//
//  Created by Kaneda Shotaro on 21/05/15.
//  Copyright (c) 2015 UCA. All rights reserved.
//

#ifndef _382_KYOGRE_H
#define _382_KYOGRE_H

#include "pokemon.h"


class Kyogre : public Pokemon
{
public:
	Kyogre ();
	Kyogre ();
	Pokemon(string nombre, tipos tipo, bool salvaje, unsigned nivel,
			unsigned ps, unsigned ataque, unsigned defensa,
			unsigned ataque_esp, unsigned defensa_esp, unsigned velocidad,
			Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4);
};


#endif // _382_KYOGRE_H
