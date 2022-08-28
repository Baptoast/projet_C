#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "input.h"
#include "sol.h"
#include "sort.h"
#include "img.h"
#include "pnj.h"
#include "joueur.h"
#include "materiaux.h"
#include "hud.h"
#include "inventaire.h"
#include "table_craft.h"
#include <vector>
#include <SFML/Network.hpp>
#include <windows.h>


//Constantes du Programme
const int SCREEN_SIZE_WEIGHT = 960;
const int SCREEN_SIZE_HEIGHT = 960;

using namespace sf;
using namespace std;

class Jeu {
	View vue = View();
	VideoMode ecran;
	Clock clk;
	Clock tempsRafraichissementMateriaux;
	Mouse laSouris;

	TcpSocket socket;

	RenderWindow window;

	Input input;
	Event event;

	vector<Joueur> listeDeJoueur;
	/*
	1 = Spawn
	2 = Zone 1
	3 = Zone 2
	0 = Zone 3
	4 = Zone dejà chargée
	5 = Zone dejà chargée et qui ne fait plus charger
	*/
	const int tabCarteOriginal[441] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,
						  0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,
						  0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,1,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,
						  0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,
						  0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
						};
	int tabCarte[441] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,
						  0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,
						  0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,1,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,2,2,2,2,2,2,2,2,2,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,2,2,2,2,2,2,2,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,0,0,0,
						  0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,
						  0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,
						  0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	vector<Materiaux> listeDeMateriaux;
	vector<Materiaux*> listeDeMateriauxJoueur;
	vector<Materiaux*> listeDeMateriauxPoubelle;

	vector<Pnj> listeDePnj;
	Sol leSol;
	Img imageStock;
	Inventaire inventaire;
	TableCraft tableCraft;

	vector<Sort> sortEnJeu;
	bool sortAppuie = false;
	//A remplacer par couldown
	Clock sort1cd;
	Clock sort2cd;
	Clock sort3cd;
	Clock sort4cd;
	Clock sort5cd;
	Clock sort6cd;
	vector<int> degatsSorts;
	

public:

	//Proto du contructeur
	Jeu();

	//getter

	//setter

	//fonction
	void creationJeu(vector<int>* elemJoueur);
	void bouclePrincipale();
	bool isOpen();
	void communicationServeur(Socket::Status* status);
	void communicationServeurReception(Socket::Status* status);

	void generationAleatoireMateriaux(int numcase);

private:

};
#endif


