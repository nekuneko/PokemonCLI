#ifndef  MOVIMIENTOSDB_H
#define  MOVIMIENTOSDB_H

#include "movimientos.hpp"

// CUIDADO, AL DEFINIRLOS COMO STATIC NO SE LES PUEDE RESTAR LOS PP
// Y ADEMÁS SON COMUNES A TODOS LOS POKÉMON

/* Objetos movimientos predefinidos */

static Movimiento nulo      ("----------", NoTipo, "--------", 0, 0, 0);

static Movimiento placaje   ("Placaje   ", Normal,	"Físico  ", 50, 100, 35);

static Movimiento llamarada ("Llamarada ", Fuego,	"Especial", 110, 85, 5);
static Movimiento rayoSolar ("Rayo Solar", Planta,	"Especial", 120, 100, 10);
static Movimiento terremoto ("Terremoto ", Tierra,	"Físico  ", 100, 100, 10);
static Movimiento estallido ("Estallido ", Fuego,	"Especial", 150, 100, 5);

static Movimiento ventisca  ("Ventisca  ", Hielo,	"Especial", 110, 70, 5);
static Movimiento surf		("Surf      ", Agua,	"Especial", 90, 100, 15);
static Movimiento salpicar  ("Salpicar  ", Agua,	"Especial", 150, 100, 5);
static Movimiento hidrobomba("Hidrobomba", Agua,	"Especial", 110, 80, 5);

/* Movimientos de tipo Agua	*/

/* Movimientos de tipo Eléctrico */

static Movimiento trueno	("Trueno    ", Eléctrico, "Especial", 110, 70, 10);

/* Movimientos de tipo Fuego */

/* Movimientos de tipo Hielo */

/* Movimientos de tipo Normal */

/* Movimientos de tipo Planta */

/* Movimientos de tipo Tierra */


#endif // MOVIMIENTOSDB_H
