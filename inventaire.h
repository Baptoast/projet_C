#ifndef INVENTAIRE_H
#define INVENTAIRE_H

//include
#include <SFML/Graphics.hpp>
#include "img.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Inventaire {

	Img imgStock;

	Texture texture_inventaire;
	Texture texture_flecheG;
	Texture texture_flecheD;

	Sprite sprite_inventaire;
	Sprite sprite_flecheG;
	Sprite sprite_flecheD;
	Sprite sprite_materiaux;


public:
	vector<int> idMateriaux;
	vector<int> quantite;
	int curseur = 0;

	//Proto du 
	Inventaire();

	//fontion
	void loadTextureInventaire();
	void afficheInventaire(RenderWindow& window, int x, int y);

private:

};
#endif

