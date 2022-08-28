#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "input.h"
#include <vector>
#include <SFML/Network.hpp>
#include <windows.h>


//Constantes du Programme
const int SCREEN_SIZE_WEIGHTS = 960;
const int SCREEN_SIZE_HEIGHTS = 960;

using namespace sf;
using namespace std;

class Menu {
	View vue = View();
	VideoMode ecran;
	Mouse laSouris;

	RenderWindow window;

	Input input;
	Event event;

	TcpSocket socket;

	Texture texture_menu;
	Sprite sprite_menu;

	Texture texture_Elem1;
	Texture texture_Elem2;
	Texture texture_Elem3;

	Sprite sprite_Elem1;
	Sprite sprite_Elem2;
	Sprite sprite_Elem3;

	bool choix1 = false;
	bool choix2 = false;
	bool choix3 = false;

	bool premiere = true;

	

public:
	int elem1;
	int elem2;
	int elem3;

	bool accepteJeu = false;
	bool fermeFenetr = false;
	//Proto du contructeur
	Menu();

	//getter

	//setter

	//fonction
	void creationMenu();
	void bouclePrincipale();
	void loadImageMenu();
	bool isOpen();
	void fermeFenetre();
	int convertisseurDeuxCaractereChiffres(char chiffre1, char chiffre2);
	void miseAJourChoixElements(char* data);
	void miseAJourCaseElements(int numElem, int cas);

	void premiereConnexion(Socket::Status* status);


private:

};
#endif



