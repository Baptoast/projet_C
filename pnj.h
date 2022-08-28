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

	//structure utilis�e dans Perso.cpp
	struct Pos { int posX, posY; };

	//Texture du personnage (image dans un dossier)
	//Sprite du personnage (apparence du personnage en jeu)
	
	Sprite sprite_pv;
	Sprite sprite_pvmax;
	//Liste des directions o� peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 � 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;
	//Toutes les clocks
	Clock timeDeplacementPerso;
	Clock timeAnimationPerso;

	Clock reflexion;
	bool enChasse = false;
	float nouvelleDirectionX;
	float nouvelleDirectionY;
	int avancement;

	//Caract�ristiques du personnage
	bool updateFPS;
	int vitesse;
	float positionXSourisVue;
	float positionYSourisVue;

	int ramassage = 0;

	int pvmax;
	
	


	//Fonction public
public:
	Sprite sprite_pnj;
	int pv;
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
