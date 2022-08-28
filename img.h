#ifndef IMG_H
#define IMG_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Img {
	

public:
	
	Texture bois;
	Texture fleur1;
	Texture fleur2;
	Texture fleur3;
	Texture fleur4;
	Texture pierre1;
	Texture pierre2;
	Texture pierre3;
	Texture boisMort;
	Texture planteBougeante;
	Texture table_craft;
	Texture mur_bois;
	Texture mur_pierre;
	Texture mur_pierre_ame;
	Texture pioche;
	Texture pelle;
	Texture baril;
	Texture totem1;
	Texture totem2;
	Texture totem3;
	Texture note;

	//Texture monsters
	Texture espritVengeur;

	//Texture animations
	Texture eau;
	Texture feu;
	Texture terre;
	Texture metal;
	Texture plante;
	Texture electricite;
	Texture air;
	Texture tenebre;
	Texture lumiere;
	Texture espace;
	Texture temps;
	Texture poison;

	//Proto du contructeur
	Img();
	void loadTextures();
	Texture* getImageByID(int id);



	//attribut private
private:

};
#endif

