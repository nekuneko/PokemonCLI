#ifndef TIPOS_H
#define TIPOS_H

enum tipos
{
	Acero		= 0,
	Agua		= 1,
	Bicho		= 2,
	Dragón		= 3,
	Eléctrico	= 4,
	Fantasma	= 5,
	Fuego		= 6,
	Hada		= 7,
	Hielo		= 8,
	Lucha		= 9,
	Normal		= 10,
	Planta		= 11,
	Psíquico	= 12,
	Roca		= 13,
	Siniestro	= 14,
	Tierra		= 15,
	Veneno		= 16,
	Volador		= 17,
	NoTipo		= 18
};

static const char* nom_tipo[] =
{
	"Acero    ",
	"Agua     ",
	"Bicho    ",
	"Dragón   ",
	"Eléctrico",
	"Fantasma ",
	"Fuego    ",
	"Hada     ",
	"Hielo    ",
	"Lucha    ",
	"Normal   ",
	"Planta   ",
	"Psíquico ",
	"Roca     ",
	"Siniestro",
	"Tierra   ",
	"Veneno   ",
	"Volador  ",
	"---------"
};

enum categorias
{
	Físico		= 0,
	Especial	= 1,
	NoCat		= 2
};

static const char* nom_cat[] =
{
	"Fisico  ",
	"Especial",
	"--------"

};

enum genero { masculino = 0, femenino = 1 };

static const char* nom_gen[] = { "Masculino", "Femenino" };

#endif	// TIPOS_HPP
