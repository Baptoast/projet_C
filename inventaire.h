#ifndef INVENTAIRE_H
#define INVENTAIRE_H

//include
#include <SFML/Graphics.hpp>
#include "img.h"
#include "materiaux.h"
#include "table_craft.h"
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
	vector<Materiaux*>* listeDeMateriauxJoueur;
	vector<Materiaux*>* listeDeMateriauxPoubelle;
	TableCraft* tableCraft;

	Texture fichetmp;
	Sprite fichetmp_sprite;
	bool afficheFiche;

	float rotationM = 0.0;

	Clock tempsAttenteAjoutRetrait;

	bool tableCraftOuverte = false;


public:
	vector<int> idMateriaux;
	vector<int> quantite;
	int curseur = 0;
	bool enAppuie = false;
	bool enAppuieMiddle = false;
	bool first = false;

	//Proto du 
	Inventaire();

	//fontion
	void loadTextureInventaire();
	void initialiseListeMateriaux(vector<Materiaux>* laListe, vector<Materiaux*>* laListeJoueur, vector<Materiaux*>* laListeJoueurPoubelle, TableCraft* laTableDeCraft);
	void afficheInventaire(RenderWindow& window, int x, int y, bool  mouseWheelB, bool mouseWheelH);
	float anglePoints(int x1, int y1, int x2, int y2);
	float anglePointsDegree(int x1, int y1, int x2, int y2);

private:

};
#endif

