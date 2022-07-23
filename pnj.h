#ifndef PNJ_H
#define PNJ_H

//include
#include <SFML/Graphics.hpp>
#include "joueur.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Pnj {

	Mouse laSouris;

	//structure utilisée dans Perso.cpp
	struct Pos { int posX, posY; };

	//Texture du personnage (image dans un dossier)
	Texture texture_pnj;
	//Sprite du personnage (apparence du personnage en jeu)
	Sprite sprite_pnj;
	//Liste des directions où peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 à 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;
	//Toutes les clocks
	Clock timeDeplacementPerso;
	Clock timeAnimationPerso;

	Clock reflexion;
	bool enChasse = false;
	float nouvelleDirectionX;
	float nouvelleDirectionY;
	int avancement;

	//Caractéristiques du personnage
	bool updateFPS;
	int vitesse;
	float positionXSourisVue;
	float positionYSourisVue;

	int ramassage = 0;
	


	//Fonction public
public:
	bool estDead = false;
	//Proto du contructeur
	Pnj();
	Pnj(int x, int y, Texture* texture, int id);

	Sprite getSprite();

	//fontion
	void loadTexturePnj();
	void deplacementPnj(RenderWindow& window, Joueur& leJoueur);
	void animationPnj(int y);
	void vitesseDeplacementPnj(int vitesse);

	float anglePoints(int x1, int y1, int x2, int y2);

	//attribut private
private:
	Pos posPnj;
};
#endif
