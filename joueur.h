#ifndef JOUEUR_H
#define JOUEUR_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include "materiaux.h"
#include "inventaire.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Joueur {
	//recupere les actions du joueur (shift pour aller plus vite)
	Input inputPerso;
	Mouse laSouris;
	Inventaire *inventaire;


	//structure utilisée dans Perso.cpp
	struct Pos { float posX, posY; };

	//Texture du personnage (image dans un dossier)
	Texture texture_joueur;
	Texture texture_joueur_slave;
	//Sprite du personnage (apparence du personnage en jeu)
	Sprite sprite_joueur;
	Sprite sprite_pv;
	Sprite sprite_pvmax;
	//Liste des directions où peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 à 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;
	//Toutes les clocks
	Clock timeDeplacementPerso;
	Clock timeAnimationPerso;

	Texture texture_boite;
	Texture texture_chargement;
	Sprite sprite_boite;
	Sprite sprite_chargement;

	//Caractéristiques du personnage
	bool updateFPS;
	int vitesse;
	float positionXSourisVue;
	float positionYSourisVue;

	int ramassage = 0;
	bool estPossede = false;
	int compteurPossession = 0;
	float effet = 0.0;
	bool reverseEffet = false;

	bool effetTotemSpeed = false;
	bool effetTotemRecupSpeed = false;

	int pvmax;

	//PARTIE PROJET C

	/* Liste elements :
	1 - Eau
	2 - Feu
	3 - Terre
	4 - Metal
	5 - Plante
	6 - Electricité
	7 - Air
	8 - Ténèbre
	9 - Lumière
	10 - Espace
	11 - Temps
	12 - Poison
	*/
	
	

	//Fonction public
public:
	int elements[3];
	bool dansTableCraft = false;
	int pv;

	//Proto du contructeur
	Joueur(float x, float y, Inventaire* inventaireDuJoueur);

	//Setter
	void setInput(Input input);
	void setPosX(float x);
	void setPosY(float y);

	//Getter
	Pos getPos(void) const;
	Sprite getSprite();

	//fontion
	void loadTexturePerso();
	void deplacementPerso(vector<Materiaux*>& listeDesMateriaux);
	void ramasseMateriaux(RenderWindow& window, vector<Materiaux*>& listeDesMateriaux, vector<Materiaux*>& listeDesMateriauxPoubelle);
	void consultationMateriaux(RenderWindow& window, vector<Materiaux*>& listeDesMateriaux);
	void animationPerso(int y);
	void vitesseDeplacementPerso(int vitesse, vector<Materiaux*>& listeDesMateriaux);
	void controlePerso(RenderWindow& window, vector<Materiaux*>& listeDesMateriaux, vector<Materiaux*>& listeDesMateriauxPoubelle);
	float anglePoints(int x1, int y1, int x2, int y2);
	float anglePointsDegree(int x1, int y1, int x2, int y2);
	bool dansChampDeVision(int xObj, int yObj);
	void changementApparence(int num);
	void deplacementPersoPossede();



	//attribut private
private:
	Pos posJoueur;
};
#endif
