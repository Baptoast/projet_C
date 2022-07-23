#ifndef MATERIAUX_H
#define MATERIAUX_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include "img.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Materiaux {

	Sprite sprite_materiaux;

	//Fonction public
public:
	int posX;
	int posY;
	int solidite;
	int idMateriaux;
	int resistantmax = -1;
	int resistant = -1;

	//Proto du contructeur
	Materiaux(int x, int y, Texture* texture, int id, float rotation);
	void afficheMateriaux(RenderWindow& window);

	Sprite getSprite();


	//attribut private
private:

};
#endif

