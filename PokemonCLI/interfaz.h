#ifndef _INTERFAZ_H_
#define _INTERFAZ_H_

#include "pokemon.h"	// TAD Pokemon.

void menuInicial	(Pokemon& pkm, Pokemon& rival);
void combate		(Pokemon& pkm, Pokemon& rival);
int menucombate		(Pokemon& pkm);
int menuataque		(Pokemon& pkm);	// En realidad es un submenú de menucombate
void imprimecombate (Pokemon& pkm, Pokemon& rival);
void imprimepkm		(void);
void imprimerival	(void);
void imprimetrainer (void);
void imprimestatspkm	(Pokemon& pkm);
void imprimestatsrival	(Pokemon& rival);

// void imprimeImagen (Imagen& I);
// Recibirá una imagen y la imprimirá según el contexto (primer plano/segundo plano)
// El tipo imagen consistirá en 9 cadenas de texto de 20 caracteres
// Las imágenes por defecto estarán en primer plano.
// En segundo plano invertirá los caracteres de las cadenas y añadira \ts al principio

//void imprimeInfo(Pokemon& P);
// Recibirá un pokémon e imprimirá su nombre, nivel y barra de vida según
// el contexto (primer plano/segundo plano)
//En primer plano añadirá \t



#endif //_INTERFAZ_H_