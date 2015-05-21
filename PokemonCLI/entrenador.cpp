#include <cstdlib>	// Para srand() y rand()
#include <ctime>	// Para	semilla aleatoria
#include "entrenador.hpp"

Entrenador::Entrenador(string nombre, enum genero genero)
						 : nombre(nombre), genero(genero)
{
	srand((unsigned) time(0));
	ID = 0 + (rand() % 65535);
	for (int i=0; i<=7; ++i)
		medallas[i] = 0;
}

/*
void fichaEntrenador(Entrenador& e)
{
	unsigned short int medallas = 0;
	for (int i=0; i<=7; ++i)
		if (e.medallas[i])
			medallas++;
	
	cout << " \t--- Ficha de Entrenador ---"	<< endl;
	cout << "Nombre:   " << e.nombre				<< endl;
	cout << "Género:   " << nom_gen[e.genero]		<< endl;
	cout << "Medallas: " << medallas                << endl;
	cout << endl << " \t--- Equipo Pokémon ---" << endl;
	for (int i=0; i<=5; ++i)
		if (e.equipo[i].nombre != "Missingno.")	// Si el pokémon no es nulo.
			cout <<i+1 << ": " << e.equipo[i].nombre << endl;
}
*/