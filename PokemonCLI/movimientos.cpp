#include "movimientos.h"

Movimiento::Movimiento()	// Movimiento nulo.
{
	this->nombre = "----------";
	this->tipo = NoTipo;
	this->categoria = NoCat;
	this->potencia = 0;
	this->precision = 0;
	this->pp_tot = 0;
	this->pp = 0;
}

Movimiento::Movimiento(string nombre, tipos tipo, string categoria,
					   unsigned potencia, unsigned precision, unsigned pp)
	:
		nombre(nombre), tipo(tipo), categoria(categoria), potencia(potencia),
		precision(precision), pp(pp), pp_tot(pp)
{}





