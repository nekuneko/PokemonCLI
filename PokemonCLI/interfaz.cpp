#include <iostream>		// Para E/S.
#include <ctime>		// Para ataque aleatorio.
#include <iomanip>		// Para setfill y setw (rellenar con 0s).
#include <thread>       // std::this_thread::sleep_for
#include <chrono>		// std::chrono::seconds
#include <cmath>		// Para floor
#include "efectividad.hpp"	//Determinación de la efectividad
#include "interfaz.hpp"

void cuantoEfectivo (Pokemon& pkm, Pokemon& rival, int sel)
{
	float e = efectividad(pkm.movimientos[sel].tipo, rival.tipo);

	if (e == 2)
	{
		system("afplay music/superdamage.wav &");
		cout << "¡Es muy eficaz!" << endl;
	}
	else
	{
		if (e == 0.5)
		{
			system("afplay music/notverydamage.wav &");
			cout << "No es muy eficaz..." << endl;
		}
		else
		{
			if (e == 0)
			{
				cout << "No afecta a " << rival.nombre << "..." << endl;
			}
			else // e = 1
			{
				system("afplay music/normaldamage.wav &");
			}
		}
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


void imprimeinicio (Pokemon&rival)
{
	system("clear");
	imprimestatsrival(rival);
	imprimerival();
	
	imprimetrainer();
}

void imprimecombate (Pokemon& pkm, Pokemon& rival)
{
	system("clear");
	imprimestatsrival(rival);
	imprimerival();

	imprimepkm();
	imprimestatspkm(pkm);
}

void menuInicial (Pokemon& pkm, Pokemon& rival)
{
	system("afplay music/382Cry.wav &");
	imprimeinicio(rival);
	cout << "¡Un " << rival.nombre << " salvaje!";
	cin.get();
	
	
	imprimeinicio(rival);
	cout << "¡Adelante, " << pkm.nombre << "!";
	cin.get();
	
	system("afplay music/383Cry.wav &");
	combate(pkm, rival);
}

bool fin_combate(Pokemon pkm)
{
	return *pkm.ps <= 0;
}

void combate (Pokemon& pkm, Pokemon& rival)
{
	int	max, min,
		terminado = 0;
	
	Pokemon primero, segundo;
	
	do
	{
		do /* Menú combate */
		{	imprimecombate(pkm, rival);
			
			cout << "¿Qué debería hacer " << pkm.nombre << "?" << endl;
			max = menucombate(pkm);
		} while (max < 0 || max > 3);

		switch (max)
		{
			case 0:
				
				do // Menú ataque
				{
					imprimecombate(pkm, rival);
					
					cout << "¿Qué debería hacer " << pkm.nombre << "?" << endl;
					max = menuataque(pkm);
					
					srand((unsigned) time(0));	// Ataque aleatorio para Min.
					min = (0 + (rand() % (3 - 0 + 1)));
					
					if (pkm.movimientos[max].pp <= 0)
					{
						cout << "¡No quedan PP para este movimiento!" << endl;
						cin.get();
					}	// BUCLE INFNITIO SI EL POKEMON SE QUEDA SIN PP EN TODOS LOS MOVIMIENTOS
					
					// Si nigún ataque tiene PPs, usar "Combate"
				
				} while ((max < 0 || max > 3) || (pkm.movimientos[max].pp <= 0));
				// Hay que elegir un ataque válido, y con suficientes PP.
				
				/*
				// Determinación del orden
				if (*pkm.velocidad >= *rival.velocidad)	// MAX ataca primero.
				{
					pkm.atacar(rival, max);
					terminado = fin_combate(rival);
					if (terminado)
						terminado = 1;
					else
					{
						rival.atacar(pkm, min);
						terminado = fin_combate(pkm);
						if (terminado)
							terminado = -1;
					}
				}
				else	// MIN ataca primero.
				{
					rival.atacar(pkm, min);
					terminado = fin_combate(pkm);
					if (terminado)
						terminado = -1;
					else
					{
						rival.atacar(rival, max);
						terminado = fin_combate(rival);
						if (terminado)
							terminado = 1;
					}
				}
				
				// Ataqur
				imprimecombate(pkm, rival);
				cout << primero.nombre << " usó " << primero.movimientos[mov1].nombre << "." << endl;
				getchar(); getchar();
				
				primero.atacar(segundo, primero.movimientos[mov2]);
				imprimecombate(primero, segundo);
				
				if (*segundo.ps <= 0)	// Si pierde acaba el combate.
					terminado = 1;
				else					// Sino le toca al oponente.
				{
					imprimecombate(pkm, rival);
					cout << segundo.nombre << " usó " << segundo.movimientos[mov2].nombre << "." << endl;
					getchar();
					
					segundo.atacar(primero, segundo.movimientos[mov2]);
					imprimecombate(pkm, rival);
					
					if (*primero.ps <= 0)
						terminado = -1;
				}
			
*/
				terminado = 0;
				if (*pkm.velocidad >= *rival.velocidad)	// MAX ataca primero.
				{
					imprimecombate(pkm, rival);	// Vista global del combate sin menús.
					
					cout << pkm.nombre << " usó " << pkm.movimientos[max].nombre << ".";
					getchar(); getchar();
					
					pkm.atacar(rival, max);
					
					imprimecombate(pkm, rival);
					cuantoEfectivo(pkm, rival, max);
					
					if (*rival.ps <= 0)
						terminado = 1;
					
					else
					{
						imprimecombate(pkm, rival);
						cout << rival.nombre << " usó " << rival.movimientos[min].nombre << ".";
						cin.get();
						
						rival.atacar(pkm, min);
						
						imprimecombate(pkm, rival);
						cuantoEfectivo(rival, pkm, min);
						
						if (*pkm.ps <= 0)
							terminado = -1;
					}

				}
				else	// MIN ataca primero.
				{
					imprimecombate(pkm, rival);	// Vista global del combate sin menús.
					cout << rival.nombre << " usó " << rival.movimientos[min].nombre << ".";
					cin.get();
					
					rival.atacar(pkm, min);
					
					imprimecombate(pkm, rival);
					cuantoEfectivo(rival, pkm, min);
					
					if (*pkm.ps <= 0)
						terminado = -1;
					else
					{
						imprimecombate(pkm, rival);
						cout << pkm.nombre << " usó " << pkm.movimientos[max].nombre << ".";
						cin.get();
						
						pkm.atacar(rival, max);
						
						imprimecombate(pkm, rival);
						cuantoEfectivo(pkm, rival, max);
						
						if (*rival.ps <= 0)
							terminado = 1;
					}
				}
				break;
			case 1:
				cout << "La mochila aún no está implementada.";
				getchar(); getchar();
				break;
			case 2:
				cout << "¡Este es tu último Pokémon!";
				getchar(); getchar();
				break;
			case 3:
				terminado = 2;
				break;
			default: 
				break;
		}
		
	} while (terminado == 0);
	
	
	
	
	switch (terminado)
	{
	case -1:
			system("killall afplay");	// Para la música (Cambio a música victoria/derrota).
			system("afplay music/383Cry.wav &");
			cout << "¡" << pkm.nombre << " se debilitó!" << endl;
			cout << "¡A <NOMBRE_ENTRENADOR> no le quedan más pokémon!" << endl;
			cout << "<NOMBRE_ENTRENADOR> corrió al Centro Pokémon más cercano." << endl;
			break;
	case 1:
			system("killall afplay");	// Para la música (Cambio a música victoria/derrota).
			
			if (rival.salvaje == 1)
			{
				system("afplay music/382Cry.wav &");
				system("afplay music/victory.mp3 &");
				cout << "¡" << rival.nombre << " salvaje se debilitó!" << endl;
				cout << "¡"<< pkm.nombre << " ganó " << 3000 << " puntos de experiencia!";
				
			}
			else
			{
				system("afplay music/382Cry.wav &");
				system("afplay music/victory.mp3 &");
				cout << "¡" << rival.nombre << " enemigo se debilitó!" << endl;
				cout << "¡"<< pkm.nombre << " ganó " << 3000 << " puntos de experiencia!" << endl;
				cout << "¡Derrotaste a <CLASE_ENTRENADOR> <NOMBRE_ENTRENADOR>!";
			}
			
			
			getchar();
			break;
	case 2:
			system("killall afplay");	// Para la música (Cambio a música victoria/derrota).
			system("afplay music/Flee.wav &");
			cout << "¡Escapaste sin problemas!";
			getchar(); getchar();
			break;
	default:
			break;
	}
	
	system("killall afplay");	// Para la música (Fin del combate).
	
}

void imprimepkm (void)
{
		cout <<"      |\\ |\\ |\\ |\\     " << endl
	 		 <<"      | \\|_\\|_\\| \\    " << endl
			 <<"     /    \\_O_/_  \\   "   << endl
	         <<"  <<   <<|| /\\/\\/\\/   "  << endl
			 <<"   /     || \\/\\/\\/\\   " << endl
			 <<"<<   | |    ______/   "     << endl
			 <<"/   / | \\   /         "    << endl
			 <<"   | _O_ |            "     << endl
			 <<"   |/\\|/\\|      "         ;
}

void imprimerival (void)
{
		
	cout <<"\t\t\t    |/\\|/\\|          "  << endl
		 <<"\t\t\t    | \\O/ |          "   << endl
		 <<"\t\t\t ____\\_|_/____  ___  "   << endl
		 <<"\t\t\t/             \\/  _E "   << endl
		 <<"\t\t\t|  O  - - -    - _E  "    << endl
		 <<"\t\t\t\\_____________/\\___E "  << endl
		 <<"\t\t\t     / | \\           "   << endl
		 <<"\t\t\t    | /O\\ |          "   << endl
		 <<"\t\t\t    |/\\|/\\|          "  << endl;
}

void imprimetrainer (void)
{
	cout <<"     _____		"               << endl
		 <<"  __|_____|		"               << endl
		 <<"    |   - |		"               << endl
		 <<"    |____-|     "               << endl
		 <<"   ___| |___	"               << endl
		 <<"  /  \\\\     \\  "             << endl
		 <<" / /| \\\\  |\\ \\ "            << endl
		 <<"/ / |  \\\\ | \\ \\"            << endl;
}

void imprimestatspkm (Pokemon& pkm)
{
//	cout << "PS de " << pkm.nombre << ": " << pkm.ps << endl;
//	getchar();
	
	int maxpoints = 20;
	int relacion = floor((*pkm.ps * maxpoints) / *pkm.ps_tot);

	cout << pkm.nombre;
	for(int i=1; i<=(14 - pkm.nombre.length()); ++i)
		cout << " ";
	cout<< " Nv: " << *pkm.nivel << endl;
	
	cout <<"\t\t(";
	for (int i=1; i<=relacion; ++i)
		cout <<"#";
	for (int i=relacion; i<maxpoints; ++i)
		cout <<"_";
	cout << ")" << endl;
	
	cout << "\t\tPS: " << *pkm.ps << "/" << *pkm.ps_tot << endl;
}

void imprimestatsrival (Pokemon& rival)
{
//	cout << "PS de " << rival.nombre << ": " << *rival.ps << endl;
//	getchar();
	
	int maxpoints = 20;
	int relacion = floor((*rival.ps * maxpoints) / *rival.ps_tot);
	
	cout << rival.nombre;
	for(int i=1; i<=(14 - rival.nombre.length()); ++i)
		cout << " ";
	cout << " Nv: " << *rival.nivel << endl;
	
	cout << "(";
	for (int i=1; i<=relacion; ++i)
		cout <<"#";
	for (int i=relacion; i<maxpoints; ++i)
		cout <<"_";
	cout << ")" << endl;
	
	//cout << "PS: " << *rival.ps << "/" << *rival.ps_tot;
}

int menucombate (Pokemon& pkm)
{
	int menu;

	cout <<" _____________________________________________" << endl
		 <<"|                      |                      |"<< endl
		 <<"|  0) Luchar           |  1) Mochila          |"<< endl
	     <<"|                      |                      |"<< endl
	  	 <<"|----------------------|----------------------|"<< endl
		 <<"|                      |                      |"<< endl
		 <<"|  2) Cambiar Pkm.     |  3) Escapar          |"<< endl
		 <<"|______________________|______________________|"<< endl;

	cout <<"Su elección: "; cin >> menu;

	return menu;
}

int menuataque (Pokemon& pkm)
{
	int menu;
	cout <<" _____________________________________________" << endl
		 <<"|                      |                      |"<< endl
		 <<"|  0) " << pkm.movimientos[0].nombre << "       |  1) " << pkm.movimientos[1].nombre << "       |"<< endl
		 <<"|  " << nom_tipo[pkm.movimientos[0].tipo] << " PP: " << setfill('0') << setw(2) << pkm.movimientos[0].pp
												<< "/" << setfill('0') << setw(2) << pkm.movimientos[0].pp_tot << " |  "
			     << nom_tipo[pkm.movimientos[1].tipo] << " PP: " << setfill('0') << setw(2) << pkm.movimientos[1].pp
												<< "/" << setfill('0') << setw(2) << pkm.movimientos[1].pp_tot << " |" << endl
	  	 <<"|----------------------|----------------------|"<< endl
		 <<"|  2) " << pkm.movimientos[2].nombre << "       |  3) " << pkm.movimientos[3].nombre << "       |"<< endl
	     <<"|  " << nom_tipo[pkm.movimientos[2].tipo] << " PP: " << setfill('0') << setw(2) << pkm.movimientos[2].pp
												<< "/" << setfill('0') << setw(2) << pkm.movimientos[2].pp_tot << " |  "
				 << nom_tipo[pkm.movimientos[3].tipo] << " PP: " << setfill('0') << setw(2) << pkm.movimientos[3].pp
												<< "/" << setfill('0') << setw(2) << pkm.movimientos[3].pp_tot << " |" << endl
		 <<"|______________________|______________________|"<< endl;

	cout <<"Su elección: "; cin >> menu;
	return menu;
}