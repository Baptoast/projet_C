#ifndef INVENTAIRE_H
#define INVENTAIRE_H

//include
#include <SFML/Graphics.hpp>
#include "img.h"
#include "materiaux.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Inventaire {

	Font font;
	Text nombreDeItem;
	Mouse souris;

	Img imgStock;

	Texture texture_inventaire;
	Texture texture_flecheG;
	Texture texture_flecheD;
	

	Sprite sprite_inventaire;
	Sprite sprite_flecheG;
	Sprite sprite_flecheD;
	Sprite sprite_materiaux;
	

	CircleShape cercleSelection;
	bool enSelection = false;

	vector<Materiaux> *listeDeMateriaux;


public:
	vector<int> idMateriaux;
	vector<int> quantite;
	int curseur = 0;
	bool enAppuie = false;

	//Proto du 
	Inventaire();

	//fontion
	void loadTextureInventaire();
	void initialiseListeMateriaux(vector<Materiaux>* laListe);
	void afficheInventaire(RenderWindow& window, int x, int y);

private:

};
#endif

